#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[2 * n];
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
        }

        sort(arr, arr + 2 * n);
        int start = 0;
        int end = (2 * n) - 1;
        while(start <= end){
            if(start == end){
                cout<<arr[start]<<" ";
                break;
            }

            cout<<arr[start]<<" ";
            start++;
            cout<<arr[end]<<" ";
            end--;
        }
        cout<<endl;
    }
}