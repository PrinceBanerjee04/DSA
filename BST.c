#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode
{
  int data;
  struct bstnode *left;
  struct bstnode *right;
} bstnode;

bstnode *createNode(int a)
{
  bstnode *newnode = (bstnode *)malloc(sizeof(bstnode));
  newnode->data = a;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

bstnode *search(bstnode *root, int k)
{
  if (root == NULL || root->data == k)
    return root;
  if (k < root->data)
    return search(root->left, k);
  else
    return search(root->right, k);
}

void inserttree(bstnode **root, bstnode *newnode)
{
  if (*root == NULL)
  {
    *root = newnode;
    return;
  }

  if ((*root)->data > newnode->data)
  {
    if ((*root)->left == NULL)
      (*root)->left = newnode;
    else
      inserttree(&((*root)->left), newnode);
  }
  else
  {
    if ((*root)->right == NULL)
      (*root)->right = newnode;
    else
      inserttree(&((*root)->right), newnode);
  }
}

bstnode *delete(bstnode *root, int key)
{
  if (root == NULL)
    return root;

  if (key < root->data)
    root->left = delete(root->left, key);
  else if (key > root->data)
    root->right = delete(root->right, key);
  else
  {
    if (root->left == NULL)
    {
      bstnode *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      bstnode *temp = root->left;
      free(root);
      return temp;
    }

    bstnode *temp = root->right;
    while (temp->left != NULL)
      temp = temp->left;

    root->data = temp->data;
    root->right = delete(root->right, temp->data);
  }
  return root;
}

void inorder(bstnode *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void postorder(bstnode *root)
{
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void preorder(bstnode *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main()
{
  bstnode *root = NULL;
  int choice, value;
  do
  {
    printf("\nBinary Tree Operations:\n");
    printf("1. Insertion 2. Deletion 3. Traversal 4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &value);
      if (root == NULL)
        root = createNode(value);
      else
        inserttree(&root, createNode(value));
      break;
    case 2:
      if (root == NULL)
        printf("Tree is empty. Cannot delete.\n");
      else
      {
        printf("Enter the value to delete: ");
        scanf("%d", &value);
        root = delete(root, value);
        printf("Value %d deleted from the tree.\n", value);
      }
      break;
    case 3:
      if (root == NULL)
        printf("Tree is empty. Cannot Traverse.\n");
      else
      {
        printf("Inorder Traversal : ");
        inorder(root);
        printf("\n");
        printf("Postorder Traversal : ");
        postorder(root);
        printf("\n");
        printf("Preorder Traversal : ");
        preorder(root);
        printf("\n");
      }
      break;
    case 4:
      printf("Exiting the Program.");
      exit(0);
      break;
    default:
      printf("Invalid choice! Please enter a valid option.\n");
    }
  } while (choice != 4);

  return 0;
}
