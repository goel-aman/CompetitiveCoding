#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll numberOfBooks;
    ll freeTime;
    cin>>numberOfBooks>>freeTime;

    ll a[numberOfBooks];
    vector<ll> prefix;
    ll sum = 0;
    for(int i=0;i<numberOfBooks;i++){
        prefix.push_back(sum);
        cin>>a[i];
        sum += a[i];
    }
    prefix.push_back(sum);
    ll maxAnswer = 0;
    for(ll i=numberOfBooks;i>=1;i--)
    {
        auto l = lower_bound(prefix.begin(),prefix.end(),prefix[i] - freeTime);
        ll index = l - prefix.begin();
        maxAnswer = max(maxAnswer,i - index);

    }
    cout<<maxAnswer<<endl;
}