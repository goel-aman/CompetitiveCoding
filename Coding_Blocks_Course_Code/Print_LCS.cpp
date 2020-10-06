#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> ma;

string lcs(string s1,string s2){
    if(s1.length() == 0 || s2.length() == 0){
        string m = "";
        return m;
    }
    
    string umk = s1 + ";;" + s2;
    if(ma.count(umk) > 0){
        return ma[umk];
    }

    string ans;
    if(s1[0] == s2[0]){
        ans.push_back(s1[0]);
        string s = lcs(s1.substr(1),s2.substr(1));
        ans+= s;
        ma[umk] = ans;
        return ans;
    }

    string s_one = lcs(s1,s2.substr(1));
    string s_two = lcs(s1.substr(1),s2);
    if(s_one.length() > s_two.length()){
        return s_one;
        ma[umk] = s_one;
    }
    ma[umk] = s_two;
    return s_two;
}


int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2)<<endl;
	return 0;
}