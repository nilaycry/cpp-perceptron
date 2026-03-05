#pragma once 
#include <vector>


class Perceptron {
    private:
        // weights and bias are private members of the Perceptron class
        
        std::vector<double> weights;
        double bias;
    
    public:
        // constructor initializes weights and bias
        Perceptron(int input_size);
        // activation function that maps the linear output to a binary output
        int activate(double z);
        // predict function that takes in input features and returns the predicted class label
        int predict(const std::vector<double>& inputs);
        // train function that updates the weights and bias based on the training data
        void train(const std::vector<double>& inputs, int label, double learning_rate);
        // fit function that trains the perceptron for a specified number of epochs
        int fit(const std::vector<std::vector<double>>& inputs, const std::vector<int>& labels,double learning_rate, int epochs);        
};
