#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insertNode(int data, Node* root) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        if(root == NULL) {
            printf("Memory allocation failed!");
            return NULL;
        }
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (data < root->data) {
        root->left = insertNode(data, root->left);
    } else if (data > root->data) {
        root->right = insertNode(data, root->right);
    }
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int ch, data;
    do {
        printf("Choose 1]Insert 2]Delete 3]Print 4]Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data to insert:\n");
                scanf("%d", &data);
                root = insertNode(data, root);
                break;

            case 2:
                printf("Enter the element to delete:\n");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    printf("Inorder traversal of the BST:\n");
                    inorder(root);
                    printf("\n");
                }
                break;
            
            case 4:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (ch != 4);
    return 0;
}

