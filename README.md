jkc1, usenka
Jacky Chung
Andrei Usenka


To run:
(where page_size and window_size are numbers
and process is the name of the process)


chmod u+x sim.sh
./sim page_size window_size process


Example usage:
./sim 128 100000 quicksort



Initial sorting problem is of size 10000, to change this you will have to edit PROBLEM_SIZE in quicksort.c and/or heapsort.c

The size of the hash table is set at 100, to change this you will have to edit SIZE in simulator.h

References 
https://en.wikipedia.org/wiki/Heapsort
http://stackoverflow.com/questions/806906/how-do-i-test-if-a-variable-is-a-number-in-bash

http://dl.acm.org/citation.cfm?id=512274.512284&coll=Portal&dl=ACM&idx=J79&part=magazine&WantType=Magazines&title=Communications%2520of%2520the%2520ACM
http://dl.acm.org/citation.cfm?id=366644
https://en.wikipedia.org/wiki/Quicksort