# [Gold I] Lottery for Vitcoins at Moloco (Hard) - 15513 

[문제 링크](https://www.acmicpc.net/problem/15513) 

### 성능 요약

메모리: 56748 KB, 시간: 776 ms

### 분류

그리디 알고리즘, 수학, 확률론, 정렬

### 제출 일자

2024년 10월 23일 15:59:03

### 문제 설명

<p>At the end of each month, Moloco employees participate in a simple lottery for extra employee perks.</p>

<p>As a valuable employee of Moloco, you receive <em>n</em> lottery tickets where each ticket <em>i</em> has a prize worth <em>w<sub>i</sub></em> > 0 Vitcoins.</p>

<p>In addition, each ticket <em>i</em> is paired with a coin that flips heads with probability <em>p<sub>i</sub></em> (assume 0 < <em>p<sub>i</sub></em> < 1) and tails with probability 1-<em>p<sub>i</sub></em>. </p>

<p>Each coin flip is independent.</p>

<p>At each step, you choose a ticket among those that you have not chosen yet, and claim the prize immediately. Then, you flip the coin that is paired with the ticket; if it is heads, the lottery continues and you can pick another ticket, and so on until you run out of tickets. If it is tails, then the lottery ends immediately, and you get to keep all the Vitcoins you have collected so far.</p>

<p>You know all the values <em>w<sub>i</sub></em> and <em>p<sub>i</sub></em> for all <em>i</em>, and want to know a permutation of the tickets such that picking them in this order maximizes the expected number of Vitcoins you win. </p>

### 입력 

 <p>The first line contains a single integer <em>n</em> between 1 and 1,000,000, inclusive.</p>

<p>The following <em>n</em> lines contain two integers, <em>w<sub>i</sub></em> and <em>q<sub>i</sub></em> where 1 ≤ <em>w<sub>i</sub></em> ≤ 10,000 and 0 < <em>q<sub>i</sub></em> < 10,000. We define <em>p<sub>i</sub></em> = <em>q<sub>i</sub></em> / 10000.</p>

### 출력 

 <p>You should output a permutation of length <em>n</em> containing integers between 1 and <em>n</em> in a single line, which describes the order in which you pick lottery tickets. If there exists multiple permutations that maximize the expected number of Vitcoins you can win, then output the one that comes first lexicographically (the smaller index must come first).</p>

