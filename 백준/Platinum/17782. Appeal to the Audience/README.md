# [Platinum IV] Appeal to the Audience - 17782 

[문제 링크](https://www.acmicpc.net/problem/17782) 

### 성능 요약

메모리: 10992 KB, 시간: 44 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그리디 알고리즘, 트리

### 제출 일자

2025년 10월 5일 16:37:31

### 문제 설명

<p>You are the director of the upcoming Bordfite Arena Progaming Competition. You have invited a bunch of players and are now setting up the matches for the knockout tournament that will determine the winner. As you may know, Bordfite Arena is a game that heavily rewards skill and very little luck is involved. This implies that whenever any number of players play a game of Bordfite Arena, the most skilled player will always win! Hence the winner of the tournament is already known, and you are a bit worried about this. How will you appease the audience?</p>

<p>You embark on a short quest to find out what the audience finds interesting. No surprises there: people find it most interesting when they see skillful players compete. Whenever a match is played, the happiness the audience gets from a match is the sum of the skill levels of the players. The total happiness the audience gets from the tournament is the sum of the happiness obtained during all matches. This is very useful information, because of course you want the audience to be as happy as possible at the end of the tournament.</p>

<p>Moreover, you invested some time to ask people what kind of knockout format they like. It turns out that instead of the plain old binary tree for the knockout schedule, they prefer a specific weird-looking rooted tree, and so you decide to use that. This means the final step for you to complete is to divide the players over the leaves of the given tree so that over the entire tournament, the happiness of the audience is maximized.</p>

### 입력 

 <ul>
	<li>The first line contains integers 3 ≤ n ≤ 10<sup>5</sup> and 1 ≤ k ≤ n − 1, the number of nodes of the tree and the number of players. The nodes are labelled 0 through n − 1, and 0 is the root of the tree.</li>
	<li>The second line contains k integers 0 ≤ a<sub>1</sub>, . . . , a<sub>k</sub> ≤ 10<sup>9</sup>, denoting the skill values of the players.</li>
	<li>Then follow n − 1 lines, the ith of which (1 ≤ i ≤ n − 1) contains the parent 0 ≤ p<sub>i</sub> < i of node i.</li>
</ul>

<p>It is guaranteed that the tree has exactly k leaves and that there are no nodes with exactly one child.</p>

### 출력 

 <ul>
	<li>Output the maximal possible happiness the audience can obtain from this tournament.</li>
</ul>

