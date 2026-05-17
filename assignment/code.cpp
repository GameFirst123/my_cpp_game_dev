/*
The following code has gone through multiple iterations and several hours of revisions. The detailed reasoning process and development journey are documented in the reasoning-process.md file in the same folder.
*/

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