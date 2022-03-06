#include<bits/stdc++.h>
using namespace std;
#define ll long long int


class dsu{
    public:
    vector<ll> parent;

    dsu(){
        parent.resize(101);
        for(ll i=0;i<101;i++){
            parent[i] = i;
        }
    }

    ll findParent(int val){
        if(parent[val] == val){
            return val;
        }

        return parent[val] = findParent(parent[val]);
    }

    void merge(ll first,ll second){
        ll firstParent = findParent(first);
        ll secondParent = findParent(second);

        if(firstParent != secondParent){
            parent[firstParent] = secondParent;
        }
        return ;
    }
};


int main(){
    ll numberOfVertices,numberOfEdges;
    cin>>numberOfVertices>>numberOfEdges;
    vector<dsu> temp(101);

    for(ll i = 0;i<numberOfEdges;i++){
        ll first,second,color;
        cin>>first>>second>>color;
    
        temp[color].merge(first,second);
    }

    ll queries;
    cin>>queries;

    for(ll i=0;i<queries;i++){
        ll first,second;
        cin>>first>>second;
        ll count = 0;
        for(ll j=1;j<=100;j++){
            if(temp[j].findParent(first) == temp[j].findParent(second)){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}