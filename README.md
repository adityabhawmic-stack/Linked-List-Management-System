# Linked List Management System

## Objective
A menu-driven console application to practice Singly and Doubly Linked List operations, built as a DSA mini project.

## Language Used: C++

## Features
- Singly Linked List with 19 operations
- Doubly Linked List with 20 operations
- Comparison of Singly vs Doubly Linked List
- Edge-case handling: empty list, one node, invalid positions, value not found, duplicates
- Built from raw nodes and pointers, with no arrays or built-in list collections

## Singly Linked List
Each node stores `data` and `next`. The list keeps a `head` pointer.

## Doubly Linked List
Each node stores `data`, `prev` and `next`. The list keeps `head` and `tail` pointers, so insert and delete at the end are O(1).

## Operations
Insert at beginning, end, position, after a value, before a value. Delete from beginning, end, position, by value. Search, update, display (forward and backward for doubly), count, maximum, minimum, middle element (slow/fast pointers), reverse, sort (bubble sort), remove duplicates.

## How to Run
g++ src/main.cpp -o main
./main

On Windows PowerShell use `.\main` instead of `./main`.

## Sample Output
See `sample-output/output.txt`.

## Time Complexity
| Operation | Complexity |
|---|---|
| Insert at beginning | O(1) |
| Insert at end | O(n) singly, O(1) doubly |
| Insert at position | O(n) |
| Delete from beginning | O(1) |
| Delete from end | O(n) singly, O(1) doubly |
| Search / Display / Count | O(n) |
| Find Min / Max / Middle | O(n) |
| Reverse | O(n), extra space O(1) |
| Bubble Sort | O(n^2) |
| Remove Duplicates | O(n^2) |

## Author
Aditya Bhowmic