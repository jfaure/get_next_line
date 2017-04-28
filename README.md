# get_next_line
Epitech project Tech1

Description:
The goal of this project is to write a function that returns a read line from a file descriptor.
If there are no more lines to return, or if there is an error during the reading, the function will come back NULL.
You must define a macro called READ_SIZE file, which indicates the amount of characters to be read for each read() call.
Function should be prototyped as follows: char *get_next_line(const int fd);
(!) get_next_line should return the results without the '\n'.

The main complication is handling files that don't terminate in '\n'.

Tests: (gcc string.c)
man gcc | ./a.out;
./a.out <(echo -n abc);
./a.out <(echo -en "abc \n abc");
