#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>      // std::istringstream

int main() {
    std::ifstream ist {"ex_02_input.txt"};
    ist.exceptions(ist.exceptions() | std::ios_base::badbit);
    std::cout << "Enter search phrase: ";
    std::string search;
    std::cin >> search;

    int i = 0;
    int results = 0;
    for(std::string line; std::getline(ist, line);) {
        std::istringstream buf {line};
        if(buf.bad() || ist.fail()) throw std::runtime_error("Bad source");
        
        for(std::string word; buf >> word;) {
            if(word == search) {
                std::cout << "Found search item <" << search << "> on line " << i << "\n";
                results++;
            } 
        }

        i++;
    }

    std::cout << results << " results";
}