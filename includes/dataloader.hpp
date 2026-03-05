#pragma once
#include <string>
#include <vector>

void loadIrisCSV(const std::string& file_name, std::vector<std::vector<double>>& inputs, std::vector<int>& labels);