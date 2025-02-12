#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"


typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
BTNode* CreatTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int size = 0;
//void TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	
//	size++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left_height = TreeHeight(root->left);
	int right_height = TreeHeight(root->right);

	return left_height > right_height ? left_height + 1 : right_height + 1;
}

int TreeKLevel(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k ==1)
	{
		
		return 1;
	}
	
	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);

}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root->data == x)
	{
		return root;
	}
	if (root==NULL)
	{
		return NULL;
	}
	BTNode* LeftResult = BinaryTreeFind(root->left, x);
	if (LeftResult != NULL)
	{
		return LeftResult;
	}
	BTNode* RightResult = BinaryTreeFind(root->right, x);
	if (RightResult != NULL)
	{
		return RightResult;
	}
	return NULL;
	
	
}
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestroy(&q);
}
int main()
{
	BTNode* root = CreatTree();
	/*InOrder(root);
	printf("\n");
	int size = TreeSize(root);
	printf("%d ", size);
	printf("\n");
	int height = TreeHeight(root);
	printf("%d", height);
	printf("\n");*/
	/*int klevel = TreeKLevel(root, 3);
	printf("%d", klevel);
	printf("\n");*/

	
	return 0;
}