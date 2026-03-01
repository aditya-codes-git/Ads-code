#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool rightThread;
};

Node* insert(Node* root, int key) {
    Node *ptr = root, *parent = NULL;

    while (ptr != NULL) {
        if (key == ptr->data) {
            cout << "Duplicate not allowed\n";
            return root;
        }
        parent = ptr;

        if (key < ptr->data) {
            if (ptr->left != NULL)
                ptr = ptr->left;
            else
                break;
        } else {
            if (!ptr->rightThread)
                ptr = ptr->right;
            else
                break;
        }
    }

    Node* newNode = new Node;
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->rightThread = true;

    if (parent == NULL)
        root = newNode;
    else if (key < parent->data) {
        parent->left = newNode;
        newNode->right = parent;
    } else {
        newNode->right = parent->right;
        parent->right = newNode;
        parent->rightThread = false;
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;

    Node* ptr = root;

    while (ptr->left != NULL)
        ptr = ptr->left;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        if (ptr->rightThread)
            ptr = ptr->right;
        else {
            ptr = ptr->right;
            while (ptr != NULL && ptr->left != NULL)
                ptr = ptr->left;
        }
    }
}

bool search(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return true;
        else if (key < root->data)
            root = root->left;
        else {
            if (root->rightThread)
                return false;
            root = root->right;
        }
    }
    return false;
}

/* Simplified delete (basic BST style for lab purpose) */
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data) {
        if (!root->rightThread)
            root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL || root->rightThread) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* succ = root->right;
        while (succ->left != NULL)
            succ = succ->left;

        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n1.Insert\n2.Inorder\n3.Search\n4.Delete\n5.Display\n6.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                break;

            case 2:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Found\n";
                else
                    cout << "Not Found\n";
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 5:
                cout << "Tree elements: ";
                inorder(root);
                cout << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}