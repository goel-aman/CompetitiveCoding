#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin>>n;
    int a[n];
    
    int evenCount = 0;
    int oddCount = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2 == 0){
            evenCount++;
        }else{
            oddCount++;
        }
    }
    if(evenCount > oddCount){
        int i=0;
        for(;i<n;i++){
            if(a[i]%2 != 0){
                break;
            }
        }
        cout<<i + 1<<endl;
    }else{
        int i=0;
        for(;i<n;i++){
            if(a[i]%2 == 0){
                break;
            }
        }
        cout<<i + 1<<endl;
    }
    return 0;
}