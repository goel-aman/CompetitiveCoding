#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t --){
        int n;
        cin>>n;
        string s;cin>>s;// length 2*n - 1
        if(s.size() == 1){
            cout<<s<<endl;
            continue;
        }

        string k;
        vector<string> vs;
        for(int i=0;i<n;i++){
            vs.push_back(s.substr(i,n));
        }

        for(int i=0;i<n;i++){
            char c = vs[0][i];
            for(int j=1;j<n;j++){
                char d = vs[j][i];
                if( c == '1' && d == '1') {
                    c = '1';
                }
                else{
                    c = '0';
                }
            }
            k.push_back(c);
        }
        cout<<k<<endl;
    }
    return 0;
}