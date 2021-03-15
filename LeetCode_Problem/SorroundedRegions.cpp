class Solution {
    unordered_map<int,int> um;
    
    void merge(int first,int second){
        int firstParent = findParent(first);
        int secondParent = findParent(second);

        if(firstParent != secondParent){
            um[firstParent] = secondParent;
        }

        return ;
    }
    
    int findParent(int input){
        if(!um.count(input)){
            um[input] = input;
        }

        if(um[input] == input){
            return input;
        }

        return um[input] = findParent(um[input]);
    }
public:
    void solve(vector<vector<char>>& board) {
        // cout<<"hello"<<endl;
        int rows = board.size();
        int cols = board[0].size();
        unordered_map<int,bool> isThere;
        vector<int> present;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // cout<<"i is : "<<i<<"j value is : "<<j<<endl;
                if(board[i][j] == 'O' && (i == 0 || i == rows - 1 || j == cols - 1 || j == 0)){
                    // cout<<"i is : "<<i<<" j is : "<<j<<" "<<endl;
                    int vall = findParent(i + (j * 1000));
                    present.push_back(vall);
                }
                if(board[i][j] == 'O'){
                    int val = findParent(i + (j * 1000));
                    if(i - 1 >= 0 && i - 1 < rows && board[i - 1][j] == 'O'){
                        merge(i + (j * 1000) , i - 1 + (j * 1000));
                    }

                    if(i + 1 >= 0 && i + 1 < rows && board[i + 1][j] == 'O'){
                        merge(i + (j * 1000), i + 1 + (j * 1000));
                    }

                    if(j + 1 >= 0 && j + 1 < cols && board[i][j + 1] == 'O'){
                        merge(i + (j* 1000),i + ((j + 1)* 1000 ));
                    }

                    if(j - 1 >= 0 && j - 1 < cols && board[i][j -1 ] == 'O'){
                        merge(i + (j* 1000),i + ((j - 1)* 1000));
                    }
                }
            }
        }
        for(auto val : present){
            isThere[findParent(val)] = true;
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O'){
                    if(isThere.count( findParent( i + (j* 1000) ) ) > 0){
                        continue;
                    }else{
                        board[i][j] = 'X';
                    }
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }
};