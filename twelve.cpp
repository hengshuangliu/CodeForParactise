#include<iostream>
#include<cstring> // memset,memcpy 
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//����ʦ������һ�б��ɣ�������һ����k����ɣ���������k��Щ��λ���ģ���ˣ�����������־����Ƕ����ˡ�
//����ʦ��Ҫ���æ����k�����ƽ�ָ�n��С���ѣ�����ʦ��֤��б�����ƽ�ָ�n��С���ѡ�
//��������Ҫ�����k�ж����ֿ��ܵ���ֵ
//��������:
//����������У�
//
//��һ��Ϊ�����ϵ���ֵk��ģ������λ��X��ʾ������С��18(�����ж��ģ������λ)
//
//�ڶ���ΪС���ѵ�����n
//
//�������:
//���k���ܵ���ֵ��������֤����Ϊ1
//
//��������:
//9999999999999X
//3
//
//�������:
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
