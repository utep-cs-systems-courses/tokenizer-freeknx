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
  int j = 0;
  char temp;
  printf("type something you want to tokenize, or '!n' to display a word on that sentence with 'n' being the index, '!h' to display all words, and '!x' to exit.\n$");
  fgets(str, 200, stdin);
  tokens = tokenize(str);
  
  while(1){
    add_history(history, str);
    if(str[0] == '!'){
      temp = str[1];
      if(temp == 'x'){break;}
      else if(temp == 'n'){
	printf("please input desired index: \n$");
        fgets(str, 200, stdin);
	j = str[0];
	printf("j = %d\n", j);
	if(get_history(history, j) == NULL)
	  printf("there is nothing at that index\n");
	else{
	  printf("[%d] %s\n", j, get_history(history, j));
	}
      }
      else if(temp == 'h'){print_history(history);}
      else{
	printf("unknown command: \ncommands are '!n' for word at index 'n', '!h' for history, '!x' to quit. \n$");
      }
    }
  printf("Enter another string: \n$");
  fgets(str, 200, stdin);
  tokens = tokenize(str);
  print_tokens(tokens);
  }
}

/*int menu(char str*){
  

  }*/
