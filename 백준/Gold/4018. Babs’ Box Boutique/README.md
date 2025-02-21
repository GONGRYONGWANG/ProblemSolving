# [Gold II] Babs’ Box Boutique - 4018 

[문제 링크](https://www.acmicpc.net/problem/4018) 

### 성능 요약

메모리: 2408 KB, 시간: 4 ms

### 분류

비트마스킹, 브루트포스 알고리즘, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2025년 2월 21일 14:01:14

### 문제 설명

<p>Babs sells boxes and lots of them. All her boxes are rectangular but come in many different sizes. Babs wants to create a really eye-catching display by stacking, one on top of another, as many boxes as she can outside her store. To maintain neatness and stability, she will always have the sides of the boxes parallel but will never put a box on top of another if the top box sticks out over the bottom one. For example, a box with base 5-by-10 can not be placed on a box with base 12-by-4.</p>

<p>Of course the boxes have three dimensions and Babs can orient the boxes anyway she wishes. Thus a 5-by-10-by-12 box may be stacked so the base is 5-by-10, 5-by-12, or 10-by-12.</p>

<p>For example, if Babs currently has 4 boxes of dimensions 2-2-9, 6-5-5, 1-4-9, and 3-1-1, she could stack up to 3 boxes but not all four. (For example, the third box, the first box, then the last box, appropriately oriented. Alternatively, the second box could replace the third (bottom) box.)</p>

<p>Babs’ stock rotates, so the boxes she stacks outside change frequently. It’s just too much for Babs to figure out and so she has come to you for help. Your job is to find the most boxes Babs can stack up given her current inventory. Babs will have no more than 10 different sized boxes and will use at most one box of any size in her display.</p>

### 입력 

 <p>A positive integer n (n ≤ 10) will be on the first input line for each test case. Each of the next n lines will contain three positive integers giving the dimensions of a box. No two boxes will have identical dimensions. None of the dimensions will exceed 20. A line with 0 will follow the last test case.</p>

### 출력 

 <p>For each test case, output the maximum number of boxes Babs can stack using the format given below.</p>

