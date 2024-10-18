import sys
input = lambda: sys.stdin.readline().rstrip()
from decimal import *
import math
getcontext().prec = 1200
getcontext().rounding = ROUND_HALF_UP
D = Decimal
pi = D('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679')
e = D(math.exp(1))

a =0
b=1
n = int(input())
while(n):
    tmp=a+b
    a=b
    b=tmp
    n-=1
print(a)
