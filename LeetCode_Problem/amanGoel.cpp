#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    vector<char> vec(26,0);
    for(int i=0;i<s.length();i++){
        int value = s[i] - 'a';
        vec[value]++;
    }
    unordered_set<char> us;
    for(int i=0;i<26;i++){
        if(vec[i] == 1){
            char element = 'a' + i;
            us.insert(element);
        }
    }
    char ans = '0';
    for(int i=s.length()-1;is.length();i++){
        if(us.count(s[i])){
            ans = s[i];
            break;
        }
    }
    if(ans == '0'){
        cout<<"answer doesn't exist"<<endl;
        return 0;
    }

    cout<<"ans is : "<<ans<<endl;
    return 0;
}