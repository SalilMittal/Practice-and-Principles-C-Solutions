/* Rewrite your currency converter program from the previous Try
this to use a switch-statement. Add conversions from yuan and
kroner. Which version of the program is easier to write,
understand, and modify? Why?
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    char currency;
    double amt;
    cout << "Enter amount followed by currency(y, e, p, u{yuan}): ";
    cin >> amt >> currency;
    
    switch(currency) {
        case 'y':
            cout << "$" << amt * 0.0092;
            break;
        case 'e':
            cout << "$" << amt * 1.19;
            break;
        case 'p':
            cout << "$" << amt * 1.19;
            break;
        case 'u':
            cout << amt * 1.3 << " kroner";
            break;
        default:
            cout << "Enter valid currency";
            break;
    }
}