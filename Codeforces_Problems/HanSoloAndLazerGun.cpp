#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    set<double> um;

    while(n--){
        int x1,y1;
        cin>>x1>>y1;
        if(x1 - x == 0){
            um.insert((double) INT_MAX);
            continue;
        }

        double slope = (double)((double)(y1 - y) / (double) (x1 - x));
        um.insert(slope);
    }
    cout<<um.size()<<endl;
}

