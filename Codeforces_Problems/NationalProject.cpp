#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,g,b;
        cin>>n>>g>>b;
        bool isEven = (n%2 == 0) ? 1 : 0;
        ll target = n/2;
        if(!isEven){
            target++;
        } 

        ll sum = 0;
        ll minCount = target / g;
        if(target%g == 0){
            minCount--;
        }
        target -= (g * minCount);
        sum += (g * minCount) + (b * minCount);
        
        while(target > 0){
            sum += min(target,g);
            target -= min(target,g);
            if(target == 0){
                break;
            }
            sum += min(n - sum,b);
        }
        
        if(n - sum > 0){
            sum += (n - sum);
        }
        cout<<sum<<endl;
    }
    return 0;
}