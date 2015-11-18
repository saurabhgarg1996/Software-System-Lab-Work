Group 14

C Vishwesh, 140050031		100%
Saurabh Garg, 140070003		100%
Aviral Kumar, 140070031		100%

Honor Code: 
I pledge on my honour that I have not given or received any unauthorized assistance on this assignment or any previous task. 

Question 1:

Address of the three nodes:

Head -> 0x602010
curr -> 0x6020d0
rev_transverse -> 0x6020d0

We looked at the addresses of the pointers in the main memory i.e. head, rev_traverse, curr etc by setting breakpoints and figured out that the head is not being allocated any memory. Then in the function reverse, the pointer back_head was called by value so no change was reflected back in the reverse_list function.

Thus we passed the back_head pointer as a pointer to a pointer (**).

=========================================================================================
Question 2:

time is a built in bash command. /usr/bin/time is aan external command which causes a fork and an exec to spawn an additional process.

The times obtained by time were upto 3 digits of precision (after decimal) while the entire path of time gave times only upto two digits of precision. 

Built in time command is more efficient and hence more accurate and precise time is displayed.
========================================================================================

Citations::

1. http://www.drdobbs.com/testing/13-linux-debuggers-for-c-reviewed/240156817
2. http://www.unix.com/unix-for-dummies-questions-and-answers/18315-differences-between-time-command-usr-bin-time.html
3. http://matplotlib.org/users/pyplot_tutorial.html
4. http://www.linuxintheshell.org/2013/02/26/episode-024-time-and-usrbintime/
5. stackoverflow.com
6. http://darkdust.net/files/GDB%20Cheat%20Sheet.pdf


 

  
