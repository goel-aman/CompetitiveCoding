#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class dsu{
    public:
    ll * parent;
    ll * chainLength;
    ll count;

    dsu(ll size){
        parent = new ll[size + 1];
        chainLength = new ll[size + 1];
        count = size;
        for(ll i=0;i<=count;i++){
            parent[i] = i;
            chainLength[i] = 1;
        }
    }

    ll findParent(ll value){
        if(parent[value] == value){
            return value;
        }

        return parent[value] = findParent(parent[value]);
    }

    void makeParent(ll value1,ll value2){
        ll firstParent = findParent(value1);
        ll firstCount = chainLength[firstParent];

        ll secondParent = findParent(value2);
        ll secondCount = chainLength[secondParent];
        if(firstParent != secondParent){
            if(firstCount > secondCount){
            parent[secondParent] = firstParent;
            chainLength[firstParent] = chainLength[firstParent] + chainLength[secondParent]; 
            }
            else{
                parent[firstParent] = secondParent;
                chainLength[secondParent] = chainLength[firstParent] + chainLength[secondParent];
            }
        }
    }

};


int main(){
    ll numberOfUsers,friendsGroup;
    cin>>numberOfUsers>>friendsGroup;
    
    dsu * val = new dsu(numberOfUsers);

    for(ll i=0;i<friendsGroup;i++){
        ll usersCount;
        cin>>usersCount;
        if(usersCount == 0){
            continue;
        }

        ll firstValue;
        cin>>firstValue;
        for(ll j=0;j<usersCount - 1;j++){
            ll tempValue;
            cin>>tempValue;
            val->makeParent(firstValue,tempValue);
        }       

    }


        for(ll i=1;i<=numberOfUsers;i++){
            cout<<val->chainLength[val->findParent(i)]<<" ";
        }
        cout<<endl; 
    return 0;
}