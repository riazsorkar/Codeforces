#include<bits/stdc++.h> 
using namespace std; 
  
int main(){ 
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    int t; 
    cin>>t; 
    while(t--){ 
        int n,m,k; 
        cin>>n>>m>>k; 
        vector<int> a(m); 
        for(auto &x:a) cin>>x; 
        vector<int> q(k); 
        for(auto &x:q) cin>>x; 
        if(k ==n){ 
            for(int i=0;i<m;i++) cout<<'1'; 
            cout<<"\n"; 
        } 
        else if(k ==n-1){ 
            int missing=1; 
            for(auto x:q){ 
                if(x == missing){ 
                    missing++; 
                } 
                else{ 
                    break; 
                } 
            } 
            if(missing >n){ 
                missing =n; 
            } 
            string res; 
            res.reserve(m); 
            for(auto x:a){ 
                res += (x == missing)? '1' : '0'; 
            } 
            cout<<res<<"\n"; 
        } 
        else{ 
            for(int i=0;i<m;i++) cout<<'0'; 
            cout<<"\n"; 
        } 
    } 
}