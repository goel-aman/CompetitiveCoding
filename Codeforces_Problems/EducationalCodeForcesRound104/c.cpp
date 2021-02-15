#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        ll everywinning = 0;
        ll totalTransactionPossible = ((n - 1) * n)/ 2;
        if((totalTransactionPossible * 3 ) % n == 0){
            ll value = totalTransactionPossible / n;
            unordered_map<int,int> um;
            for(int i=1;i<=n-1;i++){
                for(int j=i + 1;j<=n;j++){
                    if(um[i] < value){
                        um[i]++;
                        cout<<1<<endl;
                    }else{
                        um[j] ++;
                        cout<<-1<<endl;
                    }
                }
            }
        }
        
        for(int i=1;i<=n - 1;i++){
            for(int j=2;j<=n;j++){
                 
            }
        }
    }
}