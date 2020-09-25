
def getAnswer(i,j,chance,input_array):
    if i > j:
        return 0
    
    if(dp[i][j][chance] != -1):
        return dp[i][j][chance]

    if chance == 1:
        dp[i][j][1] = max(input_array[i] + getAnswer(i+1,j,0,input_array),input_array[j] +getAnswer(i,j-1,0,input_array))
        return dp[i][j][1]
    else:
        dp[i][j][0] = min(getAnswer(i+1,j,1,input_array),getAnswer(i,j-1,1,input_array))
        return dp[i][j][0]

if __name__ == "__main__":
    n = int(input())
    input_array = list(map(int,input().split()))
    summ = 0
    for i in input_array:
        summ += i
    w,h,s = 3001,3001,3
    dp = [[[-1 for x in range(w)] for y in range(h)] for z in range(s)]
    x = getAnswer(0,n-1,1,input_array)
     ## 1 means Taro's Chance 
    ## 0 means jiro chance
    y = summ - x
    print(x - y)


