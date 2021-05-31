#include <iostream>
#include <fstream>
#include <vector>
#include <string>

template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
	// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}

int main() {
    std::ifstream ifs {"read_binary.txt", std::ios_base::binary};
    std::ofstream ofs {"write_binary.txt", std::ios_base::binary};

    std::vector<int> v;

    /**
     * x is passed into the function uninitialized, but x's undefined value is not going to be used.

     * The read function is going to use the space allocated to x as a container.
     * It will read one int's worth of data from ifs and store it in x,
     * giving x a known value that can then be safely used. 
     * Because the body of the loop will not enter unless an int was read from the file
     * 
     * Hence first byte of x is only for the address of x
     */
    for(int x; ifs.read(as_bytes(x), sizeof(int));) {
        std::cout << as_bytes(x);
        v.push_back(x);
    }

    for(int& i : v) ++i;

    /**
     * Writes as same format not character sequence
     */
    for(int i : v) ofs.write(as_bytes(i), sizeof(int));
}