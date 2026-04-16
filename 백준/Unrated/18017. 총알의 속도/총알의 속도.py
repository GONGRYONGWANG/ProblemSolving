from decimal import *
import math
getcontext().prec = 150
getcontext().rounding = ROUND_HALF_UP
D = Decimal
pi = D('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679')
e = D(math.exp(1))
c = D('299792458')


A,B= input().split()
A = D(A)
B = D(B)
C = (A+B)/(1+A*B/c/c)
print(C)
