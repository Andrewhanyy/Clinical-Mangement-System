 #ifndef CLINICAL_H
 #define CLINICAL_H
 
 
 typedef struct N
{
   int id ;
   char name[10];
   int age;
   int date;
   char gender[10];
   struct N *next;
}Patient;


static Patient *CreateNode(int id,char *name,int age,char *gender);
void  Add_new_patient (int id,char *name,int age,char *gender);
void Insert_Last(int id,char *name,int age,char *gender);
void View_patient_record(int id);
void Edit_patient_record(int id);

void Display_Reserved_slot(); 
void Reservation (int id);



void cancel_Reservation (int id);

void user_View_todays_reservations();
void user_Display_Reserved_slot();

 #endif //CLINICAL_H