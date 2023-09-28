#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

string sum(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c = "";
    int carry = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        int digit = carry;
        if (i < a.size()) {
            digit += a[i] - '0';
        }
        if (i < b.size()) {
            digit += b[i] - '0';
        }

        c += digit % 10 + '0';
        carry = digit / 10;
    }
    if (carry) {
        c += carry + '0';
    }

    reverse(c.begin(), c.end());

    return c;
}

int main() {
    string a = "1", b = "1";
    int nth = 2;

    while (b.size() < N) {
        a = sum(a, b);
        nth++;

        swap(a, b);
    }

    cout << "The Fibonacci index with 1000 digits is " << nth << "\n";

    return 0;
}