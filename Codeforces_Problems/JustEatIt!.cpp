#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll array[n];
        ll sum = 0;
        for(ll i=0;i<n;i++){
            cin>>array[i];
            sum += array[i];
        }

        ll maxValue = INT_MIN;
        ll value = 0;
        ll isBreak = false;
        ll series = 0;
        ll finalLength = 0;
        for(int i=0;i<n;i++){
            if(value + array[i] > array[i]){
                series++;
                value = value + array[i];
            }else{
                value = array[i];
                series = 1;
            }
            // value = max({value + array[i],array[i]});
            if(value > maxValue){
                maxValue = value;
                finalLength = series;
            }
            maxValue = max(maxValue,value);
        }
        
        if(sum == maxValue && finalLength == n){
            cout<<"YES"<<endl;
            continue;
        }

        if(sum > maxValue){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}