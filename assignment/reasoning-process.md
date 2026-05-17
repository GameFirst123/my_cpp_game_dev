## Initial Hypotheses:

- At the beginning, I did not directly search on Google. Instead, based on what I had previously learned, I mentally reasoned through what a binary search tree is.
- First, I hypothesized that a tree structure and a binary search tree structure are different. I thought that in a tree structure, one node can connect to multiple child nodes, while in a binary search tree, one node should only be able to connect to two child nodes.
- Second, if leaf nodes are mentioned, that means there must also be non-leaf nodes. Through the metaphor of a tree, one can associate leaves with branches or trunks. Therefore, I hypothesized that there are leaf nodes and trunk nodes. I then thought that a trunk node might be the root node, so I hypothesized that a tree structure consists of one root node and the other leaf nodes.
- Third, from the perspective of computer structure, I hypothesized that a tree structure is similar to a linked-list structure. It should be defined through a `struct` data structure, and each node should contain a value and pointers to its child nodes.
- Fourth, a tree structure should be clearly organized, rather than being a messy structure in which child nodes can connect back to parent nodes.
- Fifth, the only difference between a binary search tree and a general tree structure is that in a binary search tree, one parent node can only have two child nodes. Printing all leaf nodes means creating a function with no return value. It only needs to take the initial root node as input, traverse the tree structure, and print all nodes except the root node.

## First Verification

- Regarding these hypotheses, I asked ChatGPT for an answer. It told me:
  1. A tree structure is divided into the root, internal nodes, and leaves. The root is the initial node; internal nodes are nodes located in the middle that have child nodes; and leaves are nodes that have no child nodes.
  2. The characteristic of a binary tree is not only that one parent node can have at most two child nodes, but also that the two child nodes are divided into left and right, and either of them can be empty.
  3. A binary search tree adds comparable keys on top of a binary tree. For a current node A, the keys of the nodes in A’s left subtree are always smaller than A’s key. Conversely, the keys of the nodes in A’s right subtree are always greater than A’s key.
- At this point, I clarified the basic concept of a binary search tree.

## First Version of the Code

- Code explanation:
  1. Use `struct` to define the tree node type.
  2. Create the `PrintLeafNodes` function, which traverses the binary search tree recursively and prints the leaf nodes.
     - When the `PrintLeafNodes` function is called, the function’s stack frame is pushed onto the stack. The stack frame contains copied parameters. Since the parameter is a pointer, it is passed by reference.
     - The first check determines whether the current node is a leaf node. If it is, it is printed; otherwise, the function continues. The second check determines whether the current node has a left child node. If it does, `PrintLeafNodes` is called recursively. When the function is called, it is pushed onto the stack as a stack frame. The parameter in this stack frame is the left child node of the node in the previous stack frame, which becomes the current node in this stack frame.
     - When the recursive call ends, the stack frame is destroyed, and the code jumps to the third check, which determines whether the current node has a right child node. This is similar to the process above, so I will not elaborate further.
  3. In the `main` function, I constructed the binary search tree in a way similar to building with blocks, and successfully printed its leaf nodes.


```c++
#include <iostream>

struct TreeNode {
    int value;
    TreeNode* leftPointer;
    TreeNode* rightPointer;
};

void PrintLeafNodes(TreeNode* treenode) {
    TreeNode* current = treenode;

    if (current->leftPointer == nullptr && current->rightPointer == nullptr) {
        std::cout << current->value << "\n";
    }
    
    if (current->leftPointer) {
        PrintLeafNodes(current->leftPointer);
    }
    
    if (current->rightPointer) {
        PrintLeafNodes(current->rightPointer);
    }
}

int main() {
    TreeNode rootNode;
    TreeNode leftInternalNode1;
    TreeNode leftInternalNode2_1;
    TreeNode leftInternalNode2_2;
    TreeNode rightInternalNode1;
    TreeNode rightInternalNode2_1;
    TreeNode rightInternalNode2_2;
    TreeNode leafNode3_1_1;
    TreeNode leafNode3_1_2;
    TreeNode leafNode3_2_1;
    TreeNode leafNode3_2_2;
    TreeNode leafNode3_3_1;
    TreeNode leafNode3_3_2;
    TreeNode leafNode3_4_1;
    TreeNode leafNode3_4_2;

    rootNode.leftPointer = &leftInternalNode1;
    rootNode.rightPointer = &rightInternalNode1;

    leftInternalNode1.leftPointer = &leftInternalNode2_1;
    leftInternalNode1.rightPointer = &leftInternalNode2_2;

    rightInternalNode1.leftPointer = &rightInternalNode2_1;
    rightInternalNode1.rightPointer = &rightInternalNode2_2;

    leftInternalNode2_1.leftPointer = &leafNode3_1_1;
    leftInternalNode2_1.rightPointer = &leafNode3_1_2;

    leftInternalNode2_2.leftPointer = &leafNode3_2_1;
    leftInternalNode2_2.rightPointer = &leafNode3_2_2;

    rightInternalNode2_1.leftPointer = &leafNode3_3_1;
    rightInternalNode2_1.rightPointer = &leafNode3_3_2;

    rightInternalNode2_2.leftPointer = &leafNode3_4_1;
    rightInternalNode2_2.rightPointer = &leafNode3_4_2;

    leafNode3_1_1.leftPointer = nullptr;
    leafNode3_1_1.rightPointer = nullptr;
    leafNode3_1_2.leftPointer = nullptr;
    leafNode3_1_2.rightPointer = nullptr;
    
    leafNode3_2_1.leftPointer = nullptr;
    leafNode3_2_1.rightPointer = nullptr;
    
    leafNode3_2_2.leftPointer = nullptr;
    leafNode3_2_2.rightPointer = nullptr;
    
    leafNode3_3_1.leftPointer = nullptr;
    leafNode3_3_1.rightPointer = nullptr;
    
    leafNode3_3_2.leftPointer = nullptr;
    leafNode3_3_2.rightPointer = nullptr;
    
    leafNode3_4_1.leftPointer = nullptr;
    leafNode3_4_1.rightPointer = nullptr;
    
    leafNode3_4_2.leftPointer = nullptr;
    leafNode3_4_2.rightPointer = nullptr;

    rootNode.value = 10;
    leftInternalNode1.value = 5;
    leftInternalNode2_1.value = 3;
    leftInternalNode2_2.value = 7;
    leafNode3_1_1.value = 2;
    leafNode3_1_2.value = 4;
    leafNode3_2_1.value = 6;
    leafNode3_2_2.value = 9;
    rightInternalNode1.value = 15;
    rightInternalNode2_1.value = 13;
    rightInternalNode2_2.value = 17;
    leafNode3_3_1.value = 12;
    leafNode3_3_2.value = 14;
    leafNode3_4_1.value = 16;
    leafNode3_4_2.value = 19;

    PrintLeafNodes(&rootNode);
    
    return 0;
}
```

