def funct(root,cons,pr):
    # if len(dict[root]) == 0:
    #     if (cons == 1):
    #         return 1
    #     else:
    #         return 2
    
    if dp[cons][root] != -1:
        return dp[cons][root]
    
    ans = 0
    ans1 = 1
    for elem in dict[root]:
        if elem != pr:
            ans1 = (ans1 * funct(elem,0,root) ) % mod

    ans = (ans + ans1) % mod

    ans2 = 1
    if cons == 0:
        for elem in dict[root]:
            if elem != pr:
                ans2 = (ans2 * funct(elem,1,root)) %mod
        ans = (ans + ans2 ) % mod

    dp[cons][root] = ans
    return ans
        

if __name__ == "__main__":
    n = int(input())
    dict = {new_list:[] for new_list in range(1,n+1)}

    for _ in range(n - 1):
        m = list(map(int,input().split()))
        dict[m[0]].append(m[1])
        dict[m[1]].append(m[0])
    s = n + 2
    dp = [[-1] * s] * 2
    mod = 1000000007
    # 0 means it doesn't have constraint ,
    # 1 means it is having constraint (Which mean it has to be white)
    print(funct(1,0,-1))