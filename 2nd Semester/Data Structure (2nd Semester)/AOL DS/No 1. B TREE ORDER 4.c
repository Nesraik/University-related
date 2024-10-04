//Bryan Orville Audric
//2602160750
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct BTreeNode
{
    char *keys;
    int degree;
    struct BTreeNode **child;
    int numKey;
    bool leaf;
};

//For main root
struct BTree
{
    struct BTreeNode *root;
    int degree;
};

struct BTree *BTreeconstruct(int degree)
{
    struct BTree *bTree = (struct BTree*)malloc(sizeof(struct BTree));
    bTree->root = NULL;
    bTree->degree = degree;
    return bTree;
}

struct BTreeNode *Nodeconstruct(struct BTree *bTree, int degree1, bool leaf1)
{
    struct BTreeNode *node = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    node->degree = degree1;
    node->leaf = leaf1;
    node->keys = malloc((sizeof(char) * bTree->degree * 2) - 1);
    node->child = malloc((sizeof(struct BTreeNode) * bTree->degree * 2));
    node->numKey = 0;
    return node;
}

void SplitChild(struct BTreeNode *nodeRoot, int index, struct BTreeNode *child, struct BTree *bTree)
{
    struct BTreeNode *newNode = Nodeconstruct(bTree, child->degree, child->leaf);
    newNode->numKey = nodeRoot->degree - 1;
    for (int j = 0; j < nodeRoot->degree - 1; j++)
    {
        newNode->keys[j] = child->keys[j + nodeRoot->degree];
    }
    if (child->leaf == false)
    {
        for (int j = 0; j < nodeRoot->degree; j++)
        {
            newNode->child[j] = child->child[j + nodeRoot->degree];
        }
    }
    child->numKey = nodeRoot->degree - 1;
    for (int j = nodeRoot->numKey; j >= index + 1; j--)
    {
        nodeRoot->child[j + 1] = nodeRoot->child[j];
    }
    nodeRoot->child[index + 1] = newNode;
    for (int j = nodeRoot->numKey - 1; j >= index; j--)
    {
        nodeRoot->keys[j + 1] = nodeRoot->keys[j];
    }
    nodeRoot->keys[index] = child->keys[nodeRoot->degree - 1];
    nodeRoot->numKey ++;
}

void NodeinsertNonFull(struct BTree *bTree, struct BTreeNode *nodeRoot, char key)
{
    int i = nodeRoot->numKey - 1;
    if (nodeRoot->leaf == true)
    {
        while (i >= 0 && nodeRoot->keys[i] > key)
        {
            nodeRoot->keys[i + 1] = nodeRoot->keys[i];
            i--;
        }
        nodeRoot->keys[i + 1] = key;
        nodeRoot->numKey ++;
    }
    else
    {
        while (i >= 0 && nodeRoot->keys[i] > key)
        {
            i--;
        }
        if (nodeRoot->child[i + 1]->numKey == (2 * nodeRoot->degree) - 1)
        {
            SplitChild(nodeRoot, i + 1, nodeRoot->child[i + 1], bTree);
            if (nodeRoot->keys[i + 1] < key)
            {
                i++;
            }
        }
        NodeinsertNonFull(bTree, nodeRoot->child[i + 1], key);
    }
}

void Insert(struct BTree *bTree, char key)
{
    if (bTree->root == NULL)
    {
        bTree->root = Nodeconstruct(bTree, bTree->degree, true);
        bTree->root->keys[0] = key;
        bTree->root->numKey = 1;
    }
    else
    {
        if (bTree->root->numKey == (2 * bTree->degree) - 1)
        {
            struct BTreeNode *newNode = Nodeconstruct(bTree, bTree->degree, false);
            newNode->child[0] = bTree->root;
            SplitChild(newNode, 0, bTree->root, bTree);
            int i = 0;
            if (newNode->keys[0] < key)
            {
                i++;
            }
            NodeinsertNonFull(bTree, newNode->child[i], key);
            bTree->root = newNode;
        }
        else
        {
            NodeinsertNonFull(bTree, bTree->root, key);
        }
    }
}
void Noderemove(struct BTreeNode *nodeRoot, char key);

