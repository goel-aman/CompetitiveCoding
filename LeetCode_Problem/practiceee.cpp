#include<bits/stdc++.h>
using namespace std;

int maximumAreaHistogram(vector<int> v){
    int length = v.size();
    int max_area = 0;
    int rb[length];
    rb[length - 1] = length;
    stack<int> s;
    s.push(length - 1);
    for(int i=length - 2;i>=0;i--){
        while(!s.empty() && v[i] <= v[s.top()]){
            s.pop();
        }
        if(s.empty()){
            rb[i] = length;
        }
        else{
            rb[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    int lb[length];
    lb[0] = -1;
    s.push(0);
    for(int i =1;i<length;i++){
        while(!s.empty() && v[i] <= v[s.top()]){
            s.pop();
        }
        if(s.empty()){
            lb[i] = -1;
        }
        else{
            lb[i] = s.top();
        }
        s.push(i);
    }


    for(int i=0;i<length;i++){
        int area_temp = v[i] * (rb[i] - lb[i] - 1);
        if(area_temp > max_area){
            max_area = area_temp;
        }
    }
    return max_area;
}

int main(){
    vector<int> v = {4 ,7, 6, 4, 3, 16, 16, 4 ,16 ,5 ,6 ,16 ,13 ,12, 3 ,7 ,16 ,0 ,8 };
    cout<<maximumAreaHistogram(v)<<endl;
}