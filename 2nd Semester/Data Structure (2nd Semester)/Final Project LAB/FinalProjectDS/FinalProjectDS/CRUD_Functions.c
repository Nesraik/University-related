#include"Base_AVL.c"

//------- CRD for tree -------

void createData(treeNode *newNode){
    if(session.root == NULL){
        session.root = newNode;
        newNode->prev = NULL;
        session.hashRoot[newNode->name[0] % 10] = session.root;
    }
    else{
        treeNode *node = session.root;
        while(1){
            if(strcmp(newNode->name, node->name) < 0){
                if(node->left != NULL) node = node->left;
                else {
                    node->left = newNode;
                    newNode->prev = node;
                    break;
                }
            }
            else if(strcmp(newNode->name, node->name) > 0){
                if(node->right != NULL) node = node->right;
                else {
                    node->right = newNode;
                    newNode->prev = node;
                    break;
                }
            }
            else{
                printf("\a\nError\n\n");
                break;
            }
        }
        AVL_check(session.root);
    }
}

void readData(treeNode *node){ // In Order
    if (node->left != NULL) readData(node->left);
    int i = 1;
    accountCell *cell;
    printf("%s\n\n", node->name);
    for(cell = node->head; cell != NULL; cell = cell->next){
        printf("%d. Username : %s\nPassword : %s\n\n", i, cell->username, cell->password);
        i++;
    }
    printf("---------------------------------------------------\n");
    if (node->right != NULL) readData(node->right);
}

void freeList(treeNode *node){
    accountCell *cell = node->head, *temp = node->head;
    while(cell != NULL){
        cell = temp->next;
        free(temp);
        temp = cell;
    }
}

void deleteData(treeNode *node){
    treeNode *parent = node->prev, *child;
    char hashValue = node->name[0] % 10;
    if (node->left == NULL){
        if(node->right == NULL){
            if(node->prev == NULL)session.root = NULL;
            else if(node == parent->left) parent->left = NULL;
            else parent->right = NULL;
            freeList(node);
            free(node);
        }

        else{
            child = node->right;
            if(node == session.root) session.root = child;
            else if(node == parent->left)parent->left = child;
            else parent->right = child;
            child->prev = parent;
            freeList(node);
            free(node);
        }
    }

    else if(node->right == NULL){
        child = node->left;
        if(node == session.root) session.root = child;
        else if(node == parent->left) parent->left = child;
        else parent->right = child;
        child->prev = parent;
        freeList(node);
        free(node);
    }

    else{ // Both left sub tree and right sub of node tree exist
        child = node->left;
        for(; child->right != NULL; child = child->right);
        strcpy(node->name, child->name);
        node->head = child->head;
        deleteData(child);
    }
    session.hashRoot[(int) hashValue % 10] = session.root;
    AVL_check(session.root);
}


//------- CRUD for data accounts -------

void createDataAccount(treeNode *node, accountCell *newCell){
    accountCell *cell = node->head;
    if(cell == NULL) node->head = newCell;
    else{
        for(; cell->next != NULL; cell = cell->next);
        cell->next = newCell;
        newCell->prev = cell;
    }
}

int readDataAccount(treeNode *node){
    int i = 1;
    accountCell *cell;
    printf("%s\n\n", node->name);
    for(cell = node->head; cell != NULL; cell = cell->next){
        printf("%d. Username : %s\nPassword : %s\n\n", i, cell->username, cell->password);
        i++;
    }
    return i-1;
}

void deleteDataAccount(accountCell *cell, treeNode *node){
    accountCell *before = cell->prev, *after = cell->next;
    if(before == NULL) node->head = after;
    else before->next = after;
    if(after != NULL) after->prev = before;
    free(cell);
}