<div align="center">
	<h1>🔄 push_swap</h1>
	<p>This repository contains the implementation of the push_swap project, which focuses on sorting a stack of numbers using a limited set of actions.</p>
    <a href="https://wakatime.com/badge/user/db0e5671-cec5-4e7b-9d41-19a881e67f7d/project/552619a1-bf7a-4090-8d74-9eb473b20c90"><img src="https://wakatime.com/badge/user/db0e5671-cec5-4e7b-9d41-19a881e67f7d/project/552619a1-bf7a-4090-8d74-9eb473b20c90.svg" alt="wakatime"></a>
    <br />
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<a href="https://developer.apple.com/library/archive/documentation/Performance/Conceptual/ManagingMemory/Articles/FindingLeaks.html"><img src="https://img.shields.io/badge/leaks-none-success" /></a>
	<img src="https://img.shields.io/badge/bonus-included-success"/>
	<br />
	<img src="https://img.shields.io/badge/-unknown%2F100-important?logo=42&logoColor=fff" />
</div>

## 🌳 Folder Structure

```
.
├── Makefile
├── README.md
├── en.subject.pdf
├── ft_printf
│   ├── ...
│   └── libft
│       └── ...
├── include
│   └── push_swap.h
└── src
    ├── checker
    │   ├── checker.c
    │   ├── checker.h
    │   └── get_next_line
    │       ├── get_next_line.c
    │       ├── get_next_line.h
    │       └── get_next_line_utils.c
    ├── main.c
    └── stack
        ├── big_sort_utils.c
        ├── errors.c
        ├── free.c
        ├── getters.c
        ├── optimiser.c
        ├── print.c
        ├── push.c
        ├── reverse_rotate.c
        ├── rotate.c
        ├── scan.c
        ├── sort.c
        ├── stack.c
        ├── stack.h
        └── swap.c
```

## ⚙️ Algorithm Logic

*🙇🏻‍♂️ The algorithm used in this project is based on the concepts described in the following article:*

[📖 Push Swap: The Least Amount of Moves with Two Stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

Please refer to the article for a detailed explanation.

### 3️⃣ Sorting 3 Numbers

*The goal is to sort 3 random numbers from smallest to largest in no more than 2 actions.*

* In this scenario, **there are only five possible cases**.

* The algorithm uses a naive `if/else` approach to cover all the different cases in the least amount of moves possible.

### 5️⃣ Sorting 5 Numbers

*When dealing with 5 random numbers, the algorithm leverages the logic from sorting 3 numbers.*

* It moves the first 2 numbers from the top of Stack A to Stack B and **sorts the remaining 3 numbers in Stack A using the previous algorithm**.

* Once the 3 numbers are sorted, the algorithm pushes back the numbers from Stack B to Stack A in the most efficient way possible.

### 💯 Sorting 100+ Numbers

* The program uses **a variant of the Insertion Sort algorithm** to sort 100 random numbers.

* However, it splits the task into smaller chunks.

* It scans Stack A to identify numbers from a chunk (between `chunk_start` and `chunk_end`), compares their positions, and determines whether to use `ra` or `rra` to bring the number to the top of Stack A.

* The algorithm repeats this process for all the chunks until Stack A is empty.

* Then, it moves the biggest number from Stack B to the top (in the most optimised way too) and pushes it to Stack A, repeating this step until Stack B is empty.

* The number of chunks is determined by the size of Stack A. The bigger the stack, the more chunks are used:

	* Between 6 and 100 numbers: **5 chunks**
	* Between 101 and 1024 numbers: **11 chunks**

## 🔎 Detailed Procedure

1. 💯 **`big_sort()`** : The algorithm **splits the stack into chunks** and calls the ``sort_chunk`` function.

2. 🔢 **`sort_chunk()`** : For every chunk, the algorithm will **scan the stack A** (both from the top and the bottom) **until it finds a number that belongs to the desired range**.

3. 🆙 **`move_in_range_to_top()`** : It will then check the positions of the number found from the top and the one from the bottom, and **determines which one costs the least operations to move to the top**, using either `ra` or `rra`.

4. 🫸🏼 **`smart_push_b()`** : Once the number is at the top, the algorithm will push it to stack B in the most efficient way possible.

    * **If the number is bigger** than all the numbers in stack B, it will be pushed **either on top of the smallest or the biggest one**, once again depending on which one costs less to bring to the top.
    * **If the number is smaller** than all the numbers in stack B, it will be pushed **on top of the smallest one**.
    * Otherwise, the number is just pushed on top of stack B.

5. 🔄 Operation is repeated until stack A is empty.

6. 🗑️ **`dump_back()`** : The algorithm will then move all the numbers from stack B to stack A, **starting from the maximum number**, until stack B is empty.

## 🚀 Performance

The performance is based on the [📖 42 Correction sheet of push_swap](https://github.com/rizky/42-corrections/blob/master/push_swap.pdf).

The testing is conducted using the objectives for the highest grade possible:
* 3 numbers: **2 instructions**
* 5 numbers: **12 instructions**
* 100 numbers: **700 instructions**
* 500 numbers: **5500 instructions**

### 🟢 3 random numbers
```
3 elements, 1000 iterations (seed 616495953)

Worst = 2 instructions
Median = 1 instructions
Best = 0 instructions
Std. deviation = 0.7 instructions
Objective = 100 % under 2 (0 above)
Precision = 100 % OK (0 KO)
100 % effective
```

### 🟢 5 random numbers
```
5 elements, 1000 iterations (seed 948434234)

Worst = 12 instructions
Median = 9 instructionss
Best = 0 instructionss
Std. deviation = 1.8 instructions
Objective = 100 % under 12 (0 above)
Precision = 100 % OK (0 KO)
100 % effective
```

### 🟠 100 random numbers
```
100 elements, 1000 iterations (seed 2718693033)

Worst = 960 instructions
Median = 844 instructions
Best = 765 instructions
Std. deviation = 32.0 instructions
Objective = 0 % under 700 (1000 above)
Precision = 100 % OK (0 KO)
100 % effective
```

### 🔴 500 random numbers
```
500 elements, 1000 iterations (seed 1977831745)

Worst = 8486 instructions
Median = 7950 instructions
Best = 7504 instructions
Std. deviation = 159.1 instructions
Objective = 0 % under 5500 (1000 above)
Precision = 100 % OK (0 KO)
100 % effective
```

