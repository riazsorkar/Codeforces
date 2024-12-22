#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;

        string b = "";
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] == 'p') b += 'q';
            else if (a[i] == 'q') b += 'p';
            else if (a[i] == 'w') b += 'w';
        }
        
        cout << b << endl;
    }
    return 0;
}