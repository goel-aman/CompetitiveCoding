// LShaped
// Problem
// Given a grid of R rows and C columns each cell in the grid is either 0 or 1.

// A segment is a nonempty sequence of consecutive cells such that all cells are in
//  the same row or the same column. We define the length of a segment as number of
//  cells in the sequence.

// A segment is called "good" if all the cells in the segment contain only 1s.
// An "L-shape" is defined as an unordered pair of segments, which has all the following properties:

// Each of the segments must be a "good" segment.
// The two segments must be perpendicular to each other.
// The segments must share one cell that is an endpoint of both segments.
// Segments must have length at least 2.
// The length of the longer segment is twice the length of the shorter segment.
// We need to count the number of L-shapes in the grid.

// Below you can find two examples of correct L-shapes,

// Examples of valid L-shapes.
// and three examples of invalid L-shapes.

// Examples of invalid L-shapes.
// Note that in the shape on the left, two segments do not share a common endpoint.
//  The next two shapes do not meet the last requirement, as in the middle shape 
// both segments have the same length, and in the last shape the longer segment is
//  longer than twice the length of the shorter one.

// Input
// The first line of the input contains the number of test cases, T. T test cases follow.
// The first line of each testcase contains two integers R and C.
// Then, R lines follow, each line with C integers representing the cells of the grid.

// Output
// For each test case, output one line containing Case #x: y, where x is the test case 
// number (starting from 1) and y is the number of L-shapes.

// Limits
// Time limit: 60 seconds.
// Memory limit: 1 GB.
// 1≤T≤100.
// Grid consists of 0s and 1s only.
// Test Set 1
// 1≤R≤40.
// 1≤C≤40.
// Test Set 2
// 1≤R≤1000 and 1≤C≤1000 for at most 5 test cases.
// For the remaining cases, 1≤R≤40 and 1≤C≤40.
// Sample
// Sample Input
// save_alt
// content_copy
// 2
// 4 3
// 1 0 0
// 1 0 1
// 1 0 0
// 1 1 0
// 6 4
// 1 0 0 0
// 1 0 0 1
// 1 1 1 1
// 1 0 1 0
// 1 0 1 0
// 1 1 1 0
// Sample Output

// Case #1: 1
// Case #2: 9
// In Sample Case #1, there is one L-shape.

// The first one is formed by using cells: (1,1), (2,1), (3,1), (4,1), (4,2)
// Visualization for the first sample case, showing one L-shape.
// In Sample Case #2, there are nine L-shapes.

// The first one is formed by using cells: (1,1), (2,1), (3,1), (4,1), (5,1), (6,1), (6,2), (6,3)
// The second one is formed by using cells: (3,1), (4,1), (5,1), (6,1), (6,2)
// The third one is formed by using cells: (6,1), (5,1), (4,1), (3,1), (3,2)
// The fourth one is formed by using cells: (3,3), (4,3), (5,3), (6,3), (6,2)
// The fifth one is formed by using cells: (6,3), (5,3), (4,3), (3,3), (3,2)
// The sixth one is formed by using cells: (3,1), (3,2), (3,3), (3,4), (2,4)
// The seventh one is formed by using cells: (3,4), (3,3), (3,2), (3,1), (2,1)
// The eighth one is formed by using cells: (3,4), (3,3), (3,2), (3,1), (4,1)
// The ninth one is formed by using cells: (6,3), (5,3), (4,3), (3,3), (3,4)
// The first three L-shapes are shown on the picture below.



#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class elem{
    public:
    ll vertical;
    ll bottom;
    ll lefthorizontal;
    ll righthorizontal;
};

