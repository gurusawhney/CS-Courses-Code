# Problem 1 

1. There is a call to `free()` on line 26 of `prob1.c`. Which function allocates
the memory that is freed be this call? <br>
**Answer:**
The function that allocates the memory is 'getline()'


2. How many times is the function that you named in answer to 1 called? <br>
**Answer:**
The function 'getline()' is called as many times as there are lines.


3. Does the program have a memory leak? Explain your answer. <br>
**Answer:**
The program has no memory leaks. The same space that was originally allocated for getline() was used for every consequent call.

==2194== HEAP SUMMARY:
==2194==     in use at exit: 0 bytes in 0 blocks
==2194==   total heap usage: 2 allocs, 2 frees, 688 bytes allocated
==2194== 
==2194== All heap blocks were freed -- no leaks are possible



