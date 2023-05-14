#include <stdio.h>
#include <stdlib.h>
void menu();
void welcome()
{
    system("cls");
    printf("\t\t\t** Welcome to Student's Database **");
    printf("\n\n\n\n\n\n Please enter any key to go to menu page:");
    getchar();
    menu();
    
}

int MAX_STUDENTS = 100;

struct student {
    char name[50];
    int roll_number;
    int lang_1st;
    int lang_2nd;
    int math;
    int phy;
    int chem;
    int opt;
    int total;
    float perc;
    char grade;
};
void add_student(struct student students[], int *num_students) 
{
	system("cls");
    if (*num_students == MAX_STUDENTS) {
        printf("Error: Maximum number of students reached\n");
        return;
    }
    int i,n;
    struct student new_student[n];
	printf("Enter the number of student to be added :\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		   
	    printf("Enter name of student: ");
	    scanf("%c",&new_student[i].name);
	    gets(new_student[i].name);
	    
	    printf("Enter roll number of student: ");
	    scanf("%d", &new_student[i].roll_number);
	    
	    printf("Enter marks for first language: ");
	    scanf("%d", &new_student[i].lang_1st);
	    
	    printf("Enter marks for second language: ");
	    scanf("%d", &new_student[i].lang_2nd);
	    
	    printf("Enter marks for mathematics: ");
	    scanf("%d", &new_student[i].math);
	    
	    printf("Enter marks for physics : ");
	    scanf("%d", &new_student[i].phy);
	    
	    printf("Enter marks for chemistry : ");
	    scanf("%d", &new_student[i].chem);
	    
	    printf("Enter marks for biology/computer : ");
	    scanf("%d", &new_student[i].opt);
	    
	    new_student[i].total=new_student[i].lang_1st+new_student[i].lang_2nd+new_student[i].math+new_student[i].phy+new_student[i].chem+new_student[i].opt;
	    new_student[i].perc=new_student[i].total/600;
	    
	    
	    if (new_student[i].perc > 90) {
	            new_student[i].grade = 'A';
	        } else if (new_student[i].perc  >= 80&&new_student[i].perc  < 90) {
	            new_student[i].grade = 'B';
	        } else if (new_student[i].perc  >= 70&&new_student[i].perc  < 80) {
	            new_student[i].grade = 'C';
	        } else if (new_student[i].perc  >= 60&&new_student[i].perc  < 70) {
	            new_student[i].grade = 'D';
	        } else {
	            new_student[i].grade = 'F';
	        }
	    
	    students[*num_students] = new_student[i];
	    (*num_students)++;
	}
	    
	    printf("Student added successfully\n");
}
void display_students(struct student students[], int num_students) {
    printf("List of students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, \nRoll Number: %d, \nMarks: %d\n", students[i].name, students[i].roll_number, students[i].total);
    }
}
void search_student(struct student students[], int num_students) {
    int roll_number;
    printf("Enter roll number of student to search for: ");
    scanf("%d", &roll_number);
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll_number) {
            printf("Student found: Name: %s, Roll Number: %d, Marks: %d\n", students[i].name, students[i].roll_number, students[i].total);
            return;
        }
    }
    
    printf("Error: Student with roll number %d not found\n", roll_number);
}

void menu()
{
 	system("cls");
    struct student students[MAX_STUDENTS];
    int num_students = 0;
    
    while (1) {
        printf("Enter \n1 to add student\n2 to display all students\n3 to search for a student by roll number\n4 to exit:\n");
        printf("Enter your choice :");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                display_students(students, num_students);
                break;
            case 3:
                search_student(students, num_students);
                break;
            case 4:
                getchar();
                welcome();
            default:
                printf("Error: Invalid choice\n");
                getchar();
                welcome();
        }
    }
    
    
}

int main()
{
	welcome();
}
