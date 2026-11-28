#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, pair<double, double>> m;
    for (int i = 0; i < n; i++) {
        string subject;
        cin >> subject;
        double x;
        cin >> x;
        if (m.find(subject) == m.end()) {
            m[subject] = {x, 1};
        } else {
            m[subject].first += x;
            m[subject].second++;
        }
    }
    for (auto x : m) {
        double a = (x.second).first;
        double b = (x.second).second;
        cout << x.first << " " << a / b << endl;
    }
}