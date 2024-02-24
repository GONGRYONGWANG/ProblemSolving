from decimal import *
import math
getcontext().prec = 150
getcontext().rounding = ROUND_HALF_UP
D = Decimal
    

def equ(a,b,c,d,x):
    return a*x*x*x+b*x*x+c*x+d

def solve():
    a,b,c,d = input().split()
    a = D(a)
    b = D(b)
    c = D(c)
    d = D(d)
    if(a<0):
        a=-a
        b=-b
        c=-c
        d=-d

    ans = []
    _a = 3*a
    _b = 2*b
    _c = c
    
    disc = _b*_b-4*_a*_c
    
    if(disc<=D('0')):
        l = D('-1000000')
        r = D('1000000')
        while(l<=r):
            m = math.floor((l+r)/2)
            if(equ(a,b,c,d,m)==D('0')):
                print(m)
                return
            elif(equ(a,b,c,d,m)<D('0')):
                l = m+1
            else:
                r = m-1
                
    else:
        mx = (-_b-disc.sqrt())/(2*_a)
        mn = (-_b+disc.sqrt())/(2*_a)
        l = D('-1000000')
        r = math.floor(mx)
        while(l<=r):
            m = math.floor((l+r)/2)
            if(equ(a,b,c,d,m)==D('0')):
                x = m
                break
            elif(equ(a,b,c,d,m)<D('0')):
                l = m+1
            else:
                r = m-1
                
        l = math.ceil(mx)
        r = math.floor(mn)
        while(l<=r):
            m = math.floor((l+r)/2)
            if(equ(a,b,c,d,m)==D('0')):
                x = m
                break
            elif(equ(a,b,c,d,m)<D('0')):
                l = m+1
            else:
                r = m-1
                
        l = math.ceil(mn)
        r = D('1000000')
        while(l<=r):
            m = math.floor((l+r)/2)
            if(equ(a,b,c,d,m)==D('0')):
                x = m
                break
            elif(equ(a,b,c,d,m)<D('0')):
                l = m+1
            else:
                r = m-1
                
        ans.append(x)
        
    A = a
    B  = b+A*x
    C = c+B*x
    # Ax^2+Bx+c=0
    d = B*B-4*A*C
    if(d == D('0')):
        ans.append(-B/(2*A))
    elif(d>D('0')):
        ans.append((-B+d.sqrt())/(2*A))
        ans.append((-B-d.sqrt())/(2*A))
        
    ans = sorted(ans)
    for i in range(len(ans)):
        if(i==0 or ans[i]>ans[i-1]+D('0.0000000001')):
            print('%.15f' % ans[i], end=' ')
    print('')



T = int(input())
while(T):
    solve()
    T = T-1

