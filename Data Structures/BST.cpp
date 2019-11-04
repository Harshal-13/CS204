#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class BST{
private:
	int data;
	BST *left, *right;
public:
  BST *newnode(int key){
    BST *a = (BST*)malloc(sizeof(BST));
    a->data=key;
    a->left=NULL;
    a->right=NULL;
    return a;
  }
  BST* Insert(int key, BST* root){
    BST *a = newnode(key);
    if(root == NULL)return a;
    else{
        if(root->data >= key){
            root->left = Insert(key, root->left);
        }else{
            root->right = Insert(key, root->right);
        }
        return root;
    }
  }

  BST* Search(int key, BST* root){
    if(root == NULL || root->data == key) return root;
    if(root->data > key) return Search(key, root->left);
    return Search(key, root->right);
  }

 BST* Min(BST* root){
    BST* temp = root;
    while(temp->left) temp = temp->left;
    return temp;
  }

  BST* Max(BST* root){
    BST* temp = root;
    while(temp->right) temp = temp->right;
    return temp;
  }

  BST* Delete(int key, BST* root){
    if(root==NULL)return root;
    if(root->data > key) root->left = Delete(key, root->left);
    else if(root->data < key) root->right = Delete(key, root->right);
    else{
      if(root->left == NULL){
            BST *temp = root->right;
            free(root);
            return temp;
      }
      else if(root->right == NULL){
            BST *temp = root->left;
            free(root);
            return temp;
      }

      BST* temp=Min(root->right);
      root->data=temp->data;
      root->right=Delete(temp->data, root->right);
    }
    return root;
  }

  void inorder(BST *root){
    if (root != NULL)
    {
        inorder(root->left);
        cout<< root->data<<" ";
        inorder(root->right);
    }
  }

  BST *inorder_successor(BST *root, BST *node){
    BST* temp = Search(node->data, root);
    if(temp->right != NULL) return Min(temp->right);

    BST* successor = NULL;

    while(root!= NULL){
        if(node->data < root->data){
            successor = root;
            root = root->left;
        }
        else if(node->data > root->data){
            root = root->right;
        }
        else break;
    }
    return successor;
  }

  BST *join(BST *t1, BST *t2){
    if(t1 == NULL) return t2;
    if(t2 == NULL) return t1;

    BST *t = newnode(Max(t1)->data);
    t1 = Delete(t->data, t1);
    t->left = t1;
    t->right = t2;
    return t;
  }


};

int main(){
	  BST* t1=NULL;
    t1 = t1->Insert(5, t1);
    t1->Insert(1, t1);
    t1->Insert(55, t1);
    t1->Insert(65, t1);
    t1->Insert(52, t1);
    t1->Insert(32, t1);
    t1->inorder(t1);
    cout<<endl;

    BST* t2=NULL;
    t2 = t2->Insert(100, t2);
    t2->Insert(200, t2);
    t2->Insert(351, t2);
    t2->Insert(631, t2);
    t2->Insert(3544, t2);
    t2->Insert(655, t2);
	  t2->inorder(t2);
    cout<<endl;

    BST *t = NULL;
    t = t->join(t1, t2);
    t->inorder(t);


}
