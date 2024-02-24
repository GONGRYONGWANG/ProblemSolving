from decimal import*
getcontext().prec = 120
getcontext().rounding = ROUND_HALF_UP
D = Decimal

N,L,W,H = input().split()
N,L,W,H = D(N),D(L),D(W),D(H)

l =D('0.0000000000001')
r = D('1000000000')

while(r-l>D('0.000000000001')):
    m = (l+r)/D('2')
    n = int(L/m)*int(W/m)*int(H/m)
    if(n>=N):
        l=m
    else: r=m
print(l)
