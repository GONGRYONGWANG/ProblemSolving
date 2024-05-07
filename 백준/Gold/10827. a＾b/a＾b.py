from decimal import *
import math
getcontext().prec = 1200
getcontext().rounding = ROUND_HALF_UP
D = Decimal
pi = D('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679')
e = D(math.exp(1))

a,b = input().split()
a = D(a)
b = int(b)

ans = D('1')

for i in range(b):
    ans = ans * a

print(format(ans,'f'))
