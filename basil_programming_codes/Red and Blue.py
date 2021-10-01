t=int(input())

for s in range(t):

    n=int(input())
    r=list(map(int,input().split()))
    m=int(input())
    b=list(map(int,input().split()))

    if(max(r)<=0 and max(b)<=0):
        print(0)

    else:
        s=0
        temp_r=[]
        temp_b=[]
        
        for i in range(n):
            s=s+r[i]
            temp_r.append(s)

        s=0
        for i in range(m):
            s=s+b[i]
            temp_b.append(s)

        if(max(temp_r)>=0 and max(temp_b)>=0):
            maxi=max(temp_r)+max(temp_b)
        elif(max(temp_r)<0 and max(temp_b)>=0):
            maxi=max(temp_b)
        elif(max(temp_b)<0 and max(temp_r)>=0):
            maxi=max(temp_r)
        elif(max(temp_b)<0 and max(temp_r)<0):
            maxi=0

        print(maxi)
                
