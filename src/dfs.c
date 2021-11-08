/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"
#include <assert.h>

/*
Create empty stack s
Push root to stack
Initialise current node as root
Push current node to stack s and set current = current->left
If current is not NULL and stack is not empty then
  pop the top item from stack
  print the popped item,  and update current
If current is NULL and stack is empty then we are done*/

void DFT (node * root) {

    //Intitialise a new stack to NULL
    stack * S = NULL;

    //Push the root of the tree into the stack
    push (&S, root);
    //As long as the tree isn't empty does this loop run 
    while (S != NULL) {
        //Create a new node that is initialised to the node of the stack
        node * current_node = S->node;
        //The left child is the left child of our node
        node * lchild = current_node->lchild;
        //The right child is the right child of our node
        node * rchild = current_node->rchild;
    
        /*If the right child isn't empty and wasn't visited already, 
        push that right child to the stack*/
        if (rchild != NULL && !rchild->visited) {
            push (&S, rchild);
        }
        /*If the left child isn't empty and wasn't visited already, 
        push that left child to the stack*/
        if (lchild != NULL && !lchild->visited) {
            push (&S, lchild);
        }

        // Pop the current node it it have already been visited
        if (current_node->visited ) { 
            pop (&S);
        }

        //Update visited and print the number if not visited yet
        if (current_node->visited == false) {
            current_node->visited = true;
            printf ("%d ", current_node->num);
        }

    }       

}
/*Making a node that consists of data, a left child and a right child 
and it keeps track of the data was already visited*/
node *make_node (int num, node * left, node * right) {
    node *newNode;
    newNode = (node*) malloc (sizeof (node));
    newNode->num = num;
    newNode->lchild = left;
    newNode->rchild = right;
    newNode->visited = false;
	return newNode;
}
//Free the used nodes
void free_node (node * p)
{
	
}

//Print the nodes
void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}

//Print the tree in the DFS order
void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

/* Topp is a double pointer; it contains the address of where the address 
of the stack is stored.
This is so the address of the stack can be modified*/
void push (stack ** topp, node * node) {
    //Create a new stack
    stack * newStack;
    newStack = (stack*) malloc (sizeof (stack));

    //The new stack points at the pointer topp
    newStack->next = *topp;
    //The new stack cosists of a node which consists a value, lchild, rchild and visited
    newStack->node = node;

    //Update stack
    *topp = newStack;
}
//If the stack is empty
bool isEmpty (stack * topp)
{
  return false;
}
//The first item
node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

/* Topp is a double pointer; it contains the address of where the address 
of the stack is stored.
This is so the address of the stack can be modified*/
node *pop (stack ** topp) {
    if (*topp == NULL) return 0;

	  //Tempoaraly storing the pointer topp in a stack
    stack * Free = *topp;
    //New node that points at the pointers topps node
    node * new_node = (*topp)->node;

    //Set new entrance point to the stack
    *topp = (*topp)->next;

    //Frees old entrance point
    free (Free);

    //Return the node
    return new_node;
}

//Print the stack
void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
