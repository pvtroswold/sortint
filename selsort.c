//selection sort variant
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
	o d=1000,v=0,q=0;
	// if(argc<2)
	// {
		// p("usage: %s [-s <size of array>] [-v (for verbose)] [-q (use qsort instead)]\n",argv[0]);
		// return 1;
	// }
	for(int j=0;j<argc;j++)
	{
		if(strcmp(argv[j],"-s")==0 && argc>j) d=atoi(argv[++j]);
		if(strcmp(argv[j],"-v")==0) v=1;
		if(strcmp(argv[j],"-q")==0) q=1;
	}
	// p("d:%i,v=%i\n",d,v);
	
	srand(time(NULL));
	o i[100000];
	o is=sizeof(i)/sizeof(o);
	is=is<d?is:d;
	
	// p("d:%i,v=%i,is=%i\n",d,v,is);
	
	p("randomizing...\n");
	for(int j=0;j<is;j++)i[j]=rand()%UINT_MAX;
	
	
	// p("number of elements: %i\n",is);
	if(v)
	{
		p("before: ");for(int j=0;j<is;j++)p("%i,",i[j]);
		putc('\n',stdout);
	}
	
	p("sorting %u elements...\n",is);
	uint64_t cl=clock();
	
	//-q to use qsort
	if(q)
		qsort(i,is,sizeof(int),s2);
	else
		for(int k=0;k<is-1;k++)
			for(int j=0;j<is-1;j++)s(i+j);
	
	p("sorting done\n");
	cl=clock()-cl; //'stop' clock
	
	if(v)
	{
		p("\nafter:  ");for(int j=0;j<is;j++)p("%i,",i[j]);
		putc('\n',stdout);
	}
	
	p("finished\nclocks: %u (%02u:%02u secs)\n",cl,(cl/CLOCKS_PER_SEC)/60,(cl/CLOCKS_PER_SEC)%60);
	
	return 0;
}
