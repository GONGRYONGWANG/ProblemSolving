from decimal import *
import math
getcontext().prec = 1200
getcontext().rounding = ROUND_HALF_UP
D = Decimal
pi = D('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679')
e = D(math.exp(1))

A = D(input())
s = input()
B= D(input())

if(s=='*'):
    print(A*B)
else:
    print(A+B)
