/* You are given an array and a value n. You need to find the
pair of elements of the array whose sum is closest to n.
Example: Input: array = {31,40,34,11,5,25}, n = 46
Output: 5 and 40
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

int main() {
    /* Get Inputs */
    std::vector<int> v;
    v = {31,40,34,11,5,25, 39, 2};

    // std::cout << "Enter Array of Elements: ";    
    // for(int x; std::cin >> x;) v.push_back(abs(x));

    int sum;    
    std::cout << "Enter sum: ";
    std::cin >> sum;
    sum = abs(sum);
    
    /* Two Pointer Approach */
    int x1 = v[0];
    int x2 = v[1];
    int least = std::numeric_limits<int>::max();

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(i == j) continue;
            int tmp_sum = v[i] + v[j];
            int tmp_dif = abs(sum - tmp_sum); 
            if(tmp_dif < least) {
                least = tmp_dif;
                x1 = v[i];
                x2 = v[j]; 
            }
        }
    }
    
    std::cout << "Closest Nums are: " << x1 << ", " << x2 << "\n";
    std::cout << "Least Dif: " << least;
}