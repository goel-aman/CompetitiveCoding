#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// B. Queries about less or equal elements

int main(){
    ll first,second;
    cin>>first>>second;
    vector<int> firstArray,secondArray;
    for(int i=0;i<first;i++){
        ll number;
        cin>>number;
        firstArray.push_back(number);
    }

    sort(firstArray.begin(),firstArray.end());

    for(int j=0;j<second;j++){
        ll number;
        cin>>number;
        auto it = upper_bound(firstArray.begin(),firstArray.end(),number);
        int index = it - firstArray.begin();
        cout<<index<<" ";
    }
    return 0;
}