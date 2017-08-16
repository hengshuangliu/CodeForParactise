#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

#define MAX 50

using namespace std;

//小易有一块n*n的棋盘，棋盘的每一个格子都为黑色或者白色，小易现在要用他喜欢的红色去涂画棋盘。
//小易会找出棋盘中某一列中拥有相同颜色的最大的区域去涂画，帮助小易算算他会涂画多少个棋格。
//输入描述:
//输入数据包括n+1行：
//
//第一行为一个整数n(1 ≤ n ≤ 50),即棋盘的大小
//
//接下来的n行每行一个字符串表示第i行棋盘的颜色，’W’表示白色，’B’表示黑色
//
//输出描述:
//输出小易会涂画的区域大小
//
//输入例子:
//3
//BWW
//BBB
//BWB
//
//输出例子:
//3

int main(int argc, const char * argv[]){
	int n;
	cin >> n;
	string s[MAX];
	for(int i=0; i<n; ++i){
		cin >> s[i];
	}
	int b = 1, w = 1;
	int tmp = 1;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n-1; ++j){
			if(s[j][i] == s[j+1][i]){
				++tmp;
			}
			else{
				if(s[j][i] == 'B'){
					b = tmp > b ? tmp : b;
				}
				else{
					w = tmp > w ? tmp : w;
				}
				tmp = 1;
			}
		}
		if(s[n-1][i] == 'B'){
					b = tmp > b ? tmp : b;
		}
		else{
			w = tmp > w ? tmp : w;
		}
		tmp = 1;
	}
	cout << max(b, w) << endl;
	return 0;
}
