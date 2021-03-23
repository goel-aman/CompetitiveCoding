#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v{{0,0},{0,1},{0,2}};
    vector<int> res = {-1,0};
    for(int i=0;i<=2;i++){
        res = max(res,v[i]);
    }
    cout<<res[1]<<endl;
    return 0;
}