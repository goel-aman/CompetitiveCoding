#include<bits/stdc++.h>
using namespace std;

// 71. Simplify Path
// Given a string path, which is an absolute path (starting with a slash '/') to a
//  file or directory in a Unix-style file system, convert it to the simplified 
// canonical path.

// In a Unix-style file system, a period '.' refers to the current directory, a 
// double period '..' refers to the directory up a level, and any multiple 
// consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem,
//  any other format of periods such as '...' are treated as file/directory names.

// The canonical path should have the following format:

// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root 
// directory to the target
//  file or directory (i.e., no period '.' or double period '..')
// Return the simplified canonical path.

// Example 1:
// Input: path = "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the 
// last directory name.

// Example 2:
// Input: path = "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the 
// root level is the highest level you can go.

// Example 3:
// Input: path = "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are 
// replaced by a single one.

// Example 4:
// Input: path = "/a/./b/../../c/"
// Output: "/c"
 
// Constraints:
// 1 <= path.length <= 3000
// path consists of English letters, digits, period '.', slash '/' or '_'.
// path is a valid absolute Unix path.

class Solution {
public:
    string simplifyPath(string path) {
        // lets first remove double slashes.
        int pathLength = path.length();
        string newPath = "";
        for(int i=0;i<=pathLength - 2;i++){
            if(path.substr(i,2) == "//"){
                continue;
            }else{
                newPath.push_back(path[i]);
            }
        }
        newPath.push_back(path[pathLength - 1]);
        
        int newPathLength = newPath.length();
        if(newPath[newPathLength - 1] == '/'){
            newPath = newPath.substr(0,newPathLength - 1);
        }
        
        newPathLength = newPath.length();
        vector<string> tokens;
        stringstream check1(newPath);
        string intermediate;
        
        
        while(getline(check1, intermediate, '/')){
            tokens.push_back(intermediate);
        }
        
        int tokensLength = tokens.size();
        int skipCount = 0;
        string ans;
        vector<string> finalVec;
        for(int i=tokensLength - 1;i>=1;i--){
            if(tokens[i] == ".."){
                skipCount++;
                continue;
            }

            if(tokens[i] == "."){
                continue;
            }

            if(skipCount > 0){
                skipCount--;
                continue;
            }

            finalVec.push_back(tokens[i]);
        }
        
        ans = "/";
    
        for(int i=finalVec.size() - 1;i>=0;i--){
            ans += finalVec[i] + "/";
        }
        string finalAns =  ans.substr(0,ans.length() - 1);
        if(finalAns == ""){
            return "/";
        }
        return finalAns;
    }
};