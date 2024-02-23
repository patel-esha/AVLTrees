# AVL Tree Implementation

This repository contains an implementation of an AVL tree, a self-balancing binary search tree. Each node in the tree keeps track of the height of the subtree rooted at that node, allowing the tree to maintain a balanced state through rotations during insertions and deletions. This ensures that the tree maintains a complexity of O(log n) for search, insertion, and deletion operations.

## What is an AVL Tree?

An AVL tree is named after its inventors, Adelson-Velsky and Landis. It is a self-balancing binary search tree where the difference in heights between the left and right subtrees (balance factor) is at most 1 for every node. When this balance factor is violated, the tree performs rotations to rebalance itself. This mechanism ensures that the tree remains approximately balanced, thereby guaranteeing that operations such as search, insertion, and deletion can be performed in O(log n) time.

## Features

- **Insertion**: Adds a new element to the tree while maintaining its balanced state.
- **Deletion**: Removes an element from the tree and rebalances it if necessary.
- **Search**: Efficiently finds an element in the tree.
- **Traversal**: Supports in-order, pre-order, and post-order traversals to explore the elements of the tree.
- **Height Calculation**: Dynamically calculates the height of the tree to ensure balance.

## Getting Started

- To use this AVL tree implementation, simply clone this repository and include the AVL tree source files in your project. The main functions you'll interact with are `insert`, `delete`, and `search`, each of which operates in O(log n) time complexity due to the self-balancing nature of AVL trees.

## Academic Integrity
- This implementation is provided for educational purposes. Users are encouraged to learn from and understand the code but should adhere to academic integrity guidelines when using this implementation in their projects or assignments. Copying this code without proper attribution and passing it off as one's own work is not allowed.

- It's important to respect the work of others and to contribute to a learning environment that values honesty and responsibility. Please ensure that your use of this and other educational resources complies with your institution's academic integrity policies.

## References
- Amanpreet Kapoor's insights on AVL Trees have been instrumental in understanding the theoretical foundations and practical applications of self-balancing binary search trees.
- The educational content and examples provided by GeeksforGeeks on AVL Trees have been valuable resources for implementing and testing this AVL Tree. For further reading, visit GeeksforGeeks AVL Tree.
