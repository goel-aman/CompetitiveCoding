#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// Omkar and Baseball

int main(){
   ll t;
   cin>>t;
   while(t--){
       ll n;
       cin>>n;
       ll arr[n];
       vector<ll> streak;
       ll correctPosition = 0;
       ll correctStreak = 0,wrongStreak = 0;
       for(ll i=0;i<n;i++){
           cin>>arr[i];
           if(arr[i] == i + 1){
               correctPosition++;
               if(wrongStreak != 0){
                   streak.push_back(0);
                   wrongStreak = 0;
               }
               correctStreak++;
           }else{
               if(correctStreak != 0){
                   streak.push_back(1);
                   correctStreak = 0;
               }
               wrongStreak++;
           }
       }
       if(wrongStreak > 0){
           streak.push_back(0);
       }

       if(correctStreak > 0){
           streak.push_back(1);
       }

        if(streak.size() == 2){
            cout<<1<<endl;
            continue;
        }

        if(streak.size() == 3 && streak[0] == 1 && streak[1] == 0 && streak[2] == 1){
            cout<<1<<endl;
            continue;
        }

        if(correctPosition == n){
            cout<<0<<endl;
            continue;
        }

        if(correctPosition == 0){
            cout<<1<<endl;
            continue;
        }

        cout<<2<<endl;
   } 
}