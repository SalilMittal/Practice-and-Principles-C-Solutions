/* Use the example above as a model for a program that converts
yen, euros, and pounds into dollars. If you like realism, you can
find conversion rates on the web. */
#include <iostream>
#include <string>
using namespace std;

int main() {
    char currency;
    double amt;
    cout << "Enter amount followed by currency(y, e, p): ";
    cin >> amt >> currency;
    if(currency == 'y') {
        cout << "$" << amt * 0.0092;
    }   else if(currency == 'e') {
        cout << "$" << amt * 1.19;
    }   else if(currency == 'p') {
        cout << "$" << amt * 1.39;
    }   else {
        cout << "Please Enter Valid Currency";
    }
}