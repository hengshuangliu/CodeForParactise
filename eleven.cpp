#include<iostream>
#include<cstring> // memset
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>

#define MAX 50

using namespace std;

//С����n��ש�飬ÿһ��ש����һ���߶ȡ�С��ϣ��������Щש�����������ͬ�߶ȵ�����
//Ϊ��������򵥣�ש��������Ǽ򵥵ĸ߶���ӣ�ĳһ��שֻ��ʹ����һ������һ�Ρ�
//С���������ܹ������������������ĸ߶Ⱦ����ߣ�С���ܷ�����ء�
//��������:
//����������У�
//��һ��Ϊ����n(1 �� n �� 50)����һ����n��ש��
//�ڶ���Ϊn����������ʾÿһ��ש��ĸ߶�height[i] (1 �� height[i] �� 500000)
//
//�������:
//���С���ܶ����������߶���ͬ��������������ƴ�յĸ߶ȣ�������������-1.
//��֤�𰸲�����500000��
//
//��������:
//3
//2 3 5
//
//�������:
//5

//����˼·����̬�滮
//����ש���ΪA��B���ѣ�dp[i][j]�е�j��ʾB-A�ĳ��ȡ�
//��ΪB-A�п����Ǹ��ģ�����j����ƫ��sum�����ȣ���2*sum+1��
//��dp[i][j]��ֵ���ʾ��A-B��ֵΪjʱ��B����󳤶��Ƕ��١�
//dp[i][j] = dp[i-1][j]��ʾ�Ҳ��õ�i��ש
//dp[i][j] = max(dp[i-1][j-h], dp[i-1][j])��ʾ�Ұ�ש����A�ѡ�
//dp[i][j] = max(dp[i-1][j+h]+h, dp[i-1][j])��ʾ�Ұ�ש����B�ѡ�
//����ʹ���ڴ����ʹ�ù��������Ż��� 


int main(int argc, const char * argv[]){
    int n=0, sum = 0;
    int a[MAX];
    cin >> n;
    for(int i=0; i<n; ++i){
    	cin >> a[i];
    	sum += a[i];
	}
	vector< vector<int> > dp(2, vector<int>(2*sum+1, -1));  // �ڶ�ά��ʼ��Ϊ2*sum+1����������ֵΪ-1; 
	dp[0][sum] = 0;
	vector<int> * dp0 = &(dp[0]);
	vector<int> * dp1 = &(dp[1]);
	for(int i=1; i<=n; ++i){
		for(int j=0; j<2*sum; ++j){
			int h = a[i-1];
			(*dp1)[j] = (*dp0)[j];                      // ����ש�飻 
			if(j-h>=0 && (*dp0)[j-h] != -1){
				(*dp1)[j] = max((*dp1)[j], (*dp0)[j-h]);  //��ש����A�ѣ� 
			}
			if(j+h<=2*sum && (*dp0)[j+h] != -1){
				(*dp1)[j] = max((*dp1)[j], (*dp0)[j+h] + h);  // ��ש����B�ѣ� 
			}
		}
		vector<int> * tmp;
		tmp = dp0;
		dp0 = dp1;
		dp1 = tmp;
	}
	if((*dp0)[sum] == 0){
		cout << -1 << endl;
	}
	else{
		cout << (*dp0)[sum] << endl;
	}
	return 0;
}
