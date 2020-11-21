// 1 ~ N까지의 번호가 적힌 카드가 존재
// 2 ~ N 사이의 x번부터 x만큼 더해가면서 카드를 뒤집음
// ex) 3번부터 3, 6, 9, 12, ... , 99가 적힌 카드를 뒤집음
// 마지막에 뒤집혀있지 않은 카드를 모두 출력

#include <iostream>

#define N 100 // N을 임의로 100으로 가정

using namespace std;

int main() {
	bool card[N + 1] = { false, };

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			card[j] = !card[j];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!card[i])
			cout << i << " ";
	}
}
