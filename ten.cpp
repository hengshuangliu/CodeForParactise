#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//С�ײ�����һ���ǵ��ʵ�С��Ϸ����Ϸ��ʼϵͳ�ṩ��m����ͬ�ĵ��ʣ�
//С�׼���һ��ʱ��֮����Ҫ��ֽ��д������ס�ĵ��ʡ�С��һ��д����n�����ܼ�ס�ĵ��ʣ�
//���С��д���ĵ�������ϵͳ�ṩ�ģ������������ʳ��ȵ�ƽ���ķ�����ע��С��д���ĵ��ʿ����ظ���
//���Ƕ���ÿ����ȷ�ĵ���ֻ�ܼƷ�һ�Ρ�
//��������:
//�������ݰ������У�
//
//��һ��Ϊ��������n(1 �� n �� 50)��m(1 �� m �� 50)���Կո�ָ�
//
//�ڶ���Ϊn���ַ�������ʾС���ܼ�ס�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��
//
//������Ϊm���ַ�����ϵͳ�ṩ�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��
//
//�������:
//���һ��������ʾС���ܻ�õķ���
//
//��������:
//3 4
//apple orange strawberry
//strawberry orange grapefruit watermelon
//
//�������:
//136

int main(int argc, const char * argv[]){
	set<string> words;
	set<string> cans;
	int n, m;
	string s;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> s;
		cans.insert(s);
	}
	for(int j=0; j<m; ++j){
		cin >> s;
		words.insert(s);
	}
	int score = 0;
	for(set<string>::iterator it=cans.begin(); it!=cans.end(); it++){
		if(words.find(*it) != words.end()){
			score += pow(it->length(), 2);
		}
	}
	cout << score << endl;
    return 0;
}
