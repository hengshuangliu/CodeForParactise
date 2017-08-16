#include <iostream>
using namespace std;

//一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，
//假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。
//n个任务可以按照任意顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。
//
//输入描述
//
//输入包括两行：
//第一行为整数n(1 ≤ n ≤ 50)
//第二行为n个整数lengthi，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。
//
//输出描述
//输出一个整数，表示最少需要处理的时间
//
//输入例子
//5
//3072 3072 7168 3072 1024
//
//输出例子
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
