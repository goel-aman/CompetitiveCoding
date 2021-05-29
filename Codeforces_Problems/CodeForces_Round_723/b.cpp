#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll n;
unordered_map<string,ll> um;
int solve(ll * a,int index,int sum){
    
    if(index == n){
        return 0;
    }
 
    string s = to_string(index) + ";" + to_string(sum);
    if(um.count(s)){
        return um[s];
    }
 
    if(a[index] >= 0){
        return um[s] = (1 + solve(a,index + 1, sum + a[index]));
    }
 
    if(a[index] < 0 && abs(a[index]) > sum){
        return um[s] = solve(a,index + 1,sum);
    }
 
 
    int value = 1 + solve(a,index + 1, sum - abs(a[index]));
    int value2 = solve(a,index + 1,sum);
    return um[s] = max(value,value2);
 
}
 
int main(){
    cin>>n;
    ll a[n];
    int count = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i] >= 0){
            count++;
        }
    }
    if(count == n){
        cout<<n<<endl;
        return 0;
    }
    cout<<solve(a,0,0)<<endl;
    return 0;
}