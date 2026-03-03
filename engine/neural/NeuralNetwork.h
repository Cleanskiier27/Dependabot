#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
#include <cstdint>

// NeuralNetwork implements a fully-connected feedforward neural network
// with seeded random initialization for reproducible results.
class NeuralNetwork {
public:
    // Construct a network with the given layer sizes and random seed.
    // layerSizes[0] is the input size; layerSizes.back() is the output size.
    // Throws std::invalid_argument if fewer than 2 layers are specified.
    NeuralNetwork(const std::vector<int>& layerSizes, unsigned int seed);

    // Run forward propagation and return the output activations.
    // Throws std::invalid_argument if input size does not match the network input layer.
    std::vector<double> forward(const std::vector<double>& input) const;

    // Return the seed used to initialize this network.
    unsigned int getSeed() const;

    // Reinitialize weights and biases using a new seed.
    void setSeed(unsigned int seed);

private:
    // Initialize weights and biases using He initialization seeded by seed_.
    void initialize();

    // Apply the ReLU activation function element-wise.
    static std::vector<double> relu(const std::vector<double>& v);

    unsigned int seed_;
    std::vector<int> layerSizes_;

    // weights_[l] is the weight matrix for layer l, stored row-major.
    // weights_[l][i * layerSizes_[l] + j] connects input j to output i.
    std::vector<std::vector<double>> weights_;

    // biases_[l][i] is the bias for neuron i in layer l+1.
    std::vector<std::vector<double>> biases_;
};

#endif // NEURAL_NETWORK_H
