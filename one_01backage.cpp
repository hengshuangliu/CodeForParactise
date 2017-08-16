#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;

//一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，
//假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。n个任务可以按照任意
//顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，
//求这个最小的时间。 
//
//输入描述:
//输入包括两行：
//第一行为整数n(1 ≤ n ≤ 50)
//第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，
//每个数均为1024的倍数。
//
//输入例子：
//5
//3072 3072 7168 3072 1024
//输出：
//9216 

//该题可看作01背包问题，总任务时间是确定的，理论上最少的时间是 （总时间/2），
//因此只需对一个CPU进行求解，看作一个容量为总时间一半的背包即可。

int main(){
	int n=0,sum=0;
	int a[50];
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		a[i] /= 1024;
		sum += a[i];
	}
	int dp_size = sum/2 + 1;
	int *dp = new int[dp_size];
	memset(dp, 0, sizeof(int)*dp_size); 
	for(int i=0; i<n; ++i){
		for(int j=dp_size-1; j>=a[i]; j--){
			dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
		}
		for(int r=0; r<dp_size; r++)
		{
			cout << dp[r] << "\t"; 
		}
		cout << endl;
	}
	cout << 1024*(sum - dp[dp_size-1]) << endl;
	delete [] dp;
	return 0;
} 
