// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    try {
        if(1) throw std::runtime_error("My Error");
    } catch(std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << "\n";        
    }
}