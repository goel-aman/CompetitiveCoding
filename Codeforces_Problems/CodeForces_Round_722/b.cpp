#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        

        sort(a,a + n);
        if(n == 2){
            ll diff = abs(a[1] - a[0]);
            if(diff >= max(a[1],a[0])){
                cout<<2<<endl;
                continue;
            }else{
                cout<<1<<endl;
                continue;
            }
        }
        int count = 0;
        int i= 0;
        for(;i<n;i++){
            if(a[i] <= 0){
                count++;
            }else{
                break;
            }
        }
        ll minDiff = INT_MAX;
        for(int j=1;j<i;j++){
            ll value = abs(a[j] - a[j - 1]);
            minDiff = min(value,minDiff);
        }

        for(int w = i;w<n;w++){
            if(a[w] <= minDiff){
                    count++;
                    break;
            }
        }
        cout<<count<<endl;
    }
}