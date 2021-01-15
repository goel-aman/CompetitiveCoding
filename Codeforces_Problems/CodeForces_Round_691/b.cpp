#include<bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<string,set<string>> um;
// set<string> s;
// next direction i have to go in
// 1 means horizontal (Change in x coordinate) and 0 means vertical (Change in y coordinate) 
set<string> solve(ll currentX,ll currentY,int direction,int stepsLeft){
    if(stepsLeft == 0){
        set<string> s;
        string ans1 = to_string(currentX) + ";" + to_string(currentY);
        s.insert(ans1);
        return s;
    }

    string generateString = to_string(currentX) + ";" + to_string(currentY) + ";" + to_string(direction) + ";" + to_string(stepsLeft);
    if(um.count(generateString) > 0)
    {
        return um[generateString];
    }
    if(direction == 1){
        set<string> s;
        set<string> s1 = solve(currentX + 1, currentY,0,stepsLeft - 1);
        set<string> s2 = solve(currentX - 1,currentY,0,stepsLeft - 1);
        set_union(s1.begin(),s1.end(),s2.begin(),
                        s2.end(), s.begin());
        um[generateString] = s;
        return s;
    }

    if(direction == 0){
        set<string> s;
        set<string> s1 = solve(currentX,currentY + 1,1,stepsLeft - 1);
        set<string> s2 = solve(currentX,currentY - 1,1,stepsLeft - 1);
        set_union(s1.begin(),s1.end(),s2.begin(),
                        s2.end(), s.begin());
        um[generateString] =s;
        return s;
    }
    set<string> sss;
    return sss;
}

int main(){
    ll t = 1;
    // cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<string> s;
        set<string> ss;
        set<string> finals;
        s = solve(0,0,1,n);
        ss = solve(0,0,0,n);
        set_union(s.begin(),s.end(),ss.begin(),ss.end(),finals.begin());
        cout<<finals.size()<<endl;
    }
    return 0;
}