#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> vec(26,0);
        char prev;
        bool answer = true;
        for(int i=0;i<n;i++){
            if(i == 0){
                vec[s[i] - 'A'] = 1;
                prev = s[i];
                continue;
            }
            if(s[i] == prev){
                continue;
            }

            if(vec[s[i] - 'A'] != 0){
                answer = false;
                break;
            }else{
                vec[s[i] - 'A'] = 1;
                prev = s[i];
                continue;
            }
        }
        if(answer == false){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
}