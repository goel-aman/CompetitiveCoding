#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printDoublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

// if output is one taro will win the game 
// if output is zero then jiro will win the game
// if chance is 1 it means,now taro will play the game.
bool game(int *arr,int n,int k,bool chance,int mini)
{
    if(k == 0){
        return (chance == true)? false : true;
    }

    if(k < mini){
        return (chance == true)? false: true;
    }

    bool k = true;
    for(int i=0;i<n;i++){
        bool y = game(arr,n,k - arr[i],(!chance),mini);

    }



}
int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int arr[n];
    int mini = INT_MAX;
    for(int i=0;i<n;i++) { 
        cin>>arr[i];
        if(arr[i]< mini){
            mini = arr[i];
        }
    }
    bool chance = true;
    bool x = game(arr,n,k,chance,mini);
    if(x == 1){// taro will win 
        cout<<"First"<<endl;
    }
    else{// jiro will
        cout<<"Second"<<endl;
    }
    return 0;
}