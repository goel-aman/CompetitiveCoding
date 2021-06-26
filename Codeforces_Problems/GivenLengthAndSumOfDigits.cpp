#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// C. Given Length and Sum of Digits...

int main(){
    ll length,s;
    cin>>length>>s;

    if(length == 1 && s == 0){
        cout<<"0 0";
        return 0;
    }

    // corner case 
    if(s > 9 * length || s == 0){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    int tempSum = s;
    // lets find the largest Number.
    string largest;
    for(int i=0;i<length;i++)
    {
        if(s >= 9){
            largest.push_back('9');
            s -= 9;
        }else{
            largest.push_back(s + '0');
            s -= s;
        }
    }
    vector<char> vec(length,'0');
    // lets find the smallest Number;
    vec[0] = '1';
    tempSum -= 1;
    for(int i=length - 1;i>=0;i--){
        if(tempSum > 0){
            if(tempSum >= 9){
                vec[i] = '9';
                tempSum -= 9;
                continue;
            }else{
                vec[i] += tempSum;
                tempSum -= tempSum;
            }
        }else{
            break;
        }
    }
    
    for(int i=0;i<length;i++){
        cout<<vec[i];
    }
    cout<<" "<<largest;
    cout<<endl;
    return 0;
}