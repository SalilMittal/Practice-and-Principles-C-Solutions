/*  Read a sequence of double values into a vector. Think of each value
as the distance between two cities along a given route. Compute and
print the total distance (the sum of all distances). Find and print the
smallest and greatest distance between two neighboring cities. Find
and print the mean distance between two neighboring cities. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector <double> v;
    
    double sum = 0;
    
    cout << "Enter distances: ";
    for(double tmp; cin >> tmp;) {
        sum += tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    cout << "Max distance: " << v[v.size() - 1] << "\n";
    cout << "Min distance: " << v[0] << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Mean: " << double(sum / v.size()) << "\n";
}