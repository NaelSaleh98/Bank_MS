struct date{
    int day,month,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;
int main_exit;
char temp;
///////////////Prototype////////////////////
void new_acc();
void edit();
void transact();
void see();
void erase();
void view_list();
void close();
///////////////////////////////////////////
// print the menu ^_^
void menu (){
	int choice;
	system("cls");
	system("color 4F");
	printf ("\n\t\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGMENT SYSTEM\n\n");
    printf("\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf ("\t\t\t\t\t1.Create new account.\n");
	printf ("\t\t\t\t\t2.Update information of existing account.\n");
	printf ("\t\t\t\t\t3.For transactions.\n");
	printf ("\t\t\t\t\t4.Check the details of existing account.\n");
	printf ("\t\t\t\t\t5.Removing existing account.\n");
	printf ("\t\t\t\t\t6.View customer\'s list.\n");
	printf ("\t\t\t\t\t7.Exit.\n\n");
	printf ("\n\t\t\t\t\tEnter your choice: ");
	scanf("%d",&choice);
	system("cls");
	
	switch (choice){
		case 1 : new_acc(); 
			break;
		case 2 : edit();
			break;
		case 3 : transact();
			break;
		case 4 : see();
			break;
		case 5 : erase();
			break;
		case 6 : view_list();
			break;
		case 7 : close();
			break;
		default : system("cls");
			printf("\t\t\t\t\tAre you joking -_-");
			exit(1);
	}
}

// for co,pute interset
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}

// make delay
void delay(double j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

// new account
void new_acc(){
	int choice;
	FILE *file;
	file = fopen("record.dat","a+");
	read_again:
		system("cls");
		system("color 4E");		
		printf("\t\t\t\t\t\t\xB2\xB2\xB2 ADD ACCOUNT  \xB2\xB2\xB2\n");
		printf("\n\t\t\t\t\tEnter today's date (dd/mm/yyyy): ");
	    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);
	    
	    printf("\t\t\t\t\tEnter your new account number : ");
	    scanf("%d",&check.acc_no);
	    
	    while(fscanf(file,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
			if (check.acc_no == add.acc_no){
				system("cls");
				system("color 4C");
				printf("\t\t\t\t\tAccount number is already exist!");
				delay(1000000000);
				goto read_again;
			}
		}
		
		add.acc_no=check.acc_no;
		printf("\t\t\t\t\tEnter your name : ");
		scanf("%c",&temp);
		scanf("%[^\n]",add.name);
		printf("\t\t\t\t\tEnter your birthdate : ");
		scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
		printf("\t\t\t\t\tEnter your age : ");
		scanf("%d",&add.age);
		printf("\t\t\t\t\tEnter your address : ");
		scanf("%c",&temp);
		scanf("%[^\n]",add.address);
	    printf("\t\t\t\t\tEnter your citizenship number : ");
    	scanf("%s",add.citizenship);
    	printf("\t\t\t\t\tEnter your phone number : ");
    	scanf("%lf",&add.phone);
    	printf("\t\t\t\t\tEnter the amount to deposit : $");
    	scanf("%f",&add.amt);
    	printf("\n\t\t\t\t\tType of account:\n\t\t\t\t\t\t#Saving\n\t\t\t\t\t\t#Current\n\t\t\t\t\t\t#Fixed1\t(for 1 year)\n\t\t\t\t\t\t#Fixed2\t(for 2 years)\n\t\t\t\t\t\t#Fixed3(for 3 years)\n\n\t\t\t\t\tEnter your choice : ");
    	scanf("%s",add.acc_type);
    	
    	fprintf(file,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    	fclose(file);
    	delay(100000000);
    	system("cls");
    	system("color 4A");
    	printf("\t\t\t\t\tAccount created successfuly!");
    	
    	add_invalid:
		    printf("\n\n\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit : ");
		    scanf("%d",&main_exit);
		    system("cls");
		    if (main_exit==1)
		        menu();
		    else if(main_exit==0)
		            exit(1);
		    else
		        {	system("color 4E");
		            printf("\n\t\t\t\t\tInvalid choice!\a");
		            goto add_invalid;
		        }
}

// edit account
void edit (){
	    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

	printf("\t\t\t\t\tEnter account number : ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\n\t\t\t\t\tWhich information do you want to change?\n\t\t\t\t\t1.Address\n\t\t\t\t\t2.Phone\n\n\t\t\t\t\tEnter your choice : ");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("\t\t\t\t\tEnter the new address : ");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("\t\t\t\t\tChanges saved!");
                }
            else if(choice==2)
                {
                printf("\t\t\t\t\tEnter the new phone number : ");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("\t\t\t\t\tChanges saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    
    if(test!=1)
        {   system("cls");
            printf("\n\t\t\t\t\tRecord not found!!\a\a\a");
            edit_invalid:
              printf("\n\t\t\t\t\tEnter 1 to try again,2 to return to main menu and 3 to exit : ");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==2)

                    menu();
                else if (main_exit==3)
                    close();
                else if(main_exit==1)
                    edit();
                else
                    {printf("\n\t\t\t\t\tInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\n\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

// for transaction
void transact(){
  int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\t\t\t\t\tEnter the account number of the customer : ");
    scanf("%d",&transaction.acc_no);
    
	while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   	{
        if(add.acc_no==transaction.acc_no)
        {   test=1;
            if(strcmp(add.acc_type,"fixed1")==0||strcmp(add.acc_type,"fixed2")==0||strcmp(add.acc_type,"fixed3")==0)
            {
                printf("\a\a\a\n\n\t\t\t\t\tYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                delay(1000000000);
                system("cls");
                menu();

            }
            printf("\n\n\t\t\t\t\tDo you want to\n\t\t\t\t\t\t1.Deposit\n\t\t\t\t\t\t2.Withdraw?\n\n\t\t\t\t\tEnter your choice : ");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("\t\t\t\t\tEnter the amount you want to deposit : $");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n\t\t\t\t\tDeposited successfully!");
                }
                else
                {
                    printf("\t\t\t\t\tEnter the amount you want to withdraw : $");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\n\t\t\t\t\tWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	
	if(test!=1){
    	printf("\n\n\t\t\t\t\tRecord not found!!");
    	transact_invalid:
    	printf("\n\n\n\t\t\t\t\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
    	scanf("%d",&main_exit);
    	system("cls");
    	if (main_exit==0)
    		transact();
    	else if (main_exit==1)
        	menu();
    	else if (main_exit==2)
        	close();
    	else
    	{
        	printf("\n\t\t\t\t\tInvalid!");
        	goto transact_invalid;
    	}

   }
   else{
    	printf("\n\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }
}
// see information
void see (){
	FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("\t\t\t\t\tDo you want to check by\n\t\t\t\t\t\t1.Account no\n\t\t\t\t\t\t2.Name\n\t\t\t\t\tEnter your choice:");
    scanf("%d",&choice);
    
    if (choice==1)
    {   printf("\t\t\t\t\tEnter the account number:");
        scanf("%d",&check.acc_no);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;
                printf("\n\t\t\t\t\tAccount NO.:%d\n\t\t\t\t\tName:%s \n\t\t\t\t\tDOB:%d/%d/%d \n\t\t\t\t\tAge:%d \n\t\t\t\t\tAddress:%s \n\t\t\t\t\tCitizenship No:%s \n\t\t\t\t\tPhone number:%.0lf \n\t\t\t\t\tType Of Account:%s \n\t\t\t\t\tAmount deposited:$ %.2f \n\t\t\t\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                if(strcmp(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmp(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmp(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmp(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\n\t\t\t\t\tYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("\t\t\t\t\tEnter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\n\t\t\t\t\tAccount No.:%d\n\t\t\t\t\tName:%s \n\t\t\t\t\tDOB:%d/%d/%d \n\t\t\t\t\tAge:%d \n\t\t\t\t\tAddress:%s \n\t\t\t\t\tCitizenship No:%s \n\t\t\t\t\tPhone number:%.0lf \n\t\t\t\t\tType Of Account:%s \n\t\t\t\t\tAmount deposited:$%.2f \n\t\t\t\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.day,add.deposit.month,add.deposit.year);
                if(strcmp(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmp(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmp(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmp(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\t\tYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmp(add.acc_type,"current")==0)
                    {

                        printf("\n\n\t\t\t\t\tYou will get no interest\a\a");

                     }

            }
        }
    }
    
    
    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\n\t\t\t\t\tRecord not found!!\a\a\a");
            see_invalid:
              printf("\n\t\t\t\t\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\n\t\t\t\t\tInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\n\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            exit(1);}   
}
void erase(){
	FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\t\t\t\t\tEnter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\n\t\t\t\t\tRecord deleted successfully!\n");
            }
   }
   
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   
   if(test==0)
        {
            printf("\n\t\t\t\t\tRecord not found!!\a\a\a");
            erase_invalid:
              printf("\n\t\t\t\t\tEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\n\t\t\t\t\tInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\n\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit(1);
        }
}

void view_list(){
	FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\n\t\t\t\t\tACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    
    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n\t\t\t\t\t%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
    fclose(view);
    
     if (test==0)
        {   system("cls");
            printf("\n\t\t\t\t\tNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\n\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\n\t\t\t\t\tInvalid!\a");
            goto view_list_invalid;
        }

}

void close (){
	printf("\n\n\n\n\t\t\t\t\tThis C Mini Project is developed by Nael!");
	delay(1000000000);
	exit(1);
}
