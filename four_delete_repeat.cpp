#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std; 

//С����һ������Ϊn���У�С�����Ƴ���������ظ�Ԫ�أ�
//����С�����Ƕ���ÿ��Ԫ�ر��������ֵ��Ǹ���С������������,ϣ��������������
//��������:
//����������У�
//��һ��Ϊ���г���n(1 �� n �� 50)
//�ڶ���Ϊn����sequencei���Կո�ָ�
//
//�������:
//��������ظ�Ԫ��֮������У��Կո�ָ�����ĩ�޿ո�
//
//��������:
//9
//100 100 100 99 99 99 100 100 100
//
//�������:
//99 100

int main(){
	int n=0;
	cin >> n;
	int *p = new int[n];
	set<int> s;
	vector<int> v;
	for(int i=0; i<n; ++i){
		cin >> p[i];
	}
	for(int j=n-1; j>=0; j--){
		if(s.find(p[j]) == s.end()){
			s.insert(p[j]);
			v.push_back(p[j]);
		}
	}
	cout << v[v.size()-1];
	for(int k=v.size()-2; k>=0; k--){
		cout << " " << v[k];
	}
	cout << endl;
	delete [] p;
	return 0;
}
