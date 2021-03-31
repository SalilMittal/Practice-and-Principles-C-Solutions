#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names;
    vector<double> ages;
    string name;
    double age;

    cout << "Enter Pairs: ";
    for(; cin >> name >> age;) {
        names.push_back(name);
        ages.push_back(age);
    }
    
    vector<string> names2 = names;

    // d a b c
    // a b c d
    sort(names.begin(), names.end());
    for(int i = 0; i < names.size(); i++) {
        string name_tmp = names[i];
        int age_tmp = 0;
        for(int j = 0; j < names2.size(); j++) {
            if(name_tmp == names2[j]) {
                age_tmp = ages[j];
                break;
            }
        }
        cout << name_tmp << ": " << age_tmp << "\t";
    }
}