# Project name : push_swap

For this project, the assignment is : 

You have to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

pa (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.<br>

pb (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.<br>

sa (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.<br>

sb (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.<br>

ss: sa and sb at the same time.<br>

ra (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.<br>

rb (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.<br>

rr: ra and rb at the same time.<br>

rra (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.<br>

rrb (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.<br>

rrr : rra and rrb at the same time.<br>

The grade depends on how efficient the program's sorting process is.<br>

Sorting 3 values: no more than 3 actions.<br>

Sorting 5 values: no more than 12 actions.<br>

Sorting 100 values: rating from 1 to 5 points depending on the number of actions:<br>

5 points for less than 700 actions<br>

4 points for less than 900<br>

3 points for less than 1100<br>

2 points for less than 1300<br>

1 point for less than 1500<br>

Sorting 500 values: rating from 1 to 5 points depending on the number of actions:<br>

5 points for less than 5500 actions<br>

4 points for less than 7000<br>

3 points for less than 8500<br>

2 points for less than 10000<br>

1 point for less than 11500<br>

## Usage

In order to compile :
<code>make</code>

Execution :
<code>./push_swap <list of numbers without any duplicates></code>

Output :
If the arguments are valid, the program will output the most efficient list of actions to sort the list
