#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
class Hash {
public:
	//T3�����ظ��ַ�����ִ�
	int lengthOfLongestSubstring(string s) {
		vector<int> hash;
		hash.resize(130, 0);
		int max = 0;
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int p = 0; p < 120; p++) {
				hash[p] = 0;
			}
			for (int j = i; j < s.length(); j++) {
				hash[s[j]]++;
				if (hash[s[j]] > 1) {
					break;
				}
				count++;
			}
			if (count > max) {
				max = count;
			}
			count = 0;
		}
		return max;
	}

	//T12:ת��������
	string intToRoman(int num) {
		string s;
		int a = 0, b = 0, c = 0, d = 0;//a:����b:ʮ��c:�٣�d:ǧ
		//�Ȳ�ָ���λ��
		if (num/10==0) {//n == 1
			a = num;
		}
		if (num/100==0) {//n == 2
			a = num % 10;
			b = num / 10;
		}
		if (num/1000==0) {//n == 3
			a = num % 10;
			b = ((num - a) % 100)/10;
			c = num / 100;
		}
		if (num/10000==0) {//n == 4
			a = num % 10;
			b = ((num - a) % 100) / 10;
			c = ((num - a - b * 10) % 1000) / 100;
			d = num / 1000;
		}
		else {
			cout << "������������" << endl;
		}
		cout << "a:" << a << "b:" << b << "c:" << c << "d:" << d << endl;
		//��d��ʼ�������ſ�
		//d
		for (int i = 0; i < d; i++) {
			s += "M";
		}
		//c
		if (c == 4) {
			s += "CD";
		}
		else if (c == 5) {
			s += "D";
		}
		else if (c == 9) {
			s += "CM";
		}
		else if (c < 4) {
			for (int i = 0; i < c; i++) {
				s += "C";
			}
		}
		else if (c > 5) {
			s += "D";
			for (int i = 0; i < c-5; i++) {
				s += "C";
			}
		}
		//b
		if (b == 4) {
			s += "XL";
		}
		else if (b == 5) {
			s += "L";
		}
		else if (b == 9) {
			s += "XC";
		}
		else if (b < 4) {
			for (int i = 0; i < b; i++) {
				s += "X";
			}
		}
		else if (b > 5) {
			s += "L";
			for (int i = 0; i < b-5; i++) {
				s += "X";
			}
		}
		//a
		if (a == 4) {
			s += "IV";
		}
		else if (a == 5) {
			s += "V";
		}
		else if (a == 9) {
			s += "IX";
		}
		else if (a < 4) {
			for (int i = 0; i < a; i++) {
				s += "I";
			}
		}
		else if (a > 5) {
			s += "V";
			for (int i = 0; i < a-5; i++) {
				s += "I";
			}
		}
		return s;
	}
	//T13:��������ת����
	int romanToInt(string s) {
		int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string reps[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		int n = s.length();
		int x = 0;
		vector<string> a;
		//���
		for (int i = 0; i < n; i++) {
			if (s[i] == 'M') x += 1000;
			if (s[i] == 'D') x += 500;
			if (s[i] == 'C') {
				if (i < n - 1) {
					if (s[i + 1] == 'D') {
						x += 400;
						i++;
					}
					else if (s[i + 1] == 'M') {
						x += 900;
						i++;
					}
					else x += 100;
				}
				else x += 100;
			}
			if (s[i] == 'L')x += 50;
			if (s[i] == 'X') {
				if (i < n - 1) {
					if (s[i + 1] == 'L') {
						x += 40;
						i++;
					}
					else if (s[i + 1] == 'C') {
						x += 90;
						i++;
					}
					else x += 10;
				}
				else x += 10;
			}
			if (s[i] == 'V')x += 5;
			if (s[i] == 'I') {
				if (i < n - 1) {
					if (s[i + 1] == 'V') {
						x += 4;
						i++;
					}
					else if (s[i + 1] == 'X') {
						x += 9;
						i++;
					}
					else x += 1;
				}
				else if(i==n-1) x += 1;
			}
		}
		return x;
	}
	//T17:�绰������������
	vector<string> letterCombinations(string digits) {
		string hash[9][4] = { {"a","b","c"},{"d","e","f"},
		{"g","h","i"},{"j","k","l"},{"m","n","o"},
		{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"} };

		int n = digits.length();//�ó��������ִ��ĳ���
		//�õ�����֮�������Ҫ���ص������ĳ���

		vector<int> a;//a������Ÿ�λ����
		for (int i = 0; i < n; i++) {
			int t = digits[i] - 48;
			a.push_back(t);
			cout << a[i] << " ";
		}
		cout << endl;

		vector<int> b;//��b����ų���
		for (int i = 0; i < n; i++) {
			if (a[i] == 7 || a[i] == 9) {
				b.push_back(4);
			}
			else {
				b.push_back(3);
			}
			cout << b[i] << " ";
		}
		cout << endl;

		//����ܳ���
		int len = 1;//len����ʾ�ܳ���
		for (int i = 0; i < n; i++) {
			len *= b[i];
		}
		cout << len << endl;
		vector<string> c;//����Ҫ���ص�string���͵�����
		string t;
		c.resize(len);
		int num = len/num;//��ʾѭ������,ÿ��ѭ�������Ա���ѭ���Ĳ�ĸ���
		//���Ȱѵ�һ��push��ȥ
		for (int j = 0; j < b[0]; j++) {//����ǰ�����ĸpush�����ص�������
			for (int k = 0; k < len/b[0]; k++) {
				c.push_back(hash[a[0] - 2][j]);
			}
		}
		/*
		//�ٰ�ʣ������ݼӽ�ȥ
		for (int i = 1; i < n; i++) {//��Ϊ��n�����֣�����Ҫѭ����ȥ��һ��֮���
			num = num / b[i];//�õ�Ҫpush������ǰ�����ĸ
			for (int j = 0; j < b[i]; j++) {//����ǰ�����ĸpush�����ص�������
				
			}

			
		}*/
		return c;
	}
};