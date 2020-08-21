#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll x1,y1,z1;
        cin>>x1>>y1>>z1;
        ll x2,y2,z2;
        cin>>x2>>y2>>z2;
        ll answer = 0;
        ll mini = min(z1,y2);
        z1 -= mini;
        y2 = y2 - mini;
        answer += 2 * mini;
        ll minii = min(y1,x2 + y2);
        y1 = y1 - minii;
        // cout<<"Answer is "<<answer<<endl;
        if(y1 == 0){
            cout<<answer<<endl;
        }
        else{
            if(z2 == 0){
                cout<<answer<<endl;
            }
            else{
                ll w = min(y1,z2);
                answer -= 2 * w;
                cout<<answer<<endl;
            }

        }
    }
    
    return 0;
}