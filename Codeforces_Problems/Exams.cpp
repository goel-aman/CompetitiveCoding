#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class element{
    public:
    ll trueDate;
    ll earlyDate;
};  

bool compare(element &a,element &b){
    if(a.trueDate < b.trueDate){
        return true;
    }

    if(a.trueDate == b.trueDate){
        if(a.earlyDate < b.earlyDate){
            return true;
        }
    }
    return false;
}

int main(){
    ll n;
    cin>>n;
    element a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i].trueDate;
        cin>>a[i].earlyDate;
    }

    sort(a,a + n,compare);
    int ans = 0;
    for(int i=0;i<n;i++){
        int first = INT_MAX;
        int second = INT_MAX;
        if(ans <= a[i].trueDate){
            first = a[i].trueDate;
        } 

        if(ans <= a[i].earlyDate){
            second = a[i].earlyDate;
        }

        ans = min(first,second);
    }
    cout<<ans<<endl;
    return 0;
}