Name: Natalie Souaid
Date: February 16th 2017
Assignment: Homework #1
Professor: Ioannis Stamos

Summary
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

Bugs
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
7fe080000000-7fe080021000 rw-p 00000000 00:00 0 
7fe080021000-7fe084000000 ---p 00000000 00:00 0 
7fe084de6000-7fe084fa3000 r-xp 00000000 fd:00 658611                     /usr/lib64/libc-2.24.so
7fe084fa3000-7fe0851a2000 ---p 001bd000 fd:00 658611                     /usr/lib64/libc-2.24.so
7fe0851a2000-7fe0851a6000 r--p 001bc000 fd:00 658611                     /usr/lib64/libc-2.24.so
7fe0851a6000-7fe0851a8000 rw-p 001c0000 fd:00 658611                     /usr/lib64/libc-2.24.so
7fe0851a8000-7fe0851ac000 rw-p 00000000 00:00 0 
7fe0851ac000-7fe0851c2000 r-xp 00000000 fd:00 654120                     /usr/lib64/libgcc_s-6.3.1-20161221.so.1
7fe0851c2000-7fe0853c1000 ---p 00016000 fd:00 654120                     /usr/lib64/libgcc_s-6.3.1-20161221.so.1
7fe0853c1000-7fe0853c2000 r--p 00015000 fd:00 654120                     /usr/lib64/libgcc_s-6.3.1-20161221.so.1
7fe0853c2000-7fe0853c3000 rw-p 00016000 fd:00 654120                     /usr/lib64/libgcc_s-6.3.1-20161221.so.1
7fe0853c3000-7fe0854cb000 r-xp 00000000 fd:00 658703                     /usr/lib64/libm-2.24.so
7fe0854cb000-7fe0856ca000 ---p 00108000 fd:00 658703                     /usr/lib64/libm-2.24.so
7fe0856ca000-7fe0856cb000 r--p 00107000 fd:00 658703                     /usr/lib64/libm-2.24.so
7fe0856cb000-7fe0856cc000 rw-p 00108000 fd:00 658703                     /usr/lib64/libm-2.24.so
7fe0856cc000-7fe085844000 r-xp 00000000 fd:00 658346                     /usr/lib64/libstdc++.so.6.0.22
7fe085844000-7fe085a44000 ---p 00178000 fd:00 658346                     /usr/lib64/libstdc++.so.6.0.22
7fe085a44000-7fe085a4e000 r--p 00178000 fd:00 658346                     /usr/lib64/libstdc++.so.6.0.22
7fe085a4e000-7fe085a50000 rw-p 00182000 fd:00 658346                     /usr/lib64/libstdc++.so.6.0.22
7fe085a50000-7fe085a54000 rw-p 00000000 00:00 0 
7fe085a54000-7fe085a79000 r-xp 00000000 fd:00 658402                     /usr/lib64/ld-2.24.so
7fe085c57000-7fe085c5b000 rw-p 00000000 00:00 0 
7fe085c76000-7fe085c79000 rw-p 00000000 00:00 0 
7fe085c79000-7fe085c7a000 r--p 00025000 fd:00 658402                     /usr/lib64/ld-2.24.so
7fe085c7a000-7fe085c7b000 rw-p 00026000 fd:00 658402                     /usr/lib64/ld-2.24.so
7fe085c7b000-7fe085c7c000 rw-p 00000000 00:00 0 
7ffd2bc79000-7ffd2bc9a000 rw-p 00000000 00:00 0                          [stack]
7ffd2bd22000-7ffd2bd24000 r--p 00000000 00:00 0                          [vvar]
7ffd2bd24000-7ffd2bd26000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
LINE 7: a = b, cout << a ->Aborted (core dumped)


