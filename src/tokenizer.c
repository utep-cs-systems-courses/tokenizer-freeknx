#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if((c == ' ' || c == '\t') & c != '\0')
    return 1;
  else
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(space_char(c))
    return 0;
  else
    return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  int i = 0;
  char *temp = str;
  while(*(temp + i)){
    if(non_space_char(*(temp + i))){
       return temp + i;
      }
    i++;
  }
    return temp + i;
} 

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  int i = 0;
  char *temp = word;
  while(*(temp + i)){
    if(space_char(*(temp + i))){
       return temp + i;
      }
    i++;
  }
    return temp + i;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int count = 0;
  char *temp = str;
  // temp = word_start(temp);
  while(*temp){
    temp = word_start(temp);
    
    if(non_space_char(*(temp))){
      count++;
    }

    temp = word_terminator(temp);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
 char *copy_str(char *inStr, short len){
   char *copy = malloc((len + 1) * sizeof(char));
   int i;
   for(i=0; i < len; i++){
     copy[i] = inStr[i];
   }
   copy[i] = '\0';
   return copy;
 }

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int length = count_words(str);
  char **tokens = malloc((length + 1) * sizeof(char*));
  int i = 0;
  char *copy1 = str;
  char *copy2;
  int num_char;
  while(i < length){
    copy1 = word_start(copy1);
    copy2 = word_terminator(copy1);
    num_char = copy2-copy1;
    tokens[i] = copy_str(copy1, num_char);
    copy1 = word_terminator(copy1);
    i++;
  }
  tokens[i] = '\0';
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  
  while(tokens[i]){
    printf("tokens[%d] %s\n", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int i = 0;

  while(tokens[i]){
    tokens[i] = NULL;
    i++;
    }
}
