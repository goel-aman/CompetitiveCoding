myfile=open('sample.txt')

info=myfile.readlines()

t=int(info[0][0])


f=open("./output.txt","a")

for i in range(1,len(info)):
    p,a,b,c=list(map(int,info[i][:-1].split()))
    print(info[i])
    if(p%a==0 and p%b==0 and p%c==0):
        f.write("0\n")

    else:

        a1=p//a
        b1=p//b
        c1=p//c


        if(p%b!=0):
            b1+=1
        if(p%c!=0):
            c1+=1
        if(p%a!=0):
            a1+=1


        a1=a1*a-p
        b1=b1*b-p
        c1=c1*c-p

        f.write("%d\n"%min(a1,b1,c1))

f.close()


myfile.close()