// n cm의 막대를 m 명이서 자를 때, 모든 막대가 1cm가 되기 위한 최소 횟수를 구하는 문제
// 거꾸로 생각해서, m 명이서 n cm의 막대를 만드는 것으로 해결

#include <iostream>
#include <queue>

#define N 100
#define M 5

using namespace std;

int main() {
	queue<int> q;
	int sum = 0;
	int count = 0; // m 명 중 몇 명이 막대를 합쳤는지 확인하기 위한 변수
	int answer = 1;

	for (int i = 0; i < M; i++) { // 만들어진 막대가 없기 때문에 M 명의 사람이 각자 막대를 만듬
		q.push(2);
		sum += 2;

		if (sum == N) { // N cm의 막대를 만들었을 경우 종료
			cout << "1\n";
			return 0;
		}
	}

	int qSize;

	while (q.front() != N) { // 아래 조건문에서 sum이 N보다 커지면 더 이상 새로운 막대를 만들지 않기 때문에, 해당 조건을 만족하는 횟수가 정답이 됨
		count = 0;
		qSize = q.size(); // 현재 q의 크기

		if (qSize >= 2) { // q에서 막대를 두 개씩 사용해서 합하기 때문에 size가 2보다 커야 함
			for (int i = 1; i < qSize; i += 2) { // 두 개의 막대를 사용하기 때문에, i+=2
				int n, m;
				n = q.front(); q.pop();
				m = q.front(); q.pop();

				q.push(n + m); // 합한 막대를 다시 q에 삽입
				count++;
			}
		}

		for (int i = count; i < M; i++) {
			if (sum + 2 <= N) { // 모든 막대 길이의 합은 N만큼만 되면 됨
				q.push(2);
				sum += 2;
			}
		}

		answer++;
	}

	cout << answer;

	return 0;
}
