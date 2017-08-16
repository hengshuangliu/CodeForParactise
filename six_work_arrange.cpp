#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#define MAX 6

using namespace std;

bool can[MAX][MAX];
bool vis[MAX];
int n=0;

//������nλ����ʦ��6���(���Ϊ0��5)�����ڸ���ÿ�����ܹ�ʤ�εĹ�����ű�
//(��һ���ַ�����ʾ�����磺045����ʾĳλ����ʦ�ܹ�ʤ��0�ţ�4�ţ�5�Ź���)��
//������Ҫ���й������ţ�ÿλ����ʦֻ�ܱ����ŵ��Լ��ܹ�ʤ�εĹ�������ȥ����λ����ʦ���ܰ��ŵ�ͬһ�������ȥ��������ֹ�����������һ���˱������ڵĹ�����Ų�һ���ͱ���Ϊ��ͬ�Ĺ������ţ�������Ҫ������ж����ֲ�ͬ�������żƻ���
//
//��������:
//����������n+1�У�
//��һ��Ϊ����ʦ����n(1 �� n �� 6)
//��������n�У�ÿ��һ���ַ�����ʾ��i(1 �� i �� n)�����ܹ�ʤ�εĹ���(�ַ�����һ���ȳ���)
//
//�������:
//���һ����������ʾ�ж����ֲ�ͬ�Ĺ������ŷ���
//
//��������:
//6
//012345
//012345
//012345
//012345
//012345
//012345
//
//�������:
//720

int dfs(int now){
	int ans = 0;
	for(int i=0; i<MAX; ++i){
		if(can[now][i] && !vis[i]){
			vis[i] = true;
			if(now == 0){
				++ans;
			}
			else{
				ans += dfs(now-1);
			}
			vis[i] = false;
		}
	}
	return ans;
}

int main(int argc, const char * argv[]){
	string s;
	cin >> n;
	memset(can, 0, sizeof(bool)*MAX*MAX);
	memset(vis, 0, sizeof(bool)*MAX);
	for(int i=0; i<n; ++i){
		cin >> s;
		for(int j=0; j<s.size(); ++j){
			can[i][s[j]-'0'] = true;
		}
	}
	cout << dfs(n-1) << endl;
	return 0;
}
