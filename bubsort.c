//bubble sort variant
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
	o d=1000,v=0,q=0,n=0;
	double cl;
	
	for(int j=0;j<argc;j++)
	{
		if(strcmp(argv[j],"-s")==0 && argc>j) d=atoi(argv[++j]);
		if(strcmp(argv[j],"-v")==0) v=1; //verbose
		if(strcmp(argv[j],"-n")==0) v=1,n=1; //output values on each line
		if(strcmp(argv[j],"-q")==0) q=1; //use qsort instead
		if(strcmp(argv[j],"?")==0)
		{
			p("usage: %s [?] [-s <size of array>] [-v (for verbose)] [-n (ints only output)] [-q (use qsort instead)]\n",argv[0]);
			return 0;
		}
	}
	
	if(!n && !q && d>=100000)
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
	
	if(!n)p("randomizing...\n");
	for(int j=0;j<d;j++)i[j]=rand()%UINT_MAX;
	
	
	// p("number of elements: %i\n",d);
	if(!n && v)
	{
		p("before: ");for(int j=0;j<d;j++)p("%i,",i[j]);
		putc('\n',stdout);
	}
	
	if(!n)p("sorting %u elements...\n",d);
	cl=(double)clock();
	
	//-q to use qsort
	if(q)
		qsort(i,d,sizeof(int),s2);
	else
		for(int k=0;k<d-1;k++)
			for(int j=0;(j<d-1-k);j++)s(i+j);
	
	if(!n)p("sorting done\n");
	cl=(double)clock()-cl; //'stop' clock
	
	if(v)
	{
		if(!n)p("\nafter:  ");
		for(int j=0;j<d;j++)
		{
			if(!n)p("%i,",i[j]);
			else p("%i\n",i[j]);
		}
		putc('\n',stdout);
	}
	
	if(!n)p("finished\nclocks: %u (%02u:%02u secs)\n",(uint64_t)(cl),(uint64_t)((double)(cl/CLOCKS_PER_SEC)/60.0L),(uint64_t)fmod(cl/CLOCKS_PER_SEC,60.0L));
	
	return 0;
}
