#include<bits/stdc++.h>
using namespace std;

// 1813. Sentence Similarity III
// A sentence is a list of words that are separated by a 
// single space with no leading or trailing spaces. For 
// example, "Hello World", "HELLO", "hello world hello 
// world" are all sentences. Words consist of only uppercase
//  and lowercase English letters.

// Two sentences sentence1 and sentence2 are similar if it 
// is possible to insert an arbitrary sentence (possibly 
// empty) inside one of these sentences such that the two 
// sentences become equal. For example, sentence1 = 
// "Hello my name is Jane" and sentence2 = "Hello Jane" can
//  be made equal by inserting "my name is" between "Hello"
//  and "Jane" in sentence2.

// Given two sentences sentence1 and sentence2, return true
//  if sentence1 and sentence2 are similar. Otherwise, return false.

// Example 1:
// Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
// Output: true
// Explanation: sentence2 can be turned to sentence1 by inserting
//  "name is" between "My" and "Haley".

// Example 2:
// Input: sentence1 = "of", sentence2 = "A lot of words"
// Output: false
// Explanation: No single sentence can be inserted inside one of 
// the sentences to make it equal to the other.

// Example 3:
// Input: sentence1 = "Eating right now", sentence2 = "Eating"
// Output: true
// Explanation: sentence2 can be turned to sentence1 by inserting
//  "right now" at the end of the sentence.

// Example 4:
// Input: sentence1 = "Luky", sentence2 = "Lucccky"
// Output: false
 
// Constraints:
// 1 <= sentence1.length, sentence2.length <= 100
// sentence1 and sentence2 consist of lowercase and uppercase 
// English letters and spaces.
// The words in sentence1 and sentence2 are separated by a single space.


class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> firstSentence;
        stringstream check1(sentence1);
        string intermediate;
        while(getline(check1,intermediate,' ')){
            firstSentence.push_back(intermediate);
        }

        vector<string> secondSentence;
        stringstream check2(sentence2);
        // intermediate;
        while(getline(check2,intermediate,' ')){
            secondSentence.push_back(intermediate);
        }        
        int secondLength = secondSentence.size();
        int firstLength = firstSentence.size();

        int start = 0;
        while(start < firstLength && start < secondLength){
            if(firstSentence[start] == secondSentence[start]){
                start++;
                continue;              
            }else{
                break;
            }
        }

        int end1 = firstLength - 1;
        int end2 = secondLength - 1;
        while(end1 >= 0 && end2 >= 0 && end1 >= start && end2 >= start){
            if(firstSentence[end1] == secondSentence[end2]){
                end1--;
                end2--;
                continue;
            }else{
                break;
            }
        }

        if(start == firstLength || start == secondLength){
            return true;
        }

        if(end1 == -1 || end2 == -1){
            return true;
        }

        if(end1 + 1 == start || end2 + 1 == start){
            return true;
        }
        return false;
    }
};