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
    const std::string file = "ex_09_io.txt";

    std::ifstream ifs {file};
    std::string output;

    for(char ch; ifs.get(ch);) output += ch;
    ifs.close();

    std::ofstream ofs {file, std::ios_base::binary};
    for(char ch : output) ofs.write(as_bytes(ch), sizeof(char));
    ofs.close();

    std::ifstream ifs_2 {file, std::ios_base::binary};
    std::vector<char> chars;
    for(char ch; ifs_2.read(as_bytes(ch), sizeof(char));) chars.push_back(ch);
    ifs_2.close();

    std::ofstream ofs_2 {file};
    for(char ch : chars) ofs_2 << ch;
}