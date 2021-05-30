#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        // n is total number of cells
        // m is total iteration
        string s;
        cin>>s;
        vector<ll> left(n,INT_MAX);
        vector<ll> right(n,INT_MAX);
        int prev = -1;
        for(int i=0;i<n;i++){
            if(i == 0)
            {
                if(s[i] == '0'){
                    left[i] = INT_MAX;
                }else{
                    left[i] = 0;
                    prev = 1;
                }
                continue;
            }
            if(s[i] == '0'){
                if(prev != -1){
                    left[i] = left[i - 1] + 1;
                }
            }else{
                prev = 1;
                left[i] = 0;
            }
        }   
        prev = -1;
        for(int i = n - 1;i>=0;i--){
            if(i == n - 1){
                if(s[i] == '0'){
                    right[i] = INT_MAX;
                    continue;
                }
                right[i] = 0;
                prev = 1;
                continue;
            }
            if(s[i] == '0'){
                if(prev != -1){
                    right[i] = right[i + 1] + 1;
                }
            }else{
                right[i] = 0;
                prev = 1;
            }
        }
        // cout<<"printing right of i"<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;


        // cout<<"printing left of i"<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        string ans;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                ans.push_back('1');
                continue;
            }

            if(abs(left[i] - right[i]) != 0 && min(left[i],right[i]) <= m){
                ans.push_back('1');
                continue;
            }

            ans.push_back('0');

        }
        cout<<ans<<endl;
    }
}