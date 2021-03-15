/* . Write a program where you first enter a set of name-and-value pairs,
such as Joe 17 and Barbara 22. For each pair, add the name to a
vector called names and the number to a vector called scores (in
corresponding positions, so that if names[7]=="Joe" then
scores[7]==17). Terminate input with NoName 0. Check that each
name is unique and terminate with an error message if a name is
entered twice. Write out all the (name,score) pairs, one per line. */

#include <iostream>
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
}