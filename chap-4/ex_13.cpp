/* Create a program to find all the prime numbers between 1 and 100.
There is a classic method for doing this, called the “Sieve of
Eratosthenes.” If you don’t know that method, get on the web and look
it up. Write your program using this method.
 */

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
    vector<int> result = primes(100);
    for(int x : result) cout << x << " ";
}