#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//���ڵ���ĩ����С�����������Ľֵ���׼�������ѾۻᣬͻȻ��������������,
//С����Ҫ�����ع�˾�޸��������bug������������һ�����޴������ÿ���ֵ�
//����������(X��Y)��С�׵�ǰ��(0��0)�ֵ����칫����(gx,gy)�ֵ��ϡ�С����Χ
//�ж�����⳵�򳵵㣬С�׸�ȥ�칫��������ѡ��һ�־�����·ȥ��˾������һ
//�־����ߵ�һ�����⳵�򳵵㣬Ȼ��Ӵ򳵵��λ�������⳵ȥ��˾��ÿ���ƶ���
//���ڵĽֵ�(�����������)��·���Ứ��walkTimeʱ�䣬�򳵽�����taxiTimeʱ�䡣
//С����Ҫ����ϵ���˾ȥ������С����֪���������Ҫ���Ѷ���ʱ��ȥ��˾��
//
//�������:
//���һ��������ʾ��С������ܸϵ��칫�ҵ�ʱ��
//��������:
//2 // ��һ��Ϊ��Χ���⳵�򳵵�ĸ���n(1 �� n �� 50)
//-2 -2 // �ڶ���Ϊÿ�����⳵�򳵵�ĺ�����tX[i] (-10000 �� tX[i] �� 10000)
//0 -2 //������Ϊÿ�����⳵�򳵵��������tY[i] (-10000 �� tY[i] �� 10000)
//-4 -2 //������Ϊ�칫������gx,gy(-10000 �� gx,gy �� 10000),�Կո�ָ�
//15 3 //������Ϊ��·ʱ��walkTime(1 �� walkTime �� 1000)��taxiTime(1 �� taxiTime �� 1000),�Կո�ָ�
//�������:  
//42 

int main(){
	int n=0,i=0;
	cin >> n;
	int *taxi_x = new int[n];
	memset(taxi_x, 0, sizeof(int)*n);
	for(i=0;i<n;++i){
		cin >> taxi_x[i];
	}
	int *taxi_y = new int[n];
	memset(taxi_y, 0, sizeof(int)*n);
	for(i=0;i<n;++i){
		cin >> taxi_y[i];
	}
	int office_x = 0;
	int office_y = 0;
	int walktime = 0, taxitime = 0;
	cin >> office_x >> office_y >> walktime >> taxitime;
	cout << office_x << office_y << walktime << taxitime << endl;
	int walktime_sum = 0;
	walktime_sum = walktime * (abs(office_x)+abs(office_y)); 
	int taxitime_least = 0, temp_taxitime = 0;
	taxitime_least = walktime * (abs(taxi_x[0])+abs(taxi_y[0])) + \
		taxitime * (abs(taxi_x[0]-office_x) + abs(taxi_y[0]-office_y));
	cout << "taxitime_least :" << taxitime_least << endl;
	for(i=1; i<n; ++i){
		temp_taxitime = walktime * (abs(taxi_x[i])+abs(taxi_y[i])) + \
		taxitime * (abs(taxi_x[i]-office_x) + abs(taxi_y[i]-office_y));
		cout << "i:" << i << ":" << temp_taxitime << endl;
		taxitime_least = (taxitime_least <= temp_taxitime) ? taxitime_least : temp_taxitime;
	}
	delete [] taxi_x;
	delete [] taxi_y;
	cout << ((taxitime_least <= walktime_sum) ? taxitime_least : walktime_sum) << endl;
	return 0;
} 
