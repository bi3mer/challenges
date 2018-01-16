# Challenge 36

I came across a problem for work that relied had the following subproblem and decided to prototype in Python before converting into c#.

## Part 1

### The Problem

Given the following input `([0,1], 2)` generate:

```
0 0
0 1
1 0
1 1
```

Given the following input `([0,1], 3)` generate:

```
0 0 0
1 0 0
0 1 0 
0 0 1
1 1 0
1 0 1
0 1 1
1 1 1
```

Meaning, generate all the possible combinations of values in the array for the given size. So the first argument is the array whereas the second is the size which tells us how big the output should be.

### Solution

I'm going with a tree like solution. The following illustrates the resulting datastructure for `([0,1], 3)`:

```
root
|-0
| |-0
| | |-0
| | |-1
| |
| |-1
|   |-0
|   |-1
|
|-1
  |-0
  | |-0
  | |-1
  |
  |-1
    |-0
    |-1
```


## Part 2

Cmpute the same problem, but this time solve it with a [generator](https://wiki.python.org/moin/Generators).