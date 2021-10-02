#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

class element{
    public:
    ll length;
    ll index;
};

class compare{
    public:
    bool operator()(element& first,element& second){
        if(first.length < second.length){
            return true;
        }
        return false;
    }
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll array[n];
        for(ll i=0;i<n;i++){
            cin>>array[i];
        }
        
        ll friendsNeed[k];
        for(ll i=0;i<k;i++){
            cin>>friendsNeed[i];
        }   
        
        // first position max,min
        vector<pair<ll,ll>> arr(k,{LLONG_MIN,LLONG_MAX});
        sort(array,array + n);
        reverse(array,array + n);
        sort(friendsNeed,friendsNeed + k);
        reverse(friendsNeed,friendsNeed + k);
        ll j=0;
        for(int i=k - 1;i>=0;i--){
            if(friendsNeed[i] > 0){
                arr[i].first = max(arr[i].first,array[j]);
                arr[i].second = min(arr[i].second,array[j]);
                friendsNeed[i]--;
                j++;
            }
        }

        j = n - 1;
        for(int i=0;i<k;i++){
            while(friendsNeed[i] > 0){
                arr[i].first = max(arr[i].first,array[j]); 
                arr[i].second = min(arr[i].second,array[j]);
                friendsNeed[i]--;
                j--;
            }
        }

        ll ans = 0;
        for(int i=0;i<k;i++){
            ans += arr[i].first;
            ans += arr[i].second;
        }
        cout<<ans<<endl;
    }
    return 0;
}