# Data Structures and Algorithms in C 🧱

A comprehensive and modular collection of fundamental data structures implemented in C. This repository is built with a strong focus on memory management, time complexity optimization, and clean code principles.

## 📌 Implemented Structures

### 1. Singly Linked List
* Dynamic memory allocation and strict memory leak prevention.
* **Operations:** `insertAtEnd` O(n), `deleteNode` O(n), `printList` O(n), `freeList` O(n).

### 2. Stack (Array-Based)
* LIFO (Last In, First Out) architecture implementation.
* **Operations:** `push` O(1), `pop` O(1), `peek` O(1).
* Features Overflow and Underflow protection.

### 3. Queue (Array-Based)
* FIFO (First In, First Out) architecture implementation.
* **Operations:** `enqueue` O(1), `dequeue` O(1), `peekFront` O(1).

### 4. Binary Search Tree (BST)
* Non-linear data structure with recursive implementations.
* **Operations:** `insert` O(log n), `inorderTraversal` O(n), `freeTree` O(n).
* Inorder traversal guarantees ascending sorted output.

## 🛠️ Technologies & Tools
* **Language:** C
* **Compiler:** GCC
* **Environment:** Linux / Ubuntu CLI
* **Concepts:** Pointers, Dynamic Memory Allocation (`malloc`/`free`), Recursion

## 🚀 How to Run
1. Clone this repository to your local machine:
   git clone https://github.com/mfcomert/Data-Structures-in-C.git

2. Navigate to the desired data structure directory, for example:
   cd Data-Structures-in-C/1-Linked-Lists

3. Compile the code using GCC:
   gcc singly_linked_list.c -o list_test

4. Run the executable:
   ./list_test

## 👨‍💻 Author
**Muhammet Furkan Cömert**
Computer Engineering Student
