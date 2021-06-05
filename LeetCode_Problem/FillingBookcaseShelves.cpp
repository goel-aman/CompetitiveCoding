// 1105. Filling Bookcase Shelves

// We have a sequence of books: the i-th book has thickness 
// books[i][0] and height books[i][1].

// We want to place these books in order onto bookcase shelves 
// that have total width shelf_width.

// We choose some of the books to place on this shelf (such that 
// the sum of their thickness is <= shelf_width), then build another level 
// of shelf of the bookcase so that the total height of the bookcase has increased
//  by the maximum height of the books we just put down.  We repeat this process 
// until there are no more books to place.

// Note again that at each step of the above process, the order of the books we place
//  is the same order as the given sequence of books.  For example, if we have an ordered
//  list of 5 books, we might place the first and second book onto the first shelf, the 
// third book on the second shelf, and the fourth and fifth book on the last shelf.

// Return the minimum possible height that the total bookshelf can be after placing shelves
//  in this manner.

// Example 1:
// Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
// Output: 6
// Explanation:
// The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
// Notice that book number 2 does not have to be on the first shelf.
 
// Constraints:
// 1 <= books.length <= 1000
// 1 <= books[i][0] <= shelf_width <= 1000
// 1 <= books[i][1] <= 1000

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int length;
    int width;
public:
    int solve(vector<vector<int>>& books,int widthLeft,int index,int maxx){
        if(index == length){
            return maxx;
        }

        int ans = INT_MAX,ans2 = INT_MAX;
        // take it in this interval.
        if(books[index][0] <= widthLeft){
            if(books[index][1] > maxx){
                ans =  min(ans,solve(books,widthLeft - books[index][0],index + 1,books[index][1]));
            }else{
                ans = min(ans,solve(books,widthLeft - books[index][0],index + 1,maxx));
            }
        }

        ans2 = maxx +  min(ans2,solve(books,width - books[index][0],index + 1,books[index][1]));
        return min(ans,ans2);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        length  = books.size();
        width = shelf_width;
        return solve(books,width,0,0);
    }
};