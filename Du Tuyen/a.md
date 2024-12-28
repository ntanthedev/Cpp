**Problem Statement**

*   Chris is given two arrays *a* and *b*, both consisting of *n* integers.
*   Iris is interested in the largest possible value of  P =  ∏<sub>i=1</sub><sup>n</sup> min(a<sub>i</sub>, b<sub>i</sub>) after an arbitrary rearrangement of *b*. Note that she only wants to know the maximum value of *P*, and no actual rearrangement is performed on *b*.
*   There will be *q* modifications. Each modification can be denoted by two integers *o* and *x* (*o* is either 1 or 2, 1 ≤ *x* ≤ *n*). If *o* = 1, then Iris will increase a<sub>x</sub> by 1; otherwise, she will increase b<sub>x</sub> by 1.
*   Iris asks Chris the maximum value of *P* for *q* + 1 times: once before any modification, then after every modification.
*   Since *P* might be huge, Chris only needs to calculate it modulo 998 244 353.

Chris soon worked out this problem, but he was so tired that he fell asleep. Besides saying thanks to Chris, now it is your turn to write a program to calculate the answers for the given input data.

**Note**: Since the input and output are large, you may need to optimize them for this problem.

For example, in C++, it is enough to use the following lines at the start of the main() function:

```c++
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}
```

**Input**

Each test contains multiple test cases. The first line of input contains a single integer *t* (1 ≤ *t* ≤ 10<sup>4</sup>) - the number of test cases. The description of test cases follows.

The first line of each test case contains two integers *n* and *q* (1 ≤ *n* ≤ 2 ⋅ 10<sup>5</sup>, 1 ≤ *q* ≤ 2 ⋅ 10<sup>5</sup>) - the length of the array and the number of operations.

The second line of each test case contains *n* integers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ 5 ⋅ 10<sup>8</sup>) - the array *a*.

The third line of each test case contains *n* integers b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>n</sub> (1 ≤ b<sub>i</sub> ≤ 5 ⋅ 10<sup>8</sup>) - the array *b*.

Then *q* lines follow, each line contains two integers *o* and *x* (*o* ∈ {1, 2}, 1 ≤ *x* ≤ *n*), representing an operation.

It's guaranteed that the sum of *n* and the sum of *q* over all test cases does not exceed 4 ⋅ 10<sup>5</sup>, respectively.

**Output**

For each test case, output *q* + 1 integers in a line, representing the answers that Chris will calculate, modulo 998 244 353.

**Example*
***input***
```
4
3 4
1 1 2
3 2 1
1 3
2 3
1 1
2 1
6 8
1 4 2 7 3 5
7 6 5 6 3 3
2 5
1 6
1 5
1 5
1 5
2 3
2 3
1 6
13 8
7 7 6 6 5 5 5 2 2 3 4 5 1
1 4 1 9 6 6 9 1 5 1 3 8 4
2 2
2 11
2 4
2 4
1 7
1 1
2 12
1 5
5 3
10000000 20000000 30000000 40000000 50000000
10000000 20000000 30000000 40000000 50000000
1 1
2 2
2 1
```
***ouput***
```
2 3 3 6 6
840 840 1008 1344 1680 2016 2016 2016 2352
2116800 2646000 3528000 3528000 3528000 4233600 4838400 4838400 4838400
205272023 205272023 205272023 264129429
```

**Note**

In the first test case:

*   Before the modifications, Chris can rearrange *b* to [1, 2, 3] so that P = ∏<sub>i=1</sub><sup>n</sup> min(a<sub>i</sub>, b<sub>i</sub>) = 1 ⋅ 1 ⋅ 2 = 2. We can prove that this is the maximum possible value. For example, if Chris rearranges *b* = [2, 3, 1], *P* will be equal 1 ⋅ 1 ⋅ 1 = 1 < 2, which is not optimal.
*   After the first modification, Chris can rearrange *b* to [1, 2, 3] so that *P* = 1 ⋅ 1 ⋅ 3 = 3, which is maximized.
*   After the second modification, Chris can rearrange *b* to [2, 2, 3] so that *P* = 1 ⋅ 1 ⋅ 3 = 3, which is maximized.
*   After the third modification, Chris can rearrange *b* to [2, 2, 3] so that *P* = 6, which is maximized.
*   After the fourth modification, Chris can rearrange *b* to [2, 2, 4] so that *P* = 6, which is maximized.