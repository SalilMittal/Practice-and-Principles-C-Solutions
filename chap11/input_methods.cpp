#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>      // std::istringstream

double str_to_double(std::string s) {
    std::istringstream is {s};
    double d;
    is >> d;
    if(!is) throw std::runtime_error("Double format error");
    return d;
}

void tolower(std::string& str) {
    for(char& c : str) c = std::tolower(c);
}

int main() {
    
    //// Position in files
    std::fstream fs {"dump_data.txt"};

    // /* Get position to 6th character */
    fs.seekg(5);
    char ch;
    fs >> ch;
    std::cout << "5th character: " << ch << "\n";

    // /* Put position to 10st character */
    // fs.seekp(9);
    // fs << 'y';

    //// istringstream
    // double d1 = str_to_double("924.784");

    //// getline() - Full line input / whitespace definition is inconsistent / extract objects from one line
    // std::string cmd;
    // std::getline(std::cin, cmd);

    // std::stringstream ss {cmd};
    // std::vector<std::string> words;
    
    // for(std::string s; ss >> s;) {
    //     words.push_back(s);
    //     std::cout << s << "\n";
    // }

    std::string str = "Hello";
    tolower(str);
    std::cout << str;
    /**
     * isspace()
     * isalpha()
     * isdigit()
     * isxdigit()
     * isupper()
     * islower()
     * isalnum()
     * iscntrl()
     * ispunct()
     * isprint()
     * isgraph()
     * 
     * toupper()
     * tolower()
     */
}