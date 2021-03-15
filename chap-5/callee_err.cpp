#include <iostream>

int area(int x1, int x2) {
    if(x1 <= 0 || x2 <= 0) throw std::runtime_error("Non Positive arguments");
    return x1*x2;
}

int main() {
    int x1, x2;
    std::cin >> x1 >> x2;

    std::cout << area(x1, x2);
}