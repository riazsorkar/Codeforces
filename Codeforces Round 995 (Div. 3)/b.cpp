#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;

        vector<long long> days = {a, b, c};

        long long cycle_sum = a + b + c;
        long long full_cycles = n / cycle_sum;
        long long covered_distance = full_cycles * cycle_sum;
        long long day = full_cycles * 3;

        for (int i = 0; i < 3 && covered_distance < n; i++) {
            covered_distance += days[i];
            day++;
        }

        cout << day << endl;
    }

    return 0;
}
