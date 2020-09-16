#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        if(n == 2){
            cout<<x<<" "<<y<<endl;
            continue;
        }
        vector<long long int> v;
        v.push_back(x);
        v.push_back(y);
        ll diff = y - x;
        ll ndiff = n - 2;
        ll k = ndiff + 1;
        while((diff%k)  != 0){
            k = k - 1;
        }
        ll incr = diff / k;

        ll m = k - 1;
        ll start = x;
        for(int i=0;i<m;i++){
            start += incr;
            v.push_back(start);
        }
        ndiff = ndiff - m;
        ll hh = x;

        while(hh - incr >= 1 && ndiff > 0){
            hh = hh - incr;
            v.push_back(hh);
            ndiff--;
        }
        ll hhh = y;
        while(ndiff > 0){
            hhh += incr;
            v.push_back(hhh);
            ndiff --;
        }
        for(auto x: v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}