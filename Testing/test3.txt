denis@ubuntu:~/Desktop/var118$ valgrind ./start
==19302== Memcheck, a memory error detector
==19302== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==19302== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==19302== Command: ./start
==19302== 
Menu:
1) Input the expression
2) Print the initial expression
3) Print the transformed expression
4) Print the initial tree
5) Print the transformed tree
6) Print this menu
0) Exit
Choose the action: 1
Input the expression: (-(a+b))*(b/d)*(-(2^3))
Choose the action: 2
The initial expression:
(-(a+b))*(b/d)*(-(2^3))
Choose the action: 3
The transformed expression:
(a+b)*b/d*2^3
Choose the action: 4
Tree of initial expression:
             3
          ^
             2
       -
    *
          d
       /
          b
 *
          b
       +
          a
    -
Choose the action: 5
Tree of transformed expression
          3
       ^
          2
    *
          d
       /
          b
 *
       b
    +
       a
Choose the action: 1
Input the expression: a
Choose the action: 2
The initial expression:
a
Choose the action: 3
The transformed expression:
a
Choose the action: 4
Tree of initial expression:
 a
Choose the action: 5
Tree of transformed expression
 a
Choose the action: bdcadfad 
Error. Type '6' to find the solution
==19302== 
==19302== HEAP SUMMARY:
==19302==     in use at exit: 0 bytes in 0 blocks
==19302==   total heap usage: 67 allocs, 67 frees, 1,936 bytes allocated
==19302== 
==19302== All heap blocks were freed -- no leaks are possible
==19302== 
==19302== For counts of detected and suppressed errors, rerun with: -v
==19302== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
denis@ubuntu:~/Desktop/var118$ 
