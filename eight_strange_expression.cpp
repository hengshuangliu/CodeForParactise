#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//����ı��ʽ��ֵ�����Ƕ�����ݼ�������ȼ������㡣����/�����ȼ��͸���+-��
//����С�������������ı��ʽ����ܼ򵥣������������μ��㼴�ɣ�
//����С�����ڵ�����û�г�������ζ�ű��ʽ��û��/��ֻ��(+, - �� *)�����ڸ���һ�����ʽ��
//��Ҫ���æ�����С�����ڵ�����������ʽ��ֵΪ����
//��������:
//����Ϊһ���ַ�������һ�����ʽ�����������ֻ��-,+,*��������������ֻ��0~9.
//��֤���ʽ���ǺϷ��ģ����й�����������ʾ��
//
//�������:
//���һ�����������ʽ��ֵ
//
//��������:
//3+5*7
//
//�������:
//56 

bool num(char c){     // �ж��Ƿ�Ϊ����; 
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