int GetPredecessor(struct BTreeNode *nodeRoot, int idx)
{
    struct BTreeNode *Current = nodeRoot->child[idx];
    while (Current->leaf == false)
    {
        Current = Current->child[Current->numKey];
    }
    return Current->keys[Current->numKey - 1];
}

int GetSuccessor(struct BTreeNode *nodeRoot, int idx)
{
    struct BTreeNode *Current = nodeRoot->child[idx + 1];
    while (Current->leaf==false)
    {
        Current = Current->child[0];
    }
    return Current->keys[0];
}

void Merge(struct BTreeNode *nodeRoot, int idx)
{
    struct BTreeNode *child = nodeRoot->child[idx];
    struct BTreeNode *sibling = nodeRoot->child[idx + 1];
    child->keys[nodeRoot->degree - 1] = nodeRoot->keys[idx];
    for (int i = 0; i < sibling->numKey; i++)
    {
        child->keys[i + nodeRoot->degree] = sibling->keys[i];
    }
    if (child->leaf == false)
    {
        for (int i = 0; i <= sibling->numKey; i++)
        {
            child->child[i + nodeRoot->degree] = sibling->child[i];
        }
    }
    for (int i = idx + 1; i < nodeRoot->numKey; i++)
    {
        nodeRoot->keys[i - 1] = nodeRoot->keys[i];
    }
    for (int i = idx + 2; i <= nodeRoot->numKey; i++)
    {
        nodeRoot->child[i - 1] = nodeRoot->child[i];
    }
    child->numKey += sibling->numKey + 1;
    nodeRoot->numKey --;
    free(sibling);
    sibling = NULL;
    return;
}

void RemoveNonLeaf(struct BTreeNode *nodeRoot, int idx)
{
    int key = nodeRoot->keys[idx];
    if (nodeRoot->child[idx]->numKey >= nodeRoot->degree)
    {
        int Predecessor = GetPredecessor(nodeRoot, idx);
        nodeRoot->keys[idx] = Predecessor;
        Noderemove(nodeRoot->child[idx], Predecessor);
    }
    else if (nodeRoot->child[idx + 1]->numKey >= nodeRoot->degree)
    {
        int Successor = GetSuccessor(nodeRoot, idx);
        nodeRoot->keys[idx] = Successor;
        Noderemove(nodeRoot->child[idx + 1], Successor);
    }
    else
    {
        Merge(nodeRoot, idx);
        Noderemove(nodeRoot->child[idx], key);
    }
    return;
}

void RemoveLeaf(struct BTreeNode *nodeRoot, int idx)
{
    for (int i = idx + 1; i < nodeRoot->numKey; i++)
    {
        nodeRoot->keys[i - 1] = nodeRoot->keys[i];
    }
    nodeRoot->numKey --;
    return;
}

void BorrowPrev(struct BTreeNode *nodeRoot, int idx)
{
    struct BTreeNode *child = nodeRoot->child[idx];
    struct BTreeNode *sibling = nodeRoot->child[idx - 1];
    for (int i = child->numKey - 1; i >= 0; i--)
    {
        child->keys[i + 1] = child->keys[i];
    }
    if (child->leaf==false)
    {
        for (int i = child->numKey; i >= 0; i--)
        {
            child->child[i + 1] = child->child[i];
        }
    }
    child->keys[0] = nodeRoot->keys[idx - 1];
    if (child->leaf==false)
    {
        child->child[0] = sibling->child[sibling->numKey];
    }
    nodeRoot->keys[idx - 1] = sibling->keys[sibling->numKey - 1];
    child->numKey ++;
    sibling->numKey --;
    return;
}

void BorrowNext(struct BTreeNode *nodeRoot, int idx)
{
    struct BTreeNode *child = nodeRoot->child[idx];
    struct BTreeNode *sibling = nodeRoot->child[idx + 1];
    child->keys[(child->numKey)] = nodeRoot->keys[idx];
    if (child->leaf == false)
    {
        child->child[(child->numKey) + 1] = sibling->child[0];
    }
    nodeRoot->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->numKey; i++)
    {
        sibling->keys[i - 1] = sibling->keys[i];
    }
    if (sibling->leaf == false)
    {
        for (int i = 1; i <= sibling->numKey; i++)
        {
            sibling->child[i - 1] = sibling->child[i];
        }
    }
    child->numKey ++;
    sibling->numKey --;
    return;
}

