#include <iostream>
#include <string>

using namespace std;

string toBin(int num); // 10진수를 2진수로
string toOct(int num); // 10진수를 8진수로
bool check(string str); // 해당 수가 대칭수인지 확인

int main() {
	int num = 11; // 10이상의 가장 작은 홀수 11

	while (true) {
		string ten_str = to_string(num);
		string bin_str = toBin(num);
		string oct_str = toOct(num);

		if (check(ten_str) && check(bin_str) && check(oct_str)) { // 10, 2, 8진수로 변환했을 때 모두 대칭수인 경우
			cout << "Num : " << num << " Bin : " << bin_str << " Oct : " << oct_str << endl;
			break;
		}

		num += 2;
	}
}

string toBin(int num) {
	string str;
	while (num > 1) {
		string temp = to_string(num % 2);

		str.insert(0, temp);

		num = num / 2;
	}

	if (num != 0) // 끝까지 나눴을때 나머지가 0인 경우는 제일 앞자리도 0이기 때문에 추가하지 않음
		str.insert(0, to_string(num));

	return str;
}

string toOct(int num) {
	string str;

	while (num > 1) {
		string temp = to_string(num % 8);
		str.insert(0, temp);

		num = num / 8;
	}

	if(num != 0)
		str.insert(0, to_string(num));

	return str;
}

bool check(string str) {
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - i - 1]) // 양쪽 끝에서부터 하나씩 중간으로 오면서 비교
			return false;
	}
	return true; // 모두 비교했을 때 같은 경우
}