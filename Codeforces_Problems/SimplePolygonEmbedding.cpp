#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// C1. Simple Polygon Embedding

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        double pi = 3.141592653589;
        double value = 1.0 / (double) tan((double)pi / (double) (2 * n));
        cout<<setprecision(8)<<value<<endl;
    }
    return 0;
}
