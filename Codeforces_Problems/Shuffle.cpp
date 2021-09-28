#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x,m;cin>>n>>x>>m;
        ll startRange = -1,endRange = -1;
        ll findFirst = 0;
        for(ll i=0;i<m;i++){
            ll start,end;
            cin>>start>>end;

            if(findFirst == 0){
                if(x >= start && x <= end){
                    findFirst = 1;
                    startRange = start;
                    endRange = end;
                    continue;
                }
            }

            if( (start >= startRange && start <= endRange) || (end >= startRange && end <= endRange) || (start < startRange && end > endRange)){
                startRange = min(start,startRange);
                endRange = max(end,endRange);
                continue;
            }
        }
        if(startRange == -1 && endRange == -1){
            cout<<1<<endl;
            continue;
        }

        cout<<endRange - startRange + 1<<endl;
    }
}