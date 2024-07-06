#pragma once
#include <string>
#include <vector>
#include <utility>

class Kit {
public:
    Kit(const std::string& filename);
    const std::vector<std::pair<std::string, int>>& getItems() const;

private:
    std::vector<std::pair<std::string, int>> items;
};