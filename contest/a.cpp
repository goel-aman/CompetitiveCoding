#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
#define ll long long int


int main() {
    ll n;
    cin>>n;
    int rem = n%4;
    if(rem == 3){
        cout<<"even"<<endl;
    }
    if(rem == 2){
        ll num = n + 1;
        if(num%2 == 0){
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
    }

    if(rem == 0){
        if(n%2 == 0){
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
        // cout<<n<<endl;
    }
    if(rem == 1){
        cout<<"odd"<<endl;
        // cout<<1<<endl;
    }
	// Your code here
	return 0;
}
