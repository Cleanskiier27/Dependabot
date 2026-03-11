#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "google/cloud/aiplatform/v1/prediction_service_client.h"
#include "google/cloud/common_options.h"
#include "google/protobuf/struct.pb.h"

// Print a labeled vector of doubles to stdout.
static void printVector(const std::string& label, const std::vector<double>& v)
{
    std::cout << label << "[ ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << std::fixed << std::setprecision(6) << v[i];
        if (i + 1 < v.size()) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0]
                  << " <project-id> <location-id> <endpoint-id>" << std::endl;
        return 1;
    }

    std::string projectId = argv[1];
    std::string locationId = argv[2];
    std::string endpointId = argv[3];

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

    // --- Sample inputs representing four sensor readings ---
    std::vector<std::vector<double>> inputs = {
        { 1.0,  0.0,  0.0,  0.0},
        { 0.0,  1.0, -1.0,  0.5},
        {-0.5,  0.3,  0.7, -0.2},
        { 0.8, -0.6,  0.4,  0.9},
    };

    std::cout << "--- Forward pass results ---" << std::endl;
    for (size_t i = 0; i < inputs.size(); ++i) {
        std::cout << "Input  " << i + 1 << ": ";
        printVector("", inputs[i]);

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
        if (response->predictions_size() > 0 && response->predictions(0).has_list_value()) {
            std::vector<double> output;
            for (const auto& v : response->predictions(0).list_value().values()) {
                output.push_back(v.number_value());
            }
            printVector("", output);
        }
        std::cout << std::endl;
    }

    return 0;
}
