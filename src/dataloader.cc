#include "dataloader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>


void loadIrisCSV(const std::string& file_name, std::vector<std::vector<double>>& inputs, std::vector<int>& labels) {
    std::ifstream ifs{file_name};

    if (!ifs.is_open()) {
        throw std::runtime_error("Could not open file: " + file_name);
    }

    std::string line;  

    // Reading the CSV file line by line
    while(std::getline(ifs, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        // Use stringstream to parse the line
        std::stringstream ss(line);
        // Tokenize the line using comma as a delimiter
        std::string token;
        // Vector to hold the feature values for the current row
        std::vector<double> row;
        int token_index = 0;
        // Process each token in the line
        while (std::getline(ss, token, ',')) {
            // The last token is the class label, which is a string. We need to convert it to an integer label.
            if (token_index == 4) {
                // Map the class label to an integer (e.g., "Iris-setosa" -> 1, "Iris-versicolor" -> 0)
                // ignoring "Iris-virginica" for binary classification
                if (token == "Iris-setosa") {
                    labels.push_back(1);
                    inputs.push_back(row);
                } else if (token == "Iris-versicolor") {
                    labels.push_back(0);
                    inputs.push_back(row);
                }
                continue;
            }
            // Convert the token to a double and add it to the current row
            double value = std::stod(token);
            row.push_back(value);
            token_index++;
        }
    }    
}