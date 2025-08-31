# [Gold I] Party at Hali-Bula - 6272 

[문제 링크](https://www.acmicpc.net/problem/6272) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 트리

### 제출 일자

2025년 8월 31일 19:08:01

### 문제 설명

<p>Dear Contestant,</p>

<p>I'm going to have a party at my villa at Hali-Bula to celebrate my retirement from BCM. I wish I could invite all my co-workers, but imagine how an employee can enjoy a party when he finds his boss among the guests! So, I decide not to invite both an employee and his/her boss. The organizational hierarchy at BCM is such that nobody has more than one boss, and there is one and only one employee with no boss at all (the Big Boss)! Can I ask you to please write a program to determine the maximum number of guests so that no employee is invited when his/her boss is invited too? I've attached the list of employees and the organizational hierarchy of BCM.</p>

<p>Best, <br>
-Brian Bennett</p>

<p>P.S. I would be very grateful if your program can indicate whether the list of people is uniquely determined if I choose to invite the maximum number of guests with that condition.</p>

### 입력 

 <p>The input consists of multiple test cases. Each test case is started with a line containing an integer n (1 ≤ n ≤ 200) , the number of BCM employees. The next line contains the name of the Big Boss only. Each of the following n - 1 lines contains the name of an employee together with the name of his/her boss. All names are strings of at least one and at most 100 letters and are separated by blanks. The last line of each test case contains a single 0.</p>

### 출력 

 <p>For each test case, write a single line containing a number indicating the maximum number of guests that can be invited according to the required condition, and a word Yes or No, depending on whether the list of guests is unique in that case.</p>

