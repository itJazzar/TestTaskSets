#include "document.h"
#include "kit.h"
#include <iostream>
#include "windows.h"

int main() {
    SetConsoleOutputCP(1251);
    Document document("document.txt");
    Kit kit("kit.txt");

    if (document.isContainsKit(kit.getItems())) {
        std::cout << "Набор содержится в документе\n";
        std::cout << "Состав набора:\n";
        std::cout << "Поз\tКол-во\tКаталог\n";
        for (const auto& item : document.getMatchingItems(kit.getItems())) {
            std::cout << item.position << "\t" << item.quantity << "\t" << item.catalogs[0] << "\n";
        }
    } 
    else {
        std::cout << "Набор не входит в документ\n";
    }

    return 0;
}