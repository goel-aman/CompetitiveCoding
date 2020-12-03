

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string dp[3001][3001];
void resett(){
    for(ll i=0;i<=3000;i++){
        for(ll j=0;j<=3000;j++){
            dp[i][j] = "-";
        }
    }
}

string lcs(string s,string t){
    if( (s.length() == 0 && t.length() == 0) || (s.length() == 0 && t.length() != 0) || (s.length() != 0 && t.length() == 0)) {
        string output = "";
        dp[s.length()][t.length()] = output;
        return output;
    }

    if(dp[s.length()][t.length()] != "-"){
        return dp[s.length()][t.length()];
    }

    ll maxx = 0;
    string ret = "";
    if(s[0] == t[0]){
        string ss;
        ss.push_back(s[0]);
        string kk = lcs(s.substr(1),t.substr(1));
        string out = ss + kk;
        if(out.size() >  maxx){
            maxx = out.length();
            ret = out;
        }
    }
    else
    {
	    string second = lcs(s,t.substr(1));
	    string third = lcs(s.substr(1),t);

	    if(second.length() > maxx){
	        ret = second;
	        maxx = second.length();
	    }

	    if(third.length() > maxx){
	        ret = third;
	        maxx = third.length();
	    }
    }
    dp[s.length()][t.length()] = ret;
    return ret;
}

int main(){

    string s,t;
    cin>>s;
    cin>>t;
    resett();
    cout<<lcs(s,t)<<endl;
    resett();
    return 0;
}