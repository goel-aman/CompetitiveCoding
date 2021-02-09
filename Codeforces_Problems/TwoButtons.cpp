#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n,m;
    cin>>n>>m;
    if(n == m){
        cout<<0<<endl;
        return 0;
    }
    if(n > m){
        cout<<n - m<<endl;
        return 0;
    }
    int flag = 0;
    unordered_map<int,bool> um;
    queue<long long int> q;
    q.push(m);
    ll step = 0;
    um[m] = true;
    while(!q.empty()){
        step++;
        ll qsize = q.size();
        while(qsize--){
            ll front = q.front();
            q.pop();
            if(front%2 == 0){
                ll val = (front / 2);
                ll val2 = front + 1;
                if(val == n || val2 == n){
                    cout<<step<<endl;
                    flag = 1;
                    break;
                }
                if(!um.count(val)){
                    um[val] = true;
                    q.push(val);
                }
                if(!um.count(val2)){
                    um[val2] = true;
                    q.push(val2);
                }
            }else{
                ll val = front + 1;
                if(val == n){
                    cout<<step<<endl;
                    flag = 1;
                    break;
                }
                if(!um.count(val)){
                    um[val] = true;
                    q.push(val);
                }
            }
        }
        if(flag == 1){
            break;
        }
    }

}