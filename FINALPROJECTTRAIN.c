#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>

typedef struct{
	char name[50];
	int train_num;
	int age;
    int res_num ;
	char gender[20];
	int num_of_seats;
}pd;

void reservation(void);							
void viewdetails(void);							
void cancel(void);
void seatnum();
void cancletrain();
void verify(void);								
void printticket(long int res_num,char name[],int num_of_seats,int age,char gender[],int train_num,float charges);
void specifictrain(int);						
float charge(int,int);
void food (void);							
void user_reg();
void user_login();
void user_info();
void exit_train (void);
int i=0;
struct login
{
  char fname[20];
  char lname[20];
  char username[20];
  char passward[20];
};
struct cancle
{
  char fname[20];
  char lname[20];
  char aadhar[20];
  char age[20];
};
struct seat
{
  char name[20];
  int seatno;
  char aadhar[20];
  char age[20];

};

void main()
{
  int choice;
    system("cls"); 
    system("color 2");
  		
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|           |       DONE BY        |            |\n");
	printf("\t\t|           |     GROUP - 54       |            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");   
	printf("\nPRESS ANY KEY TO CONTINUE:");
	getch();
	printf("\n\nLOADING...........\n\n");
	Sleep(1000);
    start2:
  		system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           1. REGISTER YOUR ACCOUNT            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|           2. LOGIN TO ACCOUNT                 |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|           |       DONE BY        |            |\n");
	printf("\t\t|           |     GROUP - 54       |            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d",&choice);
	printf("\nLOADING...........\n\n");
    Sleep(1000);
  switch (choice)
  {
    case 1 : 
      system("CLS");
      user_reg();
      break;
    case 2 : 
      system("CLS");
      user_login();  
	  break;
	default:
	  printf("\nINVALID CHOICE...");
	  printf("\nPLEASE TRY AGAIN ........\n");
	  Sleep(2000);
      printf("\n\nPRESS ANY KEY TO GO TO FIRST PAGE......");
	  getch();
     goto start2;

  }

  return ;
}
void verify()
{
    FILE *user_log;
    struct login l;
    system("cls");
    ///Reading from file
    user_log=fopen("user_data.txt","rb+");
    if(user_log==NULL)
    {
        printf("\"File not found\"");
        return ;
    }
    while(fread(&l, sizeof(struct login), 1, user_log)){
        system("cls"); 

	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              YOUR DETAILS ARE                 |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   1. YOUR NAME     : %s %s                     \n", l.fname,l.lname);
	printf("\t\t|                                                \n");
	printf("\t\t|   2. YOUR USER ID  : %s                        \n",l.username);
	printf("\t\t|                                                \n");
	printf("\t\t|   3. YOUR PASSWARD : %s                        \n",l.passward);
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
    }
    fclose(user_log);
    printf("PRESS ANY KEY TO CONTINUE...");
    getch();
    system("cls");

}
void start_page()
{
 	int menu_choice,choice_return;
	start:
			system("cls"); 
	printf("\t\t===========================================================================\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|        -----------------------------                                    |\n");
	printf("\t\t|           TRAIN RESERVATION SYSTEM                                      |\n");
	printf("\t\t|        -----------------------------                                    |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|        1. RESERVE A TICKET                6. ORDER YOUR FOOD            |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|        2. CHECK ALL AVAILABLE TRAINS      7. VIEW LOGIN DETAILS         |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|        3. CANCEL RESERVATION              8. EXIT                       |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|        4. GO BACK TO LOGIN                                              |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|        5. GO BACK TO REGISTRATION                                       |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t|                                                                         |\n");
	printf("\t\t===========================================================================\n\n\n");

    printf("\nENTER YOUR CHOICE: ");		
	scanf("%d",&menu_choice);
	printf("\nLOADING...........\n\n");
    Sleep(1000);	
	switch(menu_choice)
	{
		case 1:
			reservation();		
			break;
			goto start;
		case 2:
			viewdetails();
			Sleep(1000);
			printf("\n\nPRESS ANY KEY TO GO TO MAIN MENU......");
			getch();
			system("cls"); 
			break;
		case 3:
            cancel();
			break;
		case 4:
            user_login();
			break;
		case 5:
			user_reg();
			break;
		case 6:
			food();
			break;
		case 7:
            verify();
			break;
			system("cls");
		case 8:
            exit_train();
			return ;
		default:
			printf("\nINVALID CHOICE..");
            Sleep(5000); 
           
	}
	system("cls"); 
    goto start;
}
void user_reg()

