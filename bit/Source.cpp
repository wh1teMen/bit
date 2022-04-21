#include<iostream>
#include <cmath>
#include<Windows.h>
#include <string>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define chui(s)(unsigned int)(s)
int tobinary(char num);
string tobinary(short num);
string tobinary(int num);
//������ 2
int tohex(string &binStr);
//������ 3
void fillArr(int arr[], int length, int min, int max);



int main() {
	setlocale(LC_ALL, "ru");

	/*char tmp = '0';
	tmp++;
	cout << tmp << endl;
		//������� ��������*/
	/*unsigned char s = 176;
	unsigned int n = 5<<3;
	cout << "5 ���� ����� << 3 = " << n << endl;
	n = 35>>3;
	cout << "35 ����� ������ >> 3 = " <<n<< endl;
	s = 100;
	unsigned char ds = ~s;
	cout << "~" << chui(s)<< " = " <<chui(ds) << endl;
	s = 154;// 10011010
	ds = 171;//10101011
			 //10001010 - 138;
	cout << chui(s) << " & " << chui(ds) << " = " << chui(s & ds) << endl;
	s = 152; // 10011000
	ds = 43; // 00101011
			 // 00101011 - 187
	cout << chui(s) << " | " << chui(ds) << " = " << chui(s | ds) << endl;
	s = 152; // 10011000
	ds = 43;//  00101011
			//  10110011 - 179
	cout << chui(s) << " ^ " << chui(ds) << " = " << chui(s ^ ds) << endl;*/
	//������� �����
	/*cout << "������ 1\n";
	char z11 =70 ; //01000110
    short z12 =15000; //11101010011000
	int z13 =123124123 ; // 111010101101011100110011011
	cout << "char "<<chui(z11)<<" = "<<tobinary(z11) << endl;
	cout << "short  "<<chui(z12) <<" = " << tobinary(z12) << endl;
	cout << "int  " <<chui(z13)<<" = "<< tobinary(z13) << endl;
	system("pause>null");*/
	/*cout << "������ 2\n";
	string binStr;
	cout << "������� �������� ���: ";
	cin >> binStr;
	
	try {
		cout << tohex(binStr)<<"\n\n";
	}
	catch (const invalid_argument& ex) {
		cout << "������" << ex.what() << endl;
	}*/
	//������
	cout << "������ 3.\n������� ������ �������: ";
	int size;
	cin >> size;
	int* dArr = new int[size];
	cout << "������� ������ � ����� ���������: ";
	int a, b;
	cin >> a >> b;
	
	try
	{
		fillArr(dArr, size, a, b);
		cout << "����������� ������:\n[";
		for (int i = 0; i < size; i++) {
			cout << dArr[i] << ", ";
			
		}
		cout << "\b\b]\n";
	}
	catch (const range_error &ex){
		cout << "������ ���������: " << ex.what() << endl;
	}
	catch (const underflow_error& ex) {
		cout << "������ �����: " << ex.what() << endl;
	}




	return 0;
}
//�������������� ����������� ����� � �������� ���
int tobinary(char num) {
	int res = 0;//������ � ���� �������� �����
	for (int i = 7; i >=0; i--){
		res += (num>>i&1)*pow(10,i);
	}
	return res;
}
string tobinary(short num) {
	string res;//������ � ���� �������� �����
	for (int i = 15; i >= 0; i--) {
		res += to_string(num >> i & 1);
	}
	return res;
}
string tobinary( int num) {
	string res;//������ � ���� �������� �����
	for (int i = 31; i > 0; i--) {
		res += to_string(num >> i & 1);
	}
	return res;
}
//��������� �������� ��� � ��������������� ��� � �����
int tohex(string &binStr) {
	for (int i = 0; i < binStr.length(); i++) {
		if (binStr[i] != '0' && binStr[i] != '1')
			throw invalid_argument("not binary");
	}
	int res = 0;
	for (int i = binStr.length()-1; i >=0; i--){
		res += (int)(binStr[binStr.length() - i - 1] - 48) * pow(2, i);
	}
	




	return res;
}
//������ 4. ���������� ������� ���������� �������
void fillArr(int arr[], int length, int min, int max) {
	if (min > max)
		throw range_error("min > max");
	if (length <= 0)
		throw underflow_error("not positive length");
	srand(time(NULL));
	for (int i = 0; i < length; i++){
		arr[i] = rand() % (max - min) + min;
	}


}
