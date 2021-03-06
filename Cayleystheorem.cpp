#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class CayleysTheorem {
private:
    char _operator;
    int _modulo;
    int _generator;
    std::vector<int> _list;

public:
    CayleysTheorem(std::vector<int>& list, char oper);
    void PrintList();
    void IsomorphicPermutation();
};

CayleysTheorem::CayleysTheorem(std::vector<int>& list, char oper) {
    _operator = oper;
    _list = list;
    _generator = 2;
    _modulo = _list.size();
}

void CayleysTheorem::PrintList() {
    std::cout << "({";
    for (auto i : _list) {
        std::cout << i << " ";
    }
    std::cout << "}, " << _operator << " )" << std::endl;
}

void CayleysTheorem::IsomorphicPermutation() {
    if (_operator == '+') {
        for (size_t i = 0; i < _list.size(); ++i) {
            _list[i] = (_list[i] + _generator) % _modulo;
        }
    } else if (_operator == '*') {
        for (size_t i = 0; i < _list.size(); ++i) {
            _list[i] = (_list[i] * _generator) % _modulo;
        }
    }
}

std::vector<int> ExtractInteger(std::string str) {
    std::vector<int> list;
    std::stringstream ss(str);
    while (ss.good()) {
        std::string substr;
        getline(ss, substr, ',');
        list.push_back(std::stol(substr));
    }
    return list;
}

void Input (std::vector<int> &list, char &oper){
    std::string line;
    std::getline(std::cin, line);
    oper = line[line.size() - 2];
    list = ExtractInteger(line.substr(2, line.size() - 6));

}

int main() {
    char oper;
    std::vector<int> list;
    Input(list, oper);
    CayleysTheorem group(list, oper);
    group.PrintList();
    group.IsomorphicPermutation();
    group.PrintList();
    return 0;
}
