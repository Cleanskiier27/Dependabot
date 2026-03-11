cmake_minimum_required(VERSION 3.10)
project(DependabotNeuralNetwork CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies: Google Cloud Vertex AI (AI Platform)
find_package(google_cloud_cpp_aiplatform REQUIRED)
find_package(google_cloud_cpp_storage REQUIRED)

# Engine Library
add_library(neural_network
    engine/neural/NeuralNetwork.cpp
    engine/neural/NeuralNetwork.h
)
target_link_libraries(neural_network PRIVATE google-cloud-cpp::aiplatform)

# Examples
add_executable(neural_demo examples/neural_demo/main.cpp)
target_link_libraries(neural_demo PRIVATE neural_network)

add_executable(artemis_demo examples/artemis_demo/main.cpp)
target_link_libraries(artemis_demo PRIVATE neural_network google-cloud-cpp::aiplatform)

add_executable(storage_demo examples/storage_demo/main.cpp)
target_link_libraries(storage_demo PRIVATE google-cloud-cpp::storage)