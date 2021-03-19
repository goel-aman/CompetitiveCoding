#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k1,k2;
        cin>>n>>k1>>k2;
        ll w,b;
        cin>>w>>b;
        if((2*w + 2 *b) > (2 * n)){
            cout<<"NO"<<endl;
            continue;
        }

        if(k1%2 == 0 && k2%2 == 0){
            if( ((2 * w) == (k1 + k2) )  && (2 * b) == (n + n - k1 - k2) ){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;
        }

        ll totalwhite = 0;
        if(k1%2 == 0){
            totalwhite += k1/2;
        }
        else{
            if(k1 > 0){
                totalwhite = totalwhite + ( (k1 - 1 )/ 2);
            }
        }

        if(k2%2 == 0){
            totalwhite += k2 / 2;
        }else{
            if(k2 > 0){
                totalwhite = totalwhite + ((k2 - 1) / 2);
            }
        }

        ll totalblack = 0;
        ll n1 = n - k1;
        ll n2 = n - k2;
        if(n1%2 == 0){
            totalblack += n1 / 2;
        }else{
            if(n1 > 0){
                totalblack = totalblack + ((n1 - 1) / 2);
            }
        }

        if(n2%2 == 0){
            totalblack += n2/ 2;
        }else{
            if(n2 > 0){
                totalblack = totalblack + ((n2 - 1) / 2);
            }
        }
        if(n1%2 != 0 && n2%2 != 0){
            totalblack++;
        }
        if(k2%2 != 0 && k1%2 != 0){
            totalwhite++;
        }

        if(w <= totalwhite && b <= totalblack){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}