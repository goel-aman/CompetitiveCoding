#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    bool isEight = false;
    for(int i=0;i<s.length();i++){
        if(s[i] =='8'){
            isEight = true;
        }
        if(s[i] == '0'){
            cout<<"YES"<<endl;
            cout<<"0"<<endl;
            return 0;
        }
    }

    if(isEight){
        cout<<"YES"<<endl;
        cout<<"8"<<endl;
        return 0;
    }

    

    for(int i=0;i<s.length();i++){
        for(int j=i + 1;j<s.length();j++){
            string temp = "";
            temp += s[i];
            temp += s[j];
            int vau = stoi(temp);
            if(vau%8 == 0){
                cout<<"YES"<<endl;
                cout<<vau<<endl;
                return 0;
            }
            for(int k=j + 1;k<s.length();k++){
                string newS = "";
                newS += s[i];
                newS += s[j];
                newS += s[k];
                // cout<<"newS is :"<<newS<<endl;
                int val = stoi(newS);
                
                if(val%8 == 0){
                    cout<<"YES"<<endl;
                    cout<<newS<<endl;
                    return 0;
                }
            }
            
        }
    }
    cout<<"NO"<<endl;
    return 0;
}