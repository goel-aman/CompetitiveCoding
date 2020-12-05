#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        set<int> s1;
        set<int> s2;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            s1.insert(num);
        }
        for(int i=0;i<m;i++){
            int num;
            cin>>num;
            s2.insert(num);
        }
        set<int> intersect;
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                  std::inserter(intersect,intersect.begin()));
        cout<<intersect.size()<<endl;

    }
    return 0;
}