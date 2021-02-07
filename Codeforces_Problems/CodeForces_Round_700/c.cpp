#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll start = 1;
        ll end = n;;
        while(start < end){
            ll midValue,midPlus;
            ll mid = (start + end) / 2;
            cout<<"?"<<" "<<mid<<endl;
            cin>>midValue;
            cout<<"?"<<" "<<mid + 1<<endl;
            cin>>midPlus;
            if(midPlus < midValue){
                start = mid + 1;
                continue;
            }

            if(midPlus > midValue){
                end = mid;
            }
        }
        cout<<"! "<<start<<endl;
    }
}