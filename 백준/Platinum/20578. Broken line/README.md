# [Platinum IV] Broken line - 20578 

[문제 링크](https://www.acmicpc.net/problem/20578) 

### 성능 요약

메모리: 2916 KB, 시간: 36 ms

### 분류

브루트포스 알고리즘, 애드 혹, 비트마스킹

### 제출 일자

2026년 3월 23일 09:09:22

### 문제 설명

<p>Basia has a string $s$, each character being one of the first 16 lowercase letters of the English alphabet.</p>

<p>Each character of this string will be replaced by an arrow to the right or up, but the same letters have to be replaced by the same arrow. For example, the string "banan" can be replaced to $\uparrow \uparrow \rightarrow \uparrow \rightarrow$ or $\uparrow \uparrow \uparrow \uparrow \uparrow$, but you cannot obtain $\rightarrow \rightarrow \rightarrow \uparrow \rightarrow$ because it would require replacing two letters 'a' with different arrows.</p>

<p>Basia will use the resulting sequence of arrows to draw a broken line. She will start with a pencil set at point $(0, 0)$, then $n$ times she will move it $1$ unit right or up -- in the direction of the next arrow.</p>

<p>As a <em>result</em> of this drawing we will denote the area between the broken line and the OX axis. Formally, this area is a set of points $(x, y)$ such that $y \geq 0$ and there is a point $(x, y')$ that belongs to the broken line and $y' \geq y$ occurs.</p>

<p>What is the largest possible result of Basia's drawing?</p>

### 입력 

 <p>The first and the only line of the standard input contains one string $s$ ($1 \leq |s| \leq 300\,000$), consisting of lowercase letters of the English alphabet 'a'-'p' (16 possible characters).</p>

### 출력 

 <p>Output one integer -- the largest possible result of the drawing obtained after conversion from letters to arrows using given rules.</p>

