#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }
        int val =(int) log10(n);
        // cout<<"value of val is : "<<val<<endl;
        int vall = pow(10,val);
        int answer = val * 9;
        // cout<<"Value of answer is : "<<answer<<endl;
        string s = to_string(n);
        int siz = s.length();
        string r;
        while(siz > 0){
            r.push_back('1');
            siz--;
        }
        ll b = stoll(r);
        int extra = n / b;
        answer += extra;
        cout<<answer<<endl;
    }
}