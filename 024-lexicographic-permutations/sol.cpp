#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int main() {
    vector<int> factorial(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    string permutation = "";
    int nth = 1000000 - 1;
    vector<bool> unused_digit(N, true);
    for (int i = N - 1; i >= 0; i--) {
        int ith = nth / factorial[i];
        nth %= factorial[i];

        for (int j = 0; j < N; j++) {
            if (unused_digit[j]) {
                if (ith > 0) {
                    ith--;
                    continue;
                }

                permutation += (char) '0' + j;
                unused_digit[j] = false;
                break;
            }
        }
    }

    cout << "The millionth lexicographic permutation is " << permutation << "\n";

    return 0;
}