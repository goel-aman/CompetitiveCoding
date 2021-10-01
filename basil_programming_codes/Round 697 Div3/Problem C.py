t=int(input())


def comb(n,k):
    num=1
    den=1
    
    for i in range(n,0,-1):
        num=num*i
    for j in range(n-k,0,-1):
        den=den*j

    for k in range(k,0,-1):
        den=den*k
        
    return(num/den)
        
for s in range(t):
    a,b,k=map(int,input().split())
    s=0
    l=list(map(int,input().split()))
    m=list(map(int,input().split()))

    temp=[]
    s=s+comb(k,2)
    

    
    for i in range(len(l)):

        if(l[i] not in temp):
            if(l.count(l[i])>1):
                s=s-comb(l.count(l[i]),2)
            temp.append(l[i])

    temp=[]
    
    for i in range(len(m)):

        if(m[i] not in temp):
            if(m.count(m[i])>1):
                s=s-comb(l.count(m[i]),2)
            temp.append(m[i])
    print(s)
    
