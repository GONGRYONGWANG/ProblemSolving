# [Silver II] Tired Terry - 17882 

[문제 링크](https://www.acmicpc.net/problem/17882) 

### 성능 요약

메모리: 2648 KB, 시간: 0 ms

### 분류

누적 합

### 제출 일자

2024년 6월 5일 15:05:29

### 문제 설명

<p>Terry is feeling tired and he suspects it is because of a lack of sleep. He created a device that records his sleeping pattern over a period of time measured in seconds.</p>

<p>Assuming that the recorded sleeping pattern keeps repeating, help Terry by letting him know how often he is tired during each of the repeating time periods.</p>

<p>More precisely, for integers p and d, we say that Terry is tired at second i if from second i − p + 1 to second i (inclusive) he has slept for less than d seconds.</p>

### 입력 

 <p>The first line of input contains three integers n (1 ≤ n ≤ 86 400), the length of Terry’s sleep pattern, p (1 ≤ p ≤ N), and D (1 ≤ d ≤ p) as described above.</p>

<p>The second line of input contains a single string of length n which describes the period of time that is recorded. The i<sup>th</sup> such character is a W if Terry is awake at the i<sup>th</sup> second, or is a Z if Terry is asleep at the i<sup>th</sup> second.</p>

### 출력 

 <p>Display a single integer which represents the number of seconds that Terry is tired during each of the repeating time periods.</p>

