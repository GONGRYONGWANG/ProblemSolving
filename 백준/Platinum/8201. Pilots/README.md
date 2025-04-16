# [Platinum IV] Pilots - 8201 

[문제 링크](https://www.acmicpc.net/problem/8201) 

### 성능 요약

메모리: 26236 KB, 시간: 420 ms

### 분류

자료 구조, 덱

### 제출 일자

2025년 4월 16일 19:26:22

### 문제 설명

<p>In the Byteotian Training Centre, the pilots prepare for missions requiring extraordinary precision and control. One measure of a pilot's capability is the duration he is able to fly along a desired route without deviating too much - simply put, whether he can fly steadily. This is not an easy task, as the simulator is so sensitive that it registers even a slightest move of the yoke<sup>1</sup>. At each moment the simulator stores a single parameter describing the yoke's position. Before each training session a certain tolerance level t is set. The pilots' task then is to fly as long as they can in such a way that all the yoke's position measured during the flight differ by at most t. In other words, a fragment of the flight starting at time i and ending at time j is within tolerance level t if the position measurements, starting with i-th and ending with j-th, form such a sequence a<sub>i</sub>,…,a<sub>j</sub>  that for all elements a<sub>k</sub>,a<sub>l</sub> of this sequence, the inequality |a<sub>k</sub>-a<sub>l</sub>| ≤ t holds.</p>

<p>Your task is to write a program that, given a number and the sequence of yoke's position measurements, determines the length of the longest fragment of the flight that is within the tolerance level t.</p>

<p><sup>1</sup>a device used for piloting in an aircraft</p>

### 입력 

 <p>In the first line of the standard input two integers are given, t and n (0 ≤ t ≤ 2,000,000,000, 1 ≤ n ≤ 3,000,000), separated by a single space, denoting the tolerance level and the number of yoke's position measurements taken. The second line gives those measurements, separated by single spaces. Each measurement is an integer from the interval from 1 to 2,000,000,000.</p>

### 출력 

 <p>Your program should print a single integer to the standard output: the maximum length of a fragment of the flight that is within the given tolerance level.</p>

