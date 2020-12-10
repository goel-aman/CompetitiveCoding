#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6};
    string ans;
    for(auto m: v){
        ans.push_back(m + '0');
    }
    cout<<ans<<endl;
    return 0;
}