#include <stdio.h>

/* prototypes */
int draw_rectangle(int width, int length, char ch);
int draw_triangle(int size, char ch);
int valid_character(char ch);
char get_char();

int main(){

  int length, width, size,  selection;
  char bool=1, ch;	

  while(bool){
    printf("Enter 1(rectangle), 2(triangle), 3(other), 0(quit): ");
    scanf("%d",&selection);
    if(selection == 0){
      bool = 0; 
    }
    else if(selection == 1){
      printf("Enter character, width and length: ");
      scanf(" %c %d %d", &ch, &width, &length); 
      draw_rectangle(width, length, ch);			
    }
    else if(selection == 2){
      printf("Enter character and size: ");
      scanf(" %c %d", &ch, &size);
      draw_triangle(size, ch);
    }
    else if(selection == 3){
    }
    else{
      printf("Invalid choice.\n");
    }
    while(get_char() != '\n');		
  }
  printf("Bye Bye.\n");
  return 0;
}


int draw_rectangle(int width, int length, char ch){
  int i, j;

  if(valid_character(ch) == 0|| width <= 0 || length <= 0){
    printf("Invalid data provided.\n");
    return 0;
  }
  for(i = 0; i < width; i++){
    for(j = 0; j < length; j++){
      printf("%c", ch);		
    }
    printf("\n");
  }

  return 1;
}

int draw_triangle(int size, char ch){
  int i, j, length = 1;

  if(valid_character(ch) == 0 || size <= 0){
    printf("Invalid data provided.\n");
    return 0;
  }
  for(i = 0; i < size; i++){
    for(j = 0; j < size - i - 1; j++){
      printf(" ");
    }
    for(j = 0; j < length; j++){
      printf("%c", ch);
    }
    length += 2;
    printf("\n");
  }
  return 1;	
}

int valid_character(char ch){
  if(ch == '*' || ch == '#' || ch == '%'){
    return 1;
  } else {
    return 0;
  }
}

char get_char(){
  char ch;
  scanf("%c", &ch);
  return ch;
    }
