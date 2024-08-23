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

    //insertNode
};

int main() {
    BinaryTree bt;
    ListNode* head = nullptr;
    int choice, data;

    do {
        system("cls");
        // bt.displayTree();
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
            // case 1:
            //     cout << "\nEnter the data to insert: ";
            //     cin >> data;
            //     bt.insert(data);
            //     break;

            // case 2:
            //     cout << "\nInorder Traversal: ";
            //     bt.inorder();
            //     system("pause");
            //     break;

            // case 3:
            //     cout << "\nPreorder Traversal: ";
            //     bt.preorder();
            //     system("pause");
            //     break;

            // case 4:
            //     cout << "\nPostorder Traversal: ";
            //     bt.postorder();
            //     system("pause");
            //     break;

            // case 5:
            //     cout << "\nPlease enter a value to search: ";
            //     cin >> data;
            //     bt.search(data);
            //     system("pause");
            //     break;

            // case 6:
            //     bt.height();
            //     system("pause");
            //     break;

            // case 7:
            //     bt.levelOrderTraversal();
            //     system("pause");
            //     break;

            // case 8:
            //     cout << "\nEnter the value to delete: ";
            //     cin >> data;
            //     bt.deleteNode(data);
            //     break;

            // case 9:
            //     bt.findMinMax();
            //     system("pause");
            //     break;

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

            // case 15:
            //     bt.displayTree();
            //     system("pause");
            //     break;

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