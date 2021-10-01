t=int(input())


for s in range(t):

    n=int(input())
    l=list(map(int,input().split()))
    k=[]

    r=len(l)//2
    
    for i in range(0,r):

        k.append(l[i])
        k.append(l[len(l)-i-1])
    if(n%2!=0):
        k.append(l[r])
        
    for i in range(len(k)):
        print(k[i],end=" ")
    print(" ")
