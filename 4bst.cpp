#include <iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left = nullptr;
    BstNode* right = nullptr;

    BstNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BTree {
public:
    BstNode* root;

    BTree() {
        root = nullptr;
    }

    BstNode* insert(BstNode* node, int value) {
        if (node == nullptr) {
            return new BstNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    int height(BstNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int height() {
        return height(root);
    }

    int findMin(BstNode* node) {
        if (node == nullptr) {
            return -1;
        }
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    int findMin() {
        return findMin(root);
    }

    void mirror(BstNode* node) {
        if (node == nullptr) {
            return;
        }
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    void mirror() {
        mirror(root);
    }

    bool search(BstNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    bool search(int value) {
        return search(root, value);
    }

    void inorder(BstNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void inorder() {
        inorder(root);
    }
};

int main() {
    BTree tree;
    int n, value;
    cout << "Enter the number of elements to insert into the tree: ";
    cin >> n;
    cout << "Enter " << n << " values for the BST:\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        tree.insert(value);
    }
    cout << "\n--- Inorder Traversal ---\n";
    tree.inorder();
    cout << endl;
    int choice;
    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert a new node\n";
        cout << "2. Find the height of the tree\n";
        cout << "3. Find the minimum value in the tree\n";
        cout << "4. Mirror the tree\n";
        cout << "5. Search for a value\n";
        cout << "6. Display the tree (Inorder Traversal)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter a value to insert into the tree: ";
            cin >> value;
            tree.insert(value);
            cout << "Value " << value << " inserted.\n";
        } else if (choice == 2) {
            cout << "Height of the tree: " << tree.height() << endl;
        } else if (choice == 3) {
            cout << "Minimum value in the tree: " << tree.findMin() << endl;
        } else if (choice == 4) {
            tree.mirror();
            cout << "Tree has been mirrored.\n";
        } else if (choice == 5) {
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value)) {
                cout << "Value " << value << " found in the tree.\n";
            } else {
                cout << "Value " << value << " not found in the tree.\n";
            }
        } else if (choice == 6) {
            cout << "\n--- Inorder Traversal ---\n";
            tree.inorder();
            cout << endl;
        } else if (choice == 7) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice! Please enter a number between 1 and 7.\n";
        }
    }
    return 0;
}
