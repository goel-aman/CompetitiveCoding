
t=int(input())

for s in range(t):

    s=input()
    l=list(s)
    flag=0

    if(l[0]==")" or l[len(l)-1]=="("):
        print("NO")

    else:
        if(l[0]!="?" and l[len(l)-1]!="?"):
            if(len(l)%2==0):
                print("YES")
            else:
                print("NO")
        
        elif(l[0]=="(" and l[len(l)-1]=="?"):
            if(len(l)%2==0):
                print("YES")
            else:
                print("NO")
        elif(l[0]=="?" and l[len(l)-1]==")"):
            if(len(l)%2==0):
                print("YES")
            else:
                print("NO")
        
        
