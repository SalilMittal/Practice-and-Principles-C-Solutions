/* Modify the program from exercise 19 so that when you enter a name,
the program will output the corresponding score or name not found */


#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::string> names;
    std::vector<int> scores;

    std::string name;
    int score;
    std::cout << "Enter name followed by score: ";
    for(; std::cin >> name >> score;) {
        if(name == "NoName" && score == 0) {
            break;
        } else {
            for(std::string x : names) if(name == x) throw std::invalid_argument("Name Repeated");

            names.push_back(name);
            scores.push_back(score);
        }
    }
    for(int i = 0; i < names.size(); i++) std::cout << names[i] << "\t" << scores[i] <<"\n";
    std::cout << "\nSearch a Name: ";
    std::string search;
    std::cin >> search;

    if (std::find(names.begin(), names.end(), search)!=names.end()) {
        for(int i = 0; i < names.size(); i++) if(names[i] == search) std::cout << "Score: " << scores[i];
    } else {
        throw std::invalid_argument("Name not found");
    }
}