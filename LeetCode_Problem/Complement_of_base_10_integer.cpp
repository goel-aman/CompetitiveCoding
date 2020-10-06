class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0){
            return 1;
        }
        int n = N;
        int count = 0;
        while(N > 0){
            N = N >> 1;
            count++;
        }
        
        int number =  ((1 << count) - 1);
        // cout<<"number is : "<<number<<endl;
        int answer = (number ^ n);
        // cout<<"answer is : "<<answer<<endl;
        return answer;
    }
};

