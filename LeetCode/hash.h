#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
class Hash {
public:
	//T3：无重复字符的最长字串
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

	//T12:转罗马数字
	string intToRoman(int num) {
		string s;
		int a = 0, b = 0, c = 0, d = 0;//a:个，b:十，c:百，d:千
		//先拆分各个位数
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
			cout << "输入数据有误！" << endl;
		}
		cout << "a:" << a << "b:" << b << "c:" << c << "d:" << d << endl;
		//从d开始看，倒着看
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
	//T13:罗马数字转整数
	int romanToInt(string s) {
		int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string reps[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		int n = s.length();
		int x = 0;
		vector<string> a;
		//拆分
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
	//T17:电话号码的数字组合
	vector<string> letterCombinations(string digits) {
		string hash[9][4] = { {"a","b","c"},{"d","e","f"},
		{"g","h","i"},{"j","k","l"},{"m","n","o"},
		{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"} };

		int n = digits.length();//得出输入数字串的长度
		//得到长度之后，再求得要返回的容器的长度

		vector<int> a;//a用来存放各位数字
		for (int i = 0; i < n; i++) {
			int t = digits[i] - 48;
			a.push_back(t);
			cout << a[i] << " ";
		}
		cout << endl;

		vector<int> b;//用b来存放长度
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

		//求得总长度
		int len = 1;//len：表示总长度
		for (int i = 0; i < n; i++) {
			len *= b[i];
		}
		cout << len << endl;
		vector<string> c;//定义要返回的string类型的数组
		string t;
		c.resize(len);
		int num = len/num;//表示循环次数,每次循环都除以本次循环的层的个数
		//首先把第一层push进去
		for (int j = 0; j < b[0]; j++) {//将当前层的字母push进返回的容器中
			for (int k = 0; k < len/b[0]; k++) {
				c.push_back(hash[a[0] - 2][j]);
			}
		}
		/*
		//再把剩余的内容加进去
		for (int i = 1; i < n; i++) {//因为有n个数字，所以要循环除去第一次之外的
			num = num / b[i];//得到要push几个当前层的字母
			for (int j = 0; j < b[i]; j++) {//将当前层的字母push进返回的容器中
				
			}

			
		}*/
		return c;
	}
};