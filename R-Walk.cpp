#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
#define prDouble(x,y) cout<< fixed << setprecision(y) << x
#define mod 1000000007

vector<vector<long long int>> multiply(vector<vector<long long int>> mat1,vector<vector<long long int>> mat2){
    vector<vector<long long int>> ans; 
    ll n = mat1.size();
    for(ll i=0;i<n;i++){
        vector<long long int> vm;
        for(ll j=0;j<n;j++){
            ll value = 0;
            for(ll k=0;k<n;k++){
                value += (mat1[i][k] * mat2[k][j]);
                value = value % mod;
            }
            vm.push_back(value);
        }
        ans.push_back(vm);
    }
    return ans;
}


vector<vector<long long int>> exponentiation(ll power, vector<vector<long long int>> mat){
    if(power == 1){
        return mat;
    }

    vector<vector<long long int>> a = exponentiation(power/2, mat);

    if(power % 2 == 0){
        return multiply(a,a);
    }
    
    return multiply(mat,multiply(a,a));
}



int main(){
    ll n;
    cin>>n;
    ll k;
    cin>>k;
    vector<vector<long long int>> v;
    for(ll i=0;i<n;i++){
        vector<long long int> vv;
        for(ll j=0;j<n;j++){
            ll num;
            cin>>num;
            vv.push_back(num);
        }
        v.push_back(vv);
    }

    ll summ = 0;
    vector<vector<long long int>> ans = exponentiation(k,v);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            summ = (summ + ans[i][j]) % mod;
        }
    }
    cout<<summ<<endl;
    return 0;
}