#include <iostream>
#include <vector>

using namespace std;

int binaryTwiceSquare(int num, vector<int> range) {
    int i = 0;
    int j = range.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        long long calc = range.at(mid) * 2 * range.at(mid);
        if (calc == num) return num;
        else if (calc > num) j = mid - 1;
        else i = mid + 1;
    }
    return -1;
}

int main() {
    vector<int> range;
    for (int i; i < 100; i++) range.push_back(i+1);
    cout << binaryTwiceSquare(50, range);
    return 0;
}
