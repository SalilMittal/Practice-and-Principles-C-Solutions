#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>      // std::istringstream
#include <string>

template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
	// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}


int main() {
    const std::string file = "ex_10_data.txt";

    std::ifstream ifs {file};
    std::string output;

    for(char ch; ifs.get(ch);) output += ch;
    ifs.close();

    std::ofstream ofs {file};

    for(int i = output.size() - 1; i >= 0; i--) {
        ofs << output[i];
    }
}