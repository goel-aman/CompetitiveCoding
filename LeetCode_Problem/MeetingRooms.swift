// 252. Meeting Rooms
// Given an array of meeting time intervals where 
// intervals[i] = [starti, endi], determine if a 
// person could attend all meetings.

// Example 1:
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: false

// Example 2:
// Input: intervals = [[7,10],[2,4]]
// Output: true
 
// Constraints:
// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti < endi <= 106

class Solution {
    func canAttendMeetings(_ intervals: [[Int]]) -> Bool {
        var interval = intervals.sorted() { (lhs: [Int], rhs: [Int]) -> Bool in 
                                           return lhs[0] < rhs[0]
        }
        var ans = true
        var length = interval.count
        if(length == 0){
            return true
        }
        for i in 1 ..< length {
            var start = interval[i][0]
            var end = interval[i][1]
            var prevStart = interval[i - 1][0]
            var prevEnd = interval[i - 1][1]
            
            if((start >= prevStart && start < prevEnd)){
                return false
            }
        }
        return ans
    }
}