#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#define MAX 6

using namespace std;

//小易最近在数学课上学习到了集合的概念,集合有三个特征：1.确定性 2.互异性 3.无序性.
//小易的老师给了小易这样一个集合：
//S = { p/q | w ≤ p ≤ x, y ≤ q ≤ z }
//需要根据给定的w，x，y，z,求出集合中一共有多少个元素。
//小易才学习了集合还解决不了这个复杂的问题,需要你来帮助他。
//输入描述:
//输入包括一行：
//一共4个整数分别是w(1 ≤ w ≤ x)，x(1 ≤ x ≤ 100)，y(1 ≤ y ≤ z)，z(1 ≤ z ≤ 100).以空格分隔
//
//输出描述:
//输出集合中元素的个数
//
//输入例子:
//1 10 1 1
//
//输出例子:
//10

//题意就是给分数判重，显然我们不能直接算，
//因为浮点数是不精确的，建个结构体保存最简分数，然后丢进set里就好了。 

struct fraction{
	int m;
	int n;
	
	bool operator <(const fraction &frac) const{
	    if(m != frac.m){
	    	return m<frac.m;
		}
		if(n != frac.n){
			return n<frac.n;
		}
		return false;
	}
};

int gcd(int a, int b){     // 求公因子,辗转相除法； 
    return b==0?a:gcd(b,a%b);
}

int main(int argc, const char * argv[]){
    int w, x, y, z;
    set<fraction> s;
    cin >> w >> x >> y >> z;
    fraction tmp;
    for(int i=w; i<=x; ++i){
    	for(int j=y; j<=z; ++j){
    		int div = gcd(i, j);
    		tmp.m = i/div;
    		tmp.n = j/div;
    		s.insert(tmp);
		}
	}
	cout << s.size() << endl;
	return 0;
}
