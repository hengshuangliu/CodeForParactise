#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//终于到周末啦！小易走在市区的街道上准备找朋友聚会，突然服务器发来警报,
//小易需要立即回公司修复这个紧急bug。假设市区是一个无限大的区域，每条街道
//假设坐标是(X，Y)，小易当前在(0，0)街道，办公室在(gx,gy)街道上。小易周围
//有多个出租车打车点，小易赶去办公室有两种选择，一种就是走路去公司，另外一
//种就是走到一个出租车打车点，然后从打车点的位置坐出租车去公司。每次移动到
//相邻的街道(横向或者纵向)走路将会花费walkTime时间，打车将花费taxiTime时间。
//小易需要尽快赶到公司去，现在小易想知道他最快需要花费多少时间去公司。
//
//输出描述:
//输出一个整数表示，小易最快能赶到办公室的时间
//输入例子:
//2 // 第一行为周围出租车打车点的个数n(1 ≤ n ≤ 50)
//-2 -2 // 第二行为每个出租车打车点的横坐标tX[i] (-10000 ≤ tX[i] ≤ 10000)
//0 -2 //第三行为每个出租车打车点的纵坐标tY[i] (-10000 ≤ tY[i] ≤ 10000)
//-4 -2 //第四行为办公室坐标gx,gy(-10000 ≤ gx,gy ≤ 10000),以空格分隔
//15 3 //第五行为走路时间walkTime(1 ≤ walkTime ≤ 1000)和taxiTime(1 ≤ taxiTime ≤ 1000),以空格分隔
//输出例子:  
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
