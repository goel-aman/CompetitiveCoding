#include<iostream>
#include<vector>
using namespace std;
#define ll long long int


int main(){
    ll n;
    cin>>n;
    ll heights[n];
    for(ll i=0;i<n;i++){
        cin>>heights[i];
    }

    ll answer_array[n] = {0};
    answer_array[0] = 0;
    answer_array[1] = abs(heights[1] - heights[0]);
    for(ll i=2;i<n;i++){
        answer_array[i] = min(answer_array[i-1] + abs(heights[i] - heights[i-1]),answer_array[i-2] +abs(heights[i] - heights[i-2]));
    }
    cout<<answer_array[n-1]<<endl;
}


// Time Complexity   O(n)

// space complexity  O(n)