#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#define MAX 6

using namespace std;

//С���������ѧ����ѧϰ���˼��ϵĸ���,����������������1.ȷ���� 2.������ 3.������.
//С�׵���ʦ����С������һ�����ϣ�
//S = { p/q | w �� p �� x, y �� q �� z }
//��Ҫ���ݸ�����w��x��y��z,���������һ���ж��ٸ�Ԫ�ء�
//С�ײ�ѧϰ�˼��ϻ��������������ӵ�����,��Ҫ������������
//��������:
//�������һ�У�
//һ��4�������ֱ���w(1 �� w �� x)��x(1 �� x �� 100)��y(1 �� y �� z)��z(1 �� z �� 100).�Կո�ָ�
//
//�������:
//���������Ԫ�صĸ���
//
//��������:
//1 10 1 1
//
//�������:
//10

//������Ǹ��������أ���Ȼ���ǲ���ֱ���㣬
//��Ϊ�������ǲ���ȷ�ģ������ṹ�屣����������Ȼ�󶪽�set��ͺ��ˡ� 

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

int gcd(int a, int b){     // ������,շת������� 
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
