#include <iostream>
#include <iomanip>
#include <vector>

#include <stdexcept>
#include "../../engine/neural/NeuralNetwork.h"

// Print a vector of doubles to stdout.
static void printOutput(const std::vector<double>& v)
{
    std::cout << "[ ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << std::fixed << std::setprecision(6) << v[i];
        if (i + 1 < v.size()) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;
}

int main()
{
    // Network architecture: 3 inputs -> 4 hidden neurons -> 2 outputs
    std::vector<int> layers = {3, 4, 2};

    // Sample input used for all demonstrations
    std::vector<double> input = {0.5, -0.3, 0.8};

    std::cout << "=== Neural Network Reproducibility Demo ===" << std::endl;
    std::cout << "Architecture: 3 -> 4 -> 2" << std::endl;
    std::cout << "Input: ";
    printOutput(input);
    std::cout << std::endl;

    // --- Demonstration 1: Same seed produces identical results ---
    std::cout << "--- Demonstration 1: Two networks with seed 42 ---" << std::endl;

    NeuralNetwork net1(layers, 42);
    NeuralNetwork net2(layers, 42);

    std::vector<double> out1 = net1.forward(input);
    std::vector<double> out2 = net2.forward(input);

    std::cout << "Network 1 (seed 42) output: ";
    printOutput(out1);
    std::cout << "Network 2 (seed 42) output: ";
    printOutput(out2);

    bool identical = (out1 == out2);
    std::cout << "Outputs identical: " << (identical ? "YES" : "NO") << std::endl;
    std::cout << std::endl;

    // --- Demonstration 2: Different seed produces different results ---
    std::cout << "--- Demonstration 2: Network with seed 123 ---" << std::endl;

    NeuralNetwork net3(layers, 123);
    std::vector<double> out3 = net3.forward(input);

    std::cout << "Network 3 (seed 123) output: ";
    printOutput(out3);

    bool different = (out1 != out3);
    std::cout << "Output differs from seed-42 network: " << (different ? "YES" : "NO") << std::endl;
    std::cout << std::endl;

    // --- Demonstration 3: Save and load weights ---
    std::cout << "--- Demonstration 3: Save and load weights ---" << std::endl;
    const std::string weights_file = "neural_net_weights.bin";
    std::cout << "Saving Network 1 (seed 42) weights to " << weights_file << std::endl;
    net1.saveWeights(weights_file);

    NeuralNetwork net4(layers, 999); // Different seed
    std::cout << "Loading weights into Network 4 (seed 999)..." << std::endl;
    net4.loadWeights(weights_file);

    std::vector<double> out4 = net4.forward(input);
    std::cout << "Network 4 output after loading: ";
    printOutput(out4);
    bool loaded_identical = (out1 == out4);
    std::cout << "Output identical to Network 1: " << (loaded_identical ? "YES" : "NO") << std::endl;
    std::cout << std::endl;

    // --- Demonstration 4: Loading weights with mismatched architecture ---
    std::cout << "--- Demonstration 4: Mismatched architecture error ---" << std::endl;
    try {
        std::vector<int> wrong_layers = {3, 5, 2};
        NeuralNetwork wrong_net(wrong_layers, 100);
        std::cout << "Attempting to load 3->4->2 weights into a 3->5->2 network..." << std::endl;
        wrong_net.loadWeights(weights_file);
    } catch (const std::runtime_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    // --- Demonstration 5: Inspecting weights programmatically ---
    std::cout << "--- Demonstration 5: Inspecting internal state ---" << std::endl;
    const auto& w = net1.getWeights();
    const auto& b = net1.getBiases();
    std::cout << "Network 1 has " << w.size() << " weight matrices." << std::endl;
    std::cout << "Layer 0 (Input->Hidden) weights count: " << w[0].size() << std::endl;
    std::cout << "Layer 0 first weight: " << w[0][0] << std::endl;
    std::cout << "Layer 0 biases count: " << b[0].size() << std::endl;
    std::cout << std::endl;

    // --- Summary ---
    std::cout << "=== Summary ===" << std::endl;
    std::cout << "Seed-based initialization ensures that networks with the same seed" << std::endl;
    std::cout << "produce identical weights. Saving and loading weights allows for" << std::endl;
    std::cout << "persisting a trained network and reproducing its state." << std::endl;

    return 0;
}
