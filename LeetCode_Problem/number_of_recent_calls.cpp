#include<bits/stdc++.h>
#include<vector>
class RecentCounter {
public:
    vector<long long int> v;
    RecentCounter() {
    }
    
    int ping(int t) {
        v.push_back(t);
        long long int lowest_value = t - 3000;
        vector<long long int>::iterator it = lower_bound(v.begin(),v.end(),lowest_value);
        vector<long long int>::iterator it2 = v.end();
        long long int ans = (it2 - it);
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */