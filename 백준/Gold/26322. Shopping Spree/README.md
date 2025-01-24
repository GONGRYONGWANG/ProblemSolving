# [Gold III] Shopping Spree - 26322 

[문제 링크](https://www.acmicpc.net/problem/26322) 

### 성능 요약

메모리: 2512 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2025년 1월 25일 03:59:46

### 문제 설명

<p>You've won a shopping spree with a very peculiar rule. The items you are allowed to take are in consecutive order, indexed 1 through n. You may select any subset of these items subject to the following constraint:</p>

<blockquote>
<p>For each index k of items chosen for the subset at most half of the items with indexes 1 through k may be in the subset</p>
</blockquote>

<p>For example, if the item with index 10 is chosen for the subset, then your selected subset can contain at most half of the items with index 1 through 10. Similarly, if the item with index 2 is chosen for the subset, then your selected subset can contain at most half of the items with index 1 through 2. Note that “half” is an integer value so half of 10 and 11 are both 5. The only exception to the constraint is that if the item with index 1 is chosen for the subset, you can select 1 item and not zero (to be fair).</p>

<p>Given a list of the dollar values of items, I<sub>1</sub>, I<sub>2</sub>, … I<sub>n</sub>, in the shopping spree, determine the maximum value you can obtain from the shopping spree subject to the above constraint.</p>

### 입력 

 <p>The first line of the input is a positive integer, n, indicating the number of shopping sprees that your program will have to analyze. Following this will be the descriptions of each shopping spree. Each shopping spree will be described on a single line. The first value on each of these lines will be a single positive integer, s (s ≤ 500), representing the number of items for the shopping spree. The next s space-separated positive integers will be the values for the shopping spree items in dollars, in order. Each of these values will be less than or equal to 10<sup>6</sup>.</p>

### 출력 

 <p>For each shopping spree, first output the heading “Spree #d: ”, where d is the spree number, starting with 1. Then, print a single integer equal to the maximum value, in dollars, that can be obtained for that shopping spree. Follow the format illustrated in Sample Output.</p>

