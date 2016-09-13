#include<cstring>
#include<iostream>
#include<ctime>
using namespace std;
#define N 100000005

bool vis[N];
int p[N], cnt, phi[N];

// 求1到n之间素数的个数
int Euler(int n){
	int i, j, k;
	phi[1] = 1;
	for (i = 2; i < n; ++i){
		if (!vis[i]){
			p[cnt++] = i;
			phi[i] = i - 1;
		}
		for (j = 0; j < cnt && i * p[j] < n; ++j){
			vis[i * p[j]] = true;
			if (i % p[j]) phi[i * p[j]] = phi[i] * phi[p[j]];
			else {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
	return cnt;
}

int Eratosthenes (int n){
		int i, j, k;
		phi[1] = 1;
		for (i = 2; i < n; ++i){
				if (!vis[i]) p[cnt++] = i;
				for (j = i; j < n; j += i) {
						if (!phi[j]) phi[j] = j;
						phi[j] = phi[j] / i * (i - 1);
						vis[j] = true;
				}
		}
		return cnt;
}

int main(){
		clock_t st, en;
		int num;
		double sec;
		for (int t = 10; t < N; t *= 10){
				cout << t << ':' << endl;
				st = clock();
				num = Euler(t);
				en = clock();
				sec = (double)(en - st) / (double) CLOCKS_PER_SEC;
				//cout << "Euler : " << cnt << ' ' << sec << endl;
				printf("Euler :\t\t%8d\t%.8lf\n", num, sec);
				memset(vis, 0, sizeof(vis)), memset(p, 0, sizeof(p)), memset(phi, 0, sizeof(phi)), cnt = 0;
				st = clock();
				num = Eratosthenes(t);
				en = clock();
				sec = (double)(en - st) / (double) CLOCKS_PER_SEC;
				//cout << "Eratosthenes : " << cnt << ' ' << sec << endl;
				printf("Eratosthenes :\t%8d\t%.8lf\n", num, sec);
		}
		return 0;
}