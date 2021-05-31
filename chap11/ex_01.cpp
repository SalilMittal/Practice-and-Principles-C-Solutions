#include <iostream>
#include <fstream>

int main() {
    std::ifstream ist {"ex_01_input.txt"};
    // ist.exceptions(ist.exceptions() | std::ios_base::badbit);
    std::ofstream ost {"ex_01_out.txt"};

    for(char c; ist.get(c);) {
        ost << char(tolower(c));
    }
}