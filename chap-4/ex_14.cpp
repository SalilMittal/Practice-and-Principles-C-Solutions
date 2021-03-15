/* . Modify the program described in the previous exercise to take an
input value max and then find all prime numbers from 1 to max */


#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> primes(int max) {
    vector<int> v;
    for(int i = 2; i <= max; i++) v.push_back(i);
    
    int size = v.size();
    int p = 2;
    for(int i = 0; i < size; i++) {
        // p 2p 3p 4p .. max
        for(int j = 2; j*p <= max; j++) {
            // Erase multiples
            v.erase(std::remove(v.begin(), v.end(), j*p), v.end());
        }

        if(v.size() > 1) {
            p = v[1];
        } else {
            break;
        }
    }

    return v;
}

int main() {
    int max;
    cin >> max;
    vector<int> result = primes(max);
    for(int x : result) cout << x << " ";
}