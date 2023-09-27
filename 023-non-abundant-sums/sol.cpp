#include <bits/stdc++.h>
using namespace std;

const int N = 28123;

vector<int> get_abundant_numbers() {
    vector<int> abundants;
    for (int num = 1; num <= N; num++) {
        int sum = -num;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }

        if (sum > num) {
            abundants.push_back(num);
        }
    }

    return abundants;
}

int main() {
    vector<int> abundants = get_abundant_numbers();
    int n = abundants.size();

    cout << "First abundant number is " << abundants[0] << "\n";
    cout << "Abundant numbers amount: " << n << "\n";

    vector<bool> is_sum_of_two_abundants(N + 1, false);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = abundants[i] + abundants[j];
            if (abundants[i] + abundants[j] > N) {
                break;
            }

            is_sum_of_two_abundants[sum] = true;
        }
    }

    int sum = 0;
    for (int num = 1; num <= N; num++) {
        if (!is_sum_of_two_abundants[num]) {
            sum += num;
        }
    }

    cout << "Sum of all positive integers that cannot be written as the sum of two abundant numbers: " << sum << "\n";

    return 0;
}