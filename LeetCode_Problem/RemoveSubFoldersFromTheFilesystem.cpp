#include<bits/stdc++.h>
using namespace std;

// 1233. Remove Sub-Folders from the Filesystem
// Given a list of folders, remove all sub-folders 
// in those folders and return in any order the folders
//  after removing.

// If a folder[i] is located within another folder[j],
//  it is called a sub-folder of it.

// The format of a path is one or more concatenated strings
//  of the form: / followed by one or more lowercase English 
// letters. For example, /leetcode and /leetcode/problems are
//  valid paths while an empty string and / are not.

// Example 1:
// Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
// Output: ["/a","/c/d","/c/f"]
// Explanation: Folders "/a/b/" is a subfolder of "/a" and
//  "/c/d/e" is inside of folder "/c/d" in our filesystem.

// Example 2:
// Input: folder = ["/a","/a/b/c","/a/b/d"]
// Output: ["/a"]
// Explanation: Folders "/a/b/c" and "/a/b/d/" will be removed 
// because they are subfolders of "/a".

// Example 3:
// Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
// Output: ["/a/b/c","/a/b/ca","/a/b/d"]
 
// Constraints:
// 1 <= folder.length <= 4 * 10^4
// 2 <= folder[i].length <= 100
// folder[i] contains only lowercase letters and '/'
// folder[i] always starts with character '/'
// Each folder name is unique.

bool compare(string &s1,string &s2){
    return (s1.length() < s2.length()) ? true : false;
}

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int folderLength = folder.size();
        vector<string> ans;
        unordered_set<string> us;
        sort(folder.begin(),folder.end(),compare);
        for(int i=0;i<folderLength;i++){
            string temp = folder[i];
            int index;
            bool isPresent = true;
            for(int i=temp.length() - 1;i>=0;i--){
                if(temp[i] == '/'){
                    index = i;
                    string val = temp.substr(0,index);
                    if(us.count(val)){
                        isPresent = false;
                        break;
                    }
                }
            }
            if(isPresent){
                us.insert(temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};