void Nodefill(struct BTreeNode *nodeRoot, int idx)
{
    if (idx != 0 && nodeRoot->child[idx - 1]->numKey >= nodeRoot->degree)
    {
        BorrowPrev(nodeRoot, idx);
    }
    else if (idx != nodeRoot->numKey && nodeRoot->child[idx + 1]->numKey >= nodeRoot->degree)
    {
        BorrowNext(nodeRoot, idx);
    }
    else
    {
        if (idx != nodeRoot->numKey)
        {
            Merge(nodeRoot, idx);
        }
        else
        {
            Merge(nodeRoot, idx - 1);
        }
    }
    return;
}

int FindKey(struct BTreeNode *nodeRoot, char key)
{
    int idx = 0;
    while (idx < nodeRoot->numKey && nodeRoot->keys[idx] < key)
    {
        idx++;
    }
    return idx;
}

void Noderemove(struct BTreeNode *nodeRoot, char key)
{
    int idx = FindKey(nodeRoot, key);
    if (idx < nodeRoot->numKey && nodeRoot->keys[idx] == key)
    {
        if (nodeRoot->leaf ==  true)
        {
            RemoveLeaf(nodeRoot, idx);
        }
        else
        {
            RemoveNonLeaf(nodeRoot, idx);
        }
    }
    else
    {
    	bool flag;
        if (nodeRoot->leaf == true)
        {
            printf("%c does not exist in the tree\n", key);
            return;
        }
        
        if(idx == nodeRoot->numKey){
        	flag = true;
		}
		else{
			flag = false;
		}
		
        if (nodeRoot->child[idx]->numKey < nodeRoot->degree)
        {
            Nodefill(nodeRoot, idx);
        }
        if (flag == true && idx > nodeRoot->numKey)
        {
            Noderemove(nodeRoot->child[idx - 1], key);
        }
        else
        {
            Noderemove(nodeRoot->child[idx], key);
        }
    }
    return;
}

void BTreeremove(struct BTree *bTree, char key)
{
    if (bTree->root == NULL)
    {
        printf("There is no data\n");
        return;
    }
    Noderemove(bTree->root, key);
    if (bTree->root->numKey == 0)
    {
        struct BTreeNode *temp = bTree->root;
        if (bTree->root->leaf ==  true)
        {
            bTree->root = NULL;
        }
        else
        {
            bTree->root = bTree->root->child[0];
        }
        free(temp);
        temp = NULL;
    }
    return;
}

void Print(struct BTreeNode *nodeRoot)
{
    int i;
    for (i = 0; i < nodeRoot->numKey; i++)
    {
        if (nodeRoot->leaf == false)
        {
            Print(nodeRoot->child[i]);
        }
        printf("%c ", nodeRoot->keys[i]);
    }
    if (nodeRoot->leaf == false)
    {
        Print(nodeRoot->child[i]);
    }
}

void BTreeCheck(struct BTree *root)
{
    if (root->root != NULL)
    {
        Print(root->root);
    }
}

int main()
{
	int menu;
	char data;
	
	//ORDER = 4;
	struct BTree *root=BTreeconstruct(2);
	
	Insert(root, 'A');
	Insert(root, 'C');
	Insert(root, 'D');
	Insert(root, 'K');
	Insert(root, 'M');
	Insert(root, 'O');
	Insert(root, 'P');
	Insert(root, 'R');
	Insert(root, 'S');
	Insert(root, 'T');
	Insert(root, 'U');
	
	do{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Print\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				Insert(root, 'E');
			    Insert(root, 'I');
			    Insert(root, 'L');
			    Insert(root, 'G');
			    Insert(root, 'X');
			    printf("[E,I,L,G,X] Inserted \n");
			    system("pause");
			    system("cls");
			    break;
			case 2:
				printf("Insert data to delete: ");
				scanf("%c",&data);
				data = getchar();
				BTreeremove(root,data);
				system("pause");
				system("cls");
				break;
			case 3:
				BTreeCheck(root);
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 4:
				return 0;
		}
	}while(menu!=4);
    return 0;
}


