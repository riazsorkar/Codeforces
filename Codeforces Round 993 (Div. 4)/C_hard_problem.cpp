#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    
    while (t--) {
        long long m, a, b, c;
        cin >> m >> a >> b >> c;
        
        long long srow1 = min(a, m);
        long long srow2 = min(b, m);
        
    
        long long rrow1 = m - srow1;
        long long rrow2 = m - srow2;
        
        
        long long max = srow1 + srow2;
        long long remaining_c = c;
        
        
        long long fill_row1 = min(remaining_c, rrow1);
        max += fill_row1;
        remaining_c -= fill_row1;
        
        
        long long fill_row2 = min(remaining_c, rrow2);
        max += fill_row2;
        
    
        cout << max << endl;
    }
    return 0;
}