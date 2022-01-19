#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll rows,cols,rowInitial,colInitial,dirtyCellRow,dirtyCellCol;
        cin>>rows>>cols>>rowInitial>>colInitial>>dirtyCellRow>>dirtyCellCol;
        unordered_set<int> rowCovered;
        unordered_set<int> colCovered;
        int incrementRow = 1,incrementCol = 1;
        rowCovered.insert(rowInitial);
        colCovered.insert(colInitial);
        int time = 0;
        while(true){
            if(rowCovered.count(dirtyCellRow) > 0 || colCovered.count(dirtyCellCol) > 0){
                break;
            }

            time++;
            if((rowInitial < rows && incrementRow > 0) || (rowInitial > 1 && incrementRow < 0)){
                rowInitial += incrementRow;
            }else{
                incrementRow = -incrementRow;
                rowInitial += incrementRow;
            }

            if((colInitial < cols && incrementCol > 0) || (colInitial > 1 && incrementCol < 0)){
                colInitial += incrementCol;
            }else{
                incrementCol = -incrementCol;
                colInitial += incrementCol;
            }
            // cout<<"row is : "<<rowInitial<<" initial column is : "<<colInitial<<" time is: "<<time<<endl;
            rowCovered.insert(rowInitial);
            colCovered.insert(colInitial);
        }

        cout<<time<<endl;
    }
}