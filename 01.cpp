#include <iostream>
#include <string>

using namespace std;

string toBin(int num); // 10������ 2������
string toOct(int num); // 10������ 8������
bool check(string str); // �ش� ���� ��Ī������ Ȯ��

int main() {
	int num = 11; // 10�̻��� ���� ���� Ȧ�� 11

	while (true) {
		string ten_str = to_string(num);
		string bin_str = toBin(num);
		string oct_str = toOct(num);

		if (check(ten_str) && check(bin_str) && check(oct_str)) { // 10, 2, 8������ ��ȯ���� �� ��� ��Ī���� ���
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

	if (num != 0) // ������ �������� �������� 0�� ���� ���� ���ڸ��� 0�̱� ������ �߰����� ����
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
		if (str[i] != str[str.length() - i - 1]) // ���� ���������� �ϳ��� �߰����� ���鼭 ��
			return false;
	}
	return true; // ��� ������ �� ���� ���
}