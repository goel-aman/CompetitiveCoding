// 959. Regions Cut By Slashes

// In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space. 
//  These characters divide the square into contiguous regions.

// (Note that backslash characters are escaped, so a \ is represented as "\\".)

// Return the number of regions.

 

// Example 1:

// Input:
// [
//   " /",
//   "/ "
// ]
// Output: 2
// Explanation: The 2x2 grid is as follows:

// Example 2:

// Input:
// [
//   " /",
//   "  "
// ]
// Output: 1
// Explanation: The 2x2 grid is as follows:

// Example 3:

// Input:
// [
//   "\\/",
//   "/\\"
// ]
// Output: 4
// Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
// The 2x2 grid is as follows:

// Example 4:

// Input:
// [
//   "/\\",
//   "\\/"
// ]
// Output: 5
// Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
// The 2x2 grid is as follows:

// Example 5:

// Input:
// [
//   "//",
//   "/ "
// ]
// Output: 3
// Explanation: The 2x2 grid is as follows:

#include<bits/stdc++.h>
using namespace std;


class dsu{
    private:
    int * parent;

    public:
    dsu(int n){
        parent = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void unions(int x,int y){
        int xPar = findParent(x);
        int yPar = findParent(y);
        if(xPar != yPar){
            parent[xPar] = yPar;
        }
        return ;
    }

};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        dsu a(4 * n * n);
        int r = n, c = n;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int root = 4 * ((n * i) + j);
                char c = grid[i][j];
                
                if(c != '/'){
                    a.unions(root + 0,root + 2);
                    a.unions(root + 1 ,root + 3);
                }

                if(c != '\\'){
                    a.unions(root + 0,root + 1);
                    a.unions(root + 3,root + 2);
                }

                // Vertical Alignment
                if(i - 1 >= 0){
                    a.unions(root - (4 * n) + 3,root + 0);
                }

                if(i + 1 < n){
                    a.unions(root + 3, root + (4 * n) + 0);
                }

                // Horizontal Alignment
                if(j + 1 < n){
                    a.unions(root + 2, root + 4 + 1);
                }

                if(j - 1 >= 0){
                    a.unions(root + 1,root - 4  + 2);
                }
            }
        }
        int ans = 0;
        for(int i=0;i< (4 * n * n);i++){
            if(i == a.findParent(i)){
                ans++;
            }
        }
        return ans;
    }
};