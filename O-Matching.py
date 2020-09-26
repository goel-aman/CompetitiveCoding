
def funct(womenset,index):
    if index >= n:
        if womenset == 0:
            return 1
        else:
            return 0

    if(dp[index][womenset] != -1):
        return dp[index][womenset]

    summ = 0
    for i in range(n):
        num = ( ((1 << i)) & womenset)
        if ( (num != 0) and (input_array[index][i] == 1) ):
            newwomenset = (womenset ^ (num))
            value = funct(newwomenset,index + 1)
            summ = (summ + value) % mod

    dp[index][womenset] = summ
    return summ


if __name__ == "__main__":
    n = int(input())
    input_array = []
    mod = 1000000007
    for _ in range(n):
        sub_array = list(map(int,input().split()))
        input_array.append(sub_array)
    dp = [[-1] * (1<<22)] * (n+1)
    # print(dp)
    # dp = [[-1 for x in range(1<<22)] for y in range(n+1)]
    womenset = (((1 << n)) - 1)
    print(funct(womenset,0))




