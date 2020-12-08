d={}

def findAnswer(ring,key,index):
    val=key+str(index)

    if(len(key)==0):
        d[val]=0
        return 0

    if(val in d):
        return d[val]

    if(key=="" or key==" "):
        d[val]=0
        return d[val]

    if(key[0]==ring[index]):
        d[val]=(1+findAnswer(ring,key[1::],index))
        return d[val]


    tempindex=index
    ans1=float('inf')
    ans2=float('inf')

    counter=0

    while(index<ringsize):
        index+=1
        counter+=1

        index=index%ringsize

        if(key[0]==ring[index]):
            ans1=1+counter +findAnswer(ring,key[1::],index)
            break

    index=tempindex
    counter2=0

    while(index<ringsize):
        index=index-1
        counter2=counter2+1

        if(index<0):
            index=index+ringsize
            ans2=1+counter2 +findAnswer(ring,key[1::],index)
            break

    d[val]=min(ans1,ans2)
    return d[val]



ring=input()
key=input()

if(key==""):
    print(0)
ringsize=len(ring)

result=findAnswer(ring,key,0)
print(result)