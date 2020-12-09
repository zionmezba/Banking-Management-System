#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>
#define MAX 50

///FUNCTION PROTOTYPE SECTION
void createaccount();
void login();
void mainmenu();
void Employee();
void AssignEmployee(char name[], char desg[], int id, int count);
void display();
void search(int empidno);
void searchdel(int empidn);
///FUNCTION PROTOTYPE SECTION ENDS

struct employeenode
{
    int emplid;
    char ename[MAX];
    char edesignation[MAX];
    struct employeenode* link;
};
struct employeenode* emplinklist;


///Create Account and Login Function
char username[MAX];
char password[MAX];
char fullname[MAX];
void createaccount()
{
    int i=0;
    char chr;
    printf("\nEnter Your Full Name:\n");
    getchar();
    fgets(fullname,MAX,stdin);
    printf("Enter Username: [Max 50 character]\n");
    fgets(username,MAX,stdin);
    printf("Enter Password: [Max 50 character]\n");
    fgets(password,MAX,stdin);

    printf("\n\n----------------------------------\n");
    printf("Hi,\n");
    while (fullname[i])
    {
        chr = fullname[i];
        printf("%c", toupper(chr));
        i++;
    }
    printf("----------------------------------\n\n");
}

void login()
{
    int i=0;
    char chr,username1[MAX],password1[MAX];
again:
    printf("Enter Username:\n");
    getchar();
    fgets(username1,MAX,stdin);
    printf("Enter Password:\n");
    fgets(password1,MAX,stdin);
    if(strcmp(username1,username) == 0 && strcmp(password1,password) == 0)
    {
        printf("\n\n----------------------------------\n");
        printf("Hi,\n");
        while (fullname[i])
        {
            chr = fullname[i];
            printf("%c", toupper(chr));
            i++;
        }
        printf("----------------------------------\n\n");
    }
    else
    {
        printf("\nWrong Login Info!\nTry Again.\n\n");
        goto again;
    }
}

///MENU
void mainmenu()
{
    printf("\nWhat would you like to do?\n\n");
    printf(">> %-35s [Press 1]\n","Manage Employees");
    //printf(">> %-35s [Press 2]\n","Salary Management");
    //printf(">> %-35s [Press 3]\n","Check Deposit and Loan Status");
    //printf(">> %-35s [Press 4]\n","Customer Management");
    //printf(">> %-35s [Press 5]\n","Accounts management");
    printf(">> %-35s [Press 6]\n","Logout");
    printf(">> %-35s [Press 7]\n","Exit");
}

//==========================================================
///      THIS FUNCTION IS FOR EMPLOYEE MANAGEMENT
//==========================================================
void Employee()
{
    int val1, val2, val3, val4, ID, i=1;
    char ename[MAX];
    char edesignation[MAX];
    printf("----------------------------------\n");//34
    printf("|       EMPLOYEE MANAGEMENT       |\n");
    printf("----------------------------------\n\n");
again2:
    printf(">> %-35s [Press 1]\n","Assign New Employee");
    printf(">> %-35s [Press 2]\n","View All Employee");
    printf(">> %-35s [Press 3]\n","Search Employee Info By Employee ID");
    printf(">> %-35s [Press 4]\n","Remove Employee");
    printf(">> %-35s [Press 5]\n","Go to Main Menu");

again:
    scanf("%d",&val1);
    if(val1 == 1)
    {
        printf("----------------------------------\n");
        printf("|             ASSIGN              |\n");
        printf("----------------------------------\n\n");
        printf(">> How many Employee(s) You want to Assign?\n");
        scanf("%d",&val2);
        while(val2)
        {
            getchar();
            printf("Enter Name:\n>");
            fgets(ename,50,stdin);
            printf("Enter Designation:\n>");
            fgets(edesignation,50,stdin);
            printf("Enter ID:\n>");
            scanf("%d",&ID);
            AssignEmployee(ename,edesignation,ID,i);
            i++;
            val2--;
            if(val2 >= 1)
            {
                printf("\nEnter Other Employee Information\n>");
            }
        }
        goto again2;
    }
    else if(val1 == 2)
    {
        display();
        goto again2;
    }
    else if(val1 == 3)
    {
        printf("Enter Employee ID\n");
        scanf("%d",&val3);
        search(val3);
        goto again2;
    }
    else if(val1 == 4)
    {
        printf("Enter Employee ID to Remove\n");
        scanf("%d",&val4);
        searchdel(val4);
        goto again2;
    }
    else if( val1 == 5)
    {
        return;
    }
    else
    {
        printf("INVALID INPUT !\n\n");
        goto again;
    }
}

