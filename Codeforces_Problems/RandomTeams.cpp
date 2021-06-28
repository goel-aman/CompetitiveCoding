#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    ll participants,teams;
    cin>>participants>>teams;
    

    if(participants <= teams){
        cout<<"0 0"<<endl;
        return 0;
    }

    
    // lets calculate min first
    ll leftOut = participants % teams;
    ll everyone = participants / teams;

    ll minimumAnswer = 0;
    minimumAnswer = minimumAnswer +  ((everyone * (everyone + 1))/2) * leftOut;
    minimumAnswer = minimumAnswer + (teams - leftOut) * (((everyone) * (everyone - 1))/2);
    ll maxAnswer = (participants - teams);
    ll answer = (((maxAnswer + 1)* (maxAnswer)) /2);
    cout<<minimumAnswer<<" "<<answer<<endl;
    return 0;
}
