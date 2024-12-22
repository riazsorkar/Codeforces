#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, q;
        cin >> n >> q;
        
        vector<vector<long long>> M(n, vector<long long>(n));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                cin >> M[r][c];
            }
        }
        
        vector<vector<long long>> S(n+1, vector<long long>(n+1)), Sr(n+1, vector<long long>(n+1)), Sc(n+1, vector<long long>(n+1));
        
        for(int r = 1; r <= n; r++){
            long long current_S = 0, current_Sr = 0, current_Sc = 0;
            for(int c = 1; c <= n; c++){
                long long val = M[r-1][c-1];
                current_S += val;
                current_Sr += val * r;
                current_Sc += val * c;
                S[r][c] = S[r-1][c] + current_S;
                Sr[r][c] = Sr[r-1][c] + current_Sr;
                Sc[r][c] = Sc[r-1][c] + current_Sc;
            }
        }
        
        string output_buffer;
        output_buffer.reserve(q * 20);
        while(q--){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            long long S_sub = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
            long long Sr_sub = Sr[x2][y2] - Sr[x1-1][y2] - Sr[x2][y1-1] + Sr[x1-1][y1-1];
            long long Sc_sub = Sc[x2][y2] - Sc[x1-1][y2] - Sc[x2][y1-1] + Sc[x1-1][y1-1];
            long long sum_val = (y2 - y1 + 1) * (Sr_sub - x1 * S_sub) + (Sc_sub - (y1-1) * S_sub);
            output_buffer += to_string(sum_val) + ' ';
        }
        cout << output_buffer << '\n';
    }
    
    return 0;
}
