#include <graphics.h>
#include<stdio.h>
#include<time.h>
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    int coordsForHourX[12]={50,87,100,87,50,0,-50,-87,-100,-87,-50,0};
	int coordsForHourY[12]={-87,-50,0,50,87,100,87,50,0,-50,-87,-100};


	int coordsForMinSecX[60]={0,18,35,53,69,85,100,114,126,138,147,155,162,166,169,170,169,166,162,155,147,138,126,114,100,85,69,53,35,18,0,-18,-35,-53,-69,-85,-100,-114,-126,-138,-147,-155,-162,-166,-169,-170,-169,-166,-162,-155,-147,-138,-126,-114,-100,-85,-69,-53,-35,-18};
	int coordsForMinSecY[60]={-170,-169,-166,-162,-155,-147,-138,-126,-114,-100,-85,-69,-53,-35,-18,0,18,35,53,69,85,100,114,126,138,147,155,162,166,169,170,169,166,162,155,147,138,126,114,100,85,69,53,35,18,0,-18,-35,-53,-69,-85,-100,-114,-126,-138,-147,-155,-162,-166,-169};

    time_t rawTime;
    struct tm * currentTime;
    char a[100];

    int midX=getmaxx()/2;
    int midY=getmaxy()/2;

    int IMS;

    while(1){
    rawTime=time(NULL);
    currentTime=localtime(&rawTime);

    setcolor(WHITE);
    circle(midX,midY,200);

    outtextxy(midX+90,midY-170,"1");
	outtextxy(midX+160,midY-100,"2");
	outtextxy(midX+185,midY-7,"3");
	outtextxy(midX+158,midY+88,"4");
	outtextxy(midX+90,midY+155,"5");
	outtextxy(midX-3,midY+180,"6");
	outtextxy(midX-95,midY+155,"7");
	outtextxy(midX-163,midY+85,"8");
	outtextxy(midX-193,midY-7,"9");
	outtextxy(midX-170,midY-98,"10");
	outtextxy(midX-100,midY-170,"11");
	outtextxy(midX-6,midY-195,"12");

    strftime(a,100,"%I",currentTime);
	sscanf(a,"%d",&IMS);
	setcolor(RED);
	line(midX,midY,midX+coordsForHourX[IMS-1],midY+coordsForHourY[IMS-1]);

	strftime(a,100,"%M",currentTime);
	sscanf(a,"%d",&IMS);
	setcolor(YELLOW);
	line(midX,midY,midX+coordsForMinSecX[IMS],midY+coordsForMinSecY[IMS]);

	strftime(a,100,"%S",currentTime);
	sscanf(a,"%d",&IMS);
	setcolor(GREEN);
	line(midX,midY,midX+coordsForMinSecX[IMS],midY+coordsForMinSecY[IMS]);
    delay(1000);
    cleardevice();
    }
getch();
closegraph();
return 0;
}
