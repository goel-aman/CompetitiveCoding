class element{
    public:
    int firstElement;
    int secondElement;
};

bool compare(element e1,element e2){
    return e1.firstElement < e2.firstElement;
}

class Solution {

    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int siz = intervals.size();
        element arr[siz];
        for(int i=0;i<siz;i++){
            arr[i].firstElement = intervals[i][0];
            arr[i].secondElement = intervals[i][1];
        }
        sort(arr,arr+siz,compare);
        vector<vector<int>> ans;
        int start = arr[0].firstElement;
        int end = arr[0].secondElement;
        for(int i=1;i<siz;i++){
            if(arr[i].firstElement <= end){
                end = max(end,arr[i].secondElement);
                continue;
            }
            else{
                vector<int> c;
                c.push_back(start);
                c.push_back(end);
                ans.push_back(c);
                start = arr[i].firstElement;
                end = arr[i].secondElement;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};