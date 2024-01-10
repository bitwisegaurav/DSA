#include "header.h"

struct node{
    int data;
    struct node *right;
    struct node *left;
};

void preorder(node* root){
    if(!root) {
        // cout << "-1, ";
        return;
    }

    cout << root->data << ", ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(!root) {
        // cout << "-1, ";
        return;
    }

    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);
}

void postorder(node* root){
    if(!root) {
        // cout << "-1, ";
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ", ";
}

void level_order(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout << temp->data << ", ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

class bst{
    struct node* top_root;
  public:
    bst(){
        top_root = nullptr;
    }
    void insert(int num) {
        if(!top_root) {
            top_root = new node;
            top_root->data = num;
            top_root->left = top_root->right = nullptr;
        } else {
            insertAlgo(top_root, num);
        }
    }
    void insertAlgo(node* root, int val){
        if(!root) return;

        if(root->data == val){
            cout << "This value is already present in this BST" << endl;
        } else if(root->data < val) {
            if(root->right) insertAlgo(root->right, val);
            else {
                root->right = new node;
                root->right->data = val;
                root->right->left = root->right->right = nullptr;
            }
        } else {
            if(root->left) insertAlgo(root->left, val);
            else {
                root->left = new node;
                root->left->data = val;
                root->left->left = root->left->right = nullptr;
            }
        }
    }

    void remove(int num) {
        if(top_root) removeNode(top_root, num);
        else cout << "Tree is empty" << endl;
    }

    node* removeNode(node* root, int num) {
        if(root->data == num){
            if(root->right && root->left) { // both childs
                // find the minimum element from right subtree and replace it with root's data
                node* temp = root->left, *pre = root->left;
                while(temp->right){
                    pre = temp;
                    temp = temp->right;
                }
                root->data = temp->data;
                pre->right = temp->left;
                delete temp;
            } else if(root->right || root->left) { // only one child case
                // just delete that node and makes the bridge between parent and child of this node
                node* temp = nullptr;
                if(root->right) temp = root->right;
                else temp = root->left;
                delete root;
                return temp;
            } else { // no child
                delete root;
                return nullptr;
            }
        } else if(root->data < num) {
            root->right =  removeNode(root->right, num);
        } else {
            root->left = removeNode(root->left, num);
        }
        return root;
    }

    void display() {
        if(top_root){
            cout << "Preorder : ";
            preorder(top_root);
            cout << endl << "Inorder : ";
            inorder(top_root);
            cout << endl << "Postorder : ";
            postorder(top_root);
            cout << endl << "Level order : ";
            level_order(top_root);
            cout << endl << endl;
        } else {
            cout << "Tree is empty" << endl;
        }
    }
};

int main(){
    bst b;
    int n = 0, number = -1;

    do {
        cout << "Enter number from following : " << endl;
        cout << "1. Insert \t2. Delete \t3. Display \t4. Exit" << endl;
        cin >> n;
        switch (n) {
            case 1:
                cout << "Enter numbers to insert : ";
                do {
                    cin >> number;
                    if(number!=-1) b.insert(number);
                } while (number!=-1);
                break;
            
            case 2:
                cout << "Enter number to delete : ";
                cin >> number;
                b.remove(number);
                break;
            
            case 3:
                b.display();
                break;
            
            case 4:
                cout << "Exiting!" << endl;
                break;
            
            default:
                cout << "Enter a valid number" << endl;
                break;
        }
    } while (n!=4);

    return 0;
}