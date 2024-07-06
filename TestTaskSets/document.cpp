#include "document.h"
#include <fstream>
#include <sstream>

Document::Document(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Item item;
        iss >> item.position >> item.quantity;
        std::string catalog;
        while (iss >> catalog) {
            item.catalogs.push_back(catalog);
        }
        items.push_back(item);
    }
}

bool Document::isContainsKit(const std::vector<std::pair<std::string, int>>& kit) const {
    std::unordered_map<std::string, int> kitMap;
    for (const auto& k : kit) {
        kitMap[k.first] += k.second;
    }

    std::unordered_map<std::string, int> remainingQuantities = kitMap;

    for (const auto& item : items) {
        for (const auto& catalog : item.catalogs) {
            if (remainingQuantities.find(catalog) != remainingQuantities.end()) {
                remainingQuantities[catalog] -= item.quantity;
                if (remainingQuantities[catalog] <= 0) {
                    remainingQuantities.erase(catalog);
                }
            }
            if (remainingQuantities.empty()) {
                return true;
            }
        }
    }
    return false;
}

std::vector<Item> Document::getMatchingItems(const std::vector<std::pair<std::string, int>>& kit) const {
    std::unordered_map<std::string, int> kitMap;
    for (const auto& k : kit) {
        kitMap[k.first] += k.second;
    }

    std::vector<Item> matchingItems;
    std::unordered_map<std::string, int> remainingQuantities = kitMap;
    std::unordered_map<int, std::unordered_map<std::string, int>> positionUsage;

    for (const auto& item : items) {
        std::unordered_map<std::string, int> itemUsage;
        for (const auto& catalog : item.catalogs) {
            if (remainingQuantities.find(catalog) != remainingQuantities.end() && remainingQuantities[catalog] > 0) {
                int availableQuantity = item.quantity - positionUsage[item.position][catalog];
                int matchedQuantity = std::min(remainingQuantities[catalog], availableQuantity);
                if (matchedQuantity > 0) {
                    matchingItems.push_back({ item.position, matchedQuantity, {catalog} });
                    remainingQuantities[catalog] -= matchedQuantity;
                    positionUsage[item.position][catalog] += matchedQuantity;

                    if (remainingQuantities[catalog] == 0) {
                        remainingQuantities.erase(catalog);
                    }
                    break;
                }
            }
        }
    }

    return matchingItems;
}