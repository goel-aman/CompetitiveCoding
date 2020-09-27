
def getAnswer(i,j,chance,input_array):
    if i > j:
        return 0
    
    if(dp[chance][i][j] != -1):
        return dp[chance][i][j]

    if chance == 1:
        dp[1][i][j] = max(input_array[i] + getAnswer(i+1,j,0,input_array),input_array[j] +getAnswer(i,j-1,0,input_array))
        return dp[1][i][j]
    else:
        dp[0][i][j] = min(getAnswer(i+1,j,1,input_array),getAnswer(i,j-1,1,input_array))
        return dp[0][i][j]

if __name__ == "__main__":
    n = int(input())
    input_array = list(map(int,input().split()))
    summ = 0
    for i in input_array:
        summ += i
    w,h,s = 3001,3001,2
    dp =[[[-1] * h]* w] * s
    x = getAnswer(0,n-1,1,input_array)
     ## 1 means Taro's Chance 
    ## 0 means jiro chance
    y = summ - x
    print(x - y)

