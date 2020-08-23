class Solution {
public:
    int minDays(int n) {
        if(n == 1){
            return 1;
        }

        if(n == 2){
            return 2;
        }
        if(n <= 0){
            return 0;
        }
        int b = INT_MAX,c=INT_MAX;
        int a = minDays(n-1) + 1;
        if(n%2 == 0){
            b = minDays(n/2) + 1;
        }
        if(n%3 == 0){
            c = minDays(n/3) + 1;
        }

        return min(a,min(b,c));
    }
};