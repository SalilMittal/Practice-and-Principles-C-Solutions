/* . Write a program that takes an input value n and then finds the first n
primes. */
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> primes(int n, int max = 2147483646) {
    vector<int> v;
    for(int i = 2; i <= max; i++) v.push_back(i);
    
    int size = v.size();
    int p = 2;
    
    for(int i = 0; i < size; i++) {
        // p 2p 3p 4p .. max
        for(int j = 2; j*p <= max; j++) {
            // Erase multiples
            v.erase(remove(v.begin(), v.end(), j*p), v.end());
        }

        if(v.size() > 1) {
            p = v[1];
        } else {
            break;
        }

        if(i == n) break;
    }

    vector<int> ret;
    for(int i = 0; i < n; i++) ret.push_back(v[i]);

    return ret;
}

int main() {
    int max;
    cin >> max;
    vector<int> result = primes(max);
    for(int x : result) cout << x << " ";
}