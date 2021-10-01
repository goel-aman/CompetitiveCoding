t=int(input())

for s in range(t):
    a=input()
    n=int(a)


    while(True):
        l=list(set(str(n)))
        flag=0
        for i in range(len(l)):
            if(l[i]!='0'):
                if(n%int(l[i])!=0):
                    flag=1
                    break
        if(flag==1):
            n=n+1
        else:
            print(n)
            break
        
