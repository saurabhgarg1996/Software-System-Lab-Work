Group 14

C Vishwesh, 140050031		100%
Saurabh Garg, 140070003		100%
Aviral Kumar, 140070031		100%

Honor Code: 
I pledge on my honour that I have not given or received any unauthorized assistance on this assignment or any previous task. 

Answer to Question 1(c):
===============================
Patch was applied by using the terminal command patch b2timer.h < b2timer_h.patch and likewise for b2timer.cpp. The lines changed are as:

Some lines have been added and some have been deleted in both the files.

b2timer.h =================>

#if defined(__linux__) || defined (__APPLE__)
#include <sys/time.h>
#endif

unsigned long m_start_usec;
timeval m_start; 

these were added and::
unsigned long m_start_usec; was subtracted (removed)

7 LINES CHANGED (MODIFICATIONS: 6 INSERTIONS ( 1 blank line) and 1 deletion)

b2timer.cpp =============>

These were added-----
m_start=t;
m_start_usec = t.tv_usec * 0.001f;

timeval t, res;
gettimeofday(&t, 0);
timersub(&t, &m_start, &res);
return res.tv_sec*1000 + res.tv_usec * 0.001f;
//return 1000.0f * (t.tv_sec - m_start_sec) + 0.001f * (t.tv_usec - m_start_usec);

These were subtracted:-----
#include <sys/time.h>

m_start_usec = t.tv_usec;
timeval t;
gettimeofday(&t, 0);
return 1000.0f * (t.tv_sec - m_start_sec) + 0.001f * (t.tv_usec - m_start_usec);

TOTAL LINES CHANGED ARE::: 13 IN TOTAL (Including insertions and deletions)



(e) To reduce size of cs251_base_code we copied the new timer.h and timer.cpp into the external of the Box2D folder and 
then compressed it to reduce the size.


(h) The changes that were done is addition of a readme.txt file by the middle roll number.

(j) As we don't have a documentation as of now, we did not push this into the repo.

Our repo is named as "cs251_base_code"
========================================================================================================
Problem 2::

To run the code on the terminal type :: python3 comment_finder.py test_code.cpp
The output gets written on a file named test_code_out.txt


Citations:
1. https://help.github.com/articles/changing-a-remote-s-url/
2. http://serverfault.com/questions/315278/why-is-git-pull-throws-an-error-cannot-be-used-without-a-working-tree
3. https://www.atlassian.com/git/tutorials/
4. https://docs.python.org/3/
5. https://git-scm.com/documentation

       

