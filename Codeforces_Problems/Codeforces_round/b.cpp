#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll tempa, tempb;
        tempa = a;
        tempb = b;
        ll tempn = n;
        ll sub = a - x;
        if(sub >= n){
            a = a - n;
            n = 0;
        }
        else{
            a = x;
            n = n - sub;
        }
///////////////////////////////////////
        sub = b - y;
        if(sub >= n){
            b = b - n;
            n = 0;
        }
        else{
            b = y;
            n = n - sub;
        }

        ll ans1 = a * b;
        // cout<<"ans1 is : "<<ans1<<endl;
/////////////////////////////////////////////////////////////////////////////////
        ll tempsub = tempb - y;
        if(tempsub >= tempn){
            tempb = tempb - tempn;
            tempn = 0;
        }
        else{
            tempb = y;
            tempn = tempn - tempsub;
        }
        // cout<<"tempn is : "<<tempn<<endl;
        // cout<<"tempb is : "<<tempb<<endl;
        // cout<<"tempsub is : "<<tempsub<<endl;
        tempsub = tempa - x;
        if(tempsub >= tempn){
            tempa = tempa - tempn;
            tempn = 0;
        }
        else{
            tempa = x;
            tempn = tempn - tempsub;
        }
///////////////////////////////////////
        

        ll ans2 = tempa * tempb;
        // cout<<"ans2 is : "<<ans2<<endl;
        
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}