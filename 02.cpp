// 1000 ~ 9999 사이의 수에 사칙 연산을 무작위로 삽입한 결과가, 원래 수를 거꾸로 나열한 것과 같은 수를 찾는 문제
// ex) 1234 : 원래 수, 1 * 2 + 34 = 36 != 4321 -> 아님

#include <iostream>
#include <string>

using namespace std;

string make_string(string num, char *op, int j, int k, int l);
int calc(string s);
string reverse(int num);

int main() {
	char op[] = { '*', ' ' }; // * 이외의 연산자를 사용하면 원래 수가 절대 나올 수 없음, 가장 큰 수인 9999의 경우에도 +를 하나라도 사용 시 1008밖에 되지 않음
	string temp;
	
	for (int i = 1000; i < 10000; i++) {
		string num = to_string(i);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					if (j && k && l) // 연산자를 하나 이상 사용해야 함
						continue;
					temp = make_string(num, op, j, k, l); // 연산자를 각 자리수 사이에 삽입

					if (to_string(calc(temp)) == reverse(i)) { // 비교 후 같다면 출력
						cout << i << endl;
						break;
					}
				}
			}
		}
	}
}

string make_string(string num, char *op, int j, int k, int l) { // 연산자를 각 자리수 사이에 삽입하는 함수
	string s = "";
	s += num[0];
	s += op[j];
	s += num[1];
	s += op[k];
	s += num[2];
	s += op[l];
	s += num[3];

	return s;
}

int calc(string s) { // 연산자가 포함된 문자열을 계산하는 함수
	int temp = 0;
	int answer = 1;

	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') { // 1 ~ 9 사이인 경우, 현재까지 더했던 수에 10을 곱하고, 새로운 수를 더함
			temp *= 10;
			temp += s[i] - '0';
		}
		if (s[i] == '*') { // *의 경우, 현재까지 계산한 수와 더했던 수를 곱함
			answer = answer * temp;
			temp = 0;
		}
	}

	answer *= temp;

	return answer;
}

string reverse(int num) { // 숫자를 거꾸로
	string s = to_string(num);
	
	string temp = "";

	for (int i = s.length() - 1; i >= 0; i--) {
		temp += s[i];
	}

	return temp;
}
