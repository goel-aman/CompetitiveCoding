t=int(input())
import math
for s in range(t):

    n=int(input())
    flag=0
    
    for y in range(0,int(n/2021)+1):
        x=(n-2021*y)/2020

        if(math.ceil(x)==x):
            flag=1
            break

    if(flag==1):
        print("YES")
    else:
        print("NO")
        
