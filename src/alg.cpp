// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::fstream file(filename);
    if (!file) {
        std::cout << "Ошибка файла" << std::endl;
        return tree;
    }
    std::string str;
    while (!file.eof()) {
        char ch = file.get();
        if (ch >= 'A' && ch <= 'Z') {
            str += std::tolower(ch);
        }
        else 
            if (ch >= 'a' && ch <= 'z') {
            str += ch;
        }
        else {
            if (str != "") {
                tree.add(str);
            }
            str.clear();
        }
    }
    if (str != "") {
        tree.add(str);
    }
    file.close();
    return tree;
}
