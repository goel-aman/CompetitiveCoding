#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string n;
    cin>>n;
    int gotAnswer = 0;
    ll inputLength = n.length();
    ll lastDigit = n[inputLength - 1] - '0';
    for(int i=0;i<inputLength;i++){
        ll digit = n[i] - '0';
        if(digit%2 == 0 && digit < lastDigit){
            swap(n[i],n[inputLength - 1]);
            gotAnswer = 1;
            break;
        }
    }

    if(gotAnswer == 1){
        cout<<n<<endl;
        return 0;
    }

    for(int i=inputLength - 2;i>=0;i--){
        ll digit = n[i] - '0';
        if(digit%2 == 0){
            swap(n[i],n[inputLength - 1]);
            gotAnswer = 1;
            break;
        }
    }

    if(gotAnswer == 1){
        cout<<n<<endl;
        return 0;
    }

    cout<<-1<<endl;
    return 0;
}