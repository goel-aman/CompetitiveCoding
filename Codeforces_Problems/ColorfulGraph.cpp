#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

set<ll> nodeWithColors[100005];
ll colors[100005];

int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll color;
        cin>>color;

        colors[i] = color;
    }
    ll colorNumber = -1;
    ll count = -1;
    for(ll i=0;i<m;i++){
        ll firstVertex,secondVertex;
        cin>>firstVertex>>secondVertex;
        if(colors[firstVertex] != colors[secondVertex]){
            nodeWithColors[colors[secondVertex]].insert(colors[firstVertex]);
            nodeWithColors[colors[firstVertex]].insert(colors[secondVertex]);
            ll firstValue = nodeWithColors[colors[firstVertex]].size();
            ll secondValue = nodeWithColors[colors[secondVertex]].size();

            if(count < firstValue){
                count = firstValue;
                colorNumber = colors[firstVertex];
            }
            else if (count == firstValue){
                colorNumber = min(colorNumber,colors[firstVertex]);
            }

            if(count < secondValue){
                count = secondValue;
                colorNumber = colors[secondVertex];
            }
            else if(count == secondValue){
                colorNumber = min(colorNumber,colors[secondVertex]);
            }
        }
    }
    for(ll i=1;i<=n;i++){
        if(count < nodeWithColors[colors[i]].size()){
            count = nodeWithColors[colors[i]].size();
            colorNumber = colors[i];           
        }
        else if(count == nodeWithColors[colors[i]].size()){
            colorNumber = min(colorNumber,colors[i]);
        }
    }
    cout<<colorNumber<<endl;
    return 0;
}