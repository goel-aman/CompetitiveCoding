#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// C. Drazil and Factorial

int main(){
    ll n;
    cin>>n;
    string number;
    cin>>number;
    string temp = "";
    for(int i=0;i<number.length();i++){
        int value = number[i] - '0';
        if(value == 4){
            temp += "22";
            temp += "3";
            continue;
        }

        if(value == 6){
            temp += "5";
            temp += "3";
            continue;
        }

        if(value == 8){
            temp += "222";
            temp += "7";
            continue;
        }

        if(value == 9){
            temp += "7";
            temp += "33";
            temp += "2";
            continue;
        }

        if(value == 0 || value == 1){
            continue;
        }
        temp.push_back(number[i]);
    }

    sort(temp.begin(),temp.end());
    reverse(temp.begin(),temp.end());
    cout<<temp<<endl;
    return 0;
}