{

  char fname[20];
  char lname[20];
  char username[20];
  char passward[20];
    FILE * user_log = fopen("user_data.txt" , "w");
  struct login l ;

	system("cls"); 

	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 1. ENTER YOUR FIRST NAME:                     |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 2. ENTER YOUR LAST NAME:                      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 3. ENTER YOUR USER NAME:                      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 4. ENTER YOUR PASSWARD:                       |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	printf("ENTER YOUR DETAILS :\n");
	printf("\n1:\t");scanf("%s",&l.fname);
	printf("\n2:\t");scanf("%s",&l.lname);
	printf("\n3:\t");scanf("%s",&l.username);
	printf("\n4:\t");scanf("%s",&l.passward);

    fwrite(&l,sizeof(struct login),1,user_log);
    fclose(user_log);
	printf("\nLOADING...........\n");
	Sleep(1000);
  		system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   REGISTRATION SUCCESSFUL...........          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   YOUR USERNAME IS YOUR USER ID               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   NOW LOGIN WITH USER ID AND PASSWARD         |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   PRESS ANY KEY TO CONTINUE...........        |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");

    getch();
	
	printf("\nLOADING...........\n\n");
	Sleep(1000);
    system("CLS");
    verify(); 
    system("CLS");
	user_login();
}


void user_login()
{
  char username[200],passward[20];
  FILE * user_log = fopen("user_data.txt" ,"r");
  struct login l ;

    system("cls"); 

	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   1. YOUR USER ID  :                          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   2. YOUR PASSWARD :                          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	printf("ENTER YOUR DETAILS :\n");		
    printf("\n1: \t");
    scanf("%s",&username);
    printf("\n2: \t");
    scanf("%s",&passward);  
	printf("\nLOADING...........\n");
	Sleep(1000);
  while(fread(&l,sizeof(struct login),1,user_log))
  {
    if (strcmp(username,l.username)==0 && strcmp(passward,l.passward)==0)
    {
      printf("\nLOGIN SUCCESSFUL.........\n");
	  Sleep(1000);
	  system("cls");
	  start_page();

    }
    else
    {
      printf("\nPLEASE ENTER CORRECT USER ID OR PASSWARD\n"); 
	  Sleep(1000);
	  printf("\nPLEASE TRY AGAIN ........\n");
	  Sleep(2000);
	  printf("\nLOADING...........\n\n");
	  Sleep(1000);
	  user_login();

    }
    fclose(user_log);
   }

  }

