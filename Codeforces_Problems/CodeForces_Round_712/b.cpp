#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class elem{
    public:
    elem(){
        one = 0;
        zero = 0;
    }
    int one;
    int zero;
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        string a;
        string b;
        cin>>a;
        cin>>b;

        elem prefixa[n];
        
        for(ll i=0;i<n;i++){
            if(i == 0){
                if(a[i] == '0'){
                    prefixa[i].zero++;
                }
                else{
                    prefixa[i].one++;
                }
                continue;
            }

            if(a[i] == '0'){
                prefixa[i].zero = prefixa[i -1].zero + 1;
                prefixa[i].one = prefixa[i - 1].one;
            }
            else{
                prefixa[i].one = prefixa[i - 1].one + 1;
                prefixa[i].zero = prefixa[i - 1].zero;
            }
        }
        bool isFlip = false;
        int gotanswer = 0;
        for(ll i= n - 1;i>=0;i--){
            bool ai = a[i] - '0';
            bool bi = b[i] - '0';
            // cout<<"ai is : "<<ai<<" bi is : "<<bi<<endl;
            if(isFlip == true){
                ai = (!ai);
            }
            // cout<<"ai is : "<<ai<<" bi is : "<<bi<<" AFter manipulation"<<endl;
            if(ai == bi){
                continue;
            }
            else{
                if(prefixa[i].zero != prefixa[i].one){
                    gotanswer = 1;
                    cout<<"NO"<<endl;
                    break;
                }else{
                    // cout<<"Entered into isFlip"<<endl;
                    isFlip = (!isFlip);
                    // cout<<"Value of is flip is: "<<isFlip<<endl;
                    continue;
                }
            }
        }
        if(gotanswer == 0){
            cout<<"YES"<<endl;
            continue;
        }
    }
    return 0;
}