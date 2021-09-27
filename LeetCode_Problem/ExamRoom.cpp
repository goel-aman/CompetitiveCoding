#include<bits/stdc++.h>
using namespace std;

// 855. Exam Room
// There is an exam room with n seats in a single
//  row labeled from 0 to n - 1.

// When a student enters the room, they must sit in the
//  seat that maximizes the distance to the closest person.
//  If there are multiple such seats, they sit in the seat
//  with the lowest number. If no one is in the room, then
//  the student sits at seat number 0.

// Design a class that simulates the mentioned exam room.
// Implement the ExamRoom class:
// ExamRoom(int n) Initializes the object of the exam room 
// with the number of the seats n.
// int seat() Returns the label of the seat at which the next
//  student will set.
// void leave(int p) Indicates that the student sitting at 
// seat p will leave the room. It is guaranteed that there 
// will be a student sitting at seat p.
 
// Example 1:
// Input
// ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
// [[10], [], [], [], [], [4], []]
// Output
// [null, 0, 9, 4, 2, null, 5]

// Explanation
// ExamRoom examRoom = new ExamRoom(10);
// examRoom.seat(); // return 0, no one is in the room, then the student sits at seat number 0.
// examRoom.seat(); // return 9, the student sits at the last seat number 9.
// examRoom.seat(); // return 4, the student sits at the last seat number 4.
// examRoom.seat(); // return 2, the student sits at the last seat number 2.
// examRoom.leave(4);
// examRoom.seat(); // return 5, the student sits at the last seat number 5.

// Constraints:
// 1 <= n <= 109
// It is guaranteed that there is a student sitting at seat p.
// At most 104 calls will be made to seat and leave.


class ExamRoom {
    set<int> s;
    int size;
    int nn;
    int turn = 0;
public:
    ExamRoom(int n) {
        size = 0;
        nn = n;
    }
    
    int seat() {
        turn++;

        if(size == 0){
            s.insert(0);
            size++;
            return 0;
        }
        // cout<<"trun is : "<<turn<<endl;
        int maximumDistance = -1;
        int finalPosition = 0;
        int i=0;
        int prev;
  
        for(auto &var : s){
            // cout<<"var is :"<<var<<endl;
            if(i == 0){
                if(var != 0){
                    prev = var;
                    int position = 0;
                    int distance = var - position - 1;
                    if(maximumDistance < distance){
                        maximumDistance = distance;
                        finalPosition = position;
                    }
                }else{
                    prev = var;
                }
                i++;
                // cout<<"prev is : "<<prev<<endl;
                continue;
            }

            int position,distance;
            int space = var - prev - 1;
            if(space%2 == 0){
                position = prev + (space/2);
            }else{
                position = prev + (space/2) + 1;
            }
            distance = min(position - prev - 1,var - position - 1);
            // cout<<"distance is : "<<distance<<endl;
            if(distance > maximumDistance){
                maximumDistance = distance;
                finalPosition = position;
            }
            prev = var;
        }
        
        if(prev != nn - 1){
            int position = nn - 1;
            int distance = position - prev - 1;
            if(distance > maximumDistance){
                maximumDistance = distance;
                finalPosition = position;
            }
        }

        s.insert(finalPosition);
        size++;
        return finalPosition;
    }
    
    void leave(int p) {
        s.erase(p);
        size--;
        return ;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */