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

/**
 * Given some number (n-p), returns the integer which must be
 * squared to fit Goldbach's Other Conjecture.
 * If no such integer exists, return -1.
 * 
 * We know that n = p + 2*?^2.
 * We can rewrite this as (n-p) = 2*?^2
 * We can solve for ? = sqrt((n-p)/2)
 * 
 * If ? is an integer, then (n-p) fits Goldbach's Other Conjecture.
 * 
 * Otherwise, (n-p) does not fit Goldbach's Other Conjecture.
 */
int getBase(int num) {
    double tmp = num;
    tmp /= 2.0;
    tmp = sqrt(tmp);
    if (fmod(tmp,1.0) == 0) return (int) tmp;
    else return -1;
}


/**
 * Does the given number fit Goldbach's Other Conjecture?
 */
bool sumOfPrimeAnd(int num, vector<int> primes) {
    // Iterate over known primes
    for (int p: primes) {
        int s = getBase(num - p);
        if (s > 0) { 
            cout << num << " = " << p << " + 2*" << s << "^2" << endl;
            return true;
            }
        }
    return false;
}

/**
 * Finds the smallest number to fail Goldbach's Other Conjecture,
 * and narrates the search with printouts.
 */
void solve() {
    vector<int> primes;
    
    /** Since we're incrementing by 2 and beginning with an odd, we will
     * never need to check whether the current number is divisible by 2,
     * so we skip adding it to our vector of primes to save
     * computational effort.
     * 
     * For odd numbers, either they are prime, or they are a composite
     * odd number.
     * 
     * If they are prime, we would want to save them, so that we can
     * iterate through them later in sumOfPrimeAnd() above.
     * 
     * If they are composite prime, then we want to check whether they
     * meet or fail Goldbach's Other Conjecture.
     * 
     * The first one to fail Goldbach's Other Conjecture is printed,
     * then the search terminates.
     */
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
    cout << getBase(5620);
}

int main() {
    solve();
    return 0;
}
