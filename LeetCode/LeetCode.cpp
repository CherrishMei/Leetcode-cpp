// LeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include "LeetCodeVector.h"
#include"hash.h"
#include<vector>
#include<string>
using namespace std;


int main()
{
	/*number nu;
	int n;
	cin >> n;
	if (nu.is3(n)) {
		cout << n << "是3的倍数" << endl;
	}
	else {
		cout << n << "不是3的倍数" << endl;
	}*/

	//哈希表部分
	Hash hash;
	//T17
	/*
	string digits;
	while (1) {
		vector<string> a;
		cin >> digits;
		if (digits == "qq") break;
		a = hash.letterCombinations(digits);
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	
	
	
	//T3
	string s;
	cin >> s;
	cout << hash.lengthOfLongestSubstring(s) << endl;
	/*
	//T12
	int num;
	while (1) {
		cin >> num;
		if (num == 0)break;
		cout << hash.intToRoman(num) << endl;
	}

	//T13
	string s;
	while (1) {
		cin >> s;
		if (s == "a")break;
		cout << hash.romanToInt(s) << endl;
	}
	//T17:电话号码
	string digit;
	while (1) {
		cin >> digit;
		if (digit == "a")break;
		vector<string> c = hash.letterCombinations(digit);
		for (int i = 0; i < c.size(); i++) {
			cout << c[i] << " ";
		}
		cout << endl;
	}*/
		//Vector部分
		/*leetCodeCode solution;

		//vector<int> twoSum(vector<int>& nums, int target):
		vector<int> nums(2);
		nums= {3,3};
		int target = 6;
		vector<int> c1(2);
		c1.resize(2);
		c1 = solution.twoSum(nums, target);
		for (int i = 0; i < 2; i++) {
			cout << c1[i] << " ";
		}
		cout << endl;



		//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
		vector<int> nums1(2);
		nums1.resize(2);
		nums1 = {1,2};
		vector<int> nums2(2);
		nums2.resize(2);
		nums2 = { 3,4 };
		cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

		//int maxArea(vector<int>& height)
		vector<int>Height(9);
		Height.resize(9);
		Height = { 1,8,6,2,5,4,8,3,7 };
		cout << solution.maxArea(Height);

		//vector<vector<int>> threeSum(vector<int>& nums)
		vector<int>nums(11);
		nums.resize(11,-1);
		nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};

		vector<vector<int>> nums1;
		vector<int> temp(100, -9999999);
		nums1.resize(100, temp);
		nums1 = solution.threeSum1(nums);
		int n = nums1.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cout << nums1[i][j] << " ";
			}
			cout << endl;
		}*/


		/*
		//int threeSumClosest(vector<int>& nums, int target)
		vector<int>nums(3);
		nums.resize(3, -1);
		nums = {0,0,0};
		int target = 1;
		cout << "三个数之和为：" << solution.threeSumClosest(nums, target);


		//vector<vector<int>> fourSum(vector<int>& nums, int target)
		vector<int>nums(6);
		nums.resize(6, -1);
		nums = {1,0,-1,0,-2,2};
		int target = 0;

		vector<vector<int>> nums1;
		vector<int> temp(100, -9999999);
		nums1.resize(100, temp);
		nums1 = solution.fourSum(nums,target);
		int n = nums1.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				cout << nums1[i][j] << " ";
			}
			cout << endl;
		}

		vector<int>nums(3);
		nums.resize(3, -1);
		nums = {3,2,1};
		solution.nextPermutation(nums);
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		}
		cout << endl;

		vector<int>nums(2);
		nums.resize(2, -1);
		nums = {2,5};

		cout << solution.search(nums, 2) << endl;



		int n = 1;
		cout << solution.firstBadVersion(n)<< endl;

		vector<int>nums(2);
		nums.resize(2, -1);
		nums = {1,3};
		int target = 2;
		cout << solution.searchInsert(nums, target) << endl;
		vector<vector<char>> board;
		vector<char> temp;
		char a;
		for (int i = 0; i < 9; ) {
			for (int j = 0; j < 9; ) {
				cin >> a;
				if (a == '[' || a == ']' || a == '\"'||a==',') {
					continue;
				}
				//cout << a << " ";
				temp.push_back(a);
				j++;
			}
			//cout << endl;
			board.push_back(temp);
			i++;
			while (1) {
				temp.pop_back();
				if (temp.empty()) {
					break;
				}
			}
		}*/
		/*for (int ii = 0; ii < 9; ii++) {
			for (int jj = 0; jj < 9; jj++) {
				cout << board[ii][jj] << " ";
			}
			cout << endl;
		}*/
		//cout << solution.isValidSudoku(board) << endl;
		/*
		[["5","3",".",".","7",".",".",".","."],
		["6",".",".","1","9","5",".",".","."],
		[".","9","8",".",".",".",".","6","."],
		["8",".",".",".","6",".",".",".","3"],
		["4",".",".","8",".","3",".",".","1"],
		["7",".",".",".","2",".",".",".","6"],
		[".","6",".",".",".",".","2","8","."],
		[".",".",".","4","1","9",".",".","5"],
		[".",".",".",".","8",".",".","7","9"]]
		*/

}



