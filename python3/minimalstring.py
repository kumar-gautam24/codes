def minimalString(s):
    p=set(s)
    x="abcedfghijklmnopqrstuvwxyz"
    for i in x:
        if i not in p:
            return i
    c=2
    while True:
        from itertools import product 
        for i in product(x,repeat=c):
            y="".join(i)
            if y not in p:
                return y
            
        c+=1

s= str(input())
r=minimalString(s)
print(r)
