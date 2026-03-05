#include <iostream>
#include "perceptron.hpp"
#include "dataloader.hpp"


int main(void) {

    // Hyperparameters for training the perceptron
    double learning_rate = 0.1;
    int epochs = 100;
    // Create a Perceptron instance with 4 input features (since the Iris dataset has 4 features)
    Perceptron p(4);

    std::vector<std::vector<double>> inputs;
    std::vector<int> labels;

    // Load the Iris dataset from the CSV file
    loadIrisCSV("data/iris.csv", inputs, labels);




    p.fit(inputs, labels, learning_rate, epochs);

    std::cout << "\nPredictions after training:\n";

    // Test the perceptron on the training data
    int correct = 0;
    for (size_t i = 0; i < inputs.size(); i++) {
        if (p.predict(inputs[i]) == labels[i]) {
            correct++;
        }   
    }

    std::cout << "\nAccuracy: " << correct << "/" << inputs.size() 
          << " (" << (100.0 * correct / inputs.size()) << "%)" << std::endl;   
    return 0;
}