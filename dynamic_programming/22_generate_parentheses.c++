#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    node* newnode = (node*) malloc (sizeof(node));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

int main () {
    string str = "fuhming";
    int ln = 0, rn = 0;
    cout << "hello";
    cout << ln << rn;
    cout << str << endl;
    node* root = newNode(45);
    cout << root -> data << endl;
    cout << !(root -> left);
  
  return 0;
}