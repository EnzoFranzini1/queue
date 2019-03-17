#include <stdio.h>
#include <stdlib.h>

typedef struct data_structure{

  struct data_structure *next, *back;
  int num;
}data_structure;

struct data_structure *chain, *out, *entrance;

int main(){
  entrance = NULL;
  int op;

  ini:

  printf("\n[1] - Insert");
  printf("\n[2] - Print queue");
  printf("\n[3] - Remove");
  printf("\n[0] - Close");
  printf("\nChoose an option: ");
  scanf("%i", &op);

  switch (op){
    case 1:insert(insert);
    break;
    case 2:
    break;
    case 3:
    break;
    case 0: return 0;
    break;
  }

  goto ini;

  return 0;
}

EnterData(){
  printf("Value (integer): ");
  scanf("%i",&chain->num);
}

insert(data_structure**List){

  if(entrance == NULL){
    chain = (data_structure*)malloc(sizeof(data_structure));
    entrance = chain;
    out = chain;
    chain -> next = NULL;
    chain -> back = NULL;
    EnterData();
  }else{
    chain = (data_structure*)malloc(sizeof(data_structure));
    chain -> back = NULL;
    entrance -> back = chain;
    chain -> next = entrance;
    entrance = chain;
    EnterData();
  }

}
