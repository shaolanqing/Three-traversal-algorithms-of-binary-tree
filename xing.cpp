//二叉树的链式存储结构定义,二叉树的三种遍历算法
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
//二叉树节点信息
struct binarytreenode
{
	int  data;
	struct binarytreenode *lchild;//左子树
	struct binarytreenode *rchild;//右子树
};
typedef struct binarytreenode BiTNode;
 
void print( int e)
{
	printf(" %2d", e);
}
 
 
//二叉树创建
BiTNode *CreatTree( int *a)
{
	int i;
	BiTNode *pNode[11] = {0};
 
	for ( i = 0; i < 10; i++)
	{
		pNode[i] = (BiTNode *) malloc(sizeof(BiTNode));
 
		if ( NULL == pNode[i])
		{
			printf("malloc error!\n");
			exit(1);
		}
 
		pNode[i]->lchild = NULL;
 
		pNode[i]->rchild = NULL;
 
		pNode[i]->data = a[i];
	}
 
	for ( i = 0; i < 10/2; i++)
	{
		pNode[i]->lchild = pNode[ 2 * (i + 1) - 1];
 
		pNode[i]->rchild = pNode[ 2 * (i + 1) + 1 - 1];
	}
 
	return pNode[0];
}
 
//先序遍历
int  PreOrderTraverse( BiTNode *root, void (*visit)(int) )
{
	if ( NULL == root)
	{
		return 1;
	}
 
	(*visit)(root->data);
 
	if ( PreOrderTraverse(root->lchild, visit) )
	{
		if ( PreOrderTraverse(root->rchild, visit) )
		{
			return 1;
		}
	}
 
	return 0;
 
}
 
//中序遍历
int MidOrderTraverse( BiTNode *root, void (*visit)(int) )
{
	if ( NULL == root)
	{
		return 1;
	}
 
	if ( MidOrderTraverse( root->lchild, visit) )
	{
		(*visit)(root->data);
 
		if ( MidOrderTraverse( root->rchild, visit) )
		{
			return 1;
		}
	}
 
	return 0;
}
 
 
//后序遍历
int PostOrderTraverse( BiTNode *root, void (*visit)(int) )
{
	if ( NULL == root)
	{
		return 1;
	}
 
	if ( PostOrderTraverse( root->lchild, visit) )
	{
		if ( PostOrderTraverse( root->rchild, visit) )
		{
			(*visit)(root->data);
 
			return 1;
		}
	}
 
	return 0;
}
 

 
int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	BiTNode *root = NULL;
 
	root = CreatTree(a);
	printf("排序前:\n");
	for(int i=0;i<10;i++) 
     printf("%d\t",a[i]);
	printf("\n");

	printf("前序排列:\n");
	PreOrderTraverse( root, print);
	printf("\n");
    
	printf("中序排列:\n");
	MidOrderTraverse( root, print);
	printf("\n");
 
	printf("后序排列:\n");
	PostOrderTraverse( root, print);
 
	printf("\n");
	return 0;
}

