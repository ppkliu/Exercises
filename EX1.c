#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//#define rand1   1
#define rand2  1
typedef struct List{
  struct List *next;
  int val;
}List;

void print_list(List* head){
  List* list = head;
  while(list->val){
    printf("%d, ",list->val);
    list = list->next;
  }
}

void free_list(List* list){
  List* next;
  while(list){
    next = list->next;
    free(list); 
    list = next;
  } 

}

void bubblesort(List* list){
  List* bubble = list;
  int temp;
  while(bubble->val){
    while(list->next->val){
      list = list->next;
      if(bubble->val > list->val){
        temp = bubble->val;
        bubble->val = list->val;
        list->val=temp;
      }    
    }
    bubble = bubble->next;
    list = bubble;
  }
}

List* reverse(List* list){
  List* new = (List*)malloc(sizeof(List));
  while(list->val){
    List* next = list->next;
    list->next = new;
    new = list;
    list = next;
  }
  return new;
}
void random1(List* list){
  int random,i;
  List* head = list;
  for(i=1;i<=100;i++){
    random = (rand()%100)+1;
    while(list->next){
      if(random == list->val){
        random = (rand()%100)+1;
        list = head;
        continue;
      }
      list = list->next;
    }
    list->next = (List*)malloc(sizeof(List));
    list->val = random;
    list = head;
  }
}

void random2(List* list){
  int i,j,temp,random;
  List* head = list;
  List* swap = list;
  for(i=1;i<=100;i++){
    list->next = (List*)malloc(sizeof(List));
    list->val = i;
    list = list->next;
  }
  list = head;
  for(i=1;i<=100;i++){
    random = rand()%100+1;
    for(j=0;j<random;j++){
      list = list->next;
    }
    temp = swap->val;
    swap->val = list->val;
    list->val=temp;
    list = head;
    swap = swap->next;
  }
}

int main(){
  List* list = (List*)malloc(sizeof(List));
  srand(time(NULL));
/*everytime random will check whether it has repeated*/
  #ifdef rand1
  random1(list);
  #endif
/*card shuffle alogrithm*/
  #ifdef rand2
  random2(list);
  #endif
  printf("random list: ");
  print_list(list);
  list = reverse(list);
  printf("\n----------\n");
  printf("reverse list: ");
  print_list(list);
  bubblesort(list);
  printf("\n----------\n");
  printf("bubblesort list: ");
  print_list(list);
  printf("\n----------\n");
  free_list(list);
}
