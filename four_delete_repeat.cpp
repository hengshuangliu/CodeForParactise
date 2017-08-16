#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std; 

//小易有一个长度为n序列，小易想移除掉里面的重复元素，
//但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。
//输入描述:
//输入包括两行：
//第一行为序列长度n(1 ≤ n ≤ 50)
//第二行为n个数sequencei，以空格分隔
//
//输出描述:
//输出消除重复元素之后的序列，以空格分隔，行末无空格
//
//输入例子:
//9
//100 100 100 99 99 99 100 100 100
//
//输出例子:
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
