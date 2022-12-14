#include<stdio.h>
#include<stdlib.h>
#include"clinical.h"


 Patient *head = NULL;
 Patient *tail = NULL;
 

int time_slot_arr[5] = {0,0,0,0,0};

static Patient *CreateNode(int id,char *name,int age,char *gender)
{
	Patient *ptr=(Patient *)malloc(sizeof(Patient));
	
	ptr->id=id;
		
	for(int i=0;i<20;i++){
		ptr->name[i]=name[i];
	}
	ptr->age=age;
    for(int i=0;i<5;i++){
		ptr->gender[i]=gender[i];
	}
		return ptr;
}

void Insert_Last(int id,char *name,int age,char *gender)
{
	Patient *NewNode = CreateNode(id, name,age, gender);
	
	if(head == NULL)
		head = NewNode;
	else
		tail->next=NewNode;
	tail = NewNode;
	tail->next=NULL;
}

 void  Add_new_patient (int id,char *name,int age,char *gender)
{
	
    Patient *current = head;
	if(head == NULL) {
		Insert_Last( id, name,age, gender);
	}
	while(current !=NULL)
	{
		if (current->id == id){
			printf("There is a user with same id \n ");
			return;
			}
			
			else {
			current=current->next;
			
			}
		
		
	}
	Insert_Last( id, name,age, gender);
	
 
 return ;
}

void View_patient_record(int id)
{
	 Patient *current = head;
	if(head == NULL) { printf ("NO Patients There");}
	while(current !=NULL)
	{
		if (current->id == id){
			printf("The ID is %d\n ",current->id);
			printf("The name is %s\n ",current->name);
			printf("The age is %d \n ",current->age);
			printf("The gender is %s\n ",current->gender);
			return;
			}
			
			else {
			current=current->next;
			
			}
		
		
	}
	printf ("This Id is not registered yet \n");
	
}


void Edit_patient_record(int id)
{
	Patient *current = head;
   char edited_name[10];
   int edited_age;

   char edited_gender[5];
	if(head == NULL) { printf ("NO Patients There");}
	while(current !=NULL)
	{
		if (current->id == id){
			printf("Edit name is \n ");
			scanf("%s",edited_name);
			printf("Edit age is \n ");
			scanf("%d",&edited_age);
			printf("Edit gender is \n ");
			scanf("%s",edited_gender);
			//current->name=edited_name;
			for(int u=0;u<10;u++){
				current->name[u]=edited_name[u];
			}
			current->age=edited_age;
			for(int u=0;u<5;u++){
				current->gender[u]=edited_gender[u];
			}
			return;
			}
			
			else {
			current=current->next;
			
			}
		
		
	}
	printf ("This Id is not registered yet \n");

}

void Reservation (int id)
{
	  int choice;
	   Patient *current = head;
	if(head == NULL) { printf ("NO Patients There");
	return ;
	}
 while(current !=NULL)
	{
		if (current->id == id){
			if(time_slot_arr[0]==1&&time_slot_arr[1]==1&&time_slot_arr[2]==1&&time_slot_arr[3]==1&&time_slot_arr[4]==1){
				printf("THERE IS NO APPOINTMENTS SORRY \n");
			return ;
			}
			printf("choose slot please \n");
      Display_Reserved_slot();
      scanf("%d",&choice);
      if(time_slot_arr[choice-1] == 0)
      {
        time_slot_arr[choice-1] = 1;
		printf("Rserved \n");
        // the date is the time slot number
        current->date = choice;
      }
			return;
			}
			
			else {
			current=current->next;
			
			}
		
		
	}
		printf ("This Id is not registered yet \n");
}


void Display_Reserved_slot()
{
    if(time_slot_arr[0] == 0)
    {
        printf("For appointment from 2pm to 2:30pm => choose 1 \n");
    }
        if(time_slot_arr[1] == 0)
    {
        printf("for appointment from 2:30pm to 3pm => choose 2 \n");
    }
        if(time_slot_arr[2] == 0)
    {
        printf("for appointment from 3pm to 3:30pm => choose 3 \n");
    }
        if(time_slot_arr[3] == 0)
    {
        printf("for appointment from 3:30pm to 4pm => choose 4 \n");
    }
        if(time_slot_arr[4] == 0)
    {
        printf("for appointment from 4pm to 4:30pm => choose 5 \n");
    }
	if(time_slot_arr[0]==1&&time_slot_arr[1]==1&&time_slot_arr[2]==1&&time_slot_arr[3]==1&&time_slot_arr[4]==1) printf("THERE IS NO APPOINTMENTS SORRY \n");
}


void cancel_Reservation (int id)
{
	 int choice;
     Patient *current = head;
	if(head == NULL) { printf ("NO Patients There");
	return ;
	}
 while(current !=NULL)
	{
		if (current->id == id){
			choice=current->date;
            time_slot_arr[choice-1] =0 ;
      printf ("********Reservation is CANCELLED \n");
       return;
      }
			
				
			
			else {
			current=current->next;
			
			}
		
		
	}
		printf ("This Id is not registered yet \n");
}


