/* Rewrite the character value example from the previous Try this
to use a for-statement. Then modify your program to also write
out a table of the integer values for uppercase letters and digits.
 */

#include <iostream>
using namespace std;

int main() {
    // a-z
    for(int i = 0; i < 26; i++) {
        cout << char('a' + i) << "\t" << int('a' + i) << "\n";
    }
    cout << "\n";
    
    // A-Z
    for(int i = 0; i < 26; i++) {
        cout << char('A' + i) << "\t" << int('A' + i) << "\n";
    }
    
    cout << "\n";
    
    // 0-9
    for(int i = 0; i < 10; i++) {
        cout << char('0' + i) << "\t" << int('0' + i) << "\n";
    }
}