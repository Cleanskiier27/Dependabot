#include "google/cloud/storage/client.h"
#include <iostream>
#include <string>

namespace gcs = ::google::cloud::storage;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <bucket-name>" << std::endl;
        return 1;
    }

    std::string bucketName = argv[1];
    std::cout << "Accessing bucket: " << bucketName << std::endl;

    // Create a client to interact with Google Cloud Storage
    auto client = gcs::Client();

    // List objects in the bucket
    int count = 0;
    for (auto&& object_metadata : client.ListObjects(bucketName)) {
        if (!object_metadata) {
            std::cerr << "Error listing objects: " << object_metadata.status().message() << std::endl;
            return 1;
        }

        std::cout << object_metadata->name() << std::endl;
        count++;
    }

    std::cout << "\nFound " << count << " objects." << std::endl;

    return 0;
}