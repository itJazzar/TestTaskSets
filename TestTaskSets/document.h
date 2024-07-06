#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct Item {
    int position;
    int quantity;
    std::vector<std::string> catalogs;
};

class Document {
public:
    Document(const std::string& filename);
    bool isContainsKit(const std::vector<std::pair<std::string, int>>& kit) const;
    std::vector<Item> getMatchingItems(const std::vector<std::pair<std::string, int>>& kit) const;

private:
    std::vector<Item> items;
};