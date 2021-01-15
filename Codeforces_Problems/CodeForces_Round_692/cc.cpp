#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
class element{
    public:
    ll x;
    ll y;
};
 
bool comp(element a,element b){
    return a.x < b.x;
}
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        // first x , second y
        vector<element> vv;
        unordered_map<ll,bool> y_coordinate;
        for(int i=0;i<m;i++){
            ll x,y;cin>>x>>y;
            y_coordinate[y] = true;
            element ele;
            ele.x = x;
            ele.y = y;
            vv.push_back(ele);
        }
        ll ans = 0;
        sort(vv.begin(),vv.end(),comp);
        for(ll i=0;i<vv.size();i++){
            ll x_cor = vv[i].x;
            ll y_cor = vv[i].y;
            if(x_cor == y_cor){
                continue;
            }
            if(y_coordinate.count(x_cor) > 0){
                if(y_coordinate[x_cor] == true){
                    ans += 2;
                    y_coordinate[y_cor] = false;    
                }
                else{
                    ans += 1;
                    y_coordinate[y_cor] = false;
                    y_coordinate[x_cor] = true;
                }
            }
            else{
                ans += 1;
                y_coordinate[x_cor] = true;
                y_coordinate[y_cor] = false;
            }
        }
        if(ans ==0){
            cout<<ans<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}