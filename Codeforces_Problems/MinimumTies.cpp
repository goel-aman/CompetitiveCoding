#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    ll testCases;
    cin>>testCases;
    while(testCases--){
        ll value;
        cin>>value;

        ll totalValue = (value * (value -1))/2;
        ll tempValue = totalValue/value;
        ll targetValue = tempValue * 3;
        // cout<<"target value initially is : "<<targetValue<<endl;
        if(totalValue%value != 0){
            targetValue++;
        }
        // cout<<"target value is : "<<targetValue<<endl;
        vector<ll> valueAchieved(value + 1,targetValue);
        for(ll i=1;i<=value - 1;i++){
            for(ll j= i + 1;j<=value;j++){
                if(valueAchieved[i] != 0){
                    if(valueAchieved[i] == 1){
                        valueAchieved[i] -= 1;
                        valueAchieved[j] -= 1;
                        cout<<0<<" ";
                    }else{
                        valueAchieved[i] -= 3;
                        cout<<1<<" ";
                    }
                    continue;
                }
                
                if(valueAchieved[j] != 0){
                    valueAchieved[j] -= 3;
                    cout<<-1<<" ";
                    continue;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}