//input random data
#include<cstdio>
#include<ctime>
#include<cstdlib>
int main(){
	freopen("data.txt","w",stdout);
	srand(time(0));
	int maxn=rand()%50+10;
	for(int i=1;i<=maxn;i++){
		printf("%d %d\n",rand()%9+1,rand()%9+1);
	}
	printf("-1 -1\n");
	fclose(stdout);
	return 0;
}
