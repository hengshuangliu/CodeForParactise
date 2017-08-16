#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//常规的表达式求值，我们都会根据计算的优先级来计算。比如/的优先级就高于+-。
//但是小易所生活的世界的表达式规则很简单，从左往右依次计算即可，
//而且小易所在的世界没有除法，意味着表达式中没有/，只有(+, - 和 *)。现在给出一个表达式，
//需要你帮忙计算出小易所在的世界这个表达式的值为多少
//输入描述:
//输入为一行字符串，即一个表达式。其中运算符只有-,+,*。参与计算的数字只有0~9.
//保证表达式都是合法的，排列规则如样例所示。
//
//输出描述:
//输出一个数，即表达式的值
//
//输入例子:
//3+5*7
//
//输出例子:
//56 

bool num(char c){     // 判断是否为数字; 
    return c >= '0' && c <= '9';
}

int main(int argc, const char * argv[]){
	string s;
	cin >> s;
	int a = 0, b = 0, n = 0;
	char op = '+';
	for(int i=0; i<s.size(); ++i){
		if(num(s[i])){
			b += pow(10, n)*(s[i] - '0');
		    ++n;	
		}
		else{
			if(op == '+'){
				a += b;
				b = 0;
				n = 0;
				op = s[i];
			}
			else if(op == '-'){
				a -= b;
				b = 0;
				n = 0;
				op = s[i];
			}
			else{
				a *= b;
				b = 0;
				n = 0;
				op = s[i];
			}
		}
	}
	if(op == '+'){
				a += b;
			}
			else if(op == '-'){
				a -= b;
			}
			else{
				a *= b;
			}
	cout << a << endl;
	return 0;
}
