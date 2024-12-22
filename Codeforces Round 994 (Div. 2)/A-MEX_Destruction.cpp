#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sol() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) 
        cin >> i;

    int found = 0, nonzero = 0;

    for (int i : v) {
        if (i != 0 && !nonzero) {
            found++;
            nonzero = 1;
            if (found > 2) break; // Cap the count at 2
        }
        if (i == 0) 
            nonzero = 0;
    }

    cout << min(found, 2); // Safeguard to cap the result at 2
}

int main() {
    int tc; 
    cin >> tc; 
    while (tc--) 
        sol(), cout << '\n'; 
    return 0;
}
