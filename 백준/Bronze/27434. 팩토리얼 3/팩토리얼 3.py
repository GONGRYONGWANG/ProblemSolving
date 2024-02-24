N = int(input())
ans = 1
while(N):
    ans*=N
    N-=1
print(ans)