#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insertNode(Node* r, int x){
    if(r == NULL){
        r = new Node();
        r->data = x;
        r->left = r->right = NULL;
        return r;
    }

    if(x < r->data)
        r->left = insertNode(r->left, x);
    else
        r->right = insertNode(r->right, x);

    return r;
}

int height(Node* r){
    if(r == NULL)
        return 0;
    int l = height(r->left);
    int h = height(r->right);
    return 1 + ((l > h) ? l : h);
}

int minimum(Node* r){
    if(r == NULL){
        cout << "Tree empty";
        return -1;
    }
    while(r->left != NULL){
        r = r->left;
    }
    return r->data;
}

bool search(Node* r, int x){
    if(r == NULL)
        return false;
    if(r->data == x)
        return true;
    if(x < r->data)
        return search(r->left, x);
    return search(r->right, x);
}

int main(){
    Node* root = NULL;
    int val, ch;
    do{
        cout << "\n1.Insert\n2.Height\n3.Minimum\n4.Search\n5.Exit\n";
        cin >> ch;

        if(ch == 1){
            cin >> val;
            root = insertNode(root, val);
        }
        else if(ch == 2) {
            cout << "Height: " << height(root) << endl;
        }
        else if(ch == 3) {
            cout << "Minimum: " << minimum(root) << endl;
        }
        else if(ch == 4){
            cout << "Enter value to search: ";
            cin >> val;
            if(search(root, val))
                cout << "Found\n";
            else
                cout << "Not Found\n";
        }

    }while(ch != 5);

    return 0;
}
