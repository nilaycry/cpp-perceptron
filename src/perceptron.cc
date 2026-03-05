#include "perceptron.hpp"

#include <cstdlib>
#include <stdexcept>
#include <random>
#include <iostream>


Perceptron::Perceptron(int input_size) {   

    if (input_size < 0) {
        throw std::runtime_error("Invalid input_size");
    }

    // Initialize bias and weights
    this->bias = 0.0;
    this->weights.resize(input_size); // allocate space for weights

    // Randomly initialize weights between -1 and 1
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    
    for (int i = 0; i < input_size; ++i) {
        weights[i] = dis(gen); 
    }
}

// Activation function that maps the linear output to a binary output
int Perceptron::activate(double z) {

    if (z >= 0) {
        return 1;
    }
    return 0;
}

int Perceptron::predict(const std::vector<double>& inputs) {

    if (inputs.size() != weights.size()) {
      throw std::runtime_error("Input size does not match number of weights");
    }

    // Calculate the linear output (weighted sum + bias)
    double total = bias;
    for (size_t i = 0; i < inputs.size(); i++) {
        total += weights[i] * inputs[i];
    }

    return activate(total);
}


void Perceptron::train(const std::vector<double>& inputs, int label, double learningRate) {

    if (inputs.size() != weights.size()) {
      throw std::runtime_error("Input size does not match number of weights");
    }

    // Calculate the prediction and error
    int prediction = predict(inputs);
    int error = label - prediction;

    // Update weights and bias based on the error
    for (size_t i = 0; i < inputs.size(); i++) {
        weights[i] += (learningRate * error * inputs[i]);        
    }

    // Update bias
    bias += learningRate * error;
}

int Perceptron::fit(const std::vector<std::vector<double>> &inputs, const std::vector<int> &labels, double learning_rate, int epochs) {

    if (inputs.size() != labels.size()) {
      throw std::runtime_error("Inputs and labels size mismatch");
    }

    std::cout << "FIT CALLED" << std::endl;
    // Training loop

    for (int epoch = 0; epoch < epochs; epoch++) {
        // First loop — train on all examples;
        for (size_t i = 0; i < inputs.size(); i++) {
            this->train(inputs[i], labels[i], learning_rate);
        }

        //second loop — error counting
        int error_count = 0;
        for (size_t i = 0; i < inputs.size(); i++) {
          if (this->predict(inputs[i]) != labels[i]) {
            error_count++;
           }
        }

        std::cout << "Epoch " << epoch + 1 << "/"          << epochs 
            << " | Errors: " << error_count << std::endl;
        // Check for convergence
        if (error_count == 0) {
          std::cout << "Training complete after " << epoch + 1 << " epochs." << std::endl;
          return epoch + 1; // Return the number of epochs taken to converge
        }        
        
    }  

    std::cout << "Training did not converge after " << epochs << " epochs." << std::endl;
    return epochs; // Return the total number of epochs if convergence was not achieved    
}