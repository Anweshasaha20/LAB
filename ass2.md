## Anwesha Saha
## Roll : 002311001088
## Assignment 2 
## Consider the program in folder assign2.
## a. Put a breakpoint in 1 st executable line of the innermost loop.
### Ans:
```sh
(gdb) b 12
Breakpoint 1 at 0x1173: file d.c, line 12.
```
## b. If you run and continue ,how many times it is supposed to stop at breakpoint 1?
### $3000 \times 200 \times 10$
## c. How will you continue so that it stops at 1000 th iteration of innermost loop ?
```sh
(gdb) ignore 1 999
Will ignore next 999 crossings of breakpoint 1.
```
## d. How you can condition your breakpoint , so that the loop stops at every 1000 th iteration of innermost loop ?
```sh
condition 1 k>0 && (k-999)%1000 ==0
```
## e. Put a breakpoint in the 1 st line of outermost loop.
```sh
(gdb) b 8
Breakpoint 2 at 0x1161: file d.c, line 8.
```
## f. Disable breakpoint “1”
```sh
(gdb) disable 1
```
## g. Add a command to breakpoint 2 so that it prints the value of “i” at each hit.
```sh
(gdb) commands 2
Type commands for breakpoint(s) 2, one per line.
End with a line saying just "end".
>print i
>end
```
## h. Delete breakpoint 2.
```sh
(gdb) d 2
```


