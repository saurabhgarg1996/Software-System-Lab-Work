Group 14

C Vishwesh, 140050031		100%
Saurabh Garg, 140070003		100%
Aviral Kumar, 140070031		100%

Honor Code: 
I pledge on my honour that I have not given or received any unauthorized assistance on this assignment or any previous task. 

Citations:

1.http://linuxconfig.org/bash-scripting-tutorial
2.http://stackoverflow.com/questions/6388046/extract-integer-from-string-using-bash
3.http://bash.cyberciti.biz/file-management/unix-linu-shell-script-read-file-datetime/
4.http://www.computerhope.com/unix/stat.htm
5.http://stackoverflow.com/questions/918886/how-do-i-split-a-string-on-a-delimiter-in-bash
6.http://tldp.org/LDP/abs/html/
7. http://www.cyberciti.biz/faq/unix-linux-appleosx-bsd-bash-count-characters-variables/
8.http://askubuntu.com/questions/636050/how-to-check-if-two-or-more-programs-are-installed-using-a-bash-script
9. serverfault.com/questions/259339/bash-variable-loses-value-at-end-of-while-read-loop
10. http://stackoverflow.com/questions/16623835/bash-remove-a-fixed-prefix-suffix-from-a-string
11. http://stackoverflow.com/questions/29749205/bash-check-if-a-program-is-installed-or-not-using-bash-script
12. unix.stackexchange.com/questions/53310/splitting-string-by-the-first-occurrence-of-a-delimiter
13. linuxpoison.blogspot.in/2012/08/bash-script-how-read-file-line-by-line.html
14. http://tldp.org/LDP/abs/html/manipulatingvars.html
15. http://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO-3.html
16. http://unix.stackexchange.com/questions/181937/how-create-a-temporary-file-in-shell-script
17. http://stackoverflow.com/questions/2439579/how-to-get-the-first-line-of-a-file-in-a-bash-script
18. http://stackoverflow.com/questions/16631423/using-linux-grep-command-need-output-to-text-file-cleaner-output

What we want to tell you :-

Problem 1:
The script first truncates all the white spaces in the file and this new verison is stored in a temporary file. Then, this temp file is read line by line and cheked for comments '//'. If these comments start in the middle of the line, then the part before this is taken and cheked for '#include< >'. If a match is found, then the text inside the <> is checked for 2 or more dots. If 2 or more . are present, the file is taken to be invalid and is not listed. All  the correct files are listed along with exit codes.

Problem 2:
The . and .. directories have also been counted as folders.

Problem 4:
The file myopen.cfg must be in the home directory, and on running the script, error messages are displayed if the file is not found, or the program is not found or the program is not installed or the extension doesn't exist.

Problem 5:
Two files are created "GOOD.txt" and "BAD.txt". If they already exist, they are removed and new ones are created. GOOD stores all the correctly compiled files and BAD stores all the files which could not compile, in the current working directory.

Problem 6:
All files in the directory of script except script itself are renamed.
This is done by using stat which is used display detailed status of file or directory. %y format sequence is used to extract "Last modification time" into a variable. Then using delimiters and rename file, renaming was done.
Currently it also renames all backup files.
Also if there's no modification in files on terminal mv shows both are the same files.

Problem 7:
If population_inc.csv file already exist then script first removes that file and then create the file with required data.
Scipt parse each line of population.csv to create an array of year and population. Array is written to new file population_inc.csv after calculation of population increase.
     