int main(){
    ll t;
    cin>>t;
    
    ll w = 1;
    while(t--){
        ll r,c;
        cin>>r>>c;
        // cout<<"r is : "<<r<<" col is : "<<c<<endl;
        ll matrix[r][c];
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                ll value;
                cin>>value;
                matrix[i][j] = value;
            }
        }
        // cout<<"hello world"<<endl;
        
        elem matrixx[r][c];
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                if(matrix[i][j] != 1){
                    matrixx[i][j].lefthorizontal = 0;
                    continue;
                }
                
                if(j == 0 && matrix[i][j] == 1){
                    matrixx[i][j].lefthorizontal = 1;
                    continue;
                }
                
                if(matrix[i][j] == 1){
                    matrixx[i][j].lefthorizontal = 1;
                    if(matrix[i][j - 1] == 1){
                        matrixx[i][j].lefthorizontal = matrixx[i][j - 1].lefthorizontal + 1;
                    }                    
                }
            }
            
            for(ll j = c - 1;j >= 0;j--){
                if(matrix[i][j] != 1){
                    matrixx[i][j].righthorizontal = 0;
                    continue;
                }
                
                if(j == c - 1 && matrix[i][j] == 1){
                    matrixx[i][j].righthorizontal = 1;
                    continue;
                }
                
                if(matrix[i][j] == 1){
                    matrixx[i][j].righthorizontal = 1;
                    if(matrix[i][j + 1] == 1){
                        matrixx[i][j].righthorizontal = matrixx[i][j +1].righthorizontal + 1;
                    }
                }
            }
        }
        
        for(ll i=0;i<c;i++){
            for(ll j=0;j<r;j++){
                if(matrix[j][i] != 1){
                    matrixx[j][i].vertical = 0;
                    continue;
                }
                
                if(j == 0 && matrix[j][i] == 1){
                    matrixx[j][i].vertical = 1;
                    continue;
                }
                
                if(matrix[j][i] == 1){
                    matrixx[j][i].vertical = 1;
                    if(matrix[j - 1][i] == 1){
                        matrixx[j][i].vertical = matrixx[j - 1][i].vertical + 1;
                    }
                }
            }
            
            for(ll j=r - 1;j>=0;j--){
                if(matrix[j][i] != 1){
                    matrixx[j][i].bottom = 0;
                    continue;
                }
                
                if(j == r-1 && matrix[j][i] == 1){
                    matrixx[j][i].bottom = 1;
                    continue;
                }
                
                if(matrix[j][i] == 1){
                    matrixx[j][i].bottom = 1;
                    if(matrix[j + 1][i] == 1){
                        matrixx[j][i].bottom = matrixx[j + 1][i].bottom + 1;
                    }
                }
            }
        }
        
        ll ans = 0;
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                ll rightdis = matrixx[i][j].righthorizontal;
                ll top = matrixx[i][j].vertical;
                ll leftdis = matrixx[i][j].lefthorizontal;
                ll bottomdis = matrixx[i][j].bottom;

                ll mini = rightdis;
                for(ll m = 2;m <= mini;m++){
                    if(2*m <= top){
                        ans++;
                    }
                }

                
                mini = leftdis;
                for(ll m = 2;m<=mini;m++){
                    if(2*m <= top){
                        ans++;
                    }
                }
                
                
                
                mini = rightdis;
                for(ll m = 2;m<= mini;m++){
                    if(2*m <= bottomdis){
                        ans++;
                    }
                }
                
                
                mini = leftdis;
                for(ll m =2;m<=mini;m++){
                    if(2*m <= bottomdis){
                        ans++;
                    }
                }
                
                
                mini = top;
                for(ll m = 2;m<=mini;m++){
                    if(2*m <= rightdis){
                        ans++;
                    }
                }
                
                mini =top;
                for(ll m = 2;m<=mini;m++){
                    if(2*m <= leftdis){
                        ans++;
                    }
                }
                
                
                mini = bottomdis;
                for(ll m=2;m<=bottomdis;m++){
                    if(2*m <= rightdis){
                        ans++;
                    }
                }
                
                
                
                mini = bottomdis;
                for(ll m=2;m<=bottomdis;m++){
                    if(2*m <= leftdis)
                    {
                        ans++;
                    }
                }
                
            }
        }
        
        cout<<"Case #"<<w<<": "<<ans<<endl;
        w++;
    }
}