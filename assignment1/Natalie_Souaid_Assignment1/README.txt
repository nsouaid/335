Name: Natalie Souaid
Date: February 16th 2017
Assignment: Homework #1
Professor: Ioannis Stamos

i. Which parts of my program were completed

This assignment covered the "big five" methods of a class and dealt with overloading certain operators to successfully implement a Chain class. The following were the concepts we "warmed up" with:

	-Zero-parameter constructor
	-Copy-constructor
	-Assignment (=) operator
	-Move-constructor
	-Move-assignment (=) operator
	-Destructor
	-One-parameter constructor
	-ReadChain
	-2x Index ([]) operator
	-2x Addition (+) operator
	-Stream (<<) operator

All parts of the Assignment were attempted and completed

ii. Bugs

The project delt with something that was very new to me: Using " < 'file.txt' " as our input. The concept took a while to grasp (creating many bugs meanwhile) but eventually, once understood made the entire project much clearer.

One of the biggest bugs I had throughout was dealing with memory. Redgarding the destructor: At first I tried to "loop through" the elements of the array so that each element would be deleted from the array (using the size_ as a stopping point) but this lead to memory issues (perhaps I was "deleting" un-authorized memory locations...?) THe error looked like this:

*** Error in `./test_chain': double free or corruption (fasttop): 0x0000000001e6a060 ***
======= Backtrace: =========
/lib64/libc.so.6(+0x791fb)[0x7fe084e5f1fb]
/lib64/libc.so.6(+0x8288a)[0x7fe084e6888a]
/lib64/libc.so.6(cfree+0x4c)[0x7fe084e6c2bc]
./test_chain[0x401b98]
./test_chain[0x40203f]
./test_chain[0x40158b]
./test_chain[0x401ab8]
/lib64/libc.so.6(__libc_start_main+0xf1)[0x7fe084e06401]
./test_chain[0x4012fa]
======= Memory map: ========
00400000-00404000 r-xp 00000000 fd:00 394677                             /home/nsouaid/Documents/335/assignment1/Code/test_chain
00603000-00604000 r--p 00003000 fd:00 394677                             /home/nsouaid/Documents/335/assignment1/Code/test_chain
00604000-00605000 rw-p 00004000 fd:00 394677                             /home/nsouaid/Documents/335/assignment1/Code/test_chain
01e57000-01e89000 rw-p 00000000 00:00 0                                  [heap]

The fact that this line here said "heap" indicated the wrong use of a pointer (in my case, deleting the "pointer contents" over and over again).

Other bugs included dealing with readchain method (mostly due to the default constructor not being initialized properly.... I had attempted to initialize the array_ pointer to a new object with size "size_" however I soon realized that I was doing two things wrong: dynamicaly allocating an array with size "size_" in the default doesn't make sense if "size_" equals 0. Also - it should be initially set to nullptr as shown).

iii. Instructions on how to run my program

The only thing that the user needs to be aware of when running this program is that all of the files in the directory must stay within the directory. Additionally, in order to compile:

	To compile on terminal, type:
	make all

	To delete executables and object file, type:
	make clean

	To run the program with the given input file, type:
	./test_chain < test_input_file.txt

iv. Input and output files (if any)

There is one inupt file that is included with the directory, called "test_input_file.txt". There are no output files with this program.
