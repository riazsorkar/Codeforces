#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        s = " " + s;
        vector<int> next_p(n+2, n+1);
        for(int j=n; j>=1; j--){
            if(s[j]=='p') next_p[j]=j;
            else next_p[j]=next_p[j+1];
        }
        vector<int> last_s(n+1,0);
        for(int j=1; j<=n; j++){
            if(s[j]=='s') last_s[j]=j;
            else last_s[j]=last_s[j-1];
        }
        vector<int> Uj(n);
        for(int j=1; j<=n; j++){
            int u_p = INT32_MAX;
            if(next_p[j]<=n){
                u_p = next_p[j];
            }
            int u_s = INT32_MAX;
            if(last_s[j]>=1){
                u_s = n - last_s[j] +1;
            }
            if(u_p != INT32_MAX && u_s != INT32_MAX){
                Uj[j-1] = min(u_p, u_s);
            }
            else if(u_p != INT32_MAX){
                Uj[j-1] = u_p;
            }
            else if(u_s != INT32_MAX){
                Uj[j-1] = u_s;
            }
            else{
                Uj[j-1] = n;
            }
        }
        sort(Uj.begin(), Uj.end());
        bool ok=true;
        for(int i=1;i<=n;i++) {
            if(Uj[i-1]<i){
                ok=false;
                break;
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
}