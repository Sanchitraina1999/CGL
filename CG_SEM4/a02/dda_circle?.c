void myCircle::showCircle(){
	char *s;
	int s1,s2,ic;
	x=x1;y=y1;
	float i=0;
	while(i<=360){
		x=x1+r*cos(i);
		y=y1+r*sin(i);
		putpixel((x+320),480-(y+240),6);
		i+=0.5;
	}
	setcolor(15);
	sprintf(s,"Center(%d,%d)",x1,y1);
	outtextxy(40,10,"The Center Is At :=");
	outtextxy(40,20,s);
	sprintf(s,"Radius=%g",r);
	outtextxy(40,30,s);
	getch();
}
