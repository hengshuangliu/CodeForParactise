#include <iostream>
using namespace std;

//һ��˫��CPU���������ܹ�ͬʱ�Ĵ�������������n����֪��������������Ҫ����CPU����
//������֪CPU��ÿ����1����Դ���1kb��ÿ����ͬʱֻ�ܴ���һ������
//n��������԰�������˳�����CPU���д���������Ҫ���һ��������CPU�������������������ʱ�����٣��������С��ʱ�䡣
//
//��������
//
//����������У�
//��һ��Ϊ����n(1 �� n �� 50)
//�ڶ���Ϊn������lengthi����ʾÿ������ĳ���Ϊlength[i]kb��ÿ������Ϊ1024�ı�����
//
//�������
//���һ����������ʾ������Ҫ�����ʱ��
//
//��������
//5
//3072 3072 7168 3072 1024
//
//�������
//9216

int find(int *a, int n, int val){
	int temp1 = 0;
	int temp2 = 0;
	if(n>1){
		int *p=a+1;
		if(*a >= val){
			temp1 = *a - val;
			temp2 = find(p,n-1,val);
			if(temp2 == -1){
//				cout<< n << ":" <<temp1<< endl;
				return temp1;
			}
			else{
//				cout << n << ":" << ((temp1 < temp2) ? temp1:temp2)<< endl;
				return (temp1 < temp2) ? temp1:temp2;
			}
		}
		else{
			temp1 = find(p,n-1,val - *a);
			if(temp1 == -1 ){
//				cout<< n << ":" <<-1<< endl;
				return -1;
			}
			else{
				temp2 = find(p,n-1,val);
				if(temp2 == -1){
//					cout<< n << ":" <<temp1<< endl;
					return temp1;
				}
				else{
//					cout<< n << ":" << ((temp1 < temp2) ? temp1:temp2) << endl;
					return (temp1 < temp2)? temp1 :temp2;
				}
			}
			
		}
	}
	else{
		if(*a >= val){
//			cout<< n << ":" << (*a - val) << endl;
			return *a - val;
		}
		else{
//			cout<< n << ":" << -1 << endl;
			return -1;
		}
	}
}

int main(){
	int n=0, avg=0, time=0;
	int a[50];
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		avg += a[i];
	}
	avg /= 2;
	time = find(a, n, avg);
	cout << time + avg << endl;
} 
