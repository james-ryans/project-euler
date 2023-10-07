#include <bits/stdc++.h>
using namespace std;

const int N = 100;

string int_to_string(int i) {
    string s = "";
    while (i > 0) {
        s += '0' + i%10;
        i /= 10;
    }

    return s;
}

string sum(string a, string b) {
    string c = "";
    int carry = 0;
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        int d = carry + a[i]-'0' + b[i]-'0';
        carry = d/10;

        c += d%10 + '0';
    }
    for (int i = b.size(); i < a.size(); i++) {
        int d = carry + a[i]-'0';
        carry = d/10;

        c += d%10 + '0';
    }
    for (int i = a.size(); i < b.size(); i++) {
        int d = carry + b[i]-'0';
        carry = d/10;

        c += d%10 + '0';
    }
    if (carry) {
        c += carry + '0';
    }

    return c;
}

string sum_multiple(vector<string>& a) {
    string c = a[0];
    for (int i = 1; i < a.size(); i++) {
        c = sum(c, a[i]);
    }

    return c;
}

string mul(string a, string b) {
    vector<string> need_to_sums;
    for (int i = 0; i < b.size(); i++) {
        string c = "";
        int carry = 0;
        for (int j = 0; j < a.size(); j++) {
            int d = (b[i]-'0') * (a[j]-'0') + carry;
            carry = d / 10;

            c += d%10 +'0';
        }
        if (carry) {
            c += carry+'0';
        }

        c = string(i, '0') + c;
        need_to_sums.push_back(c);
    }

    return sum_multiple(need_to_sums);
}

int main() {
    set<string> distinct_terms;
    for (int a = 2; a <= N; a++) {
        string base = int_to_string(a);
        string powered = base;
        for (int b = 2; b <= N; b++) {
            powered = mul(powered, base);
            distinct_terms.insert(powered);
        }
    }

    cout << "Number of distinct terms is " << distinct_terms.size() << "\n";
    // cout << "List of the terms: ";
    // for (set<string>::iterator it = distinct_terms.begin(); it != distinct_terms.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << "\n";

    return 0;
}