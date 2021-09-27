#include <stdio.h>
#include <stlib.h>
#include "history.h"

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
  int index = 1;

  while(temp){
    temp = temp->next;
    index++;
  }
  temp = malloc(sizeof(Item));
  temp->id = index;
  temp->word = str;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/*Print the entire contents of the list. */
void print_history(List *list);

/*Free the history list and the strings it references. */
void free_history(List *list);
