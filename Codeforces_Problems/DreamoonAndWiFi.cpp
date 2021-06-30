#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define doublePrecise(x,y) cout<<fixed<<setprecision(y)<<x<<endl

// Dreamoon and WiFi
ll fact(ll n){
    if(n == 0){
        return 1;
    }

    ll ret = 1;
    for(ll i=1;i<=n;i++)
    {
        ret = ret * i;
    }
    return ret;
}

int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    ll s1Positive = 0;
    ll s1Negative = 0;
    for(int i=0;i<s1.length();i++){
        if(s1[i] == '+'){
            s1Positive++;
        }

        if(s1[i] == '-'){
            s1Negative++;
        }
    }

    ll s2Positive = 0;
    ll s2Negative = 0;
    ll questionMark = 0;
    for(int i=0;i<s2.length();i++){
        if(s2[i] == '+'){
            s2Positive++;
        }

        if(s2[i] == '-'){
            s2Negative++;
        }

        if(s2[i] == '?'){
            questionMark++;
        }
    }
    double ans = 0;
    ll positiveRequired = s1Positive - s2Positive;
    ll negativeRequired = s1Negative - s2Negative;
    // cout<<"positive required: "<<positiveRequired<<" negativeRequired : "<<negativeRequired<<endl;
    if(positiveRequired + negativeRequired != questionMark || positiveRequired < 0 || negativeRequired < 0){
        doublePrecise(ans,12);
        // cout<<ans<<endl;
        // cout<<"hello"<<endl;
        return 0;
    }

    ll quesFact = fact(questionMark);
    long double val = (quesFact /(double) (fact(positiveRequired) * fact(negativeRequired)));
    long double finalAns = val / pow(2,questionMark);
    doublePrecise(finalAns,12);
    // cout<<finalAns<<endl;
    return 0;
}