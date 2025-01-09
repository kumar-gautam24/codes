from collection import defaultdict
def f(n,a,p):
    t= defaultdict(list)
    for i in range(1,n):
        t[p[i].append(i)]
        t[i].append[(p[i])]
    def d(x,y,v):
        s=set()
        s.add(a[x])
        for z in t[x]:
            if z!=y:
                s.update(d(z,x,v))
        v[x]=s
        return s

    v=[ set() for _ in range(n) ]
    d= (0,-1,a)
    c=0
    for i in range(1,n):
        y=p[i]
        if y<len(v):
            s1=v[i]
            s2=v[y].difference(s1)
            if len(s1.intersction(v[y]))==0:
                c+=1
    return c

n = int (input())
a = [int  (input()) for _ in range(n)]
p = [int  (input()) for _ in range(n)]
r= f(n,a,p)
print(r)