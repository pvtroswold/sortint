//selection sort variant
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <time.h>

#define small(a,b) (a>b?b:a)
#define big(a,b) (a>b?a:b)
#define swap(a,b) (o c=a;a=b;b=c)
#define p printf

typedef int o;
void s(o *a)
{
	// *a>*(a+1)?(swap(*a,*(a+1))):0;
	if(*a>*(a+1))
	{
		o c=*a;
		*a=*(a+1);
		*(a+1)=c;
	}
}
int s2(int *a,int *b) //for qsort
{
	return (*a<*b)?((a==b)?0:-1):1;
}
o main(o argc, o **argv)
{
	srand(time(NULL));
	o *i;
	o d=1000,v=0,q=0;
	
	for(int j=0;j<argc;j++)
	{
		if(strcmp(argv[j],"-s")==0 && argc>j) d=atoi(argv[++j]);
		if(strcmp(argv[j],"-v")==0) v=1;
		if(strcmp(argv[j],"-q")==0) q=1;
		if(strcmp(argv[j],"?")==0)
		{
			p("usage: %s [-s <size of array>] [-v (for verbose)] [-q (use qsort instead)] [?]\n",argv[0]);
			return 0;
		}
	}
	
	if(!q && d>=100000)
	{
		q=1;
		p("automatically using qsort since size>=100000\n");
	}
	
	i=malloc(d*sizeof(int));
	if(!i)
	{
		p("cannot allocate memory\n");
		return 1;
	}
	
	p("randomizing...\n");
	for(int j=0;j<d;j++)i[j]=rand()%UINT_MAX;
	
	
	// p("number of elements: %i\n",d);
	if(v)
	{
		p("before: ");for(int j=0;j<d;j++)p("%i,",i[j]);
		putc('\n',stdout);
	}
	
	p("sorting %u elements...\n",d);
	uint64_t cl=clock();
	
	//-q to use qsort
	if(q)
		qsort(i,d,sizeof(int),s2);
	else
		for(int k=0;k<d-1;k++)
			for(int j=0;j<d-1;j++)s(i+j);
	
	p("sorting done\n");
	cl=clock()-cl; //'stop' clock
	
	if(v)
	{
		p("\nafter:  ");for(int j=0;j<d;j++)p("%i,",i[j]);
		putc('\n',stdout);
	}
	
	p("finished\nclocks: %u (%02u:%02u secs)\n",cl,(cl/CLOCKS_PER_SEC)/60,(cl/CLOCKS_PER_SEC)%60);
	
	return 0;
}
