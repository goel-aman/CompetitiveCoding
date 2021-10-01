def fact(n):

    if(n==0):
        return 1
    else:
        f=n*fact(n-1)
        return f





n=int(input())

result=fact(n)

print(result)
