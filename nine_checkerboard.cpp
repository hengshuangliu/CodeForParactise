#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

#define MAX 50

using namespace std;

//С����һ��n*n�����̣����̵�ÿһ�����Ӷ�Ϊ��ɫ���߰�ɫ��С������Ҫ����ϲ���ĺ�ɫȥͿ�����̡�
//С�׻��ҳ�������ĳһ����ӵ����ͬ��ɫ����������ȥͿ��������С����������Ϳ�����ٸ����
//��������:
//�������ݰ���n+1�У�
//
//��һ��Ϊһ������n(1 �� n �� 50),�����̵Ĵ�С
//
//��������n��ÿ��һ���ַ�����ʾ��i�����̵���ɫ����W����ʾ��ɫ����B����ʾ��ɫ
//
//�������:
//���С�׻�Ϳ���������С
//
//��������:
//3
//BWW
//BBB
//BWB
//
//�������:
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
