def computesum():
    for i in range(n):
        for j in range(i,n):
            if j == i:
                summ[i][j] = input_array[i]

            summ[i][j] = input_array[j] + summ[i][j - 1]

def answer(i,j):
    if i == j:
        return 0
    
    if (dp[i][j] != -1):
        return dp[i][j]

    minCost = 100000000000
    for k in range(i,j):
        minCost = min(minCost,summ[i][j] + answer(i,k) + answer(k+1,j))

    dp[i][j] = minCost
    return dp[i][j] 

if __name__ == "__main__":
    n = int(input())
    input_array = list(map(int,input().split()))
    dp = [[-1 for x in range(n+2)] for y in range(n+2)]
    summ = [[0 for x in range(n+2)] for y in range(n+2)]
    computesum()
    print(answer(0,n-1))
    