denis@ubuntu:~/Desktop/var118$ make
gcc -c main.c
gcc -c stack.c
gcc -c tree.c
gcc -c parser.c
gcc -c task.c
gcc -o start main.o stack.o tree.o parser.o task.o
denis@ubuntu:~/Desktop/var118$ valgrind ./start
==19213== Memcheck, a memory error detector
==19213== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==19213== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==19213== Command: ./start
==19213== 
Menu:
1) Input the expression
2) Print the initial expression
3) Print the transformed expression
4) Print the initial tree
5) Print the transformed tree
6) Print this menu
0) Exit
Choose the action: 1
Input the expression: a*(-b)*(-2)*d
Choose the action: 2
The initial expression:
a*(-b)*(-2)*d
Choose the action: 3
The transformed expression:
a*b*2*d
Choose the action: 4
Tree of initial expression:
          d
       *
             2
          -
    *
          b
       -
 *
    a
Choose the action: 5
Tree of transformed expression
          d
       *
          2
    *
       b
 *
    a
Choose the action: 1
Input the expression: (a+b)*(-b)
Choose the action: 2
The initial expression:
(a+b)*(-b)
Choose the action: 3
The transformed expression:
-((a+b)*b)
Choose the action: 4
Tree of initial expression:
       b
    -
 *
       b
    +
       a
Choose the action: 5
Tree of transformed expression
       b
    *
          b
       +
          a
 -
Choose the action: 1
Input the expression: (a+b)*(-(a-b))
Choose the action: 2
The initial expression:
(a+b)*(-(a-b))
Choose the action: 3
The transformed expression:
-((a+b)*(a-b))
Choose the action: 4
Tree of initial expression:
          b
       -
          a
    -
 *
       b
    +
       a
Choose the action: 5
Tree of transformed expression
          b
       -
          a
    *
          b
       +
          a
 -
Choose the action: 1
Input the expression: (-(a+b)*(-(c+d)))
Choose the action: 2
The initial expression:
(-(a+b)*(-(c+d)))
Choose the action: 3
The transformed expression:
((a+b)*(c+d))
Choose the action: 4
Tree of initial expression:
             d
          +
             c
       -
    *
          b
       +
          a
 -
Choose the action: 5
Tree of transformed expression
       d
    +
       c
 *
       b
    +
       a
Choose the action: 1
Input the expression: a*(-2)*(-5)*4 
Choose the action: 2
The initial expression:
a*(-2)*(-5)*4
Choose the action: 3
The transformed expression:
a*2*5*4
Choose the action: 4
Tree of initial expression:
          4
       *
             5
          -
    *
          2
       -
 *
    a
Choose the action: 5
Tree of transformed expression
          4
       *
          5
    *
       2
 *
    a
Choose the action: 1
Input the expression: a*(-2)*(-3)*(-4)
Choose the action: 2
The initial expression:
a*(-2)*(-3)*(-4)
Choose the action: 3
The transformed expression:
-(a*2*3*4)
Choose the action: 4
Tree of initial expression:
             4
          -
       *
             3
          -
    *
          2
       -
 *
    a
Choose the action: 5
Tree of transformed expression
             4
          *
             3
       *
          2
    *
       a
 -
Choose the action: 0
==19213== 
==19213== HEAP SUMMARY:
==19213==     in use at exit: 0 bytes in 0 blocks
==19213==   total heap usage: 234 allocs, 234 frees, 6,728 bytes allocated
==19213== 
==19213== All heap blocks were freed -- no leaks are possible
==19213== 
==19213== For counts of detected and suppressed errors, rerun with: -v
==19213== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
denis@ubuntu:~/Desktop/var118$ 
