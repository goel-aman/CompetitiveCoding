#include<bits/stdc++.h>
using namespace std;

int atMostNGivenDigitSet(vector<string>& digits, int n) {
    for(auto s: digits){
        cout<<s<<endl;
    }
    return 0;
}

int main()
{
    int number_of_digits;
    cin>>number_of_digits;
    vector<string> digits;
    for(int i=0;i<number_of_digits;i++){
        string s;
        cin>>s;
        digits.push_back(s);
    }
}