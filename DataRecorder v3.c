#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>

main(){
	
	SMALL_RECT windowSize = {0 , 0 , 80 , 20}; //change the values
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
	
	char login[20];
	MasterStart:
	system("cls");
	system("color 9");
	printf("#_____________________________DATA RECORDER V1.0________________________________#");
	printf("                                                         (FOR PASSWORD PLEASE LOOK AT ON SOURCE CODE )");
	printf("\n\n\n\n");
	printf("$-----------ENTER MASTER PASSWORD TO LOGIN INTO PROGRAM: ");
	
	scanf("%s",&login);
	if(strcmp(login,"basant123")!=0){
		
		printf("\nCHECKING...");
		sleep(1);
		goto MasterStart;
		
	}else{
	
		printf("\nCHECKING...");
		sleep(1);
	
	FILE *FilePointer;
	
	struct customer{
		
		char name[20];
		char address[20];
		char phone[20];
		char password[20];
		char newpassword[20];
		char delete_record[20];
		
	}add,check;
	
		char option[20];
		start:
		system("cls");
		system("title DATA RECORDER V1.0 ## DEVELOPED BY BASANT KARKI ##");
		system("color 9");
		printf("#_____________________________DATA RECORDER V1.0________________________________#");
		printf("\n");
		printf("\n$---------------------------PRESS [1] TO CREATE ACCOUNT");
		printf("\n$---------------------------PRESS [2] FOR VIEW PERSONAL ACCOUNT DETAILS");
		printf("\n$---------------------------PRESS [3] FOR DELETE YOUR RECORD");
		printf("\n$---------------------------PRESS [4] TO KNOW ABOUT US");
		printf("\n");
		printf("\n$---------------------------ENTER YOUR OPTION: ");	
		scanf("%s",option);
		if(strcmp(option,"1")==0){
			
			
			FilePointer = fopen("CustomerRecord.dat","a+");
			system("cls");
			printf("#_____________________________DATA RECORDER V1.0________________________________#");
			printf("\n");
			printf("\n$---------PLEASE ENTER YOUR NAME: ");
			scanf("%s",&add.name);
			printf("\n$---------PLEASE ENTER YOUR PERMANENT ADDRESS: ");
			scanf("%s",&add.address);
			printf("\n$---------PLEASE ENTER YOUR PHONE NUMBER: ");
			scanf("%s",&add.phone);
			printf("\n$---------PLEASE ENTER YOUR STRONG PASSWORD: ");
			scanf("%s",&add.password);
			while(fprintf(FilePointer,"%s %s %s %s\n",&add.name,&add.address,&add.phone,&add.password)!=EOF){
				fclose(FilePointer);
				printf("\n");
				printf("PLEASE WAIT, YOUR PERSONAL DATA ARE STORING ON SERVER..........");
				sleep(3);
				system("cls");
				printf("#_____________________________DATA RECORDER V1.0________________________________#");
				printf("\n");
				printf("\n!!DONE!!");
				sleep(1);
				goto start;
			}
			
		}else if(strcmp(option,"2")==0){
			
			password:
			system("cls");
			FilePointer = fopen("CustomerRecord.dat","r");
			printf("#_____________________________DATA RECORDER V1.0________________________________#");
			printf("\n");
			printf("\n$-----DEAR CUSTOMER, PLEASE ENTER YOUR PERSONAL PASSWORD: ");
			scanf("%s",&check.newpassword);
			printf("\nCHECKING...");
			sleep(1);
			while(fscanf(FilePointer,"%s %s %s %s\n",add.name,&add.address,&add.phone,&add.password)!=EOF){
				if(strcmp(check.newpassword,add.password)==0){
					
					
					system("cls");
					printf("#_____________________________DATA RECORDER V1.0________________________________#");
					printf("\n");
					printf("\nNAME: %s",add.name);
					printf("\nADDRESS: %s",add.address);
					printf("\nPHONE NUMBER: %s",add.phone);
					printf("\nPASSWORD: %s",add.password);
					system("pause>nul");
					goto start;
				}
				
			
			}goto password;
			
			
		}else if(strcmp(option,"3")==0){
			
				FILE *NewFilePointer;
				NewFilePointer = fopen("newRecord.dat","w");
					FilePointer = fopen("CustomerRecord.dat","r");
					system("cls");
					_delete:
					printf("#_____________________________DATA RECORDER V1.0________________________________#");
					printf("\n");
					printf("\n$-------PLEASE ENTER YOUR PASSWORD FIRST: ");
					scanf("%s",&check.delete_record);
					while(fscanf(FilePointer,"%s %s %s %s\n",add.name,&add.address,&add.phone,&add.password)!=EOF){
						if(strcmp(check.delete_record,add.password)!=0){
							
							fprintf(NewFilePointer,"%s %s %s %s\n",add.name,&add.address,&add.phone,&add.password);	
								
						}
						
						
					}	fclose(FilePointer);
						fclose(NewFilePointer);
						remove("CustomerRecord.dat");
						rename("newRecord.dat","CustomerRecord.dat");
						system("cls");
						printf("#_____________________________DATA RECORDER V1.0________________________________#");
						printf("\n\n\n\n");
						printf("    IF THERE IS ANY DATA RECORD RELETED THIS PASSWORD, IT WILL BE DELETED!!");
						sleep(4);
						goto start;
			
		}else if(strcmp(option,"4")==0){
			
			system("cls");
			printf("#_____________________________DATA RECORDER V1.0________________________________#");
			printf("\n");
			printf("\n           HELLO DEAR CUSTOMER, HERE YOU ARE IN THE ABOUT SECTION !");
			printf("\n     THIS APPLICATION IS DEVELOPED BY BASANT KARKI, WHO IS NETWORK ENGINER,");
			printf("\n  CERTIFIED ETHICAL HACKER, PENETRATION TESTER , AND MASTER OF C ,C++ AND PHP.");
			printf("\n    IN THIS APPLICATION DEVELOPER USED C PROGRAMMING LANGAUGE TO DEVELOPED."); 
			printf("\n DATA RECORDED APPLICATION IS SPECIALLY MADE FOR STORING DATA IN SAFE WAY.");
			printf("\n THIS APPLICATION WILL BE MORE SECURED AND MORDEN WHEN NEW VERSION IS DEVELOPED!");
			printf("\n      ALL RIGHTS ARE RESERVERD THANKYOU FOR USING IT (DATA RECORDER V1.0)");
			system("pause>nul");
			goto start;
			
		}else{
			
			system("cls");
			printf("#_____________________________DATA RECORDER V1.0________________________________#");
			printf("\n");
			printf("PLEASE ENTER YOUR VALID OPTION!");
			sleep(2);
			goto start;
		}
}

}
