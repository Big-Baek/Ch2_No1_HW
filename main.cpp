#include <iostream>
#include<string>
#include<algorithm>

using namespace std;


int* New_arr(int n) {
	int m; //�Է¹��� ����

	int* arr = new int[n]; //�����Ҵ�

	for (int i = 0; i < n; i++) { //�迭�� ������ �Է�
		cin >> m;
		arr[i] = m;
	}
	return arr; //�Էµ� �迭 ����
}

void up_Sort(int n, int* arr) {//�������� ����

	for (int i = 0; i < n - 1; i++) { //�� �ε��� ����, sizeof �Լ� ���� ���ǳ�
		for (int j = 0; j < n - 1 - i; j++) {//���õ� �ε����� ���� �ε����� ��
			if (arr[j] > arr[j + 1]) {//���ڰ� �� ������ �ڸ� ����
				int imsi = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = imsi;
			}
		}
	}

	for (int i = 0; i < n; i++) {//�迭�� ���ʴ�� ���
		cout << arr[i] << " ";
	}
	cout << endl;
}

void down_Sort(int n, int* arr) {//�������� ����
	for (int i = 0; i < n - 1; i++) { 
		for (int j = 0; j < n - 1 - i; j++) {//���õ� �ε����� ���� �ε����� ��
			if (arr[j] < arr[j + 1]) {//���ڰ� �� ũ�� �ڸ� ����
				int imsi = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = imsi;
			}
		}
	}
	for (int i = 0; i < n; i++) {//�迭�� ���ʴ�� ���

		cout << arr[i] << " ";
	}
	cout << endl;
}

int sum(int n, int* arr) {
	int Sum = 0;
	for (int i = 0; i < n; i++) {
		Sum += arr[i];
	}
	return Sum;
}

int avr(int n, int* arr) {

	int Avr = sum(n, arr) / n;

	return Avr;
}

int main() {

	int n; //�Է¹��� ����
	int order = 10; //�ǹ� ���� ��
	cout << "��� ���� �Է����� �Է����ּ���" << endl;
	cin >> n;

	int* arr = New_arr(n); //�����Ҵ� �Լ�

	while (order != 0) { //0�� ������ ����
		cout << "1���� ��������, 2���� ��������, 3���� ����, 4���� ���, ����� 0�� " << endl;
		cin >> order; //��ȣ�Է����� ���
		switch (order) {
		case 1: up_Sort(n, arr); //�������� ����
			break;
		case 2: down_Sort(n, arr);//�������� ����
			break;
		case 3: cout << "������:" << " " << sum(n, arr) << endl; //���� ���
			break;
		case 4: cout << "�����:" << " " << avr(n, arr) << endl; //��� ���
			break;
			cout << "�߸��� �Է��Դϴ� �ٽ� �Է��ϼ���" << endl;
		}
	}

	delete arr;
	return 0;
}