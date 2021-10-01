#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *temp;
  Item *node = malloc(sizeof(Item));

  if(list->root == NULL){
    node->id = 1;
    list->root = node;
  }
  else{
    temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
    }
  
    node->id = temp->id + 1;
    temp->next = node;
  }

  node->str = str;
  node->next = NULL;
  
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *temp = list->root;
  while(temp){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *temp = list->root;
  while(temp){
    printf("[%d] %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *temp = list->root;
  Item *nextUp;
  while(temp){
    nextUp = temp->next;
    free(temp);
    temp = nextUp;
  }
}
