#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class element{
    public:
    int x;
    int y;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        element arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i].x;
            cin>>arr[i].y;
        }
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        int flag;
        for(int j=0;j<n;j++){
            int xx = arr[j].x;
            int yy = arr[j].y;
            flag = 0;
            for(int i=0;i<n;i++){
                if(abs(xx - arr[i].x) + abs(yy - arr[i].y) <= k){
                    continue;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                cout<<1<<endl;
                break;
            }
        }
        if(flag != 0){
            cout<<-1<<endl;
        }
    }
    return 0;
}