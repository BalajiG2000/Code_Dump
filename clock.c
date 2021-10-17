#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
	struct  time t;
	struct arccoordstype sec_arc, min_arc, hr_arc;
	int i;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c://TurboC3//BGI");
	setcolor(RED);
	//Outer circle
	circle(320,240,100);
	circle(320,240,99);
	//Inner circle
	circle(320,240,80);
	circle(320,240,81);
	setcolor(WHITE);
	//mark four points
	line(320,160,320,165);//top
	line(320,320,320,325);//bottom
	line(400,240,395,240);//left
	line(240,240,245,240);//right

	while(!kbhit())
	{
		printf("Time is : %2d:%2d:%3d\r",t.ti_hour%12, t.ti_min, t.ti_sec);
		setcolor(0);
		line(320,240, sec_arc.xend, sec_arc.yend);
		line(320,240, min_arc.xend, min_arc.yend);
		line(320,240, hr_arc.xend, hr_arc.yend);
		//Store time into struct t
		gettime(&t);
		//hour
		setcolor(0);
		arc(320,240,270,90-(t.ti_hour*6*5),55);
		setcolor(YELLOW);
		getarccoords(&hr_arc);
		line(320,240, hr_arc.xend, hr_arc.yend);
		//minute
		setcolor(0);
		arc(320,240,270,90-t.ti_min*6,65);
		setcolor(CYAN);
		getarccoords(&min_arc);
		line(320,240, min_arc.xend, min_arc.yend);
		//center circle
		setcolor(WHITE);
		pieslice(320,240,0,360,5);
		//second
		setcolor(0);
		arc(320,240,270,90-t.ti_sec*6,75);
		setcolor(RED);
		getarccoords(&sec_arc);
		line(320,240, sec_arc.xend, sec_arc.yend);
		delay(250);
		}
	getch();
}
