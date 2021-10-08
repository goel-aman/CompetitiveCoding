#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n;
    cin>>n;
    string a;
    cin>>a;
    string b;
    cin>>b;
    // cin>>a>>b;
    ll result = 0;
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            continue;
        }

        if(i+1 < n && b[i] == a[i + 1] && a[i] == b[i + 1]){
            swap(a[i],a[i + 1]);
            result++;
            continue;
        }

        result++;
    }
    cout<<result<<endl;
    return 0;
}