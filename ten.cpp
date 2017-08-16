#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

//小易参与了一个记单词的小游戏。游戏开始系统提供了m个不同的单词，
//小易记忆一段时间之后需要在纸上写出他记住的单词。小易一共写出了n个他能记住的单词，
//如果小易写出的单词是在系统提供的，将获得这个单词长度的平方的分数。注意小易写出的单词可能重复，
//但是对于每个正确的单词只能计分一次。
//输入描述:
//输入数据包括三行：
//
//第一行为两个整数n(1 ≤ n ≤ 50)和m(1 ≤ m ≤ 50)。以空格分隔
//
//第二行为n个字符串，表示小易能记住的单词，以空格分隔，每个单词的长度小于等于50。
//
//第三行为m个字符串，系统提供的单词，以空格分隔，每个单词的长度小于等于50。
//
//输出描述:
//输出一个整数表示小易能获得的分数
//
//输入例子:
//3 4
//apple orange strawberry
//strawberry orange grapefruit watermelon
//
//输出例子:
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
