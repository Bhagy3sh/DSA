#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct TreeNode** root, int val) {
    if (*root == NULL) {
        *root = createNode(val);
        return;
    }
    struct TreeNode* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = *root;
    
    while (front != rear) {
        struct TreeNode* current = queue[front++];
        
        if (current->left == NULL) {
            current->left = createNode(val);
            break;
        }
        else {
            queue[rear++] = current->left;
        }
        
        if (current->right == NULL) {
            current->right = createNode(val);
            break;
        }
        else {
            queue[rear++] = current->right;
        }
    }
}

// ---------------Traversals-------------------

// 1. Level-Order (top to bottom and left to right)
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;
    
    struct TreeNode* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;
    
    while (front != rear) {
        struct TreeNode* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// 2. In-Order (Left - Root - Right)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// 3. Pre-Order (Root - Left - Rigth)
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 4. Post-Order (Left - Right - Root)
void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// -------------------------------------------


int main() {
    struct TreeNode* root = NULL;
    int n;
    printf("n = ");
    scanf("%d", &n);
    
    while (n--) {
        int val;
        printf(">>>> ");
        scanf("%d", &val);
        insert(&root, val);
    }
    printf("\nLevel order: ");
    levelOrder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
}