## Second Version of the Code

- I corrected the shortcomings in the first version:
  1. I added an extra safety check to the `PrintLeafNodes` function to prevent the passed-in node itself from being a null pointer.
  2. Because I was not satisfied with the time-consuming, labor-intensive, and difficult-to-maintain code in the previous version, I asked Claude how to modify it and studied and understood the suggestions it gave:
     - In the previous version, the biggest problem in my thinking was that I treated a structure that should have been dynamically defined, similar to a `vector`, as if it were an array. In other words, I decided the number of nodes, node values, and node relationships in advance, but I could not freely and conveniently add or remove nodes.
     - For this kind of problem, if explained from the most fundamental principles of computers, the binary search tree should be constructed using the dynamic heap memory area. Objects are precisely data structures that are created on the heap. Objects are created with `new`, can only be accessed through external pointers, and require the developer to decide when to create and destroy them.
     - Based on this theory, the `struct` needs to be transformed into a data structure with a constructor, so that it can be used as a blueprint for objects.
     - The `Insert` function encapsulates the `struct`, giving it the ability to directly create a tree of nodes. At the beginning, we only need to define a null pointer and pass it into the `Insert` function, which will return a tree node. By repeatedly using this pointer, we can create a binary search tree of any size. Specifically, when we call the `Insert` function for the second time, the function creates a stack frame and pushes it onto the stack. The stack frame contains the object pointer and the value of the new node. When the function code executes, it determines whether the value we passed in is greater than or less than the parent node. If it is smaller, the `Insert` function is called to create the left child node. This creates a second stack frame. The parameter in the second stack frame is the object pointer of the left child node, which is currently null, so a new object is returned. The value of this object is the value that was previously passed in, and the parent node’s left pointer points to this new node. The later cases follow the same logic. With this recursive function, we can create a tree of nodes of any size, which is far more convenient than the code in the previous version.

```c++
#include <iostream>

struct TreeNode {
  int value;
  TreeNode* leftPointer;
  TreeNode* rightPointer;

  TreeNode(int val)
    : value(val), leftPointer(nullptr), rightPointer(nullptr)
  {}
};

TreeNode* Insert(TreeNode* node,int val) {
  if (node==nullptr) {
    return new TreeNode(val);
  }
  if (val<node->value) {
    node->leftPointer=Insert(node->leftPointer, val);
  }else if (val>node->value) {
    node->rightPointer=Insert(node->rightPointer, val);
  }
  return node;
}

void PrintLeafNodes(TreeNode* treenode) {
  TreeNode* current=treenode;
  if (!current) {
    return;
  }
  if (current->leftPointer==nullptr && current->rightPointer==nullptr) {
    std::cout << current->value << "\n";
  }
  if (current->leftPointer) {
    PrintLeafNodes(current->leftPointer);
  }
  if (current->rightPointer) {
    PrintLeafNodes(current->rightPointer);
  }

}

int main() {
  TreeNode* rootNode=nullptr;

  rootNode=Insert(rootNode, 10);

  rootNode=Insert(rootNode, 15);
  rootNode=Insert(rootNode, 5);

  rootNode=Insert(rootNode, 3);
  rootNode=Insert(rootNode, 7);
  rootNode=Insert(rootNode, 13);
  rootNode=Insert(rootNode, 17);

  rootNode=Insert(rootNode, 2);
  rootNode=Insert(rootNode, 4);
  rootNode=Insert(rootNode, 6);
  rootNode=Insert(rootNode, 9);
  rootNode=Insert(rootNode, 12);
  rootNode=Insert(rootNode, 14);
  rootNode=Insert(rootNode, 16);
  rootNode=Insert(rootNode, 19);

  PrintLeafNodes(rootNode);

  return 0;
}
```