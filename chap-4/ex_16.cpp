/**
In the drill, you wrote a program that, given a series of numbers,
found the max and min of that series. The number that appears the
most times in a sequence is called the mode. Create a program that
finds the mode of a set of positive integers
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

int main() {
    // Step 1-5
    std::vector<int> v;

    std::cout << "Enter Numbers: ";
    for(int x; std::cin >> x;) v.push_back(abs(x));

    int mode = v[0];
    int occurences = -1;

    // 1 1 2 2 1 3 4 2 
    for(int x : v) {
        int new_occurrences = 0;
        for(int y : v) if(y == x) new_occurrences++;

        if(new_occurrences >= occurences) {
            mode = x;
            occurences = new_occurrences;
        }
    }

    std::cout << "The mode is: " << mode;
}