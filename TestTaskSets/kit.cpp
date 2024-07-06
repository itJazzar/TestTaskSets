#include "kit.h"
#include <fstream>
#include <sstream>

Kit::Kit(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string catalog;
        int quantity;
        iss >> catalog >> quantity;
        items.emplace_back(catalog, quantity);
    }
}

const std::vector<std::pair<std::string, int>>& Kit::getItems() const {
    return items;
}