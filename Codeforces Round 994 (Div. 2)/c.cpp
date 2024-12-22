#include <bits/stdc++.h>
using namespace std;

int findMEX(const set<int>& s) {
    int mex = 0;
    while (s.find(mex) != s.end()) {
        ++mex;
    }
    return mex;
}

vector<int> assignValues(int n, int x, int y) {
    vector<int> a(n, -1);
    vector<set<int>> friends(n);

    for (int i = 0; i < n; ++i) {
        friends[i].insert((i + 1) % n);
        friends[i].insert((i - 1 + n) % n);
    }

    x--; y--;
    friends[x].insert(y);
    friends[y].insert(x);

    for (int i = 0; i < n; ++i) {
        set<int> neighborValues;
        for (int friendIndex : friends[i]) {
            if (a[friendIndex] != -1) {
                neighborValues.insert(a[friendIndex]);
            }
        }
        a[i] = findMEX(neighborValues);
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> result = assignValues(n, x, y);
        for (int value : result) {
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}