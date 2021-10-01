#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 200
void no_input();
int commands(char *input);
List *history;
char str[MAX];
char **tokens;

int main(){
  
  extern char **tokens;
  extern List *history; 
  extern char str[];
  int j = 1;
  int k = 0;
  char temp;
  char *new;
  history = init_history();
  printf("type something you want to tokenize, or '!n' to display a word on that sentence with 'n' being the index, '!h' to display all words, and '!x' to exit.\n$");
  
  while(j){
    no_input();
    if(str[0] == '!'){
       j = commands(str);
    }
   else{
       while(str[k] != '\0'){
         k++;
       }
       new = copy_str(str, k);
       k = 0;
       add_history(history, new);
       printf("Enter another string: \n$");
   } 
  }
}

void no_input(){
   extern char str[];
   extern char **tokens;
   fgets(str, MAX, stdin);
   tokens = tokenize(str);
}

int commands(char *input){
    char temp = input[1];
int j = 0;
switch(temp){
 case 'x':
  return 0;
case 'n':
  printf("please input desired index: \n$");
  fgets(str, 200, stdin);
  j = str[0] - 48;

  if(get_history(history, j) == NULL){
    printf("there is nothing at that index\n");
    printf("Enter another string: \n$");
   break;
  }
  else{
    printf("[%d] %s\n", j, get_history(history, j));
    printf("Enter another string: \n$");
    break;
  }
case 'h':
    print_history(history);
    printf("Enter another string: \n$");
    break;
default:
    printf("unknown command: \ncommands are '!n' for word at index 'n', '!h' for history, '!x' to quit. \n$");
    break;
}
return 1;
}
