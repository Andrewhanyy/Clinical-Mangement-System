#include <stdio.h>

#include "clinical.h"

int main()
{
 int type ,flag ,password,features;
 int program_flag = 1;
   int ident;
   char s[20];
   int ages;
   int date;
   char genders[5];
  while(program_flag == 1)
  {
	  printf ("if you are admin please enter : 1\n");
     printf ("if you are user please  enter : 2\n");
     printf ("Number is : ");
     scanf("%d",&type);
      if(type==1)
      {
         printf("enter you password please : ");
         scanf("%d",&password);
         if(password==1234)
         {
             flag=1;
         }
         else
         {
            for(int i=0;i<2;i++)
            {
              printf("try again : ");
              scanf("%d",&password);
              if(password==1234)
             {
                         flag = 1;
                         break;
             }
            }
        }
	  if(flag==0){
       printf("WRONG PASSWORD");
	  return 0;} 
        if(flag==1)
        {
            int cont = 1;
            while(cont == 1)
            {
                printf("enter  1 to Add new patient record \n");
                printf("enter  2 to Edit patient record \n");
                printf("enter  3 to Reserve a slot with the doctor \n");
                printf("enter  4 to Cancel reservation \n");
                scanf("%d",&features);
                if (features<5)
                {
                    switch (features)
                    {
                        case 1 :

                           printf("Please enter ID \n");
						   scanf("%d",&ident);
						
							
						printf("Enter your name:\n ");    
						scanf("%s",s);
 
						   printf("Please enter  AGE \n");
						   scanf("%d",&ages	);
						   printf("Please enter  GENDER\n");
						  scanf("%s",genders);
                            Add_new_patient (ident,s,ages,genders);

                          break ;

                        case 2 :

						printf("Please enter ID \n");
						   scanf("%d",&ident);
                         Edit_patient_record(ident);

                          break ;

                        case 3 :
						   printf("Please enter ID \n");
						   scanf("%d",&ident);
                           Reservation (ident);

                          break ;

                        case 4 :
                           printf("Please enter ID \n");
						   scanf("%d",&ident);
                        cancel_Reservation (ident);

                          break ;

                    }
                }

                printf("if you want to continue press 1 \n");
                printf("if you want to exist press any button \n");
                scanf("%d",&cont);
                printf("\n");
            }

        }
        else
        {
                printf("#wrong password try agian later#");
        }
      }
      else if(type==2)
      {
           int Logout = 1;
            while(Logout == 1)
            {
				printf("Please enter ID \n");
						   scanf("%d",&ident);
						
                View_patient_record(ident);
			   // printf("View_patient_record()\n");
                printf("if you want to logout press 2 \n");
                printf("if you want to enter id again press 1 \n");
                scanf("%d",&Logout);
                printf("\n");
            }


      }
      else
      {
          printf ("please enter 1 or 2 to login");
      }

    printf("Do you want to login again press: 1 \n");
    printf("if you don't want to exit press any other key\n");
    scanf("%d",&program_flag);
  }


  return 0;

}
