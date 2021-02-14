#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main(){
    ll x,y;
    cin>>x>>y;
    ll n;
    cin>>n;
    if(n == 1){
        cout<<((x%mod) + mod)%mod<<endl;
        return 0; 
    }

    if(n == 2){
        cout<<((y%mod) + mod)%mod<<endl;
        return 0;
    }

    long long int arr[] = {0,x,y,0,0,0,0};
    for(int i=3;i<=6;i++){
        arr[i] = arr[i - 1] - arr[i - 2];
    }
    // cout<<"hello"<<endl;
    n = n % 6;
    // cout<<"Value of n is : "<<n<<endl;
    if(n == 0){
        cout<<( (arr[6]%mod) + mod)%mod<<endl;
        return 0;
    }
    ll val = ((arr[n] % mod) + mod)%mod;
    // cout<<val<<endl;
    cout<<val<<endl;
}