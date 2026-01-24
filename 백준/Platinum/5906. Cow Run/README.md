# [Platinum III] Cow Run - 5906 

[문제 링크](https://www.acmicpc.net/problem/5906) 

### 성능 요약

메모리: 2032 KB, 시간: 124 ms

### 분류

브루트포스 알고리즘, 게임 이론, 구현, 무작위화, 시뮬레이션, 트리

### 제출 일자

2026년 1월 24일 21:30:02

### 문제 설명

<p>Farmer John and Bessie have devised a new exercise game for the cows.  The cows are running on a circular track of length M (2 <= M <= 1,000,000,000) starting from the same position.  The game proceeds in N (1 <= N <= 14) rounds using a deck of 8N cards each with a number X_i (0 <= X_i < M) written on it.</p><p>Each round FJ moves the top 8 cards into a separate pile and selects either the top 4 or bottom 4 cards for Bessie to play with.  Bessie then chooses either the top 2 cards or bottom 2 cards of the 4 cards FJ selected.  After this FJ calls out the number on the top card, X_top, and the cows run a distance of R * X_top, where R is the total distance the cows have run so far.  Bessie then calls out the number on the bottom card, X_bottom, and the cows run a distance of X_bottom.</p><p>FJ is concerned that after the exercise the cows will be too tired to get back to the beginning of the track if they end up too far away.  He believes if the cows end up more than a distance of K (0 <= K <= floor(M/2)) from their starting position they won't be able to get back home.</p><p>It is guaranteed that if FJ plays correctly, he will always be able to ensure the cows can come home, irrespective of the moves made by Bessie! For each round, your task is to determine which half of the cards FJ should choose such that no matter what Bessie does from that point on, FJ can always get the cows home.  Bessie will then make the move provided in the input and you can then continue onto the next round.  Note that even though Bessie's moves are provided to you in the input, you are to specify moves for FJ that would have worked no matter what Bessie chooses (so it is effectively as if FJ does not really know what Bessie will do during her moves).</p>

### 입력 

 <ul><li>Line 1: Three space-separated integers N, M, K</li><li>Line 2: A string N characters.  If the ith character is 'T' it means Bessie will select the top 2 cards in the ith round.  Otherwise the ith character will be 'B' to indicate Bessie will select the bottom 2 cards in the ith round.</li><li>Lines 3..2+N: Each line contains eight integers representing the 8 cards to be used that round from top to bottom.</li></ul>

### 출력 

 <ul><li>Line 1: A string of N characters where the ith character is 'T' if FJ should choose the top 4 cards or 'B' if FJ should choose the bottom 4 cards in the ith round.  If there are multiple ways to get the cows home, choose the lexicographically first (that is, the string that is alphabetically smallest).</li></ul>

