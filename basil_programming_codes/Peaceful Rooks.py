t=int(input())

for s in range(t):

    n,m=map(int,input().split())

    d={}
    l=[]
    
    for i in range(m):
        x,y=map(int,input().split())
        l.append([x,y])
        d[y]=True

    c=0
    l=sorted(l, key=lambda k: [k[0], k[1]])
    for i in range(m):

        if(l[i][0]==l[i][1]):
            continue
        elif(d[l[i][1]]
    print(c)
            
        
