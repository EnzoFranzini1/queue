#include <stdio.h>
#include <stdlib.h>

//The structure of each element in the queue
typedef struct data_structure{
  //Pointers to define the next and the previous element in the queue
  struct data_structure *next, *back;
  //Value of the unique element
  int num;
}data_structure;

//Pointers used to: go through the queue, set the exit element and the entrance element
struct data_structure *chain, *out, *entrance;

int main(){

  //Define the entrance pointer equal to null when the application starts
  entrance = NULL;
  //Variable to get the option input by user
  int op;

  //Flag to maintain the menu looping
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
    case 2:print_queue(print_queue);
    break;
    case 3:remove_element(remove_element);
    break;
    case 0: return 0;
    break;
  }

  goto ini;

  return 0;
}

//Method used to insert the value in the queue element
EnterData(){
  printf("Value (integer): ");
  scanf("%i",&chain -> num);
}

insert(data_structure**List){

  if(entrance == NULL){
    //Create the new queue element
    chain = (data_structure*)malloc(sizeof(data_structure));

    //Set the entrance position to the new element
    entrance = chain;

    //Set the exit position to the new element'
    out = chain;

    //Define the new element links
    chain -> next = NULL;
    chain -> back = NULL;
    EnterData();
  }else{
    //Create a new element in the queue
    chain = (data_structure*)malloc(sizeof(data_structure));

    //Set the new element back pointer to null
    chain -> back = NULL;

    //Link the entrance back pointer to the new element
    entrance -> back = chain;

    //Link the new element next pointer to the entrance pointer
    chain -> next = entrance;

    //Set the entrance pointer to the position of the chain pointer
    entrance = chain;
    EnterData();
  }

}

print_queue(data_structure**List){
  if(entrance == NULL){
    printf("\n\n-----Queue is empty-----\n\n");
  }else{

    //Set the chain pointer position in the entrance pointer position
    chain = entrance;

    printf("\n\n-----Entrance zone-----\n");

    //Looping to print the queue, starting in the queue entrance zone
    while(chain -> next != NULL){
      printf("\n%i", chain -> num);

      //Move the chain pointer to the next element of the queue
      chain = chain -> next;
    }

    //Print the last element in the queue
    printf("\n%i\n\n", chain -> num);
    printf("-----Exit zone-----\n");

    //Returns the chain pointer to the position of the entrance pointer
    chain = entrance;
  }

}

remove_element(data_structure**List){

  if(entrance == NULL){
    printf("\n\n-----Queue is empty-----\n\n");
  }

  //If the queue has more than one element
  if(chain == entrance && chain != out){

    //Move the chain pointer to the exit zone pointer position
    chain = out;

    //Move the chain pointer to the previous element
    chain = chain -> back;

    //Delete the element in the exit zone pointer position
    free(out);

    //Move the out pointer to the chain pointer position
    out = chain;

    //Redefine this element as the new exit pointer
    out -> next = NULL;
  }else{

    //Delete the unique element in the queue
    free(chain);

    //Set the all the pointers to null
    chain = NULL;
    entrance = NULL;
    out = NULL;
  }

}
