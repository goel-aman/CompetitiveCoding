#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,x; cin>>n>>x;
        ll weights[n];
        for(int i=0;i<n;i++){
            cin>>weights[i];
        }
        sort(weights,weights + n);
        reverse(weights,weights + n);
        int start = 0, end = n - 1;
        int ans = 0;
        int isPossible = true;
        vector<int> an;
        while(start <= end){
            if(ans + weights[start] != x){
                ans = ans + weights[start];
                an.push_back(weights[start]);
                start++;
                continue;
            }

            if(ans + weights[end] != x){
                ans = ans + weights[end];
                an.push_back(weights[end]);
                end--;
                
                continue;
            }

            isPossible = false;
            break;
        }

        if(isPossible == false){
            cout<<"NO"<<endl;continue;
        }
        cout<<"YES"<<endl;
        for(auto element : an){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}