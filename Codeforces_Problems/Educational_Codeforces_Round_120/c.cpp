#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// C. Set or Decrease

int main(){
    ll t;
    cin>>t;
    // cout<<"t is ; "<<t<<endl;
    while(t--){
        ll arraySize;
        ll upperBound;
        cin>>arraySize>>upperBound;
        // cout<<"arraySize is : "<<arraySize<<" upperBound is ; "<<upperBound<<endl;
        ll array[arraySize + 1];
        ll sum = 0;
        for(int i=1;i<=arraySize;i++){
            cin>>array[i];
            sum += array[i];
        }

        if(sum <= upperBound){
            cout<<0<<"\n";
            continue;
        }

        if(sum == upperBound + 1){
            cout<<1<<"\n";
            continue;
        }

        // cout<<"all input takned"<<endl;
        ll ans = 0;
        sort(array,array + arraySize);
        ll diff = sum - upperBound;
        ans = sum - upperBound;
        sum = 0;
        for(ll i=arraySize;i>1;i--){
            sum += array[i];
            ll x;
            if(sum - (arraySize - i + 1)* array[1] >= diff) x = 0;
            else x = max((long long int) ceil((double) (diff - sum + (arraySize - i + 1) * array[1])/(double) (arraySize - i + 2)),0LL);
            ans = min(ans,x + arraySize - i + 1);
        }
        cout<<ans<<endl;
    }
}