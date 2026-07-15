# BST Lexicon Implementation

An implementation of a text lexicon (vocabulary) using an unbalanced Binary Search Tree (BST) in C++. This project was developed as part of **Exercise 10 (Binary Trees)** for the *Programming Techniques* course at the **National Technical University of Athens (NTUA)**, School of Electrical and Computer Engineering.

---

## Technical Specifications

The `lexicon` class manages words (consisting of non-empty, lowercase Latin letters). Each distinct word corresponds to a single node in the BST, which stores:
* The **word** (lexicographically ordered: left child is smaller, right child is larger).
* The **frequency** of its occurrence (acting as an insertion counter).

The underlying tree is a standard, unbalanced BST.

### Supported Operations

* **`insert(const string &s)`**: Inserts a word into the tree. If the word already exists, its frequency counter is incremented.
* **`lookup(const string &s)`**: Returns the frequency of the word `s`, or `0` if it is not found.
* **`depth(const string &s)`**: Returns the depth of the node containing `s` (root is at depth `0`). If the word does not exist, it returns `-1`.
* **`replace(const string &s1, const string &s2)`**: Replaces all occurrences of `s1` with `s2`. 
  * If `s1` is present in the tree with frequency `k`, it is deleted.
  * If `s2` is already in the tree, its frequency is increased by `k`. Otherwise, `s2` is inserted with an initial frequency of `k`.
  * **Deletion Rules:** If a node with two non-empty children is deleted, it is replaced by its **in-order predecessor** (the node containing the immediately smaller word lexicographically). If it has one child, it is replaced by that child.
* **`operator<<`**: Overloaded stream insertion operator that prints the lexicon in alphabetical order, formatted as `[word] [frequency]`.

---

## Visualizing Deletion & Replacement

Below is a visualization of the BST's structure before and after running a `replace("boy", "wolf")` operation:

```text
       Before Replace:                      After Replace:

           the (2)                              the (2)
          /       \                            /       \
       boy (1)    wolf (1)                  and (1)    wolf (2)
       /
    and (1)
