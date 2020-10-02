from functools import reduce
def ZeroInA(arr):
    a = []
    xy = []
    for i in range(0,len(arr)):
        xy = arr[0:i] + arr[i+1:len(arr)]
        p = reduce((lambda x, y: x * y), xy)
        a.append(p)
    return a
def productExceptSelf(arr, n):
    #code here
    p = 1
    app = 0
    a = []
    if app in arr:
        a = ZeroInA(arr)
    else:
        for i in arr:
            p = p*i
        for i in arr:
            a.append(int(p/i))
    return a
