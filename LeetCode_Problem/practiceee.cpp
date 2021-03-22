#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> first = {3,4,5};
    vector<int> second = {9,8,4};
    vector<int> res = {2,1,5};
    res = min(first,res);
    res = min(second,res);
    cout<<res[0]<<endl;
}