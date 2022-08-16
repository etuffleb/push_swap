# Libft
Libft is a School 42 project. The purpose of this project is to create own C library.

# Push_swap
Push Swap is the third project of algorithm branch in the study program at School 42. The main goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 

### Game rules

* The game is composed of 2 stacks named a and b. <br>
* To start with: <br>
◦ a contains a random number of either positive or negative numbers without
any duplicates. <br>
◦ b is empty <br>
* The goal is to sort in ascending order numbers into stack a. <br>
* To do this you have the following operations at your disposal: <br>

| Command       | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |
| <b>ss</b>     | sa and sb at the same time. |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| <b>rr</b>     | ra and rb at the same time. |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one. |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one. |
| <b>rrr</b>    | rra and rrb at the same time. |

#### Push_swap example
$>./push_swap 48 -56 100 -97 99 -70
ra
pb
ra
ra
pb
ra
rrb
pa
ra
ra
pa
ra
ra

Or you can use it with flag **-v** for visualisation:
![](https://github.com/etuffleb/push_swap.git/pushswap.gif)

### Checker
* You have to write a program named checker, which will get as an argument the
stack a formatted as a list of integers. The first argument should be at the top of
the stack (be careful about the order). If no argument is given checker stops and
displays nothing.
* Checker will then wait and read instructions on the standard input, each instruction
will be followed by ’\n’. Once all the instructions have been read, checker will
execute them on the stack received as an argument.
* If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" followed by a ’\n’ on the standard output. In every
other case, checker must display "KO" followed by a ’\n’ on the standard output.
* In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer, there are duplicates, an instruction don’t exist and/or is
incorrectly formatted.

#### Checker example
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
```
