n = int(input())
a=[]
a.append(0)
a.append(1)
a.append(1)
a.append(2)
for i in range(4,n+1):
    a.append(a[i-1]+a[i-3]+1)
print(a[n])
