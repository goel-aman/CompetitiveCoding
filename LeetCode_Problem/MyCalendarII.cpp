#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
    map<int,int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int booking = 0;
        for(auto it : m){
            booking += it.second;
            if(booking == 3){
                m[start]--;
                m[end]++;
                return false;
            } 
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */