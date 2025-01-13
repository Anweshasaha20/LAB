# Anwesha Saha
# Roll No.:002311001088
# Assignment 1
## a. Compile it so that it compiles with debugging symbols [using proper option]

#### Ans: 
```sh
gcc -g  a.c b.c -o ass1
gdb ass1
GNU gdb (GDB) 14.2
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-unknown-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ass1...
```
# b. Put breakpoint to function f1.
#### Ans: 
```sh
(gdb) b f1
Breakpoint 1 at 0x401310: file /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h, line 86.
```
# c. Put breakpoint to line 10 of b.c
#### Ans: 
```sh
(gdb) b b.c:10
Breakpoint 2 at 0x401360: file b.c, line 10.
```
# d. Run the program until it finishes. Which commands are you using to take it to completion?

#### Ans: 
```sh
(gdb) run
Starting program: /home/runner/workspace/ass1 
warning: Error disabling address space randomization: Operation not permitted
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/nix/store/k7zgvzp2r31zkg9xqgjim7mbknryv6bs-glibc-2.39-52/lib/libthread_db.so.1".
Enter a number between 2 and 6 (non-inclusive): 
4
You have entered 4

Breakpoint 1, f1 (x=50, y=163) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
The numbers are : < 50, 163>

Breakpoint 2, f2 (p=p@entry=0x7ffc97feb030, q=q@entry=0x7ffc97feb034) at b.c:10
10    *p = (*p) - (*q);
(gdb) c
Continuing.

Breakpoint 1, f1 (x=163, y=50) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
After operation 1 The numbers are : < 163, 50>

Breakpoint 1, f1 (x=33, y=109) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
The numbers are : < 33, 109>

Breakpoint 2, f2 (p=p@entry=0x7ffc97feb030, q=q@entry=0x7ffc97feb034) at b.c:10
10    *p = (*p) - (*q);
(gdb) c
Continuing.

Breakpoint 1, f1 (x=109, y=33) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
After operation 2 The numbers are : < 109, 33>

Breakpoint 1, f1 (x=25, y=81) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
The numbers are : < 25, 81>

Breakpoint 2, f2 (p=p@entry=0x7ffc97feb030, q=q@entry=0x7ffc97feb034) at b.c:10
10    *p = (*p) - (*q);
(gdb) c
Continuing.

Breakpoint 1, f1 (x=81, y=25) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
After operation 3 The numbers are : < 81, 25>

Breakpoint 1, f1 (x=20, y=65) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
The numbers are : < 20, 65>

Breakpoint 2, f2 (p=p@entry=0x7ffc97feb030, q=q@entry=0x7ffc97feb034) at b.c:10
10    *p = (*p) - (*q);
(gdb) c
Continuing.

Breakpoint 1, f1 (x=65, y=20) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
After operation 4 The numbers are : < 65, 20>
[Inferior 1 (process 321) exited normally]
```
# e: How many times breakpoint “1” is hit in one run of the program ?
#### Ans: 
```sh
(gdb) info break 1
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000401310 in f1 at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
    breakpoint already hit 8 times
```
# f. How many times breakpoint “2” is hit in one run of the program
#### Ans: 
```sh
(gdb) info break 2
Num     Type           Disp Enb Address            What
2       breakpoint     keep y   0x0000000000401360 in f2 at b.c:10
    breakpoint already hit 4 times
```
# g. How you can see details about a breakpoint ?
#### Ans:
```sh
(gdb) info break <breakPoint_number>
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000401310 in f1 at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
    breakpoint already hit 8 times
```    
# h. How you can see details about all breakpoints ?
#### Ans:
```sh
(gdb) info break
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x0000000000401310 in f1 at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
    breakpoint already hit 8 times
2       breakpoint     keep y   0x0000000000401360 in f2 at b.c:10
    breakpoint already hit 4 times
```
# i. What is value of variable x in f1 when breakpoint “1” is hit for 3 rd time ? How you can examine it ?
#### Ans:
```sh
(gdb) run
Starting program: /home/runner/workspace/ass1 
warning: Error disabling address space randomization: Operation not permitted
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/nix/store/k7zgvzp2r31zkg9xqgjim7mbknryv6bs-glibc-2.39-52/lib/libthread_db.so.1".
Enter a number between 2 and 6 (non-inclusive): 
4
You have entered 4

Breakpoint 1, f1 (x=50, y=163) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
The numbers are : < 50, 163>

Breakpoint 2, f2 (p=p@entry=0x7ffcc2226d70, q=q@entry=0x7ffcc2226d74) at b.c:10
10    *p = (*p) - (*q);
(gdb) c
Continuing.

Breakpoint 1, f1 (x=163, y=50) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) c
Continuing.
After operation 1 The numbers are : < 163, 50>

Breakpoint 1, f1 (x=33, y=109) at /nix/store/fwh4fxd747m0py3ib3s5abamia9nrf90-glibc-2.39-52-dev/include/bits/stdio2.h:86
86    return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
(gdb) p x
$1 = 33
```
# j. Rerun the program.put a breakpoint at function f0. list 5 lines where it has stopped with breakpoint 3 for firsttime.
#### Ans:
```sh
(gdb) b f0
Breakpoint 1 at 0x401230: file a.c, line 4.
(gdb) run
Starting program: /home/runner/workspace/ass1 
warning: Error disabling address space randomization: Operation not permitted
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/nix/store/k7zgvzp2r31zkg9xqgjim7mbknryv6bs-glibc-2.39-52/lib/libthread_db.so.1".

Breakpoint 1, f0 (p=p@entry=0x7fffab3713ac) at a.c:4
4   int f0(int *p) {
(gdb) list 2,6
2   #include "f.h"
3
4   int f0(int *p) {
5     int x, cntr = 1;
6     printf("Enter a number between 2 and 6 (non-inclusive): \n");
```