//====================================
///Assign Employee Function
//====================================
void AssignEmployee(char name[], char desg[], int id, int count)
{
    int i;
    struct employeenode* temp1 = (struct employeenode*)malloc(sizeof(struct employeenode));
    temp1 -> emplid = id;
    strcpy(temp1 -> ename,name);
    strcpy(temp1 -> edesignation,desg);
    temp1 -> link = NULL;
    //Create link
    if(count == 1)
    {
        temp1 -> link = emplinklist;
        emplinklist = temp1;
    }
    else
    {
        struct employeenode* temp2 = emplinklist;
        for(i=0; i<count-2; i++)
        {
            temp2 = temp2 -> link;
        }
        temp1 -> link=temp2->link;
        temp2-> link= temp1;
    }
}

///DISPLAY LIST
void display()
{
    struct employeenode* newnode = emplinklist;
    printf("\n\nEmployee Details List: \n");
    while(newnode != NULL)
    {
        printf("ID : %d\n",newnode -> emplid);
        printf("Name: %s",newnode -> ename);
        printf("Designation: %s\n",newnode -> edesignation);
        printf("---------------------------------------\n");
        newnode = newnode->link;
    }
    printf("\n\n");
}

/*=====================================*/
///Search and delete Function
/*=====================================*/
void search(int empidno)
{
    struct employeenode* newnode = emplinklist;
    while(newnode != NULL)
    {
        if (newnode -> emplid == empidno)
        {
            printf("\nEMPLOYEE FOUND! \n\n");
            printf("ID : %d\n",newnode -> emplid);
            printf("Name: %s",newnode -> ename);
            printf("Designation: %s",newnode -> edesignation);
            return;
        }
        else
            newnode = newnode->link;
    }
    printf("\n Employee Number %d not found !\n", empidno);
}

void searchdel(int empidn)
{
    int i=0;
    struct employeenode* newnode = emplinklist;
    while(newnode != NULL)
    {
        if (newnode -> emplid == empidn)
        {
            ++i;
            printf("\nEMPLOYEE REMOVED! \n\n");
            struct employeenode* newnode1 = emplinklist;
            if(i == 1)
            {
                emplinklist = newnode1 -> link;
                free(newnode1);
                return;
            }

            int j;
            for(j=0; j<i-2; j++)
            {
                newnode1 = newnode1 -> link;
            }
            struct employeenode* temp2 = newnode1 -> link;
            newnode1 -> link = temp2 -> link;
            free(temp2);
            return;
        }
        else
        {
            newnode = newnode -> link;
            i++;
        }
    }
    printf("\nEmployee not found\n");
}
//==========================================================
///       EMPLOYEE MANAGEMENT SYSTEM ENDS
//==========================================================


///THE MAIN FUNCTION
int main()
{
    emplinklist = NULL;
    int val1,val2;
    printf("-----------------------------------\n");
    printf("|         WELCOME TO SBANK         |\n");
    printf("-----------------------------------\n\n");
login1:
    printf("New Here?\n>> Create Account [Press 1]\n");
    printf("or\n>> Login          [Press 2]\n");

    scanf("%d",&val1);
    if(val1 == 1)
    {
        createaccount();
    }
    else if(val1 == 2)
    {
        login();
    }
    else
    {
        printf("INVALID INPUT !\n");
        goto login1;
    }

main1:
    mainmenu();
take1:
    scanf("%d",&val2);
    switch (val2)
    {
    case 1:
        Employee();
        break;
    /*case 2:
        Salary();
        break;
    case 3:
        DepositAndLoan();
        break;
    case 4:
        Customer();
        break;
    case 5:
        Accounts();
        break;*/
    case 6:
        goto login1;
        break;
    case 7:
        return 0;
        break;
    default:
    {
        printf("Wrong Input !!\n");
        goto take1;
    }
    }
    goto main1;
}
