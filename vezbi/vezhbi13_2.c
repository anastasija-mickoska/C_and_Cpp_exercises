#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// //zadaca 1
struct stackNode{
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;


void push( StackNodePtr *topPtr, char ch )
{
    StackNodePtr newPtr;

    newPtr = malloc( sizeof( StackNode ) );

    if ( newPtr != NULL ) {
        newPtr->data = ch;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else {
        printf( "%d ne e vnesen. Nema dovolno memorija.\n", ch );
    }

}
void printStack( StackNodePtr currentPtr )
{
    if ( currentPtr == NULL ) {
        printf( "Stekot e prazen.\n\n" );
    }
    else {
        printf( "Stekot e:\n" );
            while ( currentPtr != NULL ) {
            printf( "%c --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        }

        printf( "NULL\n\n" );
    }
}


void printStackBackwards(StackNodePtr currentPtr) {
    char string[MAX];
    if (currentPtr == NULL) {
        printf("Stekot e prazen.\n\n");
        return;
    } else {
        int i = 0;
        while (currentPtr != NULL && i < MAX - 1) {
            string[i] = currentPtr->data;
            i++;
            currentPtr = currentPtr->nextPtr;
        }
        string[i] = '\0';
        StackNodePtr reverseStack = NULL;
        for (int j = 0; j < i; j++) {
            push(&reverseStack, string[j]);
        }
        printStack(reverseStack);
    }
}

//zadaca 2
struct treeNode {
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *treePtr, int value )
{
       if ( *treePtr == NULL ) {
        *treePtr = malloc( sizeof( TreeNode ) );
            if ( *treePtr != NULL ) {
            ( *treePtr )->data = value;
            ( *treePtr )->leftPtr = NULL;
            ( *treePtr )->rightPtr = NULL;
        }
        else {
            printf( "%d ne e vneseno. Nema dovolno memorija.\n", value );
        }
    }
    else {
        if ( value < ( *treePtr )->data ) {
        insertNode( &( ( *treePtr )->leftPtr ), value );
        }

        else if ( value > ( *treePtr )->data ) {
            insertNode( &( ( *treePtr )->rightPtr ), value );
        }
    }
}

void inOrder( TreeNodePtr treePtr )
{
    if ( treePtr != NULL ) {
        inOrder( treePtr->leftPtr );
        printf( "%3d", treePtr->data );
        inOrder( treePtr->rightPtr );
    }
}

void preOrder( TreeNodePtr treePtr )
{
    if ( treePtr != NULL ) {
        printf( "%3d", treePtr->data );
        preOrder( treePtr->leftPtr );
        preOrder( treePtr->rightPtr );
    }
}
void postOrder( TreeNodePtr treePtr )
{
    if ( treePtr != NULL ) {
        postOrder( treePtr->leftPtr );
        postOrder( treePtr->rightPtr );
        printf( "%3d", treePtr->data );
    }
}

//zadaca 3

TreeNode* findMin(TreeNode* root) {
    while (root->leftPtr != NULL) {
        root = root->leftPtr;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) {
        return root; //ako drvoto e prazno
    }

    if (value < root->data) {
        root->leftPtr = deleteNode(root->leftPtr, value); //rekurzizvno se prefrlame vo leviot del od drvoto
    } else if (value > root->data) {
        root->rightPtr = deleteNode(root->rightPtr, value); //se prefrlame vo desniot del od drvoto
    } else {
        if (root->leftPtr == NULL && root->rightPtr == NULL) { //ako jazolot e list (nema deca)
            free(root); //vednas go briseme jazolot
            return NULL;
        }
        else if (root->leftPtr == NULL) { //jazolot ima samo edno dete
            TreeNode* temp = root->rightPtr; //jazolot kje go zameni desnoto dete, bidejki nema levo dete
            free(root);
            return temp;
        } else if (root->rightPtr == NULL) {
            TreeNode* temp = root->leftPtr; //jazolot kje go zameni levoto dete, bidejki nema desno dete
            free(root);
            return temp;
        }
        //jazolot ima dve deca
        TreeNode* temp = findMin(root->rightPtr);  //go barame minimumot vo desnoto poddrvo
        root->data = temp->data; //go zamenuvame jazolot so najdeniot minimum
        root->rightPtr = deleteNode(root->rightPtr, temp->data); //go briseme jazolot sto beshe minimum vo desnoto poddrvo
    }
    return root;
}

int main() {

    //zadaca 1
    StackNodePtr stackPtr = NULL;
    char string[20];
    printf("Vnesi tekst\n");

    fgets(string, sizeof(string), stdin);
    for (int i = 0; string[i] != '\0'; i++) {
        push(&stackPtr, string[i]);
        if (string[i] == ' ') {
            push(&stackPtr, string[i]);
        }
    }
    printf("Tekstot vo obraten redosled e:\n");
    printStackBackwards(stackPtr);

    // //zadaca 2
    int i;
    int item;
    TreeNodePtr rootPtr = NULL;

    srand( time( NULL ) );
    printf( "Broevite koi se stavaat vo drvoto se: ");

    for ( i = 1; i <= 10; i++ ) {
        item = rand() % 15;
        printf( "%3d", item );
        insertNode( &rootPtr, item );
    }

    printf( "\n\nPominuvanjeto vo preOrder dava:\n" );
    preOrder( rootPtr );

    printf( "\n\nPominuvanjeto vo inOrder dava:\n" );
    inOrder( rootPtr );

    printf( "\n\nPominuvanjeto vo postOrder dava:\n" );
    postOrder( rootPtr );

    //zadaca 3

    int broj;
    printf("\n\nVnesi vrednost za brisenje: ");
    scanf("%d", &broj);
    rootPtr = deleteNode(rootPtr, broj);
    printf("\n\nPominuvanjeto vo inOrder po brisenje dava:\n");
    inOrder(rootPtr);

    return 0;
}
