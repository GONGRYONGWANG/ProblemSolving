from decimal import *
import math
getcontext().prec = 200
getcontext().rounding = ROUND_HALF_UP
D = Decimal
pi = D('3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679')
e = D(math.exp(1))

N = int(input())

minimum = D('1')
product = D('1')
ans = D('0')

for i in range(N):
    x = D(input())
    if(x==D('0')):
        minimum=D('1')
        product = D('1')
        continue
    
    product *= x
    
    if(product / minimum > ans):
        ans = product / minimum
        
    if(product<minimum):
        minimum = product
print(round(ans,3))
