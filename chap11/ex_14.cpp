#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct CharClassCount {
    int space_count = 0;
    int alnum_count = 0;
    int xdig_count = 0;
    int alpha_count = 0;
    int upper_count = 0;
    int lower_count = 0;
    int dig_count = 0;
    int ctrl_count = 0;
    int punct_count = 0;
    int print_count = 0;
    int graph_count = 0;
};

void count_char_type(char c, CharClassCount& counter) {
    if(isspace(c)) counter.space_count++;
    if(isalnum(c)) counter.alnum_count++;
    if(isxdigit(c)) counter.xdig_count++;
    if(isalpha(c)) counter.alpha_count++;
    if(isupper(c)) counter.upper_count++;
    if(islower(c)) counter.lower_count++;
    if(isdigit(c)) counter.dig_count++;
    if(iscntrl(c)) counter.ctrl_count++;
    if(ispunct(c)) counter.punct_count++;
    if(isprint(c)) counter.print_count++;
    if(isgraph(c)) counter.graph_count++;
}

int main() {
    std::ifstream ist {"ex_14_chars.txt"};

    CharClassCount counter {};
    for(char ch; ist.get(ch);) {
        count_char_type(ch, counter);
    }

    std::cout << counter.space_count << " spaces\n"
              << counter.alnum_count << " alphanumeric\n"
              << counter.xdig_count << " xdigit\n"
              << counter.alpha_count << " alpha\n"
              << counter.upper_count << " uppercase\n"
              << counter.lower_count << " lowercase\n"
              << counter.dig_count << " digits\n"
              << counter.ctrl_count << " control chars\n"
              << counter.punct_count << " punctuation\n"
              << counter.print_count << " printable chars\n"
              << counter.graph_count << " graphical";
}