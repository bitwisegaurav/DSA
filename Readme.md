# DSA Repository

This repository contains the implementation of various data structures and algorithms in C and C++. The code is organized into different folders based on the programming language used.

<br>

## Table of Contents
- [Data Structures](#data-structure)
- [Algorithms](#algorithms)

### Data Structures
- [Array](#array)
- [Linked List](#linked-list)
- [Stack](#stack)
- [Queue](#queue)
- [Hash Table/Maps](#hash-table)
- [Tree](#tree)
- [Heap](#heap)
- [Graph](#graph)

### Algorithms
- [Linear Search](#linear-search)
- [Binary Search](#binary-search)
- [Simple Sort](#simple-sort)
- [Selection Sort](#selection-sort)
- [Bubble Sort](#bubble-sort)
- [Insertion Sort](#insertion-sort)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)
- [Heap Sort](#heap-sort)

<br><br>

## Data Structures

### Array

Arrays are used to store a collection of elements of the same type. The elements are stored in contiguous memory locations, and they can be accessed using their index.

### Linked List

Linked lists are used to store a collection of elements where each element is linked to the next one using a pointer. There are different types of linked lists, such as singly linked lists, doubly linked lists, and circular linked lists.

### Stack

A stack is a linear data structure that follows the LIFO (Last In First Out) principle. It has two main operations, push and pop, which are used to add and remove elements from the stack, respectively.

### Queue

A queue is a linear data structure that follows the FIFO (First In First Out) principle. It has two main operations, enqueue and dequeue, which are used to add and remove elements from the queue, respectively.

### Tree

A tree is a hierarchical data structure that consists of nodes connected by edges. Each node can have zero or more child nodes, and there is a single root node at the top of the tree.

### Heap

A heap is a special tree-based data structure that satisfies the heap property. It is a complete binary tree, which means all levels of the tree are fully filled except for the last level, which is filled from left to right.

There are two types of heaps:

1. **Max-Heap**: In a max-heap, for any given node I, the value of I is greater than or equal to the values of its children. This property must be true for all nodes in the tree. The largest element in a max-heap is located at the root.

2. **Min-Heap**: In a min-heap, for any given node I, the value of I is less than or equal to the values of its children. This property must be true for all nodes in the tree. The smallest element in a min-heap is located at the root.

### Hash Table

A hash table/map is a data structure that maps keys to values using a hash function. It provides fast access to elements by calculating the hash code of the key and using it to access the corresponding value.

### Graph

A graph is a non-linear data structure that consists of nodes (also called vertices) connected by edges. There are different types of graphs, such as directed and undirected graphs, and they can be used to represent relationships between objects.

<br><br>

## Algorithms

### Linear Search

Linear search is a simple searching algorithm that searches for an element in a list by sequentially checking each element of the list until the desired element is found or the end of the list is reached.

### Binary Search

Binary search is a searching algorithm that works on sorted lists. It halves the list and compares the middle element with the desired element. If the desired element is found, its position in the list is returned. Otherwise, if the desired element is less than the middle element, the search continues in the lower half of the list. If the desired element is greater than the middle element, the search continues in the upper half of the list.

### Simple Sort

Simple sort is a comparison-based sorting algorithm that generates a new sorted array by replacing the smallest number in the array with INT_MAX and put that number into new sorted array. It has an average and worst-case time complexity of O(n^2), making it inefficient for large data sets.

### Selection Sort

Selects smallest element in each iteration and places it at the beginning.

### Bubble Sort

Compares adjacent elements and swaps them if they are in wrong order, continues until the list is sorted.

### Insertion Sort

Builds a sorted array one item at a time with the rest of the data remaining in the same sequence.

### Merge Sort

Divides the array into two halves, sorts them separately and then merges them.

### Quick Sort

Quick Sort is a divide-and-conquer algorithm that selects a pivot element and reorders the other elements into two sub-arrays, based on whether they are less than or greater than the pivot. This process is recursively applied to the sub-arrays, leading to a sorted array

### Heap Sort

Builds a heap data structure from the input array and then repeatedly swaps the first and last elements, to put the largest element at the end.