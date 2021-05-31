#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

enum class Base {dec, oct, hex};

void write_dec(Base b, int value) {
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);	

    switch (b)
    {
        case Base::hex:
            std::cout << "0x" << std::setw(8) <<  std::hex << (value)
                    << std::setw(12) << "hexadecimal";
            break;
        case Base::oct:
            std::cout << "0" << std::setw(8) <<  std::oct << (value)
                      << std::setw(12) << "octal";
            break;
        default:        
            std::cout << std::setw(8) << std::dec << (value)
                      << std::setw(12) << "decimal";
            break;
    }

    std::cout << " converts to "
              << std::setw(10) << std::dec << value
              << " decimal \n";
}

int main() {
    try {
        std::cout << "Enter some numbers (ctrl + z to exit): ";

        for(std::string line; std::cin >> line;) {
            // get line of numbers
            std::istringstream buffer {line};
            
            // get single string numbers
            for(std::string number; buffer >> number;) {
                int x;
                std::istringstream buff_2 {number};
                buff_2.unsetf(std::ios::dec);
                buff_2.unsetf(std::ios::hex);
                buff_2.unsetf(std::ios::oct);

                buff_2 >> x;
                // std::cout << number << " " << x << "\n";
                if(number[0] == '0') {
                    if(number.size() > 2 && (number[1] == 'x' || number[1] == 'X')) write_dec(Base::hex, x);
                    else if(number.size() > 1) write_dec(Base::oct, x);
                    else write_dec(Base::dec, 0);
                } else {
                    write_dec(Base::dec, x);
                }
            }
        }
    } catch(std::runtime_error& e) {
        std::cerr << e.what();
    }
}