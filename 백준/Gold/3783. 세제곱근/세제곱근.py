from decimal import *
import math
getcontext().prec = 1000
getcontext().rounding = ROUND_HALF_UP
D = Decimal
pi = D('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679')
e = D(math.exp(1))

T = int(input())



for i in range(T):
    N = D(input())
    l = D('0')
    r = N
    while(r-l>D('0.00000000000000001')):
        m = (l+r)/D('2')
        if(N>m*m*m):
            l=m
        else:
            r=m
    out = math.floor(r*D('10000000000'))/D('10000000000')
    if(N<out*out*out):
        out -= D('0.0000000001')
    print(f"{out:.10f}")
