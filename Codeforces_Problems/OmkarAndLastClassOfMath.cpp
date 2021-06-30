#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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

    
    ll n;
    cin>>n;
    ll temp = n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            temp = i;
            break;
        }
    }

    cout<<n/temp<<" "<<n - (n / temp)<<endl;
    }
    return 0;
}