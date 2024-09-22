# [Platinum V] Observation Wheel (Small) - 12307 

[문제 링크](https://www.acmicpc.net/problem/12307) 

### 성능 요약

메모리: 346088 KB, 시간: 92 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2024년 9월 22일 18:51:28

### 문제 설명

<p>An <em>observation wheel</em> consists of <strong>N</strong> passenger <em>gondolas</em> arranged in a circle, which is slowly rotating. Gondolas pass the entrance one by one, and when a gondola passes the entrance, a person may enter that gondola.</p>

<p>In this problem, the gondolas are so small that they can take just one person each, so if the gondola passing by the entrance is already occupied, the person waiting at the entrance will have to wait for the next one to arrive. If that gondola is also occupied, the person will have to wait for the next one after that, and so on, until a free gondola arrives. For simplicity, we will not consider people exiting the gondolas in this problem — let's assume that all people do is enter the gondolas, and then rotate with the wheel for an arbitrarily long time.</p>

<p>We want to make sure people are not disappointed because of long waiting times, and so we have introduced a flexible pricing scheme: when a person approaches the wheel, and the first gondola passing by the entrance is free, she pays <strong>N</strong> dollars for the ride. If the first gondola is occupied and she has to wait for the second one, she pays <strong>N</strong>-1 dollars for the ride. If the first two gondolas are occupied and she has to wait for the third one, she pays <strong>N</strong>-2 dollars for the ride. Generally, if she has to wait for <strong>K</strong> occupied gondolas to pass by, she pays <strong>N</strong>-<strong>K</strong> dollars. In the worst case, when she has to wait for all but one gondola to pass, she will pay just 1 dollar.</p>

<p>Let's assume that people approach our wheel at random moments in time, so for each person approaching the wheel, the first gondola to pass the entrance is picked uniformly and independently. Let's also assume that nobody will come to the wheel while there's already at least one person waiting to enter, so that we don't have to deal with queueing. A person will always take the first free gondola that passes the entrance.</p>

<p>You are given the number of gondolas and which gondolas are already occupied. How much money are we going to make, on average, until all gondolas become occupied?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> lines follow. Each line describes one test case and contains only '.' (dot) or 'X' (capital letter X) characters. The number of characters in this line gives you <strong>N</strong>. The <strong>i</strong>-th character is 'X' when the <strong>i</strong>-th gondola is already occupied, and '.' when it's still free. The gondolas are numbered in the order they pass the entrance, so the 1st gondola is followed by the 2nd gondola, and so on, starting over from the beginning after the last gondola passes.</p>

<p>Limits</p>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 50.</li>
	<li>1 ≤ <strong>N</strong> ≤ 20.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the average amount of money we will get, in dollars. Answers with absolute or relative error no larger than 10<sup>-9</sup> will be accepted.</p>

