#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>


//structures
struct studentInfo{
	int id;
	char name[30];
	//int numOfCourse
	int phone;
	struct studentInfo *next;
	
};
typedef struct studentInfo node;

/*struct linkedList{
	struct studentInfo student;
	struct linkedList *next;
};
typedef struct linkedList node;*/


int isRunning=1;
node *head=NULL;
int totalStudent=0;
//functions

void loadDatabase();
void updateDatabase();

void addStudent();
void editStudent(int);
void showAllStudents();
int searchStudent(int);
void deleteStudent(int);
void deleteAllStudent();

void menu();
void exitProgram();
void goBackOrExit();
void gotoxy();
void loadDummyData();
int isUniqueId(int);



int main(){
	int option;
	int foundIndex,id;			//for searching purpose
	loadDummyData();			//sample data 
	char sure;					//for confirming deletion
	
	while(isRunning){
		menu();
		scanf("%d",&option);
		switch(option){
			case 0:
				isRunning=0;
				exitProgram();
				break;
			case 1:
	            system("cls");
	            printf("\n\t\t **** Add A New Student ****\n\n");
	            addStudent();
	            goBackOrExit();
	            break;
	        case 2:
	            system("cls");
	            if(head==NULL){
	            	printf("\n\t\t!!Empty Database!!\n\n");
	            	goBackOrExit();
	            	break;
				}
	            printf("\n\t\t **** All Students ****\n\n");
	            showAllStudents();
	            goBackOrExit();
	            break;
			case 3:
	        {
	            system("cls");
	            printf("\n\t\t **** Search Students ****\n\n");
	
	            printf(" Enter The Student ID: ");
	            scanf("%d",&id);
	            foundIndex = searchStudent(id);
	            if(foundIndex<0)
	            {
	                printf(" No Student Found\n\n");
	            }
	            printf("\n");
	            goBackOrExit();
	            break;
	        }
	        
	        case 4:
	            system("cls");
	            printf("\n\t\t **** Edit a Student ****\n\n");
	            printf(" Enter The Student ID: ");
	            scanf("%d",&id);
	            foundIndex = searchStudent(id);
	
	            if(foundIndex<0)
	            {
	            	printf(" No Student Found\n\n");
	                
	            }
	            else
	            {
	                editStudent(foundIndex);
	            }
	            goBackOrExit();
	            break;
	            
		    case 5:
	            system("cls");
	            printf("\n\t\t **** Delete a Student ****\n\n");
	            printf(" Enter The Student ID: ");
	            scanf("%d",&id);
	
	            foundIndex = searchStudent(id);
	
	            if(foundIndex<0)
	            {
	             	printf(" No Student Found\n\n");
	                goBackOrExit();   
	            }
	            else
	            {
	                
	                sure = 'N';
	                getchar();
	                printf("\n\n");
	                printf(" Are you sure want to delete this student? (Y/N): ");
	                scanf("%c",&sure);
	
	                if(sure == 'Y' || sure == 'y')
	                {
	                    deleteStudent(foundIndex);
	                }
	                else
	                {
	                    printf(" Your Data is Safe.\n\n");
	                    goBackOrExit();
	                }
	
	            }
	
	            break;
	            
	    case 6:
            sure = 'N';
            getchar();
            system("cls");
            printf("\n\t\t **** Delete ALL Students ****\n\n");

            printf(" Are you sure want to delete all the students? (Y/N): ");
            scanf("%c",&sure);
            if(sure == 'Y' || sure == 'y')
            {
                deleteAllStudent();
            }
            else
            {
                printf(" Your Data is Safe.\n\n");
                goBackOrExit();
            }
            break;
        default:
            printf("Please enter the valid option!!");
            break;
        
			
		}
	}
	
	return 0;
}



void loadDummyData(){
	node* newNode1=(node*)malloc(sizeof(node));
	newNode1->id=65;
	strcpy(newNode1->name,"Niraj");
	newNode1->phone=98912;
	newNode1->next=head;
	head=newNode1;
	
	node* newNode2=(node*)malloc(sizeof(node));
	newNode2->id=66;
	strcpy(newNode2->name,"Johnson");
	newNode2->phone=98912;
	newNode2->next=head;
	head=newNode2;
	
	
	node* newNode3=(node*)malloc(sizeof(node));
	newNode3->id=67;
	strcpy(newNode3->name,"Zayn");
	newNode3->phone=98912;
	newNode3->next=head;
	head=newNode3;
	
	totalStudent=3;
}


void menu(){
	printf("\n\n\t***Student Management System Using C***\n\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show All students.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] Edit A student.\n");
    printf("\t\t[5] Delete A student.\n");
    printf("\t\t[6] Delete All students.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\t\tEnter The Choice: ");
}

void exitProgram()
{
    system("cls");
    updateDatabase();
    int i;
    char ThankYou[100]     = " ========= Thank You =========\n";
    char ExittingProgram[100]   = " ========= Exitting Program ======\n";
    for(i=0; i<strlen(ThankYou); i++)
    {
        printf("%c",ThankYou[i]);
        Sleep(40);
    }
    for(i=0; i<strlen(ExittingProgram); i++)
    {
        printf("%c",ExittingProgram[i]);
        Sleep(40);
    }
    exit(0);
}


