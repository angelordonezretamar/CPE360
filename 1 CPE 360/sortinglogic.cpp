#include <iostream>
using namespace std;



// Lecture 4/19/22
// Sorting

/*

	*O(logn) = Most efficient Big-O notation
	*Sorting: O(nlogn) = Quite a bit worse

	Types of Sorting:
		- Bubble Sort - Literally the worst. Don't talk about this one...
			> Ex: 5  10  2  3  99  4
			> Compares 5 to 10. If out of place, swaps them.
			> Least to Greatest => 5 and 10 are fine, but 10 and 2 are out of order
			   Swaps them. By the first pass, the final value has found its place
			   Requires maximum of N - 1 passes to complete...
			> for (i = 1; i <= N-1; i++)
				for (...N...)
			> ^^^ O(n^2) ^^^
			> Some algorithms do not check if the numbers are already sorted. Bubble does, which is a plus.
		- Merge Sort - Divides into equal groups (buckets), eventually down to individual values.
					    Recombine in order, starting with individual values, then groups of 2, 4, etc.
			> T(N) = O(nlogn)
		- Quick Sort - Picks a random value (pivot), placing smaller numbers to the left and larger numbers to the right
						(similar to a BST). Divides into 'buckets' like above [Divide and Conquer], placing in order
						according to which values were greater than / less than the others.
			> Ex: 1  19  2 [10] 8  9  0
			>     1  2  8  9  0 [10] 19
			>     1  2 [8] 9  0  10  19
			>     1  2  0 [8] 9  |
			>     1 [2] 0  8  9	 |
			>    [1]...... |	 |
			>    [0]   [2] v  9  v   19
			>    [0][1][2][8] 9 [10] 19

	Logic:
		- 20 minute process and 1 minute process, which should go first?
		- If 20 minute goes first, both processes wait 20 minutes, then the latter waits 1 minute.	(average = ~20.5 minutes)
		- If 1 minute goes first, both processes wait 1 minute, then the latter waits 20 minutes.	(average = ~11 minutes)
		- Makes mathematical sense to let the smaller process go first.

	Heap Sort:
		- OS make a BST, searching from the root for the next logical process. This leads to O(nlogn) efficiency.
		- BST is binary, balanced, and *left justified
			- Left Justified = All leaves are as far left as possible.
			- Just means you go level-by-level, left-to-right when constructing the tree.
		- BST is constructed oddly. Value of the parent is greater than both the children.
		- When a child is a higher value than the parent, we *sift up
			- Sift Up = Swap the parent and child.
				> Ex: 8  20  13  60  91  36  17  85  14
				- - - - - - - - - - - - - - - - - - - - - Sift Up Example
							/ 8		-->		 / 20
						   20		-->		8
				- - - - - - - - - - - - - - - - - - - - - Final Tree
							    /---91---\
						    / 85 \	    / 36 \
					    / 60 \    20  13     17
					   8      14

				> How to sort? Pop the root (91) and empty right-to-left by level (14 becomes the root).
				> Resorts the entire tree. Then, pop again (85) and repeat.
				> Popped values = values from greatest-to-least. Naturally sorts the tree.









*/






