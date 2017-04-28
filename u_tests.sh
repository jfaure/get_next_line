#!/bin/bash

gcc -o test_gnl string.c

diff <(man gcc | ./test_gnl) <(man gcc | cat)
diff <(echo -n abc | ./test_gnl) <(echo abc | cat)
diff <(echo -en "abc \n abc" | ./test_gnl) <(echo -e "abc \n abc" | cat)
