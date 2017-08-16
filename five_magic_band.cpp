#include<iostream>
#include<cstring> // memset
#include<set>
#include<vector>
#include<algorithm>
using namespace std; 
#define MAX 50
#define MOD 100

//С��ӵ��һ��ӵ��ħ�����ֻ�������n������(����һ����),�����ħ���ֻ�ÿ��ʹ��ħ����ʱ��ͻ�
//����һ�����صı仯��ÿ�����ֻ����Լ�������һ�����ֵĺ�
//(���һ�����ֵĺ���һ�������ǵ�һ��),һ��ĳ��λ�õ����ִ��ڵ���100�����϶�100ȡģ
//(����ĳ��λ�ñ�Ϊ103,�ͻ��Զ���Ϊ3).���ڸ������ħ���ֻ��Ĺ��ɣ���������ʹ��k��ħ��֮��ħ���ֻ���״̬��

//��������:
//�������ݰ������У�
//��һ��Ϊ��������n(2 �� n �� 50)��k(1 �� k �� 2000000000),�Կո�ָ�
//�ڶ���Ϊħ���ֻ���ʼ��n�������Կո�ָ�����Χ����0��99.
//
//�������:
//���ħ���ֻ�ʹ��k��֮���״̬���Կո�ָ�����ĩ�޿ո�
//
//��������:
//3 2
//1 2 3
//
//�������:
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
	
	Matrix operator ^(int k) const {   // ����������㷨 
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
