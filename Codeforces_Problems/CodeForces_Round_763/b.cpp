#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        set<vector<ll>> us;
        ll first,second;
        for(int i=0;i<n;i++){
            cin>>first>>second;
            us.insert({first,second});
        }

        for(auto var : us){
            ll firstNumber = var[0],secondNumber = var[1];
            if(firstNumber == secondNumber){
                cout<<firstNumber<<" "<<secondNumber<<" "<<firstNumber<<endl;
                continue;
            }

            for(ll i=firstNumber;i<=secondNumber;i++){
                if(i == firstNumber){
                    if(us.count({firstNumber + 1,secondNumber})){
                        cout<<firstNumber<<" "<<secondNumber<<" "<<i<<endl;
                        break;              
                    }    
                    continue;
                }            

                if(i == secondNumber){
                    if(us.count({firstNumber,secondNumber - 1})){
                        cout<<firstNumber<<" "<<secondNumber<<" "<<i<<endl;
                        break;
                    }
                    continue;
                }

                if(us.count({firstNumber,i - 1}) && us.count({i + 1,secondNumber})){
                    cout<<firstNumber<<" "<<secondNumber<<" "<<i<<endl;
                    break;
                }
            }
        }
    }
}