#include<iostream>
#include<cstring> // memset,memcpy 
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//易老师购买了一盒饼干，盒子中一共有k块饼干，但是数字k有些数位变得模糊了，看不清楚数字具体是多少了。
//易老师需要你帮忙把这k块饼干平分给n个小朋友，易老师保证这盒饼干能平分给n个小朋友。
//现在你需要计算出k有多少种可能的数值
//输入描述:
//输入包括两行：
//
//第一行为盒子上的数值k，模糊的数位用X表示，长度小于18(可能有多个模糊的数位)
//
//第二行为小朋友的人数n
//
//输出描述:
//输出k可能的数值种数，保证至少为1
//
//输入例子:
//9999999999999X
//3
//
//输出例子:
//4

int transform(long long *mod, int n, char c){
	long long *tmp = new long long[n];
	memset(tmp, 0, sizeof(long long)*n);
	if(c == 'X'){
		for(int i=0; i<n; ++i){
			for(int j=0; j<10; ++j){
				tmp[(i*10+j)%n] += mod[i];
			}
		}
	}
	else{
		int num = c - '0';
		for(int i=0; i<n; ++i){
			tmp[(i*10+num)%n] += mod[i];
		}
	}
	memcpy(mod, tmp, sizeof(long long)*n);
	delete [] tmp;
	return 0;
}

int main(int argc, const char * argv[]){
	string s;
	int n;
	cin >> s;
	cin >> n;
	long long * mod = new long long[n];
	memset(mod, 0, sizeof(long long)*n);
	mod[0] = 1;
	for(int i=0; i<s.size(); ++i){
		transform(mod, n, s[i]);
	}
	cout << mod[0] << endl;
	delete [] mod;
	return 0;
}
