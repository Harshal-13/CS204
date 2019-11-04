#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class node{
private:
    int data;
    struct node* left;
    struct node* right;
public:
    node *newnode(int key){
        struct node *a = ( node*)malloc(sizeof( node));
        a->data=key;
        a->left=NULL;
        a->right=NULL;
        return a;
    }

    node *Insertright( node *root, int key){
    	if(root == NULL) return newnode(key);
    	root->right =  Insertright(root->right, key);
    	return root;
    }

    node *Insertleft( node *root, int key){
    	if(root == NULL) return newnode(key);
    	root->left =  Insertleft(root->left, key);
    	return root;
    }

    void inorder( node* root)
    {
        if (!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder( node* root) {
        if(root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder( node* root) {
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    bool Search( node* root, int key)
    {
        if (root == NULL)
            return false;

        if (root->data == key)
            return true;

        bool l = Search(root->left, key);

        bool r = Search(root->right, key);

        return l || r;
    }
};

int main(){
  node *root = NULL;
	root = root->Insertleft(root, 84);
	root = root->Insertright(root, 78);
	root = root->Insertright(root, 74);
	root = root->Insertright(root, 46);
	root = root->Insertright(root, 57);
	root->inorder(root);
	cout<<endl;
	root->preorder(root);
	cout<<endl;
	root->postorder(root);
	cout<<endl;
	cout<<root->Search(root, 84);
}
