#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
    vector<string> vec;
    for(int i=0;i<9;i++){
        string s;
        cin>>s;
        vec.push_back(s);
    }


    vec[0][0] = vec[0][1];
    vec[1][3] = vec[1][2];
    vec[2][6] = vec[2][5];
    vec[3][1] = vec[3][0];
    vec[4][4] = vec[4][3];
    vec[5][7] = vec[5][6];
    vec[6][2] = vec[6][1];
    vec[7][5] = vec[7][4];
    vec[8][8] = vec[8][7];
    for(int i=0;i<9;i++){
        cout<<vec[i]<<endl;
    }
    }
    return 0;
}