#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// B. Applejack and Storages

int main(){
    ll n;
    cin>>n;
    unordered_map<ll,ll> um;
    for(int i=0;i<n;i++){
        ll value;
        cin>>value;
        um[value]++;
    }

    ll greaterThan2 = 0,greaterThan4 = 0,greaterThan6 = 0,greaterThan8 = 0;
    for(auto var : um){
        if(var.second >= 8){
            greaterThan8++;
            continue;
        }

        if(var.second >= 6){
            greaterThan6++;
            continue;
        }

        if(var.second >= 4){
            greaterThan4++;
            continue;
        }

        if(var.second >= 2){
            greaterThan2++;
            continue;
        }
    }

    ll queries;
    cin>>queries;
    while(queries--){
        char sign;
        ll number;
        cin>>sign>>number;
        ll prev = um[number];
        if(sign == '+'){
            um[number]++;
            if(prev == 7){
                greaterThan8++;
                greaterThan6--;
            }
            if(prev == 5){
                greaterThan6++;
                greaterThan4--;
            }

            if(prev == 3){
                greaterThan4++;
                greaterThan2--;
            }

            if(prev == 1){
                greaterThan2++;
            }

        }else{
            um[number]--;
            if(prev == 8){
                greaterThan8--;
                greaterThan6++;
            }

            if(prev == 6){
                greaterThan6--;
                greaterThan4++;
            }

            if(prev == 4){
                greaterThan4--;
                greaterThan2++;
            }

            if(prev == 2){
                greaterThan2--;
            }
        }
        
        if(greaterThan8){
            cout<<"Yes"<<endl;
            continue;
        }       

        if(greaterThan4 >= 2 || (greaterThan4 >= 1 && greaterThan6 >= 1)){
            cout<<"Yes"<<endl;
            continue;
        }

        if(greaterThan6 >= 1 && greaterThan2 >= 1 || (greaterThan6 >= 2)){
            cout<<"Yes"<<endl;
            continue;
        }

        if(greaterThan2 >= 2 && greaterThan4 >= 1){
            cout<<"Yes"<<endl;
            continue;
        }
        if(greaterThan6 >= 1 && greaterThan2 >= 1){
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
}