#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        vector<ll> powers;
        ll p = 1;
        while (p <= r2) {
            powers.push_back(p);
            if (p > r2 / k) break;
            p *= k;
        }

        ll count = 0;

        for (ll power : powers) {
            ll x_min = max(l1, (l2 + power - 1) / power); 
            ll x_max = min(r1, r2 / power);

            if (x_min <= x_max) {
                count += (x_max - x_min + 1);
            }
        }

        cout << count << endl;
    }

    return 0;
}
