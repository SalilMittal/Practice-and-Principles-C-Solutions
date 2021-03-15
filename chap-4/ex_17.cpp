/**Write a program that finds the min, max, and mode of a sequence of
strings.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

int main() {
    // Step 1-5
    std::vector<std::string> v;

    std::cout << "Enter Strings: ";
    for(std::string x; std::cin >> x;) v.push_back(x);

    // Current is -1 as vector contains only +ve ints
    std::string mode = v[0];
    std::string min = v[0];
    std::string max = v[0];
    int occurences = -1;

    // 1 1 2 2 1 3 4 2 
    for(std::string x : v) {
        int new_occurrences = 0;
        for(std::string y : v) if(y == x) new_occurrences++;

        if(new_occurrences >= occurences) {
            mode = x;
            occurences = new_occurrences;
        }
        if(x.length() <= min.length()) min = x;
        if(x.length() >= max.length()) max = x;
    }

    std::cout << "The mode is: " << mode << "\n";
    std::cout << "The min is: " << min << "\n";
    std::cout << "The max is: " << max << "\n";
}