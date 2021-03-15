/* Write a program that performs as a very simple calculator. Your
calculator should be able to handle the four basic math operations —
add, subtract, multiply, and divide — on two input values. Your
program should prompt the user to enter three arguments: two double
values and a character to represent an operation. If the entry arguments
are 35.6, 24.1, and '+', the program output should be The sum of
35.6 and 24.1 is 59.7. In Chapter 6 we look at a much more
sophisticated simple calculator.
 */

#include <iostream>
using namespace std;

int main() {
    double x, y;
    char op;
    cout << "Enter First Value: ";
    cin >> x;
    cout << "Enter Operation: ";
    cin >> op;
    cout << "Enter Second Value: ";
    cin >> y;

    if(op == '+') {
        cout << "The sum of " << x << " and " << y << " is " << double(x+y); 
    } else if(op == '-') {
        cout << "The difference of " << x << " and " << y << " is " << double(x-y);
    } else if(op == '*') {
        cout << "The product of " << x << " and " << y << " is " << double(x*y);
    } else if(op == '/') {
        cout << "The quotient on dividing " << x << " by " << y << " is " << double(x/y);
    } else {
        cout << "Invalid Operation";
    }
}