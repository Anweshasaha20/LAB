#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
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
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create/Insert key in BST\n");
        printf("2. Search key in BST\n");
        printf("3. Find in-order predecessor and successor\n");
        printf("4. Delete key from BST\n");
        printf("5. Display in-order traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("Key %d found in the BST.\n", key);
            else
                printf("Key %d not found in the BST.\n", key);
            break;
        case 3: {
            printf("Enter key to find predecessor and successor: ");
            scanf("%d", &key);
            Node* pred = NULL;
            Node* succ = NULL;
            Node* current = root;

            while (current != NULL) {
                if (key > current->key) {
                    pred = current;
                    current = current->right;
                } else {
                    current = current->left;
                }
            }

            current = root;
            while (current != NULL) {
                if (key < current->key) {
                    succ = current;
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            if (pred)
                printf("Predecessor: %d\n", pred->key);
            else
                printf("No predecessor found.\n");

            if (succ)
                printf("Successor: %d\n", succ->key);
            else
                printf("No successor found.\n");
            break;
        }
        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 5:
            printf("In-order Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 6:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
