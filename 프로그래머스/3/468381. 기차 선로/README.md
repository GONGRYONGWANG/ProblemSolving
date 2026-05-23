# [level 3] 기차 선로 - 468381 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/468381) 

### 성능 요약

메모리: 3.7 MB, 시간: 6.61 ms

### 구분

코딩테스트 연습 > 2025 카카오 하반기 2차

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2026년 05월 23일 10:58:42

### 문제 설명

<p><code>n</code> × <code>m</code> 크기의 직사각형 격자가 있습니다. 격자의 가장 왼쪽 위는 <code>(1, 1)</code>, 가장 오른쪽 아래는 <code>(n, m)</code>입니다. 각 격자칸은 빈칸, 선로, 장애물 중 하나입니다. 선로는 7가지 종류가 있으며 아래 그림과 같습니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0f755957-bbeb-4121-b20a-ad3167a2797d/ex1-1.png" title="" alt="ex1-1.png"></p>

<p>격자의 <code>(1, 1)</code>에는 1번 선로가 놓여있고, <code>(n, m)</code>에는 1번, 2번 선로 중 하나가 놓여있습니다. 당신은 기차가 <code>(n, m)</code>에 도착할 수 있도록 격자의 빈칸에 선로를 놓으려 합니다. (선로를 놓지 않고 빈칸인 채로 두어도 됩니다.) 당신이 선로를 완성시키면 기차가 <code>(1, 1)</code>에서 오른쪽 방향으로 출발해 선로를 따라 움직입니다. 이때 기차는 격자에 있는 모든 선로를 한번 이상 지나가야 합니다. 또한, # 모양의 3번 선로는 <strong>상하좌우 모든 방향으로 연결되어 있어야 합니다.</strong> </p>

<p>당신은 격자의 정보가 주어질 때 격자에 선로를 놓는 방법의 수를 알고 싶습니다. </p>

<p>아래는 <code>n</code> = 3, <code>m</code> = 3인 격자의 예시입니다.<br>
<img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/33185aef-498c-481b-a9a4-b475bcc6e7a9/ex1-2.png" title="" alt="ex1-2.png"></p>

<p>이 격자에 선로를 놓는 방법은 아래 2가지입니다.<br>
<img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/2d7f749d-3ff2-44a7-9ebb-5c5fa8da86e4/ex1-3.png" title="" alt="ex1-3.png"></p>

<p>격자의 정보를 담고 있는 2차원 정수 배열 <code>grid</code>가 매개변수로 주어집니다. 이때, 격자에 선로를 놓는 방법의 수를 return 하도록 solution 함수를 완성해 주세요. 어떻게 선로를 놓아도 문제의 조건을 만족시킬 수 없다면 0을 return 합니다.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>2 ≤ <code>grid</code>의 세로 길이 = <code>n</code> ≤ 8</li>
<li>2 ≤ <code>grid</code>의 가로 길이 = <code>m</code> ≤ 8

<ul>
<li><code>grid[i][j]</code>는 <code>(i+1, j+1)</code> 위치의 격자칸 정보를 나타냅니다. 격자칸이 빈칸인 경우 0, 선로인 경우 각 선로의 번호(1 ~ 7), 장애물인 경우 -1입니다.</li>
<li><code>grid[0][0]</code> = 1</li>
<li><code>grid[n-1][m-1]</code> = 1 or 2</li>
<li><code>grid</code>에서 빈칸이 한 번 이상 등장합니다.</li>
</ul></li>
<li><code>n</code> × <code>m</code> ≤ 20</li>
</ul>

<hr>

<h5>테스트 케이스 구성 안내</h5>

<p>아래는 테스트 케이스 구성을 나타냅니다. 각 그룹은 하나 이상의 하위 그룹으로 이루어져 있으며, 하위 그룹의 모든 테스트 케이스를 통과하면 해당 그룹에 할당된 점수를 획득할 수 있습니다.</p>
<table class="table">
        <thead><tr>
<th>그룹</th>
<th>총점</th>
<th>추가 제한 사항</th>
</tr>
</thead>
        <tbody><tr>
<td>#1</td>
<td>35%</td>
<td>3번 선로를 고려하지 않아도 되는 경우만 주어집니다.</td>
</tr>
<tr>
<td>#2</td>
<td>65%</td>
<td>추가 제한 사항 없음</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>grid</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[[1, 0, -1], [0, 0, 7], [0, 0, 2]]</td>
<td>2</td>
</tr>
<tr>
<td>[[1, 0, 0, 0, 0, -1, -1], [-1, 0, 0, 1, 0, 0, 1]]</td>
<td>2</td>
</tr>
<tr>
<td>[[1, 0, 0, 0, 0], [0, 0, 3, 0, 2], [0, 0, 0, 0, 2]]</td>
<td>4</td>
</tr>
<tr>
<td>[[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 1]]</td>
<td>644</td>
</tr>
<tr>
<td>[[1, 7], [0, 2]]</td>
<td>1</td>
</tr>
<tr>
<td>[[1, -1, 0, 0], [-1, 0, 0, 0], [0, 0, 0, -1], [0, 0, -1, 1]]</td>
<td>0</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong></p>

<p>문제 예시와 같습니다.</p>

<p><strong>입출력 예 #2</strong></p>

<p>격자의 배치는 아래 그림과 같습니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/2f9db054-63cc-49c7-9f60-b65d70955a75/ex2-1.png" title="" alt="ex2-1.png"></p>

<p>이 격자에 선로를 놓는 방법은 아래 2가지입니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f48379cb-408b-432c-b679-b9318604f725/ex2-2.png" title="" alt="ex2-2.png"></p>

<p><strong>입출력 예 #3</strong></p>

<p>격자의 배치는 아래 그림과 같습니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/d10259c1-dcf7-425e-80b5-2f1810ac908b/ex3-1.png" title="" alt="ex3-1.png"></p>

<p>이 격자에 선로를 놓는 방법은 아래 4가지입니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/5218a06e-1183-4203-a6a6-a5a2409b4156/ex3-2.png" title="" alt="ex3-2.png"></p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/b434f08a-e373-4537-a624-6ab72329ce06/ex3-3.png" title="" alt="ex3-3.png"></p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/687e994e-bfe6-4d27-8689-5b5b1f9a9df9/ex3-4.png" title="" alt="ex3-4.png"></p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/05375063-a1a4-47b7-b46e-fed000d455f3/ex3-5.png" title="" alt="ex3-5.png"></p>

<p><strong>입출력 예 #4</strong></p>

<p>격자의 배치는 아래 그림과 같습니다.</p>

<p><img src="https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/67f5d9dd-ab19-4ab0-8b65-52331e7f0257/ex4-1.png" title="" alt="ex4-1.png"></p>

<p>이 격자에 선로를 놓는 방법은 644가지입니다.</p>

<p><strong>입출력 예 #5</strong></p>

<p>선로가 이미 완성되어 있습니다. 선로를 놓지 않는 것도 한 가지 방법으로 세며, 따라서 1을 return 합니다.</p>

<p><strong>입출력 예 #6</strong></p>

<p>어떻게 선로를 놓아도 문제의 조건을 만족시킬 수 없으므로 0을 return 합니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges