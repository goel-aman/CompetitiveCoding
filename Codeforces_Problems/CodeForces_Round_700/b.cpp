#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class elem{
    public:
    ll attack;
    ll health;
};  

bool compare(elem a,elem b){
    if(a.attack < b.attack){
        return true;
    }
    return false;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll A,B,n;
        cin>>A>>B>>n;
        ll a[n];
        ll b[n];
        int flag = 1;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }

        elem ab[n];

        for(ll i=0;i<n;i++){
            ab[i].attack = a[i];
            ab[i].health = b[i];
        }

        sort(ab,ab + n,compare);
        for(ll i=0;i<n;i++){
            ll totalattack = 0;
            if(ab[i].health%A != 0){
                totalattack++;
            }
            totalattack += ab[i].health/ A;
            // cout<<"Total attack needed : "<<totalattack<<endl;
            ll attackIHave = 0;
            if(B%ab[i].attack != 0){
                attackIHave += 1;
            }
            attackIHave += (B / ab[i].attack);
            // cout<<"attack i have : "<<attackIHave<<endl;
            if(attackIHave < totalattack){
                flag = 0;
                break;
            }
            B -= (ab[i].attack * totalattack);
            if(B <= 0){
                if(i == n - 1){
                    flag = 1;
                    break;
                }
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}