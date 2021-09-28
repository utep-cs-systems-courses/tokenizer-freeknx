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
  Item *temp = list->root;
  Item *node = malloc(sizeof(Item));
  int length = word_terminator(str)-word_start(str);
  char  *newString = str;
  
  while(temp->next != NULL){
    //printf("passing %s at [%d]\n", temp->str, temp->id);
    temp = temp->next;
  }
  //printf("inserting %s at [%d]", temp->str, temp->id);
  
  node->id = temp->id + 1;
  node->str = newString;
  if(temp = list->root){
    temp->id = temp->id + 1;
    temp->str = newString;
  }
  else
    temp->next = node;
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
