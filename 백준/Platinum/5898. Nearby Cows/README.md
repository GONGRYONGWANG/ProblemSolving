# [Platinum IV] Nearby Cows - 5898 

[문제 링크](https://www.acmicpc.net/problem/5898) 

### 성능 요약

메모리: 17044 KB, 시간: 92 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2026년 1월 23일 18:12:32

### 문제 설명

<p>Farmer John has noticed that his cows often move between nearby fields. Taking this into account, he wants to plant enough grass in each of his fields not only for the cows situated initially in that field, but also for cows visiting from nearby fields.</p><p>Specifically, FJ's farm consists of N fields (1 <= N <= 100,000), where some pairs of fields are connected with bi-directional trails (N-1 of them in total).  FJ has designed the farm so that between any two fields i and j, there is a unique path made up of trails connecting between i and j. Field i is home to C(i) cows, although cows sometimes move to a different field by crossing up to K trails (1 <= K <= 20).</p><p>FJ wants to plant enough grass in each field i to feed the maximum number of cows, M(i), that could possibly end up in that field -- that is, the number of cows that can potentially reach field i by following at most K trails.  Given the structure of FJ's farm and the value of C(i) for each field i, please help FJ compute M(i) for every field i.</p>

### 입력 

 <ul><li>Line 1: Two space-separated integers, N and K.</li><li>Lines 2..N: Each line contains two space-separated integers, i and j (1 <= i,j <= N) indicating that fields i and j are directly connected by a trail.</li><li>Lines N+1..2N: Line N+i contains the integer C(i). (0 <= C(i) <= 1000)</li></ul>

### 출력 

 <ul><li>Lines 1..N: Line i should contain the value of M(i).</li></ul>

