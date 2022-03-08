#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class dsu{
    public:
    vector<ll> parent;

    dsu(ll size){
        parent.resize(size + 1);
        for(ll i=0;i<=size;i++){
            parent[i] = i;
        }
    }
    
    void merge(ll first,ll second){
        ll firstParent = findParent(first);
        ll secondParent = findParent(second);

        if(firstParent != secondParent){
            parent[firstParent] = secondParent;
        }
        return ;
    }

    ll findParent(ll input){
        if(parent[input] == input){
            return input;
        }

        return parent[input] = findParent(parent[input]);
    }
};

int main(){
    ll numberOfBalls;
   cin>>numberOfBalls;

    dsu temp(numberOfBalls);

    for(ll i=1;i<=numberOfBalls;i++){
        ll value;
        cin>>value;
        temp.merge(i,value);       
    }
    ll ans = 0;
    for(ll i=1;i<=numberOfBalls;i++){
        if(temp.parent[i] == i){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}