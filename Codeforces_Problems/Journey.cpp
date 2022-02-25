#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
double traverse(ll node,unordered_map<ll,vector<ll>> &graph,ll parent){
    double value = 0;
    double count = 0;
    for(auto var : graph[node]){
        if(var != parent){
            value += traverse(var,graph,node) + 1;
            count++;
        }
    }
    double ans = 0;
    if(value > 0){
        ans = (double)value/(double)count;
    }
    return ans;
}
 
int main(){
    ll numberOfCities;
    cin>>numberOfCities;
 
    unordered_map<ll,vector<ll>> graph;
    for(ll i=0;i<numberOfCities-1;i++){
        ll firstValue,secondValue;
        cin>>firstValue>>secondValue;
        graph[firstValue].push_back(secondValue);
        graph[secondValue].push_back(firstValue);
    }
    cout<<fixed<<setprecision(7)<<traverse(1,graph,-1)<<endl;
    return 0;
}