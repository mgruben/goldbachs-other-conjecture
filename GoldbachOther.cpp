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

bool binaryTwiceSquare(int num, vector<int> range) {
    int i = 0;
    int j = range.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        long long calc = range.at(mid) * 2 * range.at(mid);
        if (calc == num) return true;
        else if (calc > num) j = mid - 1;
        else i = mid + 1;
    }
    return false;
}

int main() {
    vector<int> range;
    for (int i; i < 100; i++) range.push_back(i+1);
    cout << binaryTwiceSquare(71, range) << endl;
    cout << isPrime(11) << endl;
    return 0;
}
