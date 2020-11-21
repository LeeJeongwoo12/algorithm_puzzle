#include <iostream>
#include <string>

using namespace std;

string make_string(string num, char *op, int j, int k, int l);
int calc(string s);
string reverse(int num);

int main() {
	char op[] = { '*', ' ' };
	string temp;
	
	for (int i = 1000; i < 10000; i++) {
		string num = to_string(i);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					if (j && k && l)
						continue;
					temp = make_string(num, op, j, k, l);

					if (to_string(calc(temp)) == reverse(i)) {
						cout << i << endl;
						break;
					}
				}
			}
		}
	}
}

string make_string(string num, char *op, int j, int k, int l) {
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

int calc(string s) {
	int temp = 0;
	int answer = 1;

	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			temp *= 10;
			temp += s[i] - '0';
		}
		if (s[i] == '*') {
			answer = answer * temp;
			temp = 0;
		}
	}

	answer *= temp;

	return answer;
}

string reverse(int num) {
	string s = to_string(num);
	
	string temp = "";

	for (int i = s.length() - 1; i >= 0; i--) {
		temp += s[i];
	}

	return temp;
}
