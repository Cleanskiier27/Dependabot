#include "NeuralNetwork.h"

#include <cmath>
#include <random>
#include <stdexcept>

NeuralNetwork::NeuralNetwork(const std::vector<int>& layerSizes, unsigned int seed)
    : seed_(seed), layerSizes_(layerSizes)
{
    if (layerSizes_.size() < 2) {
        throw std::invalid_argument("Network must have at least 2 layers (input and output).");
    }
    for (int sz : layerSizes_) {
        if (sz <= 0) {
            throw std::invalid_argument("Each layer must have at least one neuron.");
        }
    }
    initialize();
}

void NeuralNetwork::initialize()
{
    // Use std::mt19937 seeded with seed_ for deterministic, reproducible init.
    std::mt19937 rng(seed_);

    int numLayers = static_cast<int>(layerSizes_.size());
    weights_.resize(numLayers - 1);
    biases_.resize(numLayers - 1);

    for (int l = 0; l < numLayers - 1; ++l) {
        int fanIn  = layerSizes_[l];
        int fanOut = layerSizes_[l + 1];

        // He initialization: std. dev. = sqrt(2 / fanIn), suitable for ReLU activations.
        double stddev = std::sqrt(2.0 / static_cast<double>(fanIn));
        std::normal_distribution<double> dist(0.0, stddev);

        weights_[l].resize(static_cast<size_t>(fanOut) * static_cast<size_t>(fanIn));
        for (double& w : weights_[l]) {
            w = dist(rng);
        }

        biases_[l].assign(static_cast<size_t>(fanOut), 0.0);
    }
}

void NeuralNetwork::setSeed(unsigned int seed)
{
    seed_ = seed;
    initialize();
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

        std::vector<double> next(static_cast<size_t>(fanOut));
        for (int i = 0; i < fanOut; ++i) {
            double sum = biases_[l][static_cast<size_t>(i)];
            size_t rowOffset = static_cast<size_t>(i) * static_cast<size_t>(fanIn);
            for (int j = 0; j < fanIn; ++j) {
                sum += weights_[l][rowOffset + static_cast<size_t>(j)]
                       * activation[static_cast<size_t>(j)];
            }
            next[static_cast<size_t>(i)] = sum;
        }

        // Apply ReLU to all layers except the final output layer.
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
