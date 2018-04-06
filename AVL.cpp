#include <iostream>
#include <vector>

using namespace std;

#define Height(X)  ((X) == NULL ? 0 : (X)->height)

template <typename T>
class set
{
private:   
  struct Node {
    T key;
    Node* left = NULL;
    Node* right = NULL;
    int height = 1;
  };
  
  vector<Node> nodes;
  Node* Root = NULL;
  int numNodes = 0;
  
  Node* newNode(T key) {
    nodes.push_back(Node());
    cout << "ACCESS: " << nodes.size() << " " << numNodes << endl;
    nodes[numNodes].key = key;
    return &nodes[numNodes++];
  }
  
  Node* insert(Node* root, T key) {
    if( root == NULL ) {
      return newNode(key);
    }
    
    if( key < root->key )
      root->left = insert(root->left, key);
    else if( key > root->key )
      root->right = insert(root->right, key);
    else
      return root;
    
    root->height = 1 + max(Height(root->left), Height(root->right));
    
    return root;
  }
  
  void print(Node* root) {
    if(root != NULL)
    {
      cout << root->key << " " << root->left << " " << root->right << " " << root->height << endl;
      print(root->left);
      print(root->right);
      cout << root->key << " " << root->left << " " << root->right << " " << root->height << endl;
    }
  }
public:
  void insert(T key) {
    Root = insert(Root, key);
  }
  
  void print() {
    cout << "PRINTING: " << numNodes << endl;
    print(Root);
  }
};
 
int main() {
  set<int> nums;
  nums.insert(9);
  nums.insert(5);
  nums.insert(10);
  nums.insert(0);
  nums.insert(6);
  nums.insert(11);
  nums.insert(-1);
  nums.insert(1);
  nums.insert(2);
  nums.print();
  cout << "HERE";
  return 0;
}