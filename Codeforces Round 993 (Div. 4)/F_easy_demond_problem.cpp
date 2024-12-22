#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> a(n), b(m);
    long long sum_a = 0, sum_b = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        sum_b += b[j];
    }

    long long original_beauty = sum_a * sum_b;

    // For each query, we need to check if we can reach the target beauty value
    while (q--) {
        long long x;
        cin >> x;

        // Calculate the target change from the original beauty
        long long target = x - original_beauty;
        bool possible = false;

        // Try all pairs of a[i] and b[j]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Calculate the new beauty based on swapping a[i] and b[j]
                long long new_beauty = original_beauty - a[i] * sum_b - b[j] * sum_a + a[i] * b[j];

                // Check if the new beauty matches the target
                if (new_beauty == x) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }

        // Output result for the current query
        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}
