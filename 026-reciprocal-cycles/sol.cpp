#include <bits/stdc++.h>
using namespace std;

int main() {
    int longest_cycle = 0;
    int longest_d = 0;

    map<int,int> past_reminder;
    for (int d = 2; d < 1000; d++) {
        past_reminder.clear();

        int n = 1, cnt = 0;
        while (n) {
            if (past_reminder.count(n)) {
                if (cnt - past_reminder[n] > longest_cycle) {
                    longest_d = d;
                    longest_cycle = cnt - past_reminder[n];
                }
                break;
            }

            past_reminder[n] = cnt++;
            n = (n * 10) % d;
        }
    }

    cout << "The longest recurring cycle is " << longest_d << " with " << longest_cycle << " length\n";

    return 0;
}