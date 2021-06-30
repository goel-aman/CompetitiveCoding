#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        ll a[n],b[n],a2[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            a2[i] = a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int p1 = 0, p2 = 0;
        for(int i=0;i<n;i++){
            if(b[i] == 0){
                p1 = 1;
            }
            if(b[i] == 1){
                p2 = 1;
            }
        }

        if(p1&&p2){
            cout<<"Yes"<<endl;
            continue;
        }

        sort(a2,a2 + n);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(a[i] != a2[i]){
                cout<<"No"<<endl;
                ans = 1;
                break;
            }
        }   
        if(ans == 1){
            continue;
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}