#include "NeuralNetwork.h"

#include <cmath>
#include <stdexcept>
#include <fstream>

NeuralNetwork::NeuralNetwork(const std::vector<int>& layerSizes, unsigned int seed)
    : seed_(seed), layerSizes_(layerSizes)
{
    if (layerSizes.size() < 2) {
        throw std::invalid_argument("Network must have at least 2 layers (input and output).");
    }
    initialize();
}

void NeuralNetwork::initialize()
{
    // Use a simple linear congruential generator seeded with seed_ so that
    // initialization is fully reproducible given the same seed.
    // LCG parameters from Numerical Recipes.
    uint64_t state = seed_;
    auto nextDouble = [&]() -> double {
        state = state * 6364136223846793005ULL + 1442695040888963407ULL;
        // Map to (0, 1)
        return static_cast<double>((state >> 11) & 0x1FFFFFFFFFFFFFULL) /
               static_cast<double>(0x1FFFFFFFFFFFFFULL);
    };

    int numLayers = static_cast<int>(layerSizes_.size());
    weights_.resize(numLayers - 1);
    biases_.resize(numLayers - 1);

    for (int l = 0; l < numLayers - 1; ++l) {
        int fanIn  = layerSizes_[l];
        int fanOut = layerSizes_[l + 1];

        // He initialization: scale = sqrt(6 / fanIn) for uniform distribution
        double scale = std::sqrt(6.0 / fanIn);

        weights_[l].resize(fanOut * fanIn);
        for (double& w : weights_[l]) {
            // Map uniform sample to [-1, 1] then scale
            w = (nextDouble() * 2.0 - 1.0) * scale;
        }

        biases_[l].resize(fanOut, 0.0);
    }
}

std::vector<double> NeuralNetwork::relu(const std::vector<double>& v)
{
    std::vector<double> out(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        out[i] = v[i] > 0.0 ? v[i] : 0.0;
    }
    return out;
}

std::vector<double> NeuralNetwork::forward(const std::vector<double>& input) const
{
    if (static_cast<int>(input.size()) != layerSizes_[0]) {
        throw std::invalid_argument("Input size does not match network input layer size.");
    }

    std::vector<double> activation = input;
    int numLayers = static_cast<int>(layerSizes_.size());

    for (int l = 0; l < numLayers - 1; ++l) {
        int fanIn  = layerSizes_[l];
        int fanOut = layerSizes_[l + 1];

        std::vector<double> next(fanOut);
        for (int i = 0; i < fanOut; ++i) {
            double sum = biases_[l][i];
            for (int j = 0; j < fanIn; ++j) {
                sum += weights_[l][i * fanIn + j] * activation[j];
            }
            next[i] = sum;
        }

        // Apply ReLU to all but the last layer
        if (l < numLayers - 2) {
            activation = relu(next);
        } else {
            activation = next;
        }
    }

    return activation;
}

unsigned int NeuralNetwork::getSeed() const
{
    return seed_;
}

void NeuralNetwork::saveWeights(const std::string& filename) const
{
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    // Write layer sizes to validate architecture on load
    int numLayers = static_cast<int>(layerSizes_.size());
    outFile.write(reinterpret_cast<const char*>(&numLayers), sizeof(numLayers));
    outFile.write(reinterpret_cast<const char*>(layerSizes_.data()), numLayers * sizeof(int));

    // Write weights and biases
    for (const auto& layer_weights : weights_) {
        size_t size = layer_weights.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        outFile.write(reinterpret_cast<const char*>(layer_weights.data()), size * sizeof(double));
    }

    for (const auto& layer_biases : biases_) {
        size_t size = layer_biases.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
        outFile.write(reinterpret_cast<const char*>(layer_biases.data()), size * sizeof(double));
    }
}

void NeuralNetwork::loadWeights(const std::string& filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        throw std::runtime_error("Cannot open file for reading: " + filename);
    }

    // Read and validate architecture
    int numLayers;
    inFile.read(reinterpret_cast<char*>(&numLayers), sizeof(numLayers));
    std::vector<int> fileLayerSizes(numLayers);
    inFile.read(reinterpret_cast<char*>(fileLayerSizes.data()), numLayers * sizeof(int));

    if (fileLayerSizes != layerSizes_) {
        throw std::runtime_error("Network architecture in file does not match this network.");
    }

    // Read weights and biases
    for (auto& layer_weights : weights_) {
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        if (size != layer_weights.size()) {
            throw std::runtime_error("Weight matrix size mismatch in file.");
        }
        inFile.read(reinterpret_cast<char*>(layer_weights.data()), size * sizeof(double));
    }

    for (auto& layer_biases : biases_) {
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        if (size != layer_biases.size()) {
            throw std::runtime_error("Bias vector size mismatch in file.");
        }
        inFile.read(reinterpret_cast<char*>(layer_biases.data()), size * sizeof(double));
    }
}

const std::vector<std::vector<double>>& NeuralNetwork::getWeights() const
{
    return weights_;
}

const std::vector<std::vector<double>>& NeuralNetwork::getBiases() const
{
    return biases_;
}