void addStudent(){
	//check validation (check for unique id)
	node *newNode=(node*)malloc(sizeof(node));
	int studentId;
	char studentName[30];
	int phone;
	int valid=0;
	
	while(!valid){
		//system("cls");
		printf("Enter the id of a student:");
		scanf("%d",&studentId);
		
		if(isUniqueId(studentId)!=1){
			printf("This student ID already Exists!!\n\n");
		}
		else
			valid++;	
	}

	printf("Enter The Name: ");
    scanf("%49s", studentName); 

    printf("Enter the phone number: ");
    scanf("%d",&phone);
    
    newNode->id=studentId;
    strcpy(newNode->name, studentName); 
    newNode->phone=phone;
    newNode->next=head;
	head=newNode;   
	totalStudent++; 
	printf("\n Student Added Successfully.\n\n");
}



void goBackOrExit(){
	getchar();
    char option;
    printf(" Go back(b)? or Exit(0)?: ");
    scanf("%c",&option);
    if(option == '0')
    {
        exitProgram();
    }
    else
    {
        system("cls");
    }
}

void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void showAllStudents(){
	
	int j=6;
	node* temp=head;
    printf("|==========|====================|====================|=============|\n");
    printf("|    ID    |        Name        |       Phone        |  NO.Course  |\n");
    printf("|==========|====================|====================|=============|\n");

    while(temp!=NULL)
    {
   
       
        gotoxy(0,j);
        printf("|");
        printf("%d",temp->id);
        
        gotoxy(11,j);

        printf("|");
        printf("%s",temp->name);
        
        gotoxy(32,j);
        printf("|");
        printf("%d",temp->phone);

        /*printf("|");
        printf("%s",Students[i].Phone);
        for(j=0; j < (20-strlen(Students[i].Phone)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%d",Students[i].NumberOfCourse);
        for(j=0; j < 12; j++)
        {
            printf(" ");
        }*/
        printf("|\n");
        printf("|----------|--------------------|--------------------|-------------|\n");
		temp=temp->next;
		j+=2;
    }
    printf("\n");
    printf("Total Students: %d \n\n",totalStudent);
}


int searchStudent(int id){
	int foundIndex=-1;
	system("cls");
	node* temp=head;
	while(temp!=NULL){
		if(temp->id==id){
				//add courses also
			printf("\n One Student Found for ID: %d\n\n",id);
	    	printf(" Student Informations\n");
	    	printf("-------------------------\n");
	
	    	printf(" ID:    %d\n",temp->id);
	    	printf(" Name:  %s\n",temp->name);
			printf(" Phone: %d\n",temp->phone);
	    	//printf("\n Total Number of Courses: %d\n",Students[i].NumberOfCourse);
	    	return temp->id;
			
		}
		temp=temp->next;
	}
	return foundIndex;

	
}

void editStudent(int id){
	printf("\n\t\t **** Update The New Student ****\n\n");
	char newName[30];
	int newPhone;
	node* temp=head;
	printf(" Enter The New Name(0 for skip): ");
    scanf(" %49s",&newName);
	printf(" Enter The New Phone(0 for skip): ");
    scanf("%d",&newPhone);

	while(temp->id!=id){

		temp=temp->next;
	}
	if(strcmp(newName,"0") != 0){
		strcpy(temp->name,newName);
	}
	if(newPhone!=0){
		temp->phone=newPhone;
	}
	printf(" Student Updated Successfully.\n\n");

}



void deleteStudent(int id){
	node *temp=head;
	node*prev;
	
	while(temp->id!=id){
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
	
	totalStudent--;
	printf(" Student Deleted Successfully.\n\n");
    goBackOrExit();
}

void deleteAllStudent(){
	totalStudent=0;
	node* temp=head;
	
	while(temp!=NULL){
		head=temp->next;
		free(temp);
		temp=head;
	}
	printf(" All Students Deleted Successfully.\n\n");
    goBackOrExit();
}

int isUniqueId(int id){
	int isUnique=1;
	node *temp=head;
	
	while(temp!=NULL){
		if (temp->id==id){
			isUnique--;
		}
		temp=temp->next;
	}
	
	return isUnique;
}
// Function to write student data to the file
void writeStudentToFile(FILE* file, node* temp) {
    fwrite(&temp->id, sizeof(int), 1, file);
    fwrite(temp->name, sizeof(char), sizeof(temp->name), file);
    fwrite(&temp->phone, sizeof(char), 1, file);						//sizeof(temp->phone) if character
}

// Function to serialize the linked list and write it to a file
void updateDatabase() {
    FILE* file = fopen("student.bin", "wb");
    if (file != NULL) {
        node* temp = head;
        while (temp != NULL) {
            writeStudentToFile(file, temp);
            temp=temp->next;
        }
        // Write a delimiter to indicate the end of the list
        int delimiter = -1;
        fwrite(&delimiter, sizeof(int), 1, file);
        fclose(file);
    } else {
        printf("Failed to update database.\n");
    }
}


void loadDatabase(){
	FILE *file=fopen("student.bin","rb");
	
	while(fread(head,sizeof))
}

