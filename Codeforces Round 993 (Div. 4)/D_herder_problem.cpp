#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sol() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    vector<bool> used(200001, false); 
    vector<int> freq(200001, 0);
    int nextUnused = 1; 
    for (int i : v) {
        used[i] = true;
    }

    for (int i : v) {
        if (freq[i] == 0) {
            
            cout << i << " ";
            freq[i]++;
        } else {
            
            while (used[nextUnused]) {
                nextUnused++;
            }
            cout << nextUnused << " ";
            used[nextUnused] = true;
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        sol();
        cout << '\n';
    }
    return 0;
}