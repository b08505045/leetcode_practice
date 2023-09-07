#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef struct node {
  struct node* left;
  struct node* right;
  struct node* parent;
  int depth;
} node;

node* newNode() {
  node* newnode = (node* ) malloc (sizeof(node));
  newnode -> left = NULL;
  newnode -> right = NULL;
  newnode -> parent = NULL;
  newnode -> depth = 0;
  return newnode;
}

void insert_node(node* parent, node* n, int direction) {
  if (!parent) {
    cout << "parent must exist\n";
    return;
  }

  if (direction == 1) {
    parent -> left = n;
  }
  else {
    parent -> right = n;
  }
  n -> parent = parent;
  n -> depth = parent -> depth + 1;
}

bool delete_node(node* target) {
  node* parent = target -> parent;
  free(target);
  if (parent -> left == target ) {
    cout << "left ";
    parent -> left == NULL;
    return 1;
  }
  else {
    cout << "right ";
    parent -> right == NULL;
    return 0;
  }
}

vector<string> generateParenthesis(int n) {
  node* root = newNode();
  node* temp = root;
  string str;
  vector <string> ans;
  int ln = n, rn = n;
  bool isleft = false;

  while(1) {
    if (ln != 0) {
      node *n = newNode();
      insert_node(temp, n, 1);
      temp = n;
      str += "(";
      ln--;
    }
    else if (rn != 0) {
      node *n = newNode();
      insert_node(temp, n, 0);
      temp = n;
      str += ")";
      rn--;
    }
    else {
      ans.push_back(str);
      cout << str;
      // cout << ", ";
      while (isleft == false) {
        node* ttemp = temp -> parent;
        isleft = delete_node(temp);
        cout << isleft << " ";
        temp = ttemp;
        ln = isleft ? ln + 1 : ln;
        rn = !isleft ? rn + 1 : rn;
        str.pop_back();
      }
      cout << "find a sequence\n";
      node* n = newNode();
      insert_node(temp, n, 0);
      rn--;
      temp = n;
      str += ")";
    }
    if (temp == root) break;
  }
  return ans;
}

int main () {
  int n;
  vector <string> ans;
  cout << "Give a numnber :";
  cin >> n;
  ans = generateParenthesis(n);
  for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}