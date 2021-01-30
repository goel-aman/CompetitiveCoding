#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n == 1){
            cout<<k<<endl;
            continue;
        }
        if(n == k){
            cout<<1<<endl;
            continue;
        }
        if(k > n){
            ll r = k % n;
            ll q = k / n;
            if(r==0){
                cout<<q<<endl;
                continue;
            }

            else{
                cout<<q + 1<<endl;
                continue;
            }
        }

        if(n > k){
            if(n%k == 0){
                cout<<1<<endl;
                continue;
            }
            else{
                ll s = n / k;
                s++;
                ll nn = k * s;
                ll r = nn % n;
                ll q = nn / n;
                if(r == 0){
                    cout<<q<<endl;
                    continue;
                }
                cout<<q + 1<<endl;
            }
        }


    }
}