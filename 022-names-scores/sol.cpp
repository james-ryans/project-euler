#include <bits/stdc++.h>
using namespace std;

vector<string> explode(string names) {
    string next = "";
    vector<string> name_list;
    for (string::const_iterator it = names.begin(); it != names.end(); it++) {
        if (*it == ',' || *it == '"') {
            if (next.empty()) {
                continue;
            }

            name_list.push_back(next);
            next = "";
        } else {
            next += *it;
        }
    }

    return name_list;
}

int main() {
    string names;
    cin >> names;

    vector<string> name_list = explode(names);
    sort(name_list.begin(), name_list.end());
    int n = name_list.size();

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int val = 0;

        string &name = name_list[i];
        for (string::const_iterator it = name.begin(); it != name.end(); it++) {
            val += (*it - 65) + 1;
        }

        res += val * (i + 1);
    }

    cout << "The answer is " << res << "\n";

    return 0;
}