#include "tigr.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>

#define xy2i(x,y,w) ((y)*w+(x))
#define spix(x,y,w,col) wind->pix[xy2i((x),(y),w)*sizeof(TPixel)].r=col>>16&0x0000ff;\
		wind->pix[xy2i((x),(y),w)*sizeof(TPixel)].g=col>>8&0x0000ff;\
		wind->pix[xy2i((x),(y),w)*sizeof(TPixel)].b=col&0x0000ff

void main(int argc,char **argv)
{
	int *i,d;
	
	Tigr *wind=tigrWindow(640,480,"sortint | view",NULL);
	
	fscanf(stdin,"ints: %i",&d);
	assert(d>=0);
	
	i=malloc(d*sizeof(int));
	assert(i!=NULL);
	printf("read %i ints\n",d);
	
	for(int j=0;j<d;j++)
	{
		fscanf(stdin,"%i\n",&i[j]);
		// printf("%i: %i\n",j,i[j]);
	}
	
	printf("smallest:%i\nbiggest:%i\n",i[0],i[d-1]);
	
	while(true)
	{
		if(tigrClosed(wind) || tigrKeyHeld(wind,TK_ESCAPE)) break; //break out of loop
		
		for(int j=0;j<d;j++)
		{
			float ratio1=((float)j/d)*640.0f;
			float ratio2=((float)(i[j])/35536.0f)*480.0f;
			// printf("i[j]:%i,r2:%i\n",i[j],(int)ratio2);
			tigrLine(wind,  (int)ratio1,480,  (int)ratio1,480-((int)ratio2),  tigrRGB(0xff,0xff,0xff));
		}
		
		tigrUpdate(wind);
		Sleep(20);
	}
	
	free(i);
	tigrFree(wind);
}
