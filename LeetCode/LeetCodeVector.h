#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class leetCodeCode {
public:

	//求两数之和，给定一个整数数组 nums 和一个整数目标值 target，
	//请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
	//思路：遍历数组，把<9/2的数字放在一组，把<=9且>=9/2的放在一组，把>9的丢弃
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();//得到数组的长度
		vector<int> nums3;//返回的数组
		vector<vector<int>> nums1;
		vector<vector<int>> nums2;
		nums3.resize(2, -99999999);
		vector<int> temp(2,-9999999);
		nums1.resize(n, temp);
		nums2.resize(n, temp);
		//j,k用来表示nums1和nums2的长度
		int j = 0;
		int k = 0;
		int x = target / 2 ;

		for (int i = 0; i < n; i++) {
			if (nums[i] <= x) {
				//cout << nums[i] << endl;
				nums1[j][0] = nums[i];
				nums1[j][1] = i;
				j++;
			}
			if (nums[i] > x) {
				nums2[k][0] = nums[i];
				nums2[k][1] = i;
				k++;
			}
		}
		/*
		for (int u = 0; u < n; u++) {
			cout << nums1[u][0]<<" ";
		}
		cout << endl;
		for (int u = 0; u < n; u++) {
			cout << nums2[u][0] << " ";
		}
		cout << endl;
		*/

		int y = 0;//看是否能够找到结果
		int s = 0;//用来计数，看nums1中target/2的个数
		//偶数在nums1里面找
		if (target % 2 == 0) {
			for (int i = 0; i < j; i++) {
				if (nums1[i][0] == target / 2) {
					nums3[s] = nums1[i][1];
					s++;
				}
			}

		}
		//负数或者
		if (s < 2) {
			for (int i = 0; i < j; i++) {
				//cout << "biaoji" << endl;
				int m = target - nums1[i][0];
				for (int p = 0; p < k; p++) {
					if (nums2[p][0] == m) {
						
						nums3[1] = nums2[p][1];
						nums3[0] = nums1[i][1];
						y = 1;
					}

				}
				if (y == 0) {
					for (int o = 0; o < j; o++) {
						if (nums1[o][0] == m) {
							nums3[1] = nums1[o][1];
							nums3[0] = nums1[i][1];
							y = 1;
						}
					}
				}
			}

		}
		return nums3;
	}
	

	//求两个数组的中位数
	//思路：两个有序数组合为一个有序数组，然后根据n1+n2的值的奇数或者偶数来求得中位数
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//求出两个数组的长度，备用
		int n1 = nums1.size();
		int n2 = nums2.size();

		//将两个有序数组合为一个有序数组

		//先定义一个容器用来存放有序数组
		vector<int> nums;
		nums.resize(n1 + n2, -9999);//初始化该数组
		int i = 0, j = 0, k = 0;
		//生成有序的总数组
		while (1) {
			if (i < n1&&j < n2) {
				if (nums1[i] <= nums2[j]) {
					nums[k] = nums1[i];
					k++;
					i++;
				}
				else {
					nums[k] = nums2[j];
					k++;
					j++;
				}
				
			}
			if((i==n1)&&(j<n2)) {
				nums[k] = nums2[j];
				k++;
				j++;
			}
			if ((i<n1)&&(j == n2)) {
				nums[k] = nums1[i];
				k++;
				i++;
			}
			if (i == n1 && j == n2) {
				break;
			}
		}
		/*for (int i = 0; i < n1 + n2; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
		return 0;*/

		//如果总数组的长度是偶数的话
		if ((n1 + n2) % 2 == 0) {
			return (nums[(n1 + n2) / 2] + nums[(n1 + n2) / 2 - 1]) / 2.0;
		}
		else {
			return nums[(n1 + n2) / 2];
		}
	}


	//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
	//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
	//返回容器可以储存的最大水量。
	//说明：你不能倾斜容器。
	//思路：两个指针，分别指向头和尾，向内移动短板时，可能会使得2面积增大，而向内移动长版时则不会增大
	//因此，我们可以每次向内移动短板来看看面积是否增大，若增大，则面积等于大的，若没有，则面积不变
	int maxArea(vector<int>& height) {
		//计算数组长度，备用

		int n = height.size();

		//设置两个指针ph和pt
		int ph = 0;//开始时指向头部
		int pt = n - 1;//开始时指向尾部
		int h = 0;
		int s1 = 0, s = 0;
		while (ph<pt) {
			//h=min(ph,pt);
			if (height[ph] > height[pt]) {
				h = height[pt];
				pt--;
			}
			else {
				h = height[ph];
				ph++;
			}
			s1 = h * (pt - ph+1);
			s1 > s ? s = s1 : s = s;
		}
		return s;
	}

	//给你一个包含 n 个整数的数组 nums，
	//判断 nums 中是否存在三个元素 a，b，c ，
	//使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
	//注意：答案中不可以包含重复的三元组。
	vector<vector<int>> threeSum(vector<int>& nums) {
		//计算数组长度，备用
		int n = nums.size();

		//定义要返回的数组
		vector<vector<int>> nums1;
		vector<int>a;//用来存放三元组
		//若总共没有三个数
		if (n < 3) {
			return nums1;
		}
		//对数组进行排序
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > i; j--) {
				if (nums[j] < nums[j-1]) {
					temp = nums[j];
					nums[j] = nums[j - 1];
					nums[j - 1] = temp;
				}
			}
		}
		/*
		//验证排序是否是正确的
		for (int i = 0; i < n; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
		*/
		if (nums[0]>0) {
			return nums1;
		}

		//三个指针，分别指向开头，第二个和结尾，中间的指针作为活动者前后移动来凑0
		int p = 0;
		int q = 0;
		int r = 0;
		int s = 0;
		while (r < n - 1) {
			p = r + 1;
			q = n - 1;
			while (p < q) {
				s = nums[p] + nums[r] + nums[q];
				if (s == 0) {
					a.push_back(nums[r]);
					a.push_back(nums[p]);
					a.push_back(nums[q]);
					nums1.push_back(a);
					a.pop_back();
					a.pop_back();
					a.pop_back();
					while (1) {
						p++;
						if (p >= q) {
							break;
						}
						else {
							if ((nums[p] != nums[p - 1])) {
								break;
							}
						}
					}
					while (1) {
						q--;
						if (p >= q) {
							break;
						}
						else {
							if ((nums[q] != nums[q + 1])) {
								break;
							}
						}
					}

				}
				if (s < 0) {
					while (1) {
						p++;
						if (p >= q) {
							break;
						}
						else {
							if ((nums[p] != nums[p - 1])) {
								break;
							}
						}
					}
				}
				if (s > 0) {
					while (1) {
						q--;
						if (p >= q) {
							break;
						}
						else {
							if ((nums[q] != nums[q + 1])) {
								break;
							}
						}
					}
				}
			}
			while (1) {
				r++;
				if (r >= q) {
					break;
				}
				else {
					if ((nums[r] != nums[r - 1])) {
						break;
					}
				}
			}
		}
		return nums1;
	}
	//给你一个长度为 n 的整数数组 nums 和 一个目标值 target。
	//请你从 nums 中选出三个整数，使它们的和与 target 最接近。
	//返回这三个数的和。
	//假定每组输入只存在恰好一个解。
	int threeSumClosest(vector<int>& nums, int target) {
		//计算数组长度，备用
		int n = nums.size();

		//对数组进行排序
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > i; j--) {
				if (nums[j] < nums[j - 1]) {
					temp = nums[j];
					nums[j] = nums[j - 1];
					nums[j - 1] = temp;
				}
			}
		}

		int r = 0;
		int s = 0;
		int c = 0;//这个数代表|三个数之和-target|
		int minc = 10000000;//找到最小的差值
		int minsum = 0;//找到差值最小时的三个数之和
		while (r < n) {
			int p = r + 1;
			int q = n - 1;
			while (p < q) {
				s = nums[r] + nums[p] + nums[q];//三个数字之和
				c = s - target;//差值
				if (abs(c) < minc) {//把最小值留出来
					minc = abs(c);
					minsum = s;
					//c>0的情况
					if (c >= 0) {
						q--;
					}
					//c<0的情况
					else {
						p++;
					}
				}
				else {
					if (c >= 0) {
						q--;
					}
					//c<0的情况
					else {
						p++;
					}
				}
			}
			r++;
		}
		return minsum;
	}
	/*
	给你一个由 n 个整数组成的数组 nums ，
	和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 
	[nums[a], nums[b], nums[c], nums[d]] 
	（若两个四元组元素一一对应，则认为两个四元组重复）：
		0 <= a, b, c, d  < n
		a、b、c 和 d 互不相同
		nums[a] + nums[b] + nums[c] + nums[d] == target
		你可以按 任意顺序 返回答案 。

		这个题就先放弃了
	*/
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		//计算nums的长度，备用
		int n = nums.size();
		//定义要返回的值
		vector<vector<int>> sum;
		vector<int> temp;
		//若n<4，返回空值
		if (n < 4) {
			return sum;
		}
		//对数组进行排序
		int t = 0;
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > i; j--) {
				if (nums[j] < nums[j - 1]) {
					t = nums[j];
					nums[j] = nums[j - 1];
					nums[j - 1] = t;
				}
			}
		}
		//若排序之后最小的数字也比target大，则返回空值
		if (nums[0] > target) {
			return sum;
		}
		//定义a,b,c,d四个指针
		int a = 0;
		int b = 0;
		int c = 0;
		int d = n - 1;

		//定义四个数之和为s
		int s = 0;
		//定义k = s - target
		int k = 0;
		while (a < n) {
			b = a + 1;
			c = d - 1;
			while (c < d) {
				s = nums[a] + nums[b] + nums[c] + nums[d];
				k = s - target;
				if (k == 0) {
					temp.push_back(nums[a]);
					temp.push_back(nums[b]);
					temp.push_back(nums[c]);
					temp.push_back(nums[d]);
					sum.push_back(temp);
					temp.pop_back();
					temp.pop_back();
					temp.pop_back();
					temp.pop_back();
					
					break;
				}
				if (k > 0) {
					while (b < c) {
						c--;
						if (nums[c] != nums[c + 1]) {
							break;
						}
					}
				}
				if (k < 0) {
					while (b < c) {
						b++;
						if (nums[b] != nums[b - 1]) {
							break;
						}
					}
				}
			}
		}

		return sum;

	}

	int removeDuplicates(vector<int>& nums) {
		int k=0;
		int n = nums.size();
		int i = 0;
		while (i < n) {
			while (1) {
				i++;
				if (i >= n) {
					break;
				}
				if (nums[i] != nums[i - 1]) {
					break;
				}
			}
			nums[k] = nums[i - 1];
			k++;
			
		}
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
		return k;
		
	}

	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		int i = 0;
		int k = 0;
		while (i < n) {
			if (nums[i] != val) {
				nums[k] = nums[i];
				k++;
			}
			i++;
		}
		return k;
	}

	void nextPermutation(vector<int>& nums) {
		int n = nums.size();

		int i = n - 1;
		while (i > 0) {
			if (nums[i] >= nums[i - 1]) {
				//把后面进行排序
				for (int p = i; p < n; p++) {
					for (int q = n - 1; q > i; q--) {
						if (nums[q] < nums[q - 1]) {
							int te = nums[q];
							nums[q] = nums[q - 1];
							nums[q - 1] = te;
						}
					}
				}
				for (int h = 0; h < n; h++) {
					cout << nums[h] << "  ";
				}
				cout << endl;
				//把排序结果中的第一个比i-1大的跟i-1换过来
				int k = 0;
				for (int p = i; p < n; p++) {
					if (nums[p] > nums[i - 1]) {
						int te = nums[p];
						nums[p] = nums[i - 1];
						nums[i - 1] = te;
						k++;
						break;
					}
				}
				if (k != 0) {
					break;
				}
				
			}
			i--;
		}
		if (i == 0) {
			for (int h = 0; h < (n / 2); h++) {
				int te = nums[h];
				nums[h] = nums[n - h - 1];
				nums[n - h - 1] = te;
			}
		}
	}

	//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
	//写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int mid = 0;
		int p = 0;
		int q = n - 1;
		if (n == 0) {
			return -1;
		}
		if (n == 1) {
			if (nums[0] == target) {
				return 0;
			}
			else {
				return -1;
			}
		}
		while (p <= q ) {
			mid = p + (q - p) / 2;
			cout << "mid:" << mid << endl;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] < target) {
				p = mid+1;
			}
			if (nums[mid] > target) {
				q = mid-1;
			}
			
		}
		return -1;
	}

	//278.也算是一个二分查找
	bool isBadVersion(int bad) {
		if (bad >= 1) {
			return true;
		}
		else return false;
	}
	int firstBadVersion(int n) {
		int p = 1;
		int q = n;
		int mid = 0;
		while (p <= q) {
			mid = p + (q - p) / 2;
			cout << mid << endl;
			if (isBadVersion(mid)) {
				if (isBadVersion(mid - 1)) {
					q = mid - 1;
				}
				else {
					return mid;
				}
				
			}
			else {
				p = mid + 1;
			}
		}
		return -1;
	}


	//35.搜索插入位置
	int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		int p = 0;
		int q = n - 1;
		int mid = 0;
		/*if (n < 2) {
			if (nums[0] < target) {
				return 1;
			}
			if (nums[0] > target) {
				return 0;
			}
		}*/
		while (p <= q) {
			mid = p + (q - p) / 2;
			if (p != q) {
				if (nums[mid] == target) {
					return mid;
				}
				else if (nums[mid] > target) {
					q = mid - 1;
				}
				else if (nums[mid] < target) {
					p = mid + 1;
				}
			}
			if (p == q) {
				//cout <<"p"<< p << endl;
				if (nums[p] > target) {
					if (p == 0) {
						mid = 0;
					}
					else {
						mid = p ;
					}
				}
				else if (nums[p] == target) {
					mid = p;
				}
				else if (nums[p] < target) {
					mid = p + 1;
				}
				return mid;
			}
			//cout << "mid" << mid << endl;
		}
		return mid;
	}


	//36.有效的数独

	bool isValidSudoku(vector<vector<char>>& board1) {
		//将char型转化为整型
		vector<vector<int>> board;
		vector<int> temp;
		char a;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				a = board1[i][j];
				//cout << "a：" << a<<"    ";
				switch (a)
				{
				case '1':temp.push_back(1); break;
				case '2':temp.push_back(2); break;
				case '3':temp.push_back(3); break;
				case '4':temp.push_back(4); break;
				case '5':temp.push_back(5); break;
				case '6':temp.push_back(6); break;
				case '7':temp.push_back(7); break;
				case '8':temp.push_back(8); break;
				case '9':temp.push_back(9); break;
					default:
						temp.push_back(-1); break;
						
				}
				
			}
			board.push_back(temp);
			while (1) {
				if (temp.empty())
					break;
				temp.pop_back();
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		vector<int> temp_;
		temp_.resize(10, 0);
		//看小九宫格
		vector<vector<int>> hash1(3, vector<int>(10, 0));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				cout << hash1[i][j] << " ";
			}
			cout << endl;
		}
		int k = 0;
		//看大九宫格
		vector<vector<int>> hash4(10, vector<int>(10, 0));
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << hash4[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < 9; i++) {
			k = 0;
			//解决小九宫格
			if ( i % 3 == 0) {
				for (int iii = 0; iii < 3; iii++) {
					for (int jjj = 0; jjj < 10; jjj++) {
						hash1[iii][jjj] = 0;
					}
				}
			}
			for (int j = 0; j < 9 ; j++) {
				if ( j  % 3 == 0&&j!=0) {
					k++;
				}
				if (board[i][j]<0) {
					continue;
				}
				hash1[k][board[i][j]]+=1;
				cout << hash1[k][board[i][j]] <<"board"<<board[i][j]<< "  " << "  i:" << i << "  J:" << j << "  K:" << k << endl;
				hash4[i][board[i][j]]+=1;

				if (hash1[k][board[i][j]] > 1||hash4[i][board[i][j]] > 1) {
					return false;
				}
			}
		}
		vector<vector<int>> hash5(10, vector<int>(10, 0));
		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 9; i++) {
				if (board[i][j] < 0)continue;
				hash5[board[i][j]][j]++;
				if (hash5[board[i][j]][j] > 1)
					return false;
			}
			cout << endl;
		}
		return true;
	}
};