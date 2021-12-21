#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class CayleysTheorem {
private:
    char _operator;
    int _modulo;
    std::vector<int> _list;
    std::vector<int> _generator_subset;

public:
    CayleysTheorem(std::vector<int>& list, char oper, std::vector<int> _generator_subset);
    void PrintList();
    void PrintSubSet();
    void PrintPermutation();
    std::vector<int> IsomorphicPermutation(int generator);
    void GetGraph();
};

CayleysTheorem::CayleysTheorem(std::vector<int>& list, char oper, std::vector<int> generator_subset) {
    _operator = oper;
    _list = list;
    _generator_subset = generator_subset;
    _modulo = _list.size();
}

void CayleysTheorem::PrintList() {
    std::cout << "({";
    for (auto i : _list) {
        std::cout << i << " ";
    }
    std::cout << "}, " << _operator << " )" << std::endl;
}
void CayleysTheorem::PrintSubSet() {
    std::cout << "(";
    for (auto i : _generator_subset) {
        std::cout << i << " ";
    }
    std::cout << ")" << std::endl;
}
void CayleysTheorem::PrintPermutation() {
    
}
std::vector<int> CayleysTheorem::IsomorphicPermutation(int generator) {
    std::vector<int> permutation(_modulo);
    if (_operator == '+') {
        for (size_t i = 0; i < _list.size(); ++i) {
            permutation[i] = (_list[i] + generator) % _modulo;
        }
    } else if (_operator == '*') {
        for (size_t i = 0; i < _list.size(); ++i) {
            permutation[i] = (_list[i] * generator) % _modulo;
        }
    }
    for (auto i : permutation) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return permutation;
}

void CayleysTheorem::GetGraph() {
    std::vector<std::vector<int>> adj(_modulo, std::vector<int>(_modulo, 0));
    for (size_t i = 0; i < _generator_subset.size(); ++i) {
        std::vector<int> permutation = IsomorphicPermutation(_generator_subset[i]);
        for (size_t j = 0; j < _modulo; ++j) {
            adj[j][permutation[j]] = 1;
        }
    } 
    std::cout<<"  ";
    for (size_t i = 0; i < _modulo; i++){
        std::cout<<"_"<<i;
    }
    std::cout<<std::endl;
    /*for (size_t i = 0; i < 2*_modulo; i++){
        std::cout<<"_";
    }
    std::cout<<std::endl;*/

    for (size_t i = 0; i < _modulo; i++)
    {   
        std::cout<<i<<"| ";
        for (size_t j = 0; j < _modulo; j++)
        {
           std::cout << adj[i][j] << " ";
        }
        std::cout << std::endl;
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

void Input (std::vector<int> &list, char &oper, std::vector<int> &sub_set) {
    std::string line;
    std::getline(std::cin, line);
    oper = line[line.size() - 2];
    list = ExtractInteger(line.substr(2, line.size() - 6));
    std::getline(std::cin, line);
    sub_set  = ExtractInteger(line.substr(3, line.size() - 4));
}

int main() {
    char oper;
    std::vector<int> list;
    std::vector<int> sub_set;
    Input(list, oper, sub_set);
 
    CayleysTheorem group(list, oper, sub_set);
    group.PrintList();
    group.PrintSubSet();
    group.GetGraph();
    group.PrintList();
    return 0;
}