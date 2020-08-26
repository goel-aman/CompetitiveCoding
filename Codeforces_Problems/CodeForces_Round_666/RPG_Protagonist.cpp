#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x


int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t --){
        ll pp,ff;
        cin>>pp>>ff;
        ll count_s, count_w;
        cin>>count_s>>count_w;
        ll s,w;
        cin>>s>>w;

        ll min_cc = count_s;
        ll minww = s;
        ll max_cc = count_w;
        ll maxww = w;
        if( w < s){
            min_cc = count_w;
            minww = w;
            max_cc = count_s;
            maxww = s;

        }
        ll anss = 0;
        for(ll i=0;i<=min_cc;i++){
            ll p,f;
            p = pp;
            f = ff;
            ll min_c = min_cc , max_c = max_cc,minw = minww,maxw = maxww;
            ll ans = 0;
            ll me = min((p / minw),i);
            ans += me;
            p = p -  (me * minw);
            ll mee = min(p / maxw ,max_c);
            ans += mee; 
            max_c -= mee;
            ll kk = min(f/minw,min_c - i);
            f = f - (kk * minw);
            ans += kk;
            ll kkk = min(f/maxw,max_c);
            ans += kkk;
            if(ans > anss){
                anss = ans;
            }
        }
        cout<<anss<<endl;
    }
    return 0;
}