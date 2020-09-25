def func(index,k,input_array,n):
    # Base Condition
    if index == n - 1:
        if k <= input_array[index]:
            return 1
        else:
            return 0

    # applying dynamic programming        
    if(dp[index][k] != -1):
        return dp[index][k]
    
    
    summ =0
    for i in range(0,min(k,input_array[index]) + 1):
        summ = (summ +  func(index + 1, k - i,input_array,n)) % mod
    dp[index][k] = summ % mod
    return summ

def answer(n,k,input_array):
    return func(0,k,input_array,n)

if __name__ == "__main__":
    dp = []
    n,k = list(map(int,input().split()))
    dp = [[-1 for x in range(0,k+1)] for y in range(0,n)]
    input_array = list(map(int,input().split()))
    mod = 1000000007
    ans = answer(n,k,input_array)
    print(ans)
    
