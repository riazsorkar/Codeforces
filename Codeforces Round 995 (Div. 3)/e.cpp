#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int size;
        long long limit;
        cin >> size >> limit;
        vector<long long> array1(size), array2(size);
        for(auto &elem : array1) cin >> elem;
        for(auto &elem : array2) cin >> elem;
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        vector<long long> combined;
        combined.reserve(2 * size);
        for(auto elem : array1) combined.push_back(elem);
        for(auto elem : array2) combined.push_back(elem);
        sort(combined.begin(), combined.end());
        combined.erase(unique(combined.begin(), combined.end()), combined.end());
        long long max_profit = 0;
        for(auto value : combined){
            int idx1 = lower_bound(array1.begin(), array1.end(), value) - array1.begin();
            int idx2 = lower_bound(array2.begin(), array2.end(), value) - array2.begin();
            long long diff = (long long)(idx1) - (long long)(idx2);
            if(diff <= limit){
                long long buyers = size - idx2;
                long long profit = value * buyers;
                if(profit > max_profit) max_profit = profit;
            }
        }
        cout << max_profit << "\n";
    }
}
