Note: These programs have only been tested on Windows


To use sortint:  sortint [?] [-s <size of array>] [-r <random seed>] [-v (for verbose)]
                         [-n (ints only output)] [-q (use qsort instead)] [-z (don't sort)]

e.g.,  sortint -s 5000 -r 1234 -q
will print 5000 random integers with random seed '1234' using the implementation of thequick sort algorithm.
If you repeat this without the -q switch,you can immediately compare the speed in clocks and seconds between
the bubble sort and quick sort implementations.


To use view (only with stdout from sortint): sortint -n | view
Alternatively                              : sortint -n > file.dat & view < file.dat

view.c depends on the tigr library, which you can find as of this writing at the following URL:
https://bitbucket.org/rmitton/tigr/src/be3832bee7fb2f274fe5823e38f8ec7fa94e0ce9?at=default
