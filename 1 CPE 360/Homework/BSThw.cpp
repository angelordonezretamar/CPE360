#include <iostream>
using namespace std;

/*
Angel Tomas Ordonez Retamar
BST Homework Assignment
I pledge my honor that I have abided by the Stevens Honor System
*/

class TreeChunk {
  public:
    int value;
    TreeChunk *left;
    TreeChunk *right;

  TreeChunk() {
    value = 0;
    left = right = NULL;
  }
};

class BST{
  public:
    TreeChunk *root;

    BST() {
      root = NULL;
    }

  void addValue(int key) {
    if(root == NULL) {
      root = new TreeChunk;
      root->value = key;
      return;
    }

    TreeChunk *fast, *slow;
    fast = slow = root;

    while(fast != NULL) {
      slow = fast; 

      if(fast->value == key) {
        cout << "Sorry, not adding duplicates" << endl;
        return;
      }
      else if(key < fast->value) {
        fast = fast->left;
      }
      else {
        fast = fast->right;
      }
    }

    if(fast == NULL) {
      TreeChunk *temp = new TreeChunk;
      temp->value = key;

      if(key < slow->value) {
        slow->left = temp;
      }
      else
        slow->right = temp;
    }
  }

  void searchBST(int key, TreeChunk *start) {
    if(start == NULL) {
      cout << "Value is not in this tree..." << endl;
    }
    else {
      if(key == start->value) {
        cout << "Found it!" << endl;
      }
      else if(key > start->value) {
        searchBST(key, start->right);
      }
      else {
        searchBST(key, start->left);
      }
    }
  }

  int minValTree(TreeChunk *start) {
    if(start == NULL) {
      return -1;
    }

    while(start->left != NULL) {
      start = start->left;
    }
    return start->value;
  }

  int maxValTree(TreeChunk *start) {
    if(start == NULL) {
      return -1;
    }
    while (start->right != NULL) {
      start = start->right;
    }
    return start-> value;
  }

  void deleteChunk(int key, TreeChunk *start) {
    if (start == NULL) {
      cout << "Can't find this value, so it can't be deleted..." << endl;
      return;
    }

    TreeChunk *slow, *fast;
    slow = fast = start;

    while (key != fast->value && fast != NULL) {
      slow = fast;
      if (key > fast->value) {
        fast = fast->right;
      }
      else {
        fast = fast->left;
      }
    }
    if (fast == NULL) {
      cout << "This value does not exist, not deleting " << endl;
      return;
    }
    if (key == fast->value) {
      //Case I: leaf node, no children
      if (fast->left == NULL && fast->right == NULL) {
        cout << "---------------" << endl;
        cout << "Case I Delete... " << endl;
        if (slow->right == fast) {
          slow->right = NULL;
          cout << "About to delete: << " << fast->value << endl;
          delete fast;
        } 
        else {
          slow->left = NULL;
          cout << "About to delete: << " << fast->value << endl;
          delete fast;
        }

      }

      //Case II: node with exactly one child
      else if (fast->left == NULL && fast->right != NULL) {
        cout << "---------------" << endl;
        cout << "Case II Delete... " << endl;
        if (slow->left == fast) {  
          slow->left = fast->right;
          cout << "About to Delete: " << fast->value << endl;
          delete fast;
        } else {
          slow->right = fast->right;
          cout << "About to Delete: " << fast->value << endl;
          delete fast;
        }
      } else if (fast->left != NULL && fast->right == NULL) {
        cout << "---------------" << endl;
        cout << "Case 2 Delete... " << endl;
        if (slow->left == fast) {  
          slow->left = fast->left;
          cout << "About to Delete: " << fast->value << endl;
          delete fast;
        } else {
          slow->right = fast->left;
          cout << "About to Delete: " << fast->value << endl;
          delete fast;
        }
      }

      // Case 3: node with two children
      else {
        cout << "---------------" << endl;
        cout << "Case 3 Delete " << endl;
        int swap = minValTree(fast->right);
        fast->value = swap;  
        deleteChunk(swap, fast->right);
      }
    }
  }

  void inOrder(TreeChunk *start) {
    if(start == NULL) {
      return;
    }
    else {
      inOrder(start->left);
      cout << start->value << " " << endl;
      inOrder(start->right);
    }
  }

  void preOrder(TreeChunk *start) {
    if(start == NULL)
      return;
    else {
      cout << start->value << " " << endl;
      preOrder(start->left);
      preOrder(start->right);
    }
  }
  void postOrder(TreeChunk *start) {
    if(start==NULL)
      return;
    else {
      postOrder(start->left);
      postOrder(start->right);
      cout << start->value << " " << endl;
    }
  }

};

int main() {
  int choice, value;
  BST tree;
  //jumpstarting the tree with the same values from lecture. I don't know if this is required or recommended for the HW, but I'm just putting it in 
  tree.addValue(30);
  tree.addValue(15);
  tree.addValue(60);
  tree.addValue(7);
  tree.addValue(22);
  tree.addValue(45);
  tree.addValue(17);
  tree.addValue(27);
  tree.addValue(75);
  tree.addValue(100);
  tree.addValue(1);
  tree.addValue(40);
  tree.addValue(50);
  tree.addValue(35);
  tree.addValue(42);
  tree.addValue(48);
  tree.addValue(55);
  tree.addValue(65);
  
  while(1) {
    cout << "Press 1 to add new value" << endl;
    cout << "Press 2 to search" << endl;
    cout << "Press 3 for in-order" << endl;
    cout << "Press 4 for pre-order" << endl;
    cout << "Press 5 for post-order" << endl;
    cout << "Press 6 for deleting node" << endl;
    cin >> choice;

    switch(choice) {
      case 1: cout << "What value do you want to add?" << endl;
              cin >> value;
              tree.addValue(value);
              break;

      case 2: cout << "What do you want to search for?" << endl;
              cin >> value;
              tree.searchBST(value, tree.root);
              break;
      
      case 3: tree.inOrder(tree.root);
              break;
      
      case 4: tree.preOrder(tree.root);
              break;

      case 5: tree.postOrder(tree.root);
              break;
      
      case 6: cout << "What do you want to delete what?" << endl;
              cin >> value;
              tree.deleteChunk(value, tree.root);
              break;

      default: cout << "Goodbye!" << endl;
              exit(1);
    }
  }
}