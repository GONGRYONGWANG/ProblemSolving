# [Platinum II] Installing Apps - 15607 

[문제 링크](https://www.acmicpc.net/problem/15607) 

### 성능 요약

메모리: 41908 KB, 시간: 1276 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 정렬

### 제출 일자

2025년 1월 19일 03:32:41

### 문제 설명

<p>Sandra recently bought her first smart phone. One of her friends suggested a long list of applications (more commonly known as “apps”) that she should install on the phone. Sandra immediately started installing the apps from the list, but after installing a few, the phone did not have enough disk space to install any more apps. Sometimes, the app installation failed because there was not even enough space to download the installation package. Other apps could be downloaded just fine, but had insufficient space to store the installed app.</p>

<p>Each app that Sandra installs has a download size d and a storage size s. To download the app, Sandra’s phone must have at least d megabytes of free disk space. After the app has been installed, it then uses s megabytes of disk space on the phone. The download size may be smaller than the storage size (e.g., if the app data is heavily compressed) or larger than the storage size (e.g., if the download contains material that might not get used such as translations to different languages). The installer is very efficient and can transform the downloaded package to an installed app without using any extra disk space. Thus, to install an app, the phone must have at least max(d, s) megabytes of free disk space.</p>

<p>Sandra quickly realised that she may have run out of space just because she installed apps in the wrong order. Thus, she decided to give the installation another try. She uninstalled all apps, and will now choose an installation order that lets her install the largest number of apps from the list. Sandra may not install any app more than once.</p>

<p>Help her determine what apps on the list she should install, and in what order.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers n, c (1 ≤ n ≤ 500, 1 ≤ c ≤ 10 000), the number of available apps and the available disk space of the phone in megabytes.</li>
	<li>n lines, each with two integers d, s (1 ≤ d, s ≤ 10 000), the download size and storage size of an app, in megabytes.</li>
</ul>

### 출력 

 <p>Output one line with the maximum number of apps that can be installed. Then output one line listing the numbers of those apps, in the order that Sandra should install them. In the case that no apps can be installed, this line can be omitted.</p>

<p>The apps are numbered from 1 to n, in the order they are given in the input. If there are multiple optimal solutions, output any one of them.</p>

