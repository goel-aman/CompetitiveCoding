#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void traverse(ll node,unordered_map<ll,vector<ll>> &graph,vector<ll> &visited,vector<ll> &temp){
    visited[node] = 1;
    temp.push_back(node);

    for(auto var : graph[node]){
        if(visited[var] == -1){
            traverse(var,graph,visited,temp);
        }
    }
    return ;
}

int main(){
    ll numberOfMembers;
    ll friendsPair;
    unordered_map<ll,vector<ll>> graph;
    cin>>numberOfMembers>>friendsPair;
    set<vector<ll>> forSearching; 
    for(ll i=0;i<friendsPair;i++){
        ll firstMember,secondMember;
        cin>>firstMember>>secondMember;
        forSearching.insert({firstMember,secondMember});
        forSearching.insert({secondMember,firstMember});
        graph[firstMember].push_back(secondMember);
        graph[secondMember].push_back(firstMember);
    }

    vector<ll> visited(numberOfMembers + 1, -1);
    bool gotAnswer = true;
    for(ll i=1;i<=numberOfMembers;i++){
        
        if(visited[i] == -1){
            vector<ll> temp;
            traverse(i,graph,visited,temp);
            // cout<<"Array after traversing is : "<<endl;
            // for(auto var : temp){
                // cout<<var<<" ";
            // }
            // cout<<endl;
            ll length = temp.size();
            for(ll j=0;j<length - 1;j++){
                for(ll k= j + 1;k<length;k++){
                    if(forSearching.count({temp[j],temp[k]}) > 0 ||  forSearching.count({temp[k],temp[j]}) > 0){
                        continue;
                    }else{
                        // cout<<"value of i is : "<<i<<endl;
                        // cout<<"value of j is : "<<j<<" and k is: "<<k<<endl;
                        gotAnswer = false;
                        break;
                    }
                }
                if(gotAnswer == false){
                    break;
                }
            }
        }
        if(gotAnswer == false){
            break;
        }
    }
    if(gotAnswer == false){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}