void viewdetails(void)
{
	system("cls"); 
	printf("=========================================================================================================\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|                               -----------------------------                               \t\t|\n");
	printf("|                                 TRAIN RESERVATION SYSTEM                                  \t\t|\n");
	printf("|                               -----------------------------                               \t\t|\n");
	printf("|                                                                                           \t\t|\n");
	printf("|TRAIN 	TRAIN NAME\t\t\t\tCHARGES\tTYPE\t\tRUN DAYS\tDTIME\tATIME   |\n");
	printf("|                                                                                           \t\t|\n");
	printf("|12267  MUMBAI CENTRAL - AHMEDABAD\t\t1500 RS\tDURONTO\t\tM,T,W,T,F,S,S\t23:25\t05:55   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|12268  AHMEDABAD - MUMBAI CENT\t\t\t1500 RS\tDURONTO\t\tM,T,W,T,F,S,S\t23:40\t06:00   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|22201	KOLKATA SEALDAH - PURI\t\t\t450 RS\tDURONTO\t\tM,W,F\t\t20:00\t04:00   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|22204	SECUNDERABAD - VISAKHAPATNAM\t\t1700 RS\tDURONTO\t\tM,W,S\t\t20:15\t06:35   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|22206	MADURAI - CHENNAI CENTRAL\t\t1300 RS\tDURONTO\t\tTUE,THU\t\t22:40\t07:20   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|12426	JAMMU TAWI - NEW DELHI\t\t\t600 RS\tRAJDHANI\tM,T,W,T,F,S,S\t19:40\t05:05   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|12430	NEW DELHI - LUCKNOW\t\t\t1500 RS\tRAJDHANI\tM,T,F,S\t\t20:50\t06:40   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|12437	SECUNDERABAD - HAZRAT NIZAMUDDIN\t900 RS\tRAJDHANI\tWED\t\t12:45\t10:25   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|12951	MUMBAI CENTRAL - NEW DELHI\t\t1200 RS\tRAJDHANI\tM,T,W,T,F,S,S\t16:35\t08:35   |\n");
	printf("|                                                                                           \t\t|\n");
    printf("|12953	MUMBAI CENT - HAZRAT NIZAMUDDIN\t\t1400 RS\tRAJDHANI\tM,T,W,T,F,S,S\t17:40\t10:55   |\n");
	printf("|                                                                                           \t\t|\n");
	printf("=========================================================================================================\n");

	
}
void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");

	system("cls");
	
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 1. ENTER YOUR NAME:                           |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 2. ENTER NUMBER OF SEATS:                     |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 3. ENTER YOUR AGE:                            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 4. ENTER YOUR GENDER:                         |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 5. PRESS ENTER TO VIEW AVAILABLE TRAINS:      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	fflush(stdin);
    printf("\n1:\t");scanf("%s",&passdetails.name);

	printf("\n2: \t");scanf("%d",&passdetails.num_of_seats);
	
	printf("\n3: \t");scanf("%d",&passdetails.age);

	printf("\n4: \t");scanf("%s",&passdetails.gender);

	printf("\n5: \t");
	getch();
	system("cls");
	viewdetails();
	Sleep(2000);
	printf("\n\n 1. ENTER TRAIN NUMBER:   ");scanf("%d",&passdetails.train_num);
	Sleep(2000);
    user_info();
    Sleep(2000);
	seatnum();
	start1:
	if(passdetails.train_num==12267)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==12268)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==22201)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==22204)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==22206)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==12426)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==12430)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==12437)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==12951)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else if(passdetails.train_num==12953)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nINVALID TRAIN NUMBER !\n \n ENTER AGAIN ");
		goto start1;
	}

	printf("\n\nCONFIRM TICKET (y/n):");
	
	start:
	scanf(" %c",&confirm);
	Sleep(1000);
	if(confirm == 'y')
	{
		fprintf(fp,"%ld\t\t%s\t\t%d\t\t%d\t\t%s\t\t%d\t\t%.2f\n",&passdetails.res_num,passdetails.name,passdetails.num_of_seats,passdetails.age,passdetails.gender,passdetails.train_num,charges);
		Sleep(1000);
		printf("==================");
		printf("\n RESERVATION DONE ....\n");
		printf("==================");
		printf("\nLOADING...........\n\n");
		printf("\nPRESS ANY KEY TO GO BACK TO MAIN MENU..");
		
	}
	else
	{
		if(confirm=='n'){
			printf("\nRESERVATION NOT DONE!\nPRESS ANY KEY TO GO BACK TO MAIN MENU..!");
		}
		else
		{
			printf("\nINVALID CHOICE ENTERED !\n\n ENTER AGAIN.. ");
			goto start;
		}
	}
	fclose(fp);
    getch();	
}

/*********************************************TRAIN CHARGE()*************************************************/

