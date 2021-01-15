#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define doubleprec(x,y) cout<<fixed<<setprecision(y)<<x

// Recursive function to return gcd of a and b 
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s,tt;
        cin>>s>>tt;
        ll slength = s.length();
        ll ttlength = tt.length();
        ll lcmValue = lcm(slength,ttlength);
        int firstval = lcmValue / slength;
        int secondVal = lcmValue / ttlength;
        string sFinal = "",ttFinal = "";
        for(int i = 0;i<firstval;i++){
            sFinal += s;
        }
        for(int i=0;i<secondVal;i++){
            ttFinal += tt;
        }
        if(sFinal == ttFinal){
            cout<<sFinal<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}