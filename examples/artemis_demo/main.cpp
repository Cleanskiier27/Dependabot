#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

#include "google/cloud/aiplatform/v1/prediction_service_client.h"
#include "google/cloud/common_options.h"
#include "google/protobuf/struct.pb.h"
#include "google/cloud/storage/client.h"

// Print a labeled vector of doubles to a generic output stream.
static void printVector(std::ostream& os, const std::string& label, const std::vector<double>& v)
{
    os << label << "[ ";
    for (size_t i = 0; i < v.size(); ++i) {
        os << std::fixed << std::setprecision(6) << v[i];
        if (i + 1 < v.size()) {
            os << ", ";
        }
    }
    os << " ]" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc < 5) {
        std::cerr << "Usage: " << argv[0]
                  << " <project-id> <location-id> <endpoint-id> <bucket-name>" << std::endl;
        return 1;
    }

    std::string projectId = argv[1];
    std::string locationId = argv[2];
    std::string endpointId = argv[3];
    std::string bucketName = argv[4];

    // Endpoint resource name: projects/{project}/locations/{location}/endpoints/{endpoint}
    std::string endpointName = "projects/" + projectId + "/locations/" + locationId + "/endpoints/" + endpointId;
    // API Endpoint URL for the specific region
    std::string apiEndpoint = locationId + "-aiplatform.googleapis.com";

    std::cout << "=== Artemis Neural Network Demo (Vertex AI) ===" << std::endl;
    std::cout << "Target Endpoint: " << endpointName << std::endl;
    std::cout << std::endl;

    namespace aiplatform = ::google::cloud::aiplatform::v1;
    auto options = google::cloud::Options{}.set<google::cloud::EndpointOption>(apiEndpoint);
    auto client = aiplatform::PredictionServiceClient(aiplatform::MakePredictionServiceConnection(options));

    // Prepare a buffer to store results for upload
    std::stringstream resultBuffer;

    // --- Sample inputs representing four sensor readings ---
    std::vector<std::vector<double>> inputs = {
        { 1.0,  0.0,  0.0,  0.0},
        { 0.0,  1.0, -1.0,  0.5},
        {-0.5,  0.3,  0.7, -0.2},
        { 0.8, -0.6,  0.4,  0.9},
    };

    std::cout << "--- Forward pass results ---" << std::endl;
    resultBuffer << "--- Forward pass results ---" << std::endl;

    for (size_t i = 0; i < inputs.size(); ++i) {
        std::cout << "Input  " << i + 1 << ": ";
        printVector(std::cout, "", inputs[i]);
        
        resultBuffer << "Input  " << i + 1 << ": ";
        printVector(resultBuffer, "", inputs[i]);

        // Construct the request
        aiplatform::PredictRequest request;
        request.set_endpoint(endpointName);

        // Convert input vector to protobuf Value (ListValue)
        google::protobuf::Value instance;
        auto* list_value = instance.mutable_list_value();
        for (double val : inputs[i]) {
            list_value->add_values()->set_number_value(val);
        }
        *request.add_instances() = instance;

        // Call Predict
        auto response = client.Predict(request);
        if (!response) {
            std::cerr << "Prediction failed: " << response.status() << std::endl;
            continue;
        }

        std::cout << "Output " << i + 1 << ": ";
        resultBuffer << "Output " << i + 1 << ": ";

        if (response->predictions_size() > 0 && response->predictions(0).has_list_value()) {
            std::vector<double> output;
            for (const auto& v : response->predictions(0).list_value().values()) {
                output.push_back(v.number_value());
            }
            printVector(std::cout, "", output);
            printVector(resultBuffer, "", output);
        }
        std::cout << std::endl;
        resultBuffer << std::endl;
    }

    // --- Upload results to Google Cloud Storage ---
    std::cout << "Uploading results to gs://" << bucketName << "/artemis_results.txt ..." << std::endl;
    
    namespace gcs = ::google::cloud::storage;
    auto storage_client = gcs::Client();
    auto writer = storage_client.WriteObject(bucketName, "artemis_results.txt");
    writer << resultBuffer.str();
    writer.Close();

    if (!writer.metadata()) {
        std::cerr << "Upload failed: " << writer.metadata().status().message() << std::endl;
        return 1;
    }
    std::cout << "Upload successful!" << std::endl;

    return 0;
}
