//program to test speed, results of quick sort vs. bubble sort
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <time.h>
#include <string.h>
#define pr printf

typedef int o;
void bs(o *a,o num)
{
	o t;
	for(int k=0;k<num-1;k++)
		for(int j=0;(j<num-1-k);j++)
			if(a[j]>a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
}
void qs(o *a,o num)
{
	o *p=a+num-1,*i=a-1,*j=a,t;
	
	if(num<=1) return;
	
	for(int k=0;k<num && j+k<p;k++)
	{
		if(j[k]<*p)
		{
			t=*(++i);*i=j[k];j[k]=t;
		}
	}
	t=*(++i);*i=*p;*p=t;
	
	qs(a,i-a);
	qs(i+1,a+num-1-i);
}


o main(o argc, o **argv)
{
	srand(time(NULL));
	o *i;
	o d=1000,v=0,q=0,n=0,z=0;
	double cl;
	
	for(int j=0;j<argc;j++)
	{
		if(strcmp(argv[j],"-s")==0 && argc>j) d=atoi(argv[++j]);
		if(strcmp(argv[j],"-r")==0 && argc>j) srand(atoi(argv[++j]));
		if(strcmp(argv[j],"-v")==0) v=1; //verbose
		if(strcmp(argv[j],"-n")==0) v=1,n=1; //output values on each line
		if(strcmp(argv[j],"-q")==0) q=1; //use qsort instead
		if(strcmp(argv[j],"-z")==0) z=1; //don't sort
		if(strcmp(argv[j],"?")==0)
		{
			pr("usage: %s [?] [-s <size of array>] [-r <random seed>] [-v] [-n] [-q] [-z]\n",argv[0]);
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
	
	
	if(!n && v)
	{
		pr("\nbefore: ");for(int j=0;j<d;j++)pr("%i,",i[j]);
		putc('\n',stdout);
	}
	
	cl=(double)clock();
	
	//-q to use quick sort
	if(!z)
	{
		if(!n)pr("\nsorting %u elements...\n",d);
		if(q) qs(i,d);
		else bs(i,d);
		if(!n)pr("sorting done\n");
	}
	
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
	
	if(!n)pr("\nfinished\nclocks: %u (%02u:%02u secs)\n",(uint64_t)(cl),(uint64_t)((double)(cl/CLOCKS_PER_SEC)/60.0L),(uint64_t)fmod(cl/CLOCKS_PER_SEC,60.0L));
	
	return 0;
}
