#include<bits/stdc++.h>
using namespace std;

// 1792. Maximum Average Pass Ratio
// There is a school that has classes of students and each class will
//  be having a final exam. You are given a 2D integer array classes, 
// where classes[i] = [passi, totali]. You know beforehand that in the 
// ith class, there are totali total students, but only passi number of
//  students will pass the exam.

// You are also given an integer extraStudents. There are another extraStudents
//  brilliant students that are guaranteed to pass the exam of any class
//  they are assigned to. You want to assign each of the extraStudents students
//  to a class in a way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class that 
// will pass the exam divided by the total number of students of the class. The 
// average pass ratio is the sum of pass ratios of all the classes divided by the
//  number of the classes.

// Return the maximum possible average pass ratio after assigning the extraStudents
//  students. Answers within 10-5 of the actual answer will be accepted.

// Example 1:
// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The 
// average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

// Example 2:
// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485

// Constraints:
// 1 <= classes.length <= 105
// classes[i].length == 2
// 1 <= passi <= totali <= 105
// 1 <= extraStudents <= 105


class element{
    public:
    int pass;
    int total;
    double value;
    double passRatioIncrease;
};

class compare{
    public:
    bool operator()(element &first,element &second){
        if(first.passRatioIncrease < second.passRatioIncrease){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<element,vector<element>,compare> pq;
        int classesLength = classes.size();
        for(int i=0;i<classesLength;i++){
            double value = ((double) classes[i][0] / (double) classes[i][1]);
            element e;
            e.pass = classes[i][0],e.total = classes[i][1],e.value = value;
            double futureRatio = ((double) (e.pass + 1)/(double) (e.total + 1));
            double diff = futureRatio - value;
            e.passRatioIncrease = diff;
            pq.push(e);
        }

        while(extraStudents > 0){
            element front = pq.top();
            pq.pop();
            extraStudents--;
            front.pass += 1;
            front.total += 1;
            front.value = ((double) front.pass / (double) front.total);
            double futureRatio = ((double) (front.pass + 1)/(double) (front.total + 1));
            front.passRatioIncrease = futureRatio - front.value;
            pq.push(front);
        }

        double ans = 0;
        while(!pq.empty()){
            element front = pq.top();
            pq.pop();
            ans += front.value;
        }

        double ret = ((double) ans / (double) classesLength);
        return ret;
    }
};