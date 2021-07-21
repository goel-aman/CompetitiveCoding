#include<bits/stdc++.h>
using namespace std;

// 838. Push Dominoes
// There are n dominoes in a line, and we place each domino vertically upright.
// In the beginning, we simultaneously push some of the dominoes either to the
//  left or to the right.
// After each second, each domino that is falling to the left pushes the adjacent
//  domino on the left. Similarly, the dominoes falling to the right push their 
// adjacent dominoes standing on the right.
// When a vertical domino has dominoes falling on it from both sides, it stays 
// still due to the balance of the forces.
// For the purposes of this question, we will consider that a falling domino 
// expends no additional force to a falling or already fallen domino.

// You are given a string dominoes representing the initial state where:
// dominoes[i] = 'L', if the ith domino has been pushed to the left,
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and
// dominoes[i] = '.', if the ith domino has not been pushed.
// Return a string representing the final state.

// Example 1:
// Input: dominoes = "RR.L"
// Output: "RR.L"
// Explanation: The first domino expends no additional force on the second domino.

// Example 2:
// Input: dominoes = ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."
 
// Constraints:
// n == dominoes.length
// 1 <= n <= 105
// dominoes[i] is either 'L', 'R', or '.'.

class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> que;
        int dominoesLength = dominoes.length();
        for(int i=0;i<dominoesLength;i++){
            if(dominoes[i] == 'L' || dominoes[i] == 'R'){
                que.push(i);
            }
        }      
        string prev = dominoes;
        while(!que.empty()){
            int siz = que.size();
            string changes = prev;
            string current = prev;
            while(siz--){
                int front = que.front();
                que.pop();    
                if(current[front] == 'L'){
                    if( front - 1 >= 0 &&  current[front - 1] == '.'){
                        if(front - 2 < 0){
                            changes[front - 1] = 'L';
                            continue;
                        }

                        if(front-2 >= 0 && (current[front-2] == '.' || current[front-2] == 'L')){
                            changes[front - 1] = 'L';
                            que.push(front - 1);
                        }

                    }
                    continue;
                }

                if(current[front] == 'R')
                {
                    if(front + 1 < dominoesLength && current[front + 1] == '.'){
                        if(front + 2 >= dominoesLength){
                            changes[front + 1] = 'R';
                            continue;
                        }

                        if(front + 2 < dominoesLength && (current[front +2] == '.' || current[front + 2] == 'R')){
                            changes[front + 1] = 'R';
                            que.push(front + 1);
                        }
                    }
                    continue;
                }
            }
            prev = changes;
        }
        return prev;
    }
};