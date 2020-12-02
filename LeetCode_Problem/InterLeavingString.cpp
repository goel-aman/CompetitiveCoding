#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string,bool> um;
public:
    bool isInterleave(string s1, string s2, string s3) {
        string ss = s1 + ";" + s2 + ";" + s3;
        int s1length = s1.length();
        cout<<"s1 length is : "<<s1length<<endl;
        int s2length = s2.length();
        cout<<"s2 length is : "<<s2length<<endl;
        int s3length = s3.length();
        cout<<"s3 length is : "<<s3length<<endl;
        if(s1length == 0 && s2length == 0 && s3length == 0){
            return true;
        }
        
        if(s1length + s2length != s3length){
            return false;
        }
            
        if(s1length == 0 && s2length != 0 && s3length != 0){
            if(s2 == s3){
                return true;
            }
            return false;
        }
         
        if(s1length != 0 && s2length == 0 && s3length != 0){
            if(s1 == s3){
                return true;
            }
            return false;
        }
        
        if(um.count(ss) > 0){
            return um[ss];
        }
        
        bool ans1 = false;
        bool ans2 = false;
        
        if(s1[0] == s3[0]){
            ans1 = isInterleave(s1.substr(1),s2,s3.substr(1));
        }
        cout<<"ans1 is : "<<ans1<<endl;
        if(s2[0] == s3[0]){
            cout<<"h1"<<endl;
            ans2 = isInterleave(s1,s2.substr(1),s3.substr(1));
        }
        cout<<"ans2 is : "<<ans2<<endl;
        cout<<"started"<<endl;
        cout<<"S1 is : "<<s1<<" S2 is : "<<s2<<" S3 is : "<<s3<<endl;
        if(ans1 || ans2){
            cout<<"Yes Matching "<<endl;
        }
        else{
            cout<<"Not Matching "<<endl;
        }
        cout<<"Ended"<<endl;
        um[ss] = (ans1 || ans2);
        return (ans1 || ans2);
    }
};