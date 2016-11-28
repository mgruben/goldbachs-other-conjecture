#include <iostream>
#include <vector>

using namespace std;

// https://en.wikipedia.org/wiki/Primality_test#Pseudocode
bool isPrime(int n) { 
    if (n <= 1) return false;
    if (n <= 3) return true;
    if ((n % 2 == 0) || (n % 3 == 0)) return false;
    int i = 5;
    while (i * i <= n) {
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
        i += 6;
    }
    return true;
}

int binaryTwiceSquare(int num, vector<int> range) {
    int i = 0;
    int j = range.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        long long calc = range.at(mid) * 2 * range.at(mid);
        if (calc == num) return mid + 1;
        else if (calc > num) j = mid - 1;
        else i = mid + 1;
    }
    return -1;
}

bool sumOfPrimeAnd(int num, vector<int> primes, vector<int> range) {
    for (int p: primes) {
        int s = binaryTwiceSquare(num - p, range);
        if (s > 0) { 
            cout << num << " - " << p << " + 2*" << s << "^2" << endl;
            return true;
            }
        }
    return false;
}


int main() {
    vector<int> range;
    for (int i; i < 100; i++) range.push_back(i+1);
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(19);
    primes.push_back(31);
    for (int i: {9, 15, 21, 25, 27, 33}) {
        cout << sumOfPrimeAnd(i, primes, range) << endl;
    }
    
    
    //~ for (int i = 3; i < 34; i += 2) {
        //~ cout << "checking " + i << endl;
        //~ if (isPrime(i)) primes.push_back(i);
        //~ else for (int p: primes) {
            //~ cout << binaryTwiceSquare(i - p, range) << endl;
        //~ }
    //~ }
    
    return 0;
}
