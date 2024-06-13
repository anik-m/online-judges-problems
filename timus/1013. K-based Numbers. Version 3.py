def mmul(a,b):
    x0=(a[0][0]*b[0][0]+a[1][0]*b[0][1])%m
    x1=(a[0][0]*b[1][0]+a[1][0]*b[1][1])%m
    x2=(a[0][1]*b[0][0]+a[1][1]*b[0][1])%m
    x3=(a[0][1]*b[1][0]+a[1][1]*b[1][1])%m
    b[0][0]=x0
    b[1][0]=x1
    b[0][1]=x2
    b[1][1]=x3

def solve(n,a):
    p=n-1
    b=[[1,0],[0,1]]
    #print(b[0][0])
    while p>0:
        if p%2==1:
            mmul(a,b)
        mmul(a,a)
        p=p>>1
        #print(b[0][0])
    return b

n=int(input())
k=int(input())
m=int(input())
a=[[k-1,1],[k-1,0]]
#b=[[1,0],[0,1]]
c=solve(n,a)
print(((k-1)*c[0][0]+c[1][0])%m)
