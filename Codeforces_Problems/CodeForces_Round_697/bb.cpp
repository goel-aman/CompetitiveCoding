#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n == 1){
            cout<<"NO"<<endl;
            continue;
        }

        ll nn = n;
        ll case1 = 0;
        ll case2 = 0;
        n = n % 2021;
        n = n % 2020;
        if(n == 0){
            case1 = 1;
        }

        nn = nn % 2020;
        // cout<<"nn is : "<<nn<<endl;
        nn = nn % 2021;
        // cout<<"nn is : "<<nn<<endl;
        if(nn == 0 || nn == 1){
            case2 = 1;
        }

        if((case1 == 1) || (case2 == 1)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}