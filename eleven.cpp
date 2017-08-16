#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

#define MAX 50

using namespace std;

//小易有n块砖块，每一块砖块有一个高度。小易希望利用这些砖块堆砌两座相同高度的塔。
//为了让问题简单，砖块堆砌就是简单的高度相加，某一块砖只能使用在一座塔中一次。
//小易现在让能够堆砌出来的两座塔的高度尽量高，小易能否完成呢。
//输入描述:
//输入包括两行：
//第一行为整数n(1 ≤ n ≤ 50)，即一共有n块砖块
//第二行为n个整数，表示每一块砖块的高度height[i] (1 ≤ height[i] ≤ 500000)
//
//输出描述:
//如果小易能堆砌出两座高度相同的塔，输出最高能拼凑的高度，如果不能则输出-1.
//保证答案不大于500000。
//
//输入例子:
//3
//2 3 5
//
//输出例子:
//5

//个人思路：动态规划
//假设砖块分为A，B两堆，dp[i][j]中的j表示B-A的长度。
//因为B-A有可能是负的，所以j整体偏移sum个长度，即2*sum+1。
//而dp[i][j]的值则表示当A-B的值为j时，B的最大长度是多少。
//dp[i][j] = dp[i-1][j]表示我不用第i块砖
//dp[i][j] = max(dp[i-1][j-h], dp[i-1][j])表示我把砖放在A堆。
//dp[i][j] = max(dp[i-1][j+h]+h, dp[i-1][j])表示我把砖放在B堆。
//由于使用内存过大，使用滚动数组优化。 


int main(int argc, const char * argv[]){
    int n=0, sum = 0;
    int a[MAX];
    cin >> n;
    for(int i=0; i<n; ++i){
    	cin >> a[i];
    	sum += a[i];
	}
	vector< vector<int> > dp(2, vector<int>(2*sum+1, -1));  // 第二维初始化为2*sum+1，并令所有值为-1; 
	dp[0][sum] = 0;
	vector<int> * dp0 = &(dp[0]);
	vector<int> * dp1 = &(dp[1]);
	for(int i=1; i<=n; ++i){
		for(int j=0; j<2*sum; ++j){
			int h = a[i-1];
			(*dp1)[j] = (*dp0)[j];                      // 不放砖块； 
			if(j-h>=0 && (*dp0)[j-h] != -1){
				(*dp1)[j] = max((*dp1)[j], (*dp0)[j-h]);  //放砖块至A堆； 
			}
			if(j+h<=2*sum && (*dp0)[j+h] != -1){
				(*dp1)[j] = max((*dp1)[j], (*dp0)[j+h] + h);  // 放砖块至B堆； 
			}
		}
		vector<int> * tmp;
		tmp = dp0;
		dp0 = dp1;
		dp1 = tmp;
	}
	if((*dp0)[sum] == 0){
		cout << -1 << endl;
	}
	else{
		cout << (*dp0)[sum] << endl;
	}
	return 0;
}
