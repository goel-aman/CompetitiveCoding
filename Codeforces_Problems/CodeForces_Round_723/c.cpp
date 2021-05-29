#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    priority_queue<long long int> pq;
    ll answer = 0;
    ll count = 0;
    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum += arr[i];
        count++;
        if(sum >= 0){
            answer = max(count,answer);
        }
        if(arr[i] < 0){
            pq.push(abs(arr[i]));
        }

        while(sum < 0 && !pq.empty()){
            ll front = pq.top();
            pq.pop();
            sum += front;
            count--;
        }
        
        if(sum < 0){
            break;
        }
    }
    cout<<answer<<endl;
}