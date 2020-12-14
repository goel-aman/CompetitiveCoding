#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    

    int minCut(string s)
    {
        
        int slength = s.length();
        bool matrix[slength][slength];
        memset(matrix,0,sizeof(matrix));
        int i = 0;
        int m, n;
        m = 0;
        n = i;
        while (m < slength && n < slength)
        {
            matrix[m][n] = true;
            m++;
            n++;
        }
        m = 0;
        n = 1;
        while (m < slength && n < slength)
        {
            if (s[m] == s[n])
            {
                matrix[m][n] = true;
            }
            else
            {
                matrix[m][n] = false;
            }
            m++;
            n++;
        }

        for (int i = 2; i < slength; i++)
        {
            int m, n;
            // m denotes row
            // n denotes column;
            m = 0;
            n = i;
            while (m < slength && n < slength)
            {
                if (s[m] == s[n])
                {
                    matrix[m][n] = matrix[m + 1][n - 1];
                }
                else
                {
                    matrix[m][n] = false;
                }
                m++;
                n++;
            }
            
        }
//         cout<<"Start of matrix"<<endl;
//         for(int i=0;i<slength;i++){
//             for(int j=0;j<slength;j++){
//                 cout<<matrix[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<"end of matrix"<<endl;
        
        if (slength == 0 || slength == 1)
        {
            return 0;
        }

        if (matrix[0][slength - 1])
        {
            return 0;
        }

        int arr[slength];
        arr[0] = 0;
        for (int j = 1; j < slength ; j++){
            int ans = INT_MAX;
            int val = 0;
            for (int i = j; i >= 0  ; i--){
                string substr = s.substr(i,j-i+1);
                if (matrix[i][i + (j - i + 1) - 1]){
                    if(i == 0){
                        arr[j] = 0;
                        val = 1;
                        break;
                    }
                    else{
                        ans = min(ans,arr[i -1]);
                    }
                }
            }
            if(val == 1){
                arr[j] = 0;
                continue;
            }
            arr[j] = ans + 1;
        }
        for(int i=0;i<slength;i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        return arr[slength - 1];
    }
};
