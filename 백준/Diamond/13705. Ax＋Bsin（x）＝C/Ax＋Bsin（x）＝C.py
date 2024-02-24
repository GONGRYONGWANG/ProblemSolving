from decimal import *
getcontext().prec = 120
getcontext().rounding = ROUND_HALF_UP
D = Decimal
pi = D('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679')
prc = D('0.0000000000000000000001')

def sin(x):
    x %=D(2*pi)
    ret = x
    _x = x
    cnt = D('2')
    sign = D('-1')
    while(abs(x)>D(str(10**(-100)))):
        x = x*_x*_x/cnt/(cnt+1)
        ret += x*sign
        cnt = cnt+2
        sign = -sign
    return ret

def eq(A,B,C,x):
    return A*x+B*sin(x)-C
    


A,B,C = input().split()
A = D(A)
B = D(B)
C = D(C)
l = D('0')
r = D('200000')
while(r-l>prc):
    m = (l+r)/2
    if(eq(A,B,C,m)>0): r = m
    else: l = m
    
print(round(r,6))
    
    

