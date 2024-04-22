# Push_Swap 🧮  
## 📋 Summary
Push_swap is an algorithm project in which we are to sort data in ascending order on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

## 📌 Rules
The game is composed of 2 stacks, Stack A and Stack B.

To start with:
* Stack A contains a random number of either positive or negative numbers without any duplicates.
* Stack B is empty
  
The goal is to sort in ascending order numbers into stack A.

To do this, the following operations are available:
|Command                | Description                                                                                       |
|-----------------------|---------------------------------------------------------------------------------------------------|
| sa (swap a)           | Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.  |
| sb (swap b)           | Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.  |
| ss                    | sa and sb at the same time                                                                        |
| pa (push a)           | Take the first element at the top of B and put it at the top of A. Do nothing if b is empty.      |
| pb (push b)           | Take the first element at the top of A and put it at the top of B. Do nothing if a is empty.      |
| ra (rotate a)         | Shift up all elements of stack A by 1. The first element becomes the last one.                    |
| rb (rotate b)         | Shift up all elements of stack B by 1. The first element becomes the last one.                    |
| rr                    | ra and rb at the same time                                                                        |
| rra (reverse rotate a)| Shift down all elements of stack A by 1. The last element becomes the first one.                  |
| rrb (reverse rotate b)| Shift down all elements of stack B by 1. The last element becomes the first one.                  |
| rrr                   | rra and rrb at the same time.                                                                     |


## ⚙️ Usage
Clone the repository using the following command:
```
git clone git@github.com:mpeterson114/push_swap.git
```
then enter into the cloned directory and run the command ```make``` to compile.
You can then run the program with the following:
```
./push_swap <numbers of your choice>
```
with any range or number of values passed as arguments, positive or negative, as long as there are no duplicates. For example:
```
./push_swap -4 2147483647 0 22 892 -2147483648
```
To test with a larger range or number of values, you can use a random number generator like [this one](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)

* Note: Keep **Allow Repeats** set to **<ins>No</ins>**, and **Sort** set to **<ins>Do Not Sort</ins>**

Copy the randomly generated numbers and paste them into the command line as arguments to be passed with ```./push_swap```.

Here is an example test to sort 100 values ranging from -500 to 500:
```
./push_swap -209 407 160 188 416 360 444 -213 90 -376 297 -143 206 -226 413 43 -434 149 201 101 -382 113 150 -25 340 -463 469 -185 242 -410 250 -317 -197 -267 -357 -44 286 142 301 121 358 -142 -269 -249 -255 -146 -485 84 -391 -437 -479 -358 306 -54 362 122 157 323 -242 -487 -16 262 -68 -59 354 379 -422 404 -336 370 -76 405 -296 -459 302 -349 -137 -205 -268 -340 -168 -375 275 397 -12 96 -307 172 394 -303 462 -286 -328 217 289 332 -300 -204 399 78
```
The result will be a list of actions (sorting operations) needed to sort the values in ascending order.
### Desired Outcomes
* Sorting 3 values: No more than **3** actions
* Sorting 5 values: No more than **12** actions
* Sorting 100 values: No more than **700** actions
* Sorting 500 values: No more than **5500** actions
