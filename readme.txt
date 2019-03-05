Note: These programs have only been tested on Windows


To use sortint:  sortint [?] [-s <size of array>] [-r <random seed>] [-v (for verbose)] [-n (ints only output)] [-q (use qsort instead)]

e.g.,  sortint -s 5000 -r 1234 -q
will print 5000 random integers with random seed '1234' using the quick sort algorithm. If you repeat this without the -q switch,
you can immediately compare the speed in clocks and seconds between bubble sort and quick sort.


To use view (only with stdout from sortint): sortint -n | view
Alternatively                              : sortint -n > file.dat & view < file.dat
