#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  char **tokens;
  List *history = init_history();
  char str[50];
  char *strHist;
  int indexHist;
  int j;
  char temp;
  printf("type something you want to tokenize, or '!n' to display a word on that sentence with 'n' being the index, '!h' to display all words, and '!x' to exit.\n$");
  fgets(str, 50, stdin);
  tokens = tokenize(str);
  
  while(1){
    if(str[0] == '!'){
      temp = str[1];
      switch(temp){
      case 'n':
	printf("string at index n");

      case 'h':
	print_tokens(tokens);
      case 'x':
	break;
	
      default:
	printf("unknown command: \ncommands are '!n' for word at index 'n', '!h' for history, '!x' to quit. \n$");
	  fgets(str, 50, stdin);
      }
      printf("\n$");
      fgets(str, 50, stdin);
      
  }
}

int menu(char str*){
  

}
