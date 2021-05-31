#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>      // std::istringstream
#include <algorithm>

void disemvowel(std::string& s) {
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    std::string corrected;
    for(char& c : s) if(std::find(vowels.begin(), vowels.end(), (char) tolower(c)) == vowels.end()) corrected+=c;
    s = corrected;
}

int main() {
    std::ifstream ist {"ex_03_data.txt"};
    std::string results;
    ist.exceptions(ist.exceptions() | std::ios_base::badbit);

    for(std::string line; std::getline(ist, line);) {
        if(ist.fail()) throw std::runtime_error("Bad source");
        disemvowel(line);
        results += line;
    }

    ist.close();
    std::ofstream ost {"ex_03_data.txt", std::ios_base::binary};
    ost << results;
}