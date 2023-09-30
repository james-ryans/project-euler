#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int main() {
    int sum = 1;
    for (int d = 1; d < (N+1)/2; d++) {
        int b = -2*d;
        int n = 4;
        int a_1 = (2*d + 1) * (2*d + 1);
        int a_n = a_1 + (n-1) * b;

        sum += n * (a_1 + a_n)/2;
    }

    cout << "The sum of spiral diagonals is " << sum << "\n";

    return 0;
}