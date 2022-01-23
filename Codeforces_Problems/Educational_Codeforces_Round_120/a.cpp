#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll first,second,third;
        cin>>first>>second>>third;
        vector<ll> elements = {first,second,third};

        sort(elements.begin(),elements.end());
        first = elements[0],second = elements[1],third = elements[2];
        if(first + second == third){
            cout<<"YES"<<endl;
            continue;
        }

        if(first == second){
            if(third%2 == 0){
                cout<<"YES"<<endl;
                continue;
            }
        }

        if(second == third){
            if(first%2 == 0){
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
}