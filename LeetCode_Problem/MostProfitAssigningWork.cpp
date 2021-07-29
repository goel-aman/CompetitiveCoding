#include<bits/stdc++.h>
using namespace std;

// 826. Most Profit Assigning Work
// You have n jobs and m workers. You are given 
// three arrays: difficulty, profit, and worker where:
// difficulty[i] and profit[i] are the difficulty and 
// the profit of the ith job, and
// worker[j] is the ability of jth worker (i.e., the jth 
// worker can only complete a job with difficulty at most
//  worker[j]).
// Every worker can be assigned at most one job, but one 
// job can be completed multiple times.

// For example, if three workers attempt the same job that
//  pays $1, then the total profit will be $3. If a worker
//  cannot complete any job, their profit is $0.
// Return the maximum profit we can achieve after assigning
//  the workers to the jobs.

// Example 1:
// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50],
//  worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6]
//  and they get a profit of [20,20,30,30] separately.

// Example 2:
// Input: difficulty = [85,47,57], profit = [24,66,99],
//  worker = [40,25,25]
// Output: 0
 
// Constraints:
// n == difficulty.length
// n == profit.length
// m == worker.length
// 1 <= n, m <= 104
// 1 <= difficulty[i], profit[i], worker[i] <= 105



class maxWeCan{
    public:
    int difficulty;
    int profit;
    int maxProfitTillNow;
};

bool compare(maxWeCan& a,maxWeCan &b){
    if(a.difficulty < b.difficulty){
        return true;
    }

    if(a.difficulty == b.difficulty){
        if(a.profit >  b.profit)
        {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<maxWeCan> vec;
        int finalAns = 0;
        int profitLength = profit.size();
        for(int i=0;i<profitLength;i++){
            vec.push_back({difficulty[i],profit[i],0});
        }
        sort(vec.begin(),vec.end(),compare);

        vec[0].maxProfitTillNow = vec[0].profit;
        for(int i=1;i<profitLength;i++){
            vec[i].maxProfitTillNow = max(vec[i - 1].maxProfitTillNow,vec[i].profit);
        }
        int workerLength = worker.size();
        for(int i=0;i<workerLength;i++){
            int ans = -1;
            int start = 0 , end = workerLength - 1;
            while(start <= end){
                int mid = (start + end)/2;
                if(vec[mid].difficulty <= worker[i]){
                    ans = mid;
                    start = mid + 1;
                    continue;
                }    

                if(vec[mid].difficulty > worker[i]){
                    end = mid - 1;
                    continue;
                }
            }

            if(ans != -1){
                finalAns += vec[ans].maxProfitTillNow;
            }
        }
        return finalAns;
    }
};