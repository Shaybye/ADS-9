// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
using namespace std;

BST<std::string> makeTree(const char* filename) {
BST<string> Tree;
ifstream file(filename);
string str = "";
if (!file) {
    cout << "opening error" << endl;
    return Tree;
}
while (!file.eof()) {
    char sym = file.get();
    str += sym;
}
for (char& c : str) {
    c = tolower(c);
}
int len = str.length();
bool inWord = false;
string tempStr = "";
for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
        inWord = true;
    } else {
        inWord = false;
    }
    if (inWord) {
        tempStr += str[i];
    } else {
        Tree.add(tempStr);
        tempStr = "";
    }
}
file.close();
return Tree;
}
