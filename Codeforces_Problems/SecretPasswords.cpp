#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

class dsu{
    public:
    vector<ll> parent;
    dsu(ll length){
        parent.resize(length);
        for(ll i=0;i<length;i++){
            parent[i] = i;
        }
    }


    ll findParent(ll node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findParent(parent[node]);
    }

    void merge(ll firstNode,ll secondNode){
        ll firstParent = findParent(firstNode);
        ll secondParent = findParent(secondNode);

        if(firstParent != secondParent){
            parent[firstParent] = secondParent;
        }
        return ;
    }
};

int main(){
    ll n;
    cin>>n;
    unordered_set<ll> alphabets[26];
    vector<string> inputString;
    for(ll i=0;i<n;i++){
        string input;
        cin>>input;
        inputString.push_back(input);
        for(auto var : input){
            ll index = var - 'a';
            alphabets[index].insert(i);
        }
    }
    dsu temp(n);
    for(ll i=0;i<26;i++){
        ll firstLoop = false;
        ll prev = -1;
        for(auto var : alphabets[i]){
            if(firstLoop == false){
                prev = var;
                firstLoop = true;
                continue;
            }
            temp.merge(prev,var);
        }
    }

    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(i ==  temp.parent[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}