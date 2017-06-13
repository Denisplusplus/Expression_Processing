denis@ubuntu:~/Desktop/var118$ valgrind ./start
==19265== Memcheck, a memory error detector
==19265== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==19265== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==19265== Command: ./start
==19265== 
Menu:
1) Input the expression
2) Print the initial expression
3) Print the transformed expression
4) Print the initial tree
5) Print the transformed tree
6) Print this menu
0) Exit
Choose the action: aaaaaaaaaaaaaaaaaaaaaaaaa
Error. Type '6' to find the solution
==19265== 
==19265== HEAP SUMMARY:
==19265==     in use at exit: 0 bytes in 0 blocks
==19265==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==19265== 
==19265== All heap blocks were freed -- no leaks are possible
==19265== 
==19265== For counts of detected and suppressed errors, rerun with: -v
==19265== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
denis@ubuntu:~/Desktop/var118$ 

-----------------------------------------------------------------------------------------------
denis@ubuntu:~/Desktop/var118$ valgrind ./start
==19269== Memcheck, a memory error detector
==19269== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==19269== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==19269== Command: ./start
==19269== 
Menu:
1) Input the expression
2) Print the initial expression
3) Print the transformed expression
4) Print the initial tree
5) Print the transformed tree
6) Print this menu
0) Exit
Choose the action: 2
You have to input the expression before printing of this
Choose the action: 3
The transformed expression:

Choose the action: 4
Tree is empty
Choose the action: 5
Tree is empty
Choose the action: 0
==19269== 
==19269== HEAP SUMMARY:
==19269==     in use at exit: 0 bytes in 0 blocks
==19269==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==19269== 
==19269== All heap blocks were freed -- no leaks are possible
==19269== 
==19269== For counts of detected and suppressed errors, rerun with: -v
==19269== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
