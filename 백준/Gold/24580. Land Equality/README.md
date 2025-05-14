# [Gold V] Land Equality - 24580 

[문제 링크](https://www.acmicpc.net/problem/24580) 

### 성능 요약

메모리: 2036 KB, 시간: 0 ms

### 분류

애드 혹, 많은 조건 분기, 수학

### 제출 일자

2025년 5월 14일 15:35:04

### 문제 설명

<p>There is a kingdom where the old King wants to divide his land into two pieces and give them to his two descendants. The King’s land is a grid of r rows and c columns. Each cell in the grid has an integer value representing the prosperity of the cell, which can be 0 (deserted), 1 (regular), or 2 (fertile). Two cells are connected if they share a side horizontally or vertically.</p>

<p>Each descendant shall receive a single connected piece of land with at least one cell, in which all cells must be directly connected or indirectly connected via other cells. There shall be no leftover cells, which means that each cell must be given to one descendant. The <em>prosperity</em> of a piece of land is the product of all the prosperity values of its cells. The King wants the absolute difference between the prosperity of the two descendants’ land to be as small as possible. He has asked his best counselor to devise a land division plan between the two descendants.</p>

### 입력 

 <p>The first line of input contains two positive integers r and c (2 ≤ r × c ≤ 64). The next r lines each have c integers giving the prosperity values of the King’s land. All those integers are 0, 1, or 2.</p>

### 출력 

 <p>Output the smallest absolute difference between the prosperity of the two descendants’ land.</p>

