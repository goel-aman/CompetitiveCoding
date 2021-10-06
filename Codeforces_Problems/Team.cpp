#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n,m;
    cin>>n>>m;
    // n -> 0 && m -> 1
    if(m > 2 *(n + 1)){
        cout<<-1<<endl;
        return 0;
    }

    if(m + 1 < n){
        cout<<-1<<endl;
        return 0;
    }

    if(abs(n - m) == 1){
        int pre = -1;
        if(n > m){
            cout<<0;
            n -= 1;
            pre = 0;
        }
        if(m > n){
            cout<<1;
            m -= 1;
            pre = 1;
        }
        
        for(int i=0;i<2 * n;i++){
            pre = !pre;
            cout<<pre;
        }
        return 0;
    }

    while(m > n && m > 1 && n != 0){
        cout<<"11";
        cout<<"0";
        m -= 2;
        n -= 1;
    }
    if(m == 1 && n == 0){
        cout<<1;
        m -= 1;
        return 0;
    } 

    if(m == 2 && n == 0){
        cout<<"11";
        m -= 2;
        return 0;
    } 

    if(m >= 1){
        cout<<"1";
        m -= 1;
    }

    if(n >= m){
        int temp = n;
        for(int i=0;i<temp;i++){
            if(n > 0){
                cout<<0;
            }
            if(m > 0){
                cout<<1;
            }
            n -= 1;
            m -= 1;
        }
        return 0;
    }
}