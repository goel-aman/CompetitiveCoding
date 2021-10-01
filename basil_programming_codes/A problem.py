t=int(input())

for _ in range(t):

    a,b=map(int,input().split())


    if(b>a):
        print(1)

    elif(a==b):
        print(2)

    else:

        i=0
        ans=10**8

        while(i*i<=a):

            if(b==1 and i==0):
                i=i+1
                continue
            count=i

            c=a

            while(c):
                c//=(b+i)
                count+=1
            ans=min(ans,count)
            i+=1
        print(ans)