float charge(int train_num,int num_of_seats)
{
		if (train_num==12267)
	{
		return(1500.0*num_of_seats);
	}
	if (train_num==12268)
	{
		return(1500.0*num_of_seats);
	}
	if (train_num==22201)
	{
		return(450.0*num_of_seats);
	}
	if (train_num==22204)
	{
		return(1700.0*num_of_seats);
	}
	if (train_num==22206)
	{
		return(1300.0*num_of_seats);
	}
	if (train_num==12426)
	{
		return(600.0*num_of_seats);
	}
	if (train_num==12430)
	{
		return(1500.0*num_of_seats);
	}
	if (train_num==12437)
	{
		return(900.0*num_of_seats);
	}
	if (train_num==12951)
	{
		return(1200.0*num_of_seats);
	}
	if (train_num==12953)
	{
		return(1400.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(long int res_num,char name[],int num_of_seats,int age,char gender[],int train_num,float charges)
{    res_num = train_num *10 + num_of_seats*1000 + age;
	system("cls");
		printf("\t\t============================================================\n");
	printf("\t\t|                                                              |\n");
	printf("\t\t|        -----------------------------                         |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM                          |\n");
	printf("\t\t|        -----------------------------                         |\n");
	printf("\t\t|                                                              |\n");
    printf("\t\t|                        TICKET                                |\n");
	printf("\t\t|                                                              |\n");
	printf("\t\t|   RESERVATION NUMBER %ld                                      \n",res_num);	
	printf("\t\t|                                                               \n");
	printf("\t\t| 1.NAME           : %s                                         \n",name);
	printf("\t\t|                                                               \n");
	printf("\t\t| 2.NUMBER OF SEATS: %d                                         \n",num_of_seats);
	printf("\t\t|                                                               \n");
	printf("\t\t| 1.AGE            : %d                                         \n",age);
	printf("\t\t|                                                               \n");
	printf("\t\t| 2.GENDER         : %s                                         \n",gender);
	printf("\t\t|                                                               \n");
	printf("\t\t| 3.TRAIN NUMBER   : %d                                         \n",train_num);
	printf("\t\t|                                                               \n");
	specifictrain(train_num);
	printf("\t\t| 7.CHARGES        : %.2f                                       \n",charges);
	printf("\t\t|                                                              |\n");
	printf("\t\t|    PLEASE NOTE ALL THE DETAILS YOU ENTERED......             |\n");
	printf("\t\t|                                                              |\n");
	printf("\t\t|                        IT IS USED TO CANCLE YOU TICKET....   |\n");
	printf("\t\t================================================================\n\n\n");

    printf("\nPRESS ANY KEY TO CONTINUE..");
    getch();
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{
	
	if (train_num==12267)
	{	printf("\t\t| 4.TRAIN          : MUMBAI CENTRAL - AHMEDABAD AC DURONTO EXP \n");
	    printf("\t\t| 5.DESTINATION    : MUMBAI CENTRAL TO AHMEDABAD               \n");
	    printf("\t\t| 6.DEPARTURE TIME : 23:25                                     \n");
		
	}
	if (train_num==12268)
	{
		printf("\t\t| 4.TRAIN          : AHMEDABAD - MUMBAI CENT AC DURONTO EXP    \n");
	    printf("\t\t| 5.DESTINATION    : AHMEDABAD TO MUMBAI CENTRAL               \n");
	    printf("\t\t| 6.DEPARTURE TIME : 23:40                                     \n");
	}
	if (train_num==22201)
	{
		printf("\t\t| 4.TRAIN          : KOLKATA SEALDAH - PURI DURONTO EXPRESS    \n");
	    printf("\t\t| 5.DESTINATION    : KOLKATA SEALDAH TO PURI                   \n");
	    printf("\t\t| 6.DEPARTURE TIME : 20:00                                     \n");
	}
	if (train_num==22204)
	{
		printf("\t\t| 4.TRAIN          : SECUNDERABAD - VISAKHAPATNAM DURONTO EXP  \n");
	    printf("\t\t| 5.DESTINATION    : SECUNDERABAD TO  VISAKHAPATNAM            \n");
	    printf("\t\t| 6.DEPARTURE TIME : 20:15                                     \n");
	}
	if (train_num==22206)
	{
		printf("\t\t| 4.TRAIN          : MADURAI - CHENNAI CENTRAL AC DURONTO EXP  \n");
	    printf("\t\t| 5.DESTINATION    : MADURAI TO CHENNAI CENTRAL                \n");
	    printf("\t\t| 6.DEPARTURE TIME : 22:40                                     \n");
	}
	if (train_num==12426)
	{
		printf("\t\t| 4.TRAIN          : JAMMU TAWI - NEW DELHI RAJDHANI EXPRESS   \n");
	    printf("\t\t| 5.DESTINATION    : JAMMU TO NEW DELHI                        \n");
	    printf("\t\t| 6.DEPARTURE TIME : 19:40                                     \n");
	}
	if (train_num==12430)
	{
		printf("\t\t| 4.TRAIN          : NEW DELHI - LUCKNOW AC SF EXPRESS         \n");
	    printf("\t\t| 5.DESTINATION    : NEW DELHI TO LUCKNOW                      \n");
	    printf("\t\t| 6.DEPARTURE TIME : 20:50                                     \n");
	}
	if (train_num==12437)
	{
		printf("\t\t| 4.TRAIN          : SECUNDERABAD - HAZRAT NIZAMUDDIN EXP      \n");
	    printf("\t\t| 5.DESTINATION    : SECUNDERABAD TO HAZRAT NIZAMUDDIN         \n");
	    printf("\t\t| 6.DEPARTURE TIME : 12:45                                     \n");
	}
	if (train_num==12951)
	{
		printf("\t\t| 4.TRAIN          : MUMBAI CENTRAL - NEW DELHI RAJDHANI EXP   \n");
	    printf("\t\t| 5.DESTINATION    : MUMBAI CENTRAL TO NEW DELHI               \n");
	    printf("\t\t| 6.DEPARTURE TIME : 16:35                                     \n");
	}
	if (train_num==12953)
	{
		printf("\t\t| 4.TRAIN          : MUMBAI CENT - HAZRAT NIZAMUDDIN KRANTI EXP\n");
	    printf("\t\t| 5.DESTINATION    : MUMBAI CENTRAL TO HAZRAT NIZAMUDDIN       \n");
	    printf("\t\t| 6.DEPARTURE TIME : 17:40                                     \n");
	}
}

void food (void)
{
    int water, snacks, lunch,breakfast,bill,dinner;
	system("cls");
	printf("\t\t=================================================================\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t|        -----------------------------                          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM                           |\n");
	printf("\t\t|        -----------------------------                          |\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t|         YOUR SAFETY IS OUR PRIORITY..                         |\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t| EVERY THING IS WELL SANITIZED AND COOKED IN A CLEAN AREA      |\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t| NOTE : EVERY THING WILL BE SERVED AT THEIR RESPECTIVE TIME    |\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t|    AVAILABLE MEALS                         COST(PER)          |\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t| 1. MINERAL WATER(ANY TIME) :               RS. 20/-           |\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t| 2. BREAKEFAST (8:00)       :               RS. 100/-          |\n");
	printf("\t\t|     CONTAINS :                                                |\n");
	printf("\t\t|       a. IDLY                                                 |\n");
	printf("\t\t|       b. SAMBAR                                               |\n");
	printf("\t\t|       c. CHUTNEY                                              |\n");
	printf("\t\t| 3. LUNCH  (12:00)          :               RS. 300/-          |\n");
	printf("\t\t|     CONTAINS :                                                |\n");
	printf("\t\t|       a. RICE                                                 |\n");
	printf("\t\t|       b. BIRYANI                                              |\n");
	printf("\t\t|       c. THREE CURRIES                                        |\n");
	printf("\t\t|       d. CURD                                                 |\n");
	printf("\t\t| 4. DINNER (20:00)          :               RS. 300/-          |\n");
	printf("\t\t|     CONTAINS :                                                |\n");
	printf("\t\t|       a. RICE                                                 |\n");
	printf("\t\t|       b. BIRYANI                                              |\n");
	printf("\t\t|       c. THREE CURRIES                                        |\n");
	printf("\t\t|       d. CURD                                                 |\n");	
	printf("\t\t|                                                               |\n");
	printf("\t\t| 5. SNACKS (ANY TIME)       :               RS. 50/-           |\n");
	printf("\t\t|     CONTAINS :                                                |\n");
	printf("\t\t|       a. SAMOSA                                               |\n");
	printf("\t\t|       b. CHUTNEY                                              |\n");
	printf("\t\t|                                                               |\n");
	printf("\t\t=================================================================\n\n\n");
    printf("\t ENTER THE QUANTITY YOU NEED OR SIMPLE ENTER 0 \n");

    printf("\t\n1. ");scanf("%d",&water);
    printf("\t\n2. ");scanf("%d",&breakfast);
	printf("\t\n3. ");scanf("%d",&lunch);
	printf("\t\n4. ");scanf("%d",&dinner);
	printf("\t\n5. ");scanf("%d",&snacks);

    bill = water*20 + snacks*100 + breakfast*100 + lunch*300+ dinner*300;
    printf("\n TOTAL Bill = %d", bill );
    Sleep(5000);
    printf("\n\nPRESS ANY KEY TO GO TO MAIN MENU......");
	getch();
}

void cancel(void)  
{

    int trainno;
	int age1;
    long int res_num1 ;
    char name1[20];
	int num_of_seats1; 
    char gender1[20];
    res_num1 = trainno *10+ num_of_seats1*1000 + age1; 
	system("cls");
	
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 1. ENTER YOUR NAME:                           |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 2. ENTER NUMBER OF SEATS:                     |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 3. ENTER YOUR AGE:                            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 4. ENTER YOUR GENDER:                         |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
    printf("\n1:\t");scanf("%s",&name1);

	printf("\n2: \t");scanf("%d",&num_of_seats1);
	
	printf("\n3: \t");scanf("%d",&age1);

	printf("\n4: \t");scanf("%s",&gender1);

	system("cls");
	printf("\t\t============================================================\n");
	printf("\t\t|                                                              |\n");
	printf("\t\t|        -----------------------------                         |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM                          |\n");
	printf("\t\t|        -----------------------------                         |\n");
	printf("\t\t|                                                              |\n");
    printf("\t\t|               CHECK YOU DETAILS ENTERED                      |\n");
	printf("\t\t|                                                              |\n");	
	printf("\t\t|                                                               \n");
	printf("\t\t| 1.NAME           : %s                                         \n",name1);
	printf("\t\t|                                                               \n");
	printf("\t\t| 2.NUMBER OF SEATS: %d                                         \n",num_of_seats1);
	printf("\t\t|                                                               \n");
	printf("\t\t| 1.AGE            : %d                                         \n",age1);
	printf("\t\t|                                                               \n");
	printf("\t\t| 2.GENDER         : %s                                         \n",gender1);
	printf("\t\t|                                                               \n");
	printf("\t\t|                                                              |\n");
 	printf("\t\t================================================================\n\n\n"); 
    Sleep(5000);
	cancletrain();
    printf("\nLOADING...........\n\n");
    Sleep(5000);
}
void exit_train (void)
{   
    system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|           THANK YOU.....                      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                HAPPY JOURNEY......            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                        GOOD LUCK......        |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|           |       DONE BY        |            |\n");
	printf("\t\t|           |     GROUP - 54       |            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");  

    return ;
}

void user_info()
{
  char fname[20];
  char lname[20];
  char aadhar[20];
  char age[20];
    FILE * user_info = fopen("user_info.txt" , "w");
    struct cancle c ;
	system("cls"); 

	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 1. ENTER YOUR FIRST NAME:                     |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 2. ENTER YOUR LAST NAME:                      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 3. ENTER YOUR AADHAR NUMBER:                  |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 4. ENTER YOUR AGE:                            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	printf("ENTER YOUR DETAILS :\n");
	printf("\n1:\t");scanf("%s",&c.fname);
	printf("\n2:\t");scanf("%s",&c.lname);
	printf("\n3:\t");scanf("%s",&c.aadhar);
	printf("\n4:\t");scanf("%s",&c.age);

    fwrite(&c,sizeof(struct cancle),1,user_info);
    fclose(user_info);
	printf("\nLOADING...........\n");
	Sleep(1000);
  		system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   RESERVATION IN PROCESS ...........          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   YOUR AADHAR IS USED TO CANCLE YOUR TICKET   |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   PRESS ANY KEY TO CONTINUE...........        |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");

    getch();
	
	printf("\nLOADING...........\n\n");
	Sleep(1000);

}

void cancletrain()
{
  char fname[20];
  char lname[20];
  char aadhar[20];
  char age[20];
  FILE * user_info = fopen("user_info.txt" ,"r");
  struct cancle c ;

    system("cls"); 

	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   1. YOUR AADHAR NUMBER :                     |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   2. YOUR AGE :                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	printf("ENTER YOUR DETAILS :\n");		
    printf("\n1: \t");
    scanf("%s",&aadhar);
    printf("\n2: \t");
    scanf("%s",&age);  
	printf("\nLOADING...........\n");
	Sleep(1000);

  while(fread(&c,sizeof(struct cancle),1,user_info))
  {
    if (strcmp(aadhar,c.aadhar)==0 && strcmp(age,c.age)==0)
    {
      printf("\nCANCLE SUCCESSFUL.........\n");
	  Sleep(1000);
	  system("cls");

    }
    else
    {
      printf("\nPLEASE ENTER CORRECT AADHAR NUMBER AND AGE\n"); 
	  Sleep(1000);
	  printf("\nPLEASE TRY AGAIN ........\n");
	  Sleep(2000);
	  printf("\nLOADING...........\n\n");
	  Sleep(1000);
      cancletrain();
    }
    fclose(user_info);
   }

}

void seatnum()
{

  char name[20];
  int seatno;
  int aadhar[20];
  int age[20];
  int numseats;
  int choice1;
  int i;
    FILE * user_seat = fopen("user_seat.txt" , "a");
  struct seat s ;
  start3:
    system("CLS");
 	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|  SELECT IN WHICH CLASS DO YOU WANT A SEAT     |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   1. FIRST CLASS (AC)                         |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|   2. SECOND CLASS (NON-AC)                    |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n"); 
	printf("\nENTER YOUR CHOICE :\n");scanf("%d",&choice1);
  switch (choice1)
  {
    case 1 : 
      system("CLS");
    printf("\t\t===============================================================================================\n");
	printf("\t\t|                                                                                             |\n");
	printf("\t\t|        -----------------------------                                                        |\n");
	printf("\t\t|           TRAIN RESERVATION SYSTEM                                                          |\n");
	printf("\t\t|        -----------------------------                                                        |\n");
	printf("\t\t|                                                                                             |\n");
	printf("\t\t|      AVAILABLE SEATS IN SL-22                                                               |\n");
	printf("\t\t|                                                                                             |\n");
	printf("\t\t|    -------------------------------------------------------------------------------------    |\n");
	printf("\t\t|    |   | ! |    | 4 |   |   | ! |    | 12|   |   | ! |    | 20|   |   | 25|    | 28|   |    |\n");
	printf("\t\t|    |                    |                    |                    |                    |    |\n");
	printf("\t\t|    |   | ! |    | ! |   |   | 10|    | ! |   |   | 18|    | 21|   |   | 26|    | ! |   |    |\n");
	printf("\t\t|    |                    |                    |                    |                    |    |\n");
	printf("\t\t|    |   | 3 |    | 6 |   |   | 11|    | ! |   |   | 19|    | 22|   |   | ! |    | ! |   |    |\n");
	printf("\t\t|    |                    |                    |                    |                    |    |\n");
	printf("\t\t|    |-----------------------------------------------------------------------------------|    |\n");
	printf("\t\t|    |                    |                    |                    |                    |    |\n");
	printf("\t\t|    |   | ! |    | 8 |   |   | ! |    | ! |   |   | ! |    | 24|   |   | ! |    | 32|   |    |\n");
	printf("\t\t|    |                    |                    |                    |                    |    |\n");
	printf("\t\t|    -------------------------------------------------------------------------------------    |\n");
	printf("\t\t|                                                                                             |\n");
	printf("\t\t|                                                                                             |\n");
	printf("\t\t|                                                                                             |\n");
	printf("\t\t===============================================================================================\n\n\n");
    printf("\n\nPLEASE REMEMBER AVAILABLE SEATS AND ENTER IN NEXT STEPS:\n");
	Sleep(5000);
        printf("\n\nPRESS ANY KEY TO CONTINUE......");
	getch();
    system("cls"); 

	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 1. ENTER YOUR NAME:                           |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 2. ENTER YOUR AADHAR NUMBER:                  |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 3. ENTER YOUR SEAT NUMBER:                    |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 4. ENTER YOUR AGE:                            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");

	printf("ENTER NUMBER OF SEATS DO YOU WANT :\n");scanf("%d",&numseats);
    for(i=0;i<=numseats-1;i=i+1)
	{
	printf("ENTER DETAILS :\n");
	printf("\n1:\t");scanf("%s",&s.name);
	printf("\n2:\t");scanf("%d",&s.aadhar);
	printf("\n3:\t");scanf("%d",&s.seatno);
    if (seatno == 3||4||6||8||10||11||12||18||19||20||21||22||23||24||25||26||28||32 )
    {
     printf("SEAT RESERVED FOR YOU"); 

    }
    else{
       printf("SEAT IS NOT AVAILABLE\n"); 
    }
	printf("\n4:\t");scanf("%d",&s.age);
     }
	 fwrite(&s,sizeof(struct seat),1,user_seat);
	  break;

    case 2 : 
      system("CLS");
		printf("\t\t===============================================================================================\n");
	    printf("\t\t|                                                                                             |\n");
	    printf("\t\t|        -----------------------------                                                        |\n");
	    printf("\t\t|           TRAIN RESERVATION SYSTEM                                                          |\n");
	    printf("\t\t|        -----------------------------                                                        |\n");
	    printf("\t\t|                                                                                             |\n");
	    printf("\t\t|      AVAILABLE SEATS IN AC-3                                                                |\n");
	    printf("\t\t|                                                                                             |\n");
	    printf("\t\t|    -------------------------------------------------------------------------------------    |\n");
	    printf("\t\t|    |   | ! |    | 4 |   |   | ! |    | 12|   |   | ! |    | 20|   |   | 25|    | 28|   |    |\n");
	    printf("\t\t|    |                    |                    |                    |                    |    |\n");
	    printf("\t\t|    |   | 2 |    | ! |   |   | 10|    | 13|   |   | 18|    | 21|   |   | 26|    | ! |   |    |\n");
	    printf("\t\t|    |                    |                    |                    |                    |    |\n");
	    printf("\t\t|    |   | ! |    | ! |   |   | ! |    | ! |   |   | ! |    | 22|   |   | ! |    | ! |   |    |\n");
	    printf("\t\t|    |                    |                    |                    |                    |    |\n");
	    printf("\t\t|    |-----------------------------------------------------------------------------------|    |\n");
	    printf("\t\t|    |                    |                    |                    |                    |    |\n");
	    printf("\t\t|    |   | 7 |    | 8 |   |   | ! |    | 16|   |   | ! |    | 24|   |   | ! |    | 32|   |    |\n");
	    printf("\t\t|    |                    |                    |                    |                    |    |\n");
	    printf("\t\t|    -------------------------------------------------------------------------------------    |\n");
	    printf("\t\t|                                                                                             |\n");
	    printf("\t\t|                                                                                             |\n");
	    printf("\t\t|                                                                                             |\n");
	    printf("\t\t===============================================================================================\n\n\n");
		printf("\n\nPLEASE REMEMBER AVAILABLE SEATS AND ENTER IN NEXT STEPS:\n");
        printf("\n\nPRESS ANY KEY TO CONTINUE......");
	    getch();
        Sleep(5000);
    system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 1. ENTER YOUR NAME:                           |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 2. ENTER YOUR AADHAR NUMBER:                  |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 3. ENTER YOUR SEAT NUMBER:                    |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t| 4. ENTER YOUR AGE:                            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");

	printf("ENTER NUMBER OF SEATS DO YOU WANT :\n");scanf("%d",&numseats);
    for(i=0;i<=numseats-1;i=i+1)
	{
	printf("ENTER DETAILS :\n");
	printf("\n1:\t");scanf("%s",&s.name);
	printf("\n2:\t");scanf("%d",&s.aadhar);
	printf("\n3:\t");scanf("%d",&s.seatno);
    if (seatno == 2||7||4||8||10||16||12||18||13||20||21||22||24||25||26||28||32 )
    {
     printf("SEAT RESERVED FOR YOU"); 

    }
    else{
       printf("SEAT IS NOT AVAILABLE\n"); 
    }
	printf("\n4:\t");scanf("%s",&s.age);
    } 
	fwrite(&s,sizeof(struct seat),1,user_seat);    
	  break;
	default:
	  printf("\nINVALID CHOICE...");
	  printf("\nPLEASE TRY AGAIN ........\n");
	  Sleep(2000);
      printf("\n\nPRESS ANY KEY TO GO TO FIRST PAGE......");
	  getch();
     goto start3;
      
    }
	fclose(user_seat);
	  printf("\nLOADING...........\n\n");
	  Sleep(1000);
}


