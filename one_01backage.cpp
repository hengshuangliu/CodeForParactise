#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;

//һ��˫��CPU���������ܹ�ͬʱ�Ĵ�������������n����֪��������������Ҫ����CPU����
//������֪CPU��ÿ����1����Դ���1kb��ÿ����ͬʱֻ�ܴ���һ������n��������԰�������
//˳�����CPU���д���������Ҫ���һ��������CPU�������������������ʱ�����٣�
//�������С��ʱ�䡣 
//
//��������:
//����������У�
//��һ��Ϊ����n(1 �� n �� 50)
//�ڶ���Ϊn������length[i](1024 �� length[i] �� 4194304)����ʾÿ������ĳ���Ϊlength[i]kb��
//ÿ������Ϊ1024�ı�����
//
//�������ӣ�
//5
//3072 3072 7168 3072 1024
//�����
//9216 

//����ɿ���01�������⣬������ʱ����ȷ���ģ����������ٵ�ʱ���� ����ʱ��/2����
//���ֻ���һ��CPU������⣬����һ������Ϊ��ʱ��һ��ı������ɡ�

int main(){
	int n=0,sum=0;
	int a[50];
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
		a[i] /= 1024;
		sum += a[i];
	}
	int dp_size = sum/2 + 1;
	int *dp = new int[dp_size];
	memset(dp, 0, sizeof(int)*dp_size); 
	for(int i=0; i<n; ++i){
		for(int j=dp_size-1; j>=a[i]; j--){
			dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
		}
		for(int r=0; r<dp_size; r++)
		{
			cout << dp[r] << "\t"; 
		}
		cout << endl;
	}
	cout << 1024*(sum - dp[dp_size-1]) << endl;
	delete [] dp;
	return 0;
} 
