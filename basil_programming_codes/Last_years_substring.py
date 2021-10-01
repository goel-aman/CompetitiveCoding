t=int(input())


for s in range(t):

    n=int(input())
    s=input()


    if(s=="2020"):
        print("YES")

    else:
        while(True):
            if(s[-4:]=='2020'):
                print("YES")
                break

            elif(s[0]=="2" and s[-3:]=='020'):
                print("YES")
                break

            elif(s[0:2]=="20" and s[-2:]=='20'):
                print("YES")
                break

            elif(s[0:3]=="202" and s[-1]=="0"):
                print("YES")
                break
            elif(s[0:4]=="2020"):
                print("YES")
                break
            else:
                print("NO")
                break
