#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<int> nums;
    std::ifstream ist {"ex_16_numbers.txt"};

    for(int x; ist >> x;) nums.push_back(x);

    std::ofstream ost {"ex_16_count.txt"};
    ost.setf(std::ios_base::left, std::ios_base::adjustfield);	

    std::vector<int> printed;
    for(int x : nums) {
        int count = 0;
        for(int y : nums) if(x == y) count++;
        
        if(std::find(printed.begin(), printed.end(), x) == printed.end()) {
            ost << std::setw(6) << x;
            if(count > 1) ost << "\t" << count;
            ost << "\n";
            printed.push_back(x);
        } 
    }
}