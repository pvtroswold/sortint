//program to test speed, results of quick sort vs. bubble sort
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <time.h>
#include <string.h>

// #define swapr(a,b,c) c=a,a=b,b=c
// #define sb(a,b,c) (a>b)?(swapr(a,b,c)):(0)
// int tmp;
// #define s(a) sb(*(a),(a)[1],tmp)
#define pr printf

typedef int o;
void s(o *a)
{
	// *a>*(a+1)?(swapr(*a,*(a+1))):0;
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
void qs(o *a,o num)
{
	o *p=a+num-1,*i=a-1,*j=a,t;
	
	// pr("### ### q(%i,%i)\n",*a,num>0?a[num-1]:*a);
	if(num<=1)
	{
		// pr("### +++ num<=1\n");
		return;
	}
	
	// pr("### p:%i\n",*p);
	
	for(int k=0;k<num && j+k<p;k++)
	{
		// pr("### %i < %i?\n",j[k],*p);
		if(j[k]<*p)
		{
			// pr("### --- yes, swapr(%i,%i)\n",i[1],j[k]);
			t=*(++i);*i=j[k];j[k]=t;
		}
		// else pr("### --- no\n");
	}
	
	// pr("### ### swapr(%i,%i)\n",i[1],*p);
	t=*(++i);*i=*p;*p=t;
	
	// swapr(*i,*p,*t);
	qs(a,i-a);
	qs(i+1,a+num-1-i);
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
		if(strcmp(argv[j],"-r")==0 && argc>j) srand(atoi(argv[++j]));
		if(strcmp(argv[j],"-v")==0) v=1; //verbose
		if(strcmp(argv[j],"-n")==0) v=1,n=1; //output values on each line
		if(strcmp(argv[j],"-q")==0) q=1; //use qsort instead
		if(strcmp(argv[j],"?")==0)
		{
			pr("usage: %s [?] [-s <size of array>] [-r <random seed>] [-v (for verbose)] [-n (ints only output)] [-q (use qsort instead)]\n",argv[0]);
			return 0;
		}
	}
	
	i=malloc(d*sizeof(int));
	if(!i)
	{
		pr("cannot allocate memory\n");
		return 1;
	}
	
	if(!n)pr("randomizing...\n");
	for(int j=0;j<d;j++)i[j]=rand()%35536;
	
	
	// pr("number of elements: %i\n",d);
	if(!n && v)
	{
		pr("before: ");for(int j=0;j<d;j++)pr("%i,",i[j]);
		putc('\n',stdout);
	}
	
	if(!n)pr("sorting %u elements...\n",d);
	cl=(double)clock();
	
	//-q to use qsort
	if(q)
		qs(i,d);
		// qsort(i,d,sizeof(int),s2);
	else
		for(int k=0;k<d-1;k++)
			for(int j=0;(j<d-1-k);j++)s(i+j);
	
	if(!n)pr("sorting done\n");
	cl=(double)clock()-cl; //'stop' clock
	
	if(v)
	{
		if(!n)pr("\nafter:  ");
		else pr("ints: %i\n",d);
		for(int j=0;j<d;j++)
		{
			if(!n)pr("%i,",i[j]);
			else pr("%i\n",i[j]);
		}
		putc('\n',stdout);
	}
	
	if(!n)pr("finished\nclocks: %u (%02u:%02u secs)\n",(uint64_t)(cl),(uint64_t)((double)(cl/CLOCKS_PER_SEC)/60.0L),(uint64_t)fmod(cl/CLOCKS_PER_SEC,60.0L));
	
	return 0;
}
