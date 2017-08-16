#include<iostream>
#include<cstring> // memset
#include<set>
#include<vector>
#include<algorithm>
using namespace std; 
#define MAX 50
#define MOD 100

//小易拥有一个拥有魔力的手环上面有n个数字(构成一个环),当这个魔力手环每次使用魔力的时候就会
//发生一种奇特的变化：每个数字会变成自己跟后面一个数字的和
//(最后一个数字的后面一个数字是第一个),一旦某个位置的数字大于等于100就马上对100取模
//(比如某个位置变为103,就会自动变为3).现在给出这个魔力手环的构成，请你计算出使用k次魔力之后魔力手环的状态。

//输入描述:
//输入数据包括两行：
//第一行为两个整数n(2 ≤ n ≤ 50)和k(1 ≤ k ≤ 2000000000),以空格分隔
//第二行为魔力手环初始的n个数，以空格分隔。范围都在0至99.
//
//输出描述:
//输出魔力手环使用k次之后的状态，以空格分隔，行末无空格。
//
//输入例子:
//3 2
//1 2 3
//
//输出例子:
//8 9 7

struct Matrix{
	int row;
	int col;
	int a[MAX][MAX];
	
	void clear(){
		row = col = 0;
		memset(a, 0, sizeof(int)*MAX*MAX);
	}
	
	Matrix operator +(const Matrix  &b) const {
	    Matrix tmp;
	    tmp.clear();
	    tmp.row = row;
	    tmp.col = col;
	    for(int i=0; i<row; ++i){
	    	for(int j=0; j<col; ++j){
	    		tmp.a[i][j] = (a[i][j] + b.a[i][j])%MOD;
			}
		}
		return tmp;
	}
	
	Matrix operator *(const Matrix &b) const {
		Matrix tmp;
		tmp.clear();
		tmp.row = row;
		tmp.col = b.col;
		for(int i=0; i<row; ++i){
			for(int j=0; j<b.col; ++j){
				for(int k=0; k<col; ++k){
					tmp.a[i][j] = (tmp.a[i][j] + a[i][k]*b.a[k][j])%MOD;
				}
			}
		}
		return tmp;
	}
	
	Matrix operator ^(int k) const {   // 矩阵快速幂算法 
	    Matrix tmp, mul;
	    tmp.clear();
		mul.clear();
		mul.row = mul.col = tmp.row = tmp.col = row;
		mul = mul + (*this);
		for(int i=0; i<row; ++i){
			tmp.a[i][i] = 1;
		}
		while(k>0){
			if(k&1){
				tmp = tmp*mul;
			}
			mul = mul * mul;
			k >>= 1;
		}
		return tmp;
	}
	
	Matrix transpose(){
		Matrix tmp;
		tmp.clear();
		tmp.row = col;
		tmp.col = row;
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				tmp.a[j][i] = a[i][j];
			}
		}
		return tmp;
	}
	
	void print() const{
		for(int i=0; i<row; i++){
			for(int j=0; j<col-1; j++){
				cout << a[i][j] << " ";
			}
			cout << a[i][col-1] << endl;
		}
	}
};



int main(int argc, const char * argv[]){
	int n,k;
	cin >> n >> k;
	Matrix tmp;
	tmp.clear();
	tmp.row = n;
	tmp.col = 1;
	for(int i=0; i<n; ++i){
		cin >> tmp.a[i][0];
	}
	Matrix mul;
	mul.clear();
	mul.row = mul.col = n;
	for(int j=0; j<n; ++j){
		mul.a[j][j] = 1;
		mul.a[j][(j+1)%n] = 1;
	}
	tmp = (mul^k)*tmp;
	tmp.transpose().print(); 
	return 0;
}
