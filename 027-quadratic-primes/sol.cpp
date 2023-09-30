#include <bits/stdc++.h>
using namespace std;

const int N = 80;
const int M = 1000;
const int P = 10000;

void sieve_of_eratosthenes(vector<bool>& is_prime) {
    for (int i = 2; i < P; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i * i; j < P; j += i) {
            is_prime[j] = false;
        }
    }
}

int main() {
    vector<bool> is_prime(P, true);
    sieve_of_eratosthenes(is_prime);

    cout << "Check the first 10 numbers\n";
    for (int i = 1; i <= 10; i++) {
        cout << i << " is " << (is_prime[i] ? "prime" : "not prime") << "\n";
    }
    cout << "\n";

    int best_n = -1, best_a = 0, best_b = 0;
    for (int a = -M + 1; a < M; a++) {
        for (int b = -M; b <= M; b++) {
            for (int n = 0; n < N; n++) {
                int q = n*n + a*n + b;
                if (q < 0 || q >= P || !is_prime[q]) {
                    break;
                }

                if (n > best_n) {
                    best_n = n;
                    best_a = a;
                    best_b = b;
                }
            }
        }
    }

    cout << "The longest consecutive n is " << best_n << "\n";
    cout << "The a and b respectively are " << best_a << " " << best_b << "\n";
    cout << "The product of a and b is " << best_a * best_b << "\n";

    return 0;
}