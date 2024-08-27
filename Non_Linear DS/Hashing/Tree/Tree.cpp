#include<iostream>
#include<climits>
#include<fstream>
#include<string>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        next = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    Node* createNode(int data) {
        return new Node(data);
    }

    Node* insert(Node* node, int data) {
        if(node == nullptr) return createNode(data);

        if(data < node->data) {
            node->left = insert(node->left, data);
        } else if(data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    Node* search(Node* node, int value) {
        if (node == nullptr || node->data == value) return node;

        if (value < node->data) return search(node->left, value);
        else return search(node->right, value);
    }

    int height(Node* node) {
        if(node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    void levelOrderTraversal(Node* node) {
        if (node == nullptr) return;

        const int MAX_SIZE = 100;
        Node* queue[MAX_SIZE];
        int front = 0;
        int rear = 0;

        queue[rear++] = node;

        cout << "\nLevel Order Traversal: ";
        while (front < rear) {
            Node* current = queue[front++];
            cout << current->data << " ";

            if(current->left != nullptr) queue[rear++] = current->left;
            if(current->right != nullptr) queue[rear++] = current->right;
        }
    }

    Node* deleteNode(Node* node, int data) {
        if(node == nullptr) return node;

        if(data < node->data) node->left = deleteNode(node->left, data);
        else if(data > node->data) node->right = deleteNode(node->right, data);
        else {
            if(node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if(node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);    
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    void findMinMax(Node* node, int& min, int& max) {
        if (node == nullptr) return;

        if (node->data < min) min = node->data;
        if (node->data > max) max = node->data;

        findMinMax(node->left, min, max);
        findMinMax(node->right, min, max);
    }

    void printTree(Node* node, int space) {
        if (node == nullptr) return;

        space += 4;

        printTree(node->right, space);

        for (int i = 4; i < space; i++) {
            cout << " ";
        }
        cout << node->data << "\n";

        printTree(node->left, space);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    void displayTree() {
        printTree(root, 0);
    }

    void search(int data) {
        Node* result = search(root, data);
        if(result != nullptr) {
            cout << "\nKey " << data << " found in the tree.\n";
        } else {
            cout << "\nKey " << data << " not found in the tree.\n";
        }
    }

    void height() {
        cout << "\nheight of the Tree: " << height(root) << endl;
    }

    void levelOrderTraversal() {
        levelOrderTraversal(root);
        cout << endl;
    }

    void deleteNode(int data) {
        root = deleteNode(root, data);
    }

    void findMinMax() {
        int min = INT_MAX, max = INT_MIN;
        findMinMax(root, min, max);
        cout << "\nMinimum value in the tree: " << min;
        cout << "\nMaximum value in the tree: " << max << endl;
    }
};

// tree: 1 8 1 3 1 10 1 1 1 6 1 14 1 4 1 7 1 13
int main() {
    BinaryTree bt;
    ListNode* head = nullptr;
    int choice, data;

    do {
        system("cls");
        bt.displayTree();
        cout << "\n\nBinary Tree Operations Menu\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Height\n";
        cout << "7. Level Order Traversal\n";
        cout << "8. Delete\n";
        cout << "9. Find Min and Max\n";
        cout << "10. Convert BST to Linked List\n";
        cout << "11. Serialize Tree\n";
        cout << "12. Deserialize Tree\n";
        cout << "13. Find LCA\n";
        cout << "14. Prune Tree\n";
        cout << "15. Display Tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the data to insert: ";
                cin >> data;
                bt.insert(data);
                break;

            case 2:
                cout << "\nInorder Traversal: ";
                bt.inorder();
                system("pause");
                break;

            case 3:
                cout << "\nPreorder Traversal: ";
                bt.preorder();
                system("pause");
                break;

            case 4:
                cout << "\nPostorder Traversal: ";
                bt.postorder();
                system("pause");
                break;

            case 5:
                cout << "\nPlease enter a value to search: ";
                cin >> data;
                bt.search(data);
                system("pause");
                break;

            case 6:
                bt.height();
                system("pause");
                break;

            case 7:
                bt.levelOrderTraversal();
                system("pause");
                break;

            case 8:
                cout << "\nEnter the value to delete: ";
                cin >> data;
                bt.deleteNode(data);
                break;

            case 9:
                bt.findMinMax();
                system("pause");
                break;

            // case 10:
            //     bt.convertBSTtoLinkedList(head);
            //     bt.printList(head);
            //     system("pause");
            //     break;

            // case 11:
            //     bt.serializeTree("store_tree.txt");
            //     cout << "\n";
            //     system("pause");
            //     break;

            // case 12:
            //     bt.deserializeTree("store_tree.txt");
            //     bt.displayTree();
            //     cout << "\n";
            //     system("pause");
            //     break;

            // case 13:
            //     cout << "Enter two keys to find LCA: ";
            //     int n1, n2;
            //     cin >> n1 >> n2;
            //     bt.findLCA(n1, n2);
            //     system("pause");
            //     break;

            // case 14:
            //     bt.pruneTree();
            //     break;

            case 15:
                bt.displayTree();
                system("pause");
                break;

            case 0:
                cout << "Exiting the program...\n";
                system("pause");
                break;

            default:
                cout << "Invalid choice!\n";
                system("pause");
                break;
        }

    } while (choice != 0);

    return 0;
}