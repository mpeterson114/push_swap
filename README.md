# Push_Swap 🧮
## Summary
Push_swap is an algorithm project in which we are to sort data in ascending order on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

## Usage
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
To test with a larger range or number of values, you can use a random number generator like [this](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)
*Keep **Allow Repeats** set to **No**, and **Sort** set to **Do not sort**

Copy the randomly generated numbers and paste them into the command line as arguments to be passed with ```./push_swap```
Here is an example testing with 100 values ranging from -500 to 500:
```
./push_swap -209 407 160 188 416 360 444 -213 90 -376 297 -143 206 -226 413 43 -434 149 201 101 -382 113 150 -25 340 -463 469 -185 242 -410 250 -317 -197 -267 -357 -44 286 142 301 121 358 -142 -269 -249 -255 -146 -485 84 -391 -437 -479 -358 306 -54 362 122 157 323 -242 -487 -16 262 -68 -59 354 379 -422 404 -336 370 -76 405 -296 -459 302 -349 -137 -205 -268 -340 -168 -375 275 397 -12 96 -307 172 394 -303 462 -286 -328 217 289 332 -300 -204 399 78
```
The result will be a list of the sorting operations needed to sort the values in ascending order.


