/* . Make a vector holding the ten string values "zero", "one", . . .
"nine". Use that in a program that converts a digit to its
corresponding spelled-out value; e.g., the input 7 gives the output
seven. Have the same program, using the same input loop, convert
spelled-out numbers into their digit form; e.g., the input seven gives
the output 7.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> nums = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    int size = nums.size();

    // cout << "Enter number: ";
    // for(int n; cin >> n;) {
    //     if(n >= 0 && n <= 9) {
    //         cout << nums[n] << "\n"; 
    //     }
    //     cout << "Enter number: ";
    // }

    cout << "Enter number in spelled form: ";
    for(string n; cin >> n;) {
        for(int i = 0; i < size; i++) {
            if(nums[i] == n) {
                cout << i << "\n";
                break;
            }
        }        
        cout << "Enter number in spelled form: ";
    }
}