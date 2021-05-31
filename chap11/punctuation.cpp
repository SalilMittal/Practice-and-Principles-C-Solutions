#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>      // std::istringstream
#include <string>
#include <algorithm>

class Punct_stream {
    public:
        Punct_stream(std::istream& is): source{is}, sensitive{true} {}
        void whitespace(const std::string& s) {white = s;}
        void add_white(char ch) {white += ch;}
        bool is_whitespace(char c);
        void case_sensitive(bool b) {sensitive = b;}
        bool is_case_sensitive() const {return sensitive;}

        Punct_stream& operator>>(std::string& s);
        operator bool();
    private:
        std::istream& source;   // character source
        std::istringstream buffer;  // buffer for formatting
        std::string white;  // characters considered whitespace
        bool sensitive;
};

bool Punct_stream::is_whitespace(char c) {
    for(char w : white) if(c == w) return true;
    return false;
}

Punct_stream::operator bool() {
    return !(source.fail() || source.bad()) && buffer.good();
}

Punct_stream& Punct_stream::operator>>(std::string& s) {
    // quit if we can read a word from buffer
    // if fail, replenish buffer from source
    // The quick brown, fox

    while(!(buffer >> s)) {
        if(buffer.bad() || !source.good()) return *this;
        buffer.clear();

        std::string line;
        std::getline(source, line);

        for(char& ch : line) 
            if(is_whitespace(ch))
                ch = ' ';
            else if(!sensitive)
                ch = tolower(ch);

        buffer.str(line);
        
        // std::cout << "\tloaded buffer: " << line << "\t";
    }

    // std::cout << "\tdid not enter loop: " << s << "\t";
    return *this;
}

int main() {
    Punct_stream ps {std::cin};
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~-");

    std::cout << "Enter words (Press CTRL+Z to terminate): ";
    std::vector<std::string> vs;

    for(std::string word; ps >> word;) {
        vs.push_back(word);
    }

    // std::sort(vs.begin(), vs.end());
    
    std::cout << "\n";
    for(std::string str : vs) std::cout << str << " ";
}