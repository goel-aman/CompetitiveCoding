#include<bits/stdc++.h>
using namespace std;

// 1626. Best Team With No Conflicts

// You are the manager of a basketball team. For the upcoming 
// tournament, you want to choose the team with the highest 
// overall score. The score of the team is the sum of scores
//  of all the players in the team.

// However, the basketball team is not allowed to have conflicts.
//  A conflict exists if a younger player has a strictly higher
//  score than an older player. A conflict does not occur
//  between players of the same age.

// Given two lists, scores and ages, where each scores[i] and
//  ages[i] represents the score and age of the ith player, 
// respectively, return the highest overall score of all 
// possible basketball teams.

// Example 1:
// Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
// Output: 34
// Explanation: You can choose all the players.

// Example 2:
// Input: scores = [4,5,6,5], ages = [2,1,2,1]
// Output: 16
// Explanation: It is best to choose the last 3 players. Notice
//  that you are allowed to choose multiple people of the same age.

// Example 3:
// Input: scores = [1,2,3,5], ages = [8,9,10,1]
// Output: 6
// Explanation: It is best to choose the first 3 players. 
 
// Constraints:
// 1 <= scores.length, ages.length <= 1000
// scores.length == ages.length
// 1 <= scores[i] <= 106
// 1 <= ages[i] <= 1000

class element{
    public:
    int score;
    int age;
};

bool compare(element& a,element& b){
    if(a.age < b.age){
        return true;
    }
    
    if(a.age == b.age){
        if(a.score < b.score){
            return true;
        }
    }

    return false;
}

class Solution {
    int agesLength;
    int dp[1001];
public:
    int solve(int index,vector<element>& vec){
        if(index == agesLength)
        {
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int ans = 0;
        for(int i=index + 1;i<agesLength;i++){
            if((vec[i].age > vec[index].age && vec[i].score >= vec[index].score) || (vec[i].age == vec[index].age)){
                ans = max(ans,solve(i,vec));
            }
        }

        return dp[index] = (ans + vec[index].score);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        agesLength = ages.size();
        vector<element> vec(agesLength);
        for(int i=0;i<agesLength;i++){
            vec[i].age = ages[i];
            vec[i].score = scores[i];
        }
        memset(dp,-1,sizeof(dp));
        sort(vec.begin(),vec.end(),compare);
        int ans = 0;
        for(int i=0;i<agesLength;i++){
            ans = max(ans,solve(i,vec));
        }
        return ans;
    }
};