t=int(input())

for s in range(t):

    n=int(input())
    c=0
    a=input()

    for i in range(len(a)-1,-1,-1):
        if(a[i]==")"):
            c=c+1
        else:
            break

    rem=n-c

    if(c>rem):
        print("Yes")
    else:
        print("No")
