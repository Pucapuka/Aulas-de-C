#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//global variables to work on
char text [];
int word, letter, sentences;

//function for sentences counting 
int sentencesCount(int sentences){
  sentences = 0
  if (isupper(text)==1){
      sentences +=1;
  }
  return sentences;
}

//function for word counting
int wordCount(int word){
    word = 1;
    if (isgraph(text)==0){
        word +=1;
    }
    return word;
}

//function for letters counting
int letterCount(int letter){
    letter = 0;
    if (isgraph(text)==1){
        letter +=1;
    }
    return letter;
}


int col-index(int L, int S){
    L = letter * word/100;
    S = sentences * word/100
   int col-index = 0.0588 * L - 0.296 * S - 15.8;
   return col-index;
}

int main(){
    
//variables
int L, S, grade;

//head
printf("Text Grade Checker");
printf("------------------0\n\n");

//Text caption
printf("Insert your text below:\n");
scanf("%s", text);

//functions calling
sentences = sentencesCount(int sentences);
word = wordCount(int word);
letter = letterCount(int letter);
grade = col-index(int L, int S);

printf("the text grade is %d.", grade);


return 0;
}
