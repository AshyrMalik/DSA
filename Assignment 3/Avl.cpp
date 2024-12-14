#include<iostream>

#define SPACE 10

using namespace std;

struct TreeNode {
  
  int value;
  TreeNode * left;
  TreeNode * right;

  
};
 TreeNode* root;

int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
}

int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
  }

TreeNode * rightRotate(TreeNode * y) {
    TreeNode * x = y -> left;
    
    y -> left = x -> right;
   	x - > right = y;

    return x;
  }
  
TreeNode * leftRotate(TreeNode * x) {
    TreeNode * y = x -> right;
    
    x->right=y->left;
    y->left=x;
    
    return y;
  }



   
  

 

  TreeNode * insert(TreeNode * r, TreeNode * new_node) {
    if (r == NULL) {
      r = new_node;
      cout << "Value inserted successfully" << endl;
      return r;
    }

    if (new_node -> value < r -> value) {
      r -> left = insert(r -> left, new_node);
    } else if (new_node -> value > r -> value) {
      r -> right = insert(r -> right, new_node);
    } else {
      cout << "No duplicate values allowed!" << endl;
      return r;
    }

    int bf = getBalanceFactor(r);
    // Left Left Case  
    if (bf > 1 && new_node -> value < r -> left -> value)
      return rightRotate(r);

	// Left Right Case  
    if (bf > 1 && new_node -> value > r -> left -> value) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }

    // Right Right Case  
    if (bf < -1 && new_node -> value > r -> right -> value)
      return leftRotate(r);

    // Right Left Case  
    if (bf < -1 && new_node -> value < r -> right -> value) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;

  }

  

  void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> left);
    /* then print the data of node */
    cout << r -> value << " ";
    /* now recur on right child */
    printInorder(r -> right);
  }
  





int main() {
  
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout<<"2.Display"<<endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      
      cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
      cin >> val;
      new_node -> value = val;
      root = insert(root, new_node);
      cout << endl;
      break;
    case 2:
    	printInorder(root);
      	
    
    
    
    
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
