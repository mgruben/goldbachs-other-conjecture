#include <iostream>
#include <vector>
#include <math.h>
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

int binaryTwiceSquare(int num) {
    double tmp = num;
    tmp /= 2.0;
    tmp = sqrt(tmp);
    if (fmod(tmp,1.0) == 0) return (int) tmp;
    else return -1;
}

bool sumOfPrimeAnd(int num, vector<int> primes) {
    for (int p: primes) {
        int s = binaryTwiceSquare(num - p);
        if (s > 0) { 
            cout << num << " = " << p << " + 2*" << s << "^2" << endl;
            return true;
            }
        }
    return false;
}

void solve() {
    vector<int> primes;
    
    for (int i = 3; i < 33334; i += 2) {
        cout << endl << "checking " << i << endl;
        if (isPrime(i)) {
            cout << i << " is prime!" << endl;
            primes.push_back(i);
        }
        else if (!sumOfPrimeAnd(i, primes)){
            cout << i << " FAILS Goldbach's Other Conjecture!" << endl;
            break;
        }
    }
}

void test() {
    cout << binaryTwiceSquare(5620);
}

int main() {
    solve();
    return 0;
}
