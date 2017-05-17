#include<cstdio>
#include<Windows.h>
#define SLEEPTIME 500
#define MAXN 10+1
#define KEEP 2
#define BORN 3
struct Cell{
	bool live;
	int others;
}c[MAXN][MAXN];
int round=0,suriver=0;
void HideCursor() { 
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};  
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
// 更改窗口大小，自适应
void ChangeWindow() {
    const int columns = 2*MAXN;
    const int rows = MAXN;
    char ch[100];
    int size = sprintf(ch,"mode con cols=%d lines=%d",columns,rows);
    ch[size]='\0';
    system(ch);
    HideCursor();
}
inline void init(){
	int x,y;
	while(1){
		scanf("%d %d",&x,&y);
		if(x>0&&x<=MAXN&&y>0&&y<=MAXN)
			c[x][y].live=true;
		else if(x==-1&&y==-1) return ;
		else printf("NO EXIST!\n");
	}
	fclose(stdin);
}
inline void judge(){
	for(int i=1;i<MAXN;i++)
		for(int j=1;j<MAXN;j++){
				c[i][j].others=0;
				if(c[i-1][j].live&&i-1>0) c[i][j].others++;
				if(c[i+1][j].live&&i+1<MAXN) c[i][j].others++;
				if(c[i][j-1].live&&j-1>0) c[i][j].others++;
				if(c[i][j+1].live&&j+1<MAXN) c[i][j].others++;
				if(c[i-1][j-1].live&&i-1>0&&j-1>0) c[i][j].others++;
				if(c[i+1][j-1].live&&i+1<MAXN&&j-1>0) c[i][j].others++; 
				if(c[i-1][j+1].live&&i-1>0&&j+1<MAXN) c[i][j].others++;
				if(c[i+1][j+1].live&&i+1<MAXN&&j+1<MAXN) c[i][j].others++;
		}
	suriver=0;
	for(int i=1;i<MAXN;i++)
		for(int j=1;j<MAXN;j++){
				switch(c[i][j].others){
					case BORN: c[i][j].live=true;suriver++; break;
					case KEEP: if(c[i][j].live)suriver++;break;
					default: c[i][j].live=false; break;
				}
		}
}
inline void draw(){
	ChangeWindow();
	//system("Cls");
	for(int i=1;i<MAXN;i++){
		for(int j=1;j<MAXN;j++){
			if(c[i][j].live)	printf("■");
			else printf("□");
		}
		//printf("\n");
	}
	printf(" round:%d suriver:%d",round,suriver);
	//printf("--------------\n");
	//Sleep(500);
}
int main(){
	//freopen("debug.out","w",stdout);
		printf("Input by file?(\"y\"or\"n\")\n");
	if(getchar()=='y') freopen("data.txt","r",stdin);
	else printf("Put points you want.\nInput -1 -1 to finish\n");
	init();
	draw();
	while(1){
		round++;
		judge();
		draw();
		Sleep(SLEEPTIME);
	}
	//fclose(stdout);
	return 0;
}
