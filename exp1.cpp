#include <iostream>
using namespace std;

struct Node {
    string title;
    Node* left;
    Node* right;

    Node(string t) {
        title = t;
        left = right = NULL;
    }
};

Node* insert(Node* root, string title) {
    if (root == NULL)
        return new Node(title);

    if (title < root->title)
        root->left = insert(root->left, title);
    else
        root->right = insert(root->right, title);

    return root;
}

bool search(Node* root, string title) {
    if (root == NULL)
        return false;
    if (root->title == title)
        return true;
    if (title < root->title)
        return search(root->left, title);
    else
        return search(root->right, title);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->title << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice;
    string title;

    do {
        cout << "\n1.Insert\n2.Search\n3.Display\n4.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin >> title;
                root = insert(root, title);
                break;

            case 2:
                cout << "Enter book title to search: ";
                cin >> title;
                if (search(root, title))
                    cout << "Book Found\n";
                else
                    cout << "Book Not Found\n";
                break;

            case 3:
                cout << "Book List (Inorder): ";
                inorder(root);
                cout << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}