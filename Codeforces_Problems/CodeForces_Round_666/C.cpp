#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int x; cin>>x;
        int n = s.length();
        string k(n,'1');
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                if(i + x <= n - 1 && i + x >= 0){
                    k[i+ x] = '0';
                }
                if( i - x >= 0 && i - x <= n - 1){
                    k[i - x] = '0';
                }
            }
        }
        // cout<<"k is : "<< k<<endl;
        int flag = 1;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                if( ( ( ((x + i) < n) && ((x + i) >= 0) )  && k[x+i] == '1') || (i - x < n && i-x >= 0 && k[i - x] == '1') ){
                    continue;
                }
                flag = 0;
                break;
            }
        }
       
        if(flag == 0){
            cout<<-1<<endl;
        }else{
            cout<<k<<endl;
        }
    }
    return 0;
}