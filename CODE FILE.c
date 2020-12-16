#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>
#define MAX 50
#define size 50

///FUNCTION PROTOTYPE SECTION
void createaccount();
void login();
void mainmenu();
void Employee();
void AssignEmployee(char name[], char desg[], int id, int count,int salary);
void display();
void search(int empidno);
void searchdel(int empidn);
void searchsal(int salar);
///FUNCTION PROTOTYPE SECTION ENDS

struct employeenode
{
    int emplid;
    int salary;
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
    printf(">> %-35s [Press 2]\n","Salary Management");
    printf(">> %-35s [Press 3]\n","Customer Management");
    printf(">> %-35s [Press 4]\n","Logout");
    printf(">> %-35s [Press 5]\n","Exit");
}

//==========================================================
///      THIS FUNCTION IS FOR EMPLOYEE MANAGEMENT
//==========================================================

int i;
void Employee()
{
    int val1, val2, val3, val4, ID, salary;
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
            printf("Enter Salary:\n>");
            scanf("%d",&salary);
            printf("Enter ID: [Example: 1001]\n>");
            scanf("%d",&ID);
            AssignEmployee(ename,edesignation,ID,i,salary);
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
        printf("Enter Employee ID: [Example: 1001]\n");
        scanf("%d",&val3);
        search(val3);
        goto again2;
    }
    else if(val1 == 4)
    {
        printf("Enter Employee ID to Remove: [Example: 1001]\n");
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
void pre_defined_employee()
{
    i=1;
    int ID1 = 1001,ID2 = 1002,ID3 = 1003,ID4 = 1004,ID5 = 1005;
    int salary1 = 75000, salary2 = 65000, salary3 = 50000, salary4 = 40000,salary5 = 35000;
    char ename1[]= "Md. Rahim Mia\n";
    char ename2[]= "Md. Rahmatullah Alamin\n";
    char ename3[]= "Ms. Salma Sakhawat\n";
    char ename4[]= "Ms. Saima Akhter\n";
    char ename5[]= "Raj Ballav Shen\n";
    char edesignation1[]= "Assistant Branch Manager";
    char edesignation2[]= "Branch Manager";
    char edesignation3[]= "Assistant Officer";
    char edesignation4[]= "Junior Officer";
    char edesignation5[]= "ATM Specialist";
    ///AssignEmployee(ename,edesignation,ID,i,salary);
    AssignEmployee(ename1,edesignation1,ID1,i,salary1);
    i++;
    AssignEmployee(ename2,edesignation2,ID2,i,salary2);
    i++;
    AssignEmployee(ename3,edesignation3,ID3,i,salary3);
    i++;
    AssignEmployee(ename4,edesignation4,ID4,i,salary4);
    i++;
    AssignEmployee(ename5,edesignation5,ID5,i,salary5);
    i++;
}
///Assign Employee Function
void AssignEmployee(char name[], char desg[], int id, int count,int sal)
{
    int i;
    struct employeenode* temp1 = (struct employeenode*)malloc(sizeof(struct employeenode));
    temp1 -> emplid = id;
    temp1 -> salary = sal;
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
    printf("\n\nEmployee Details List: \n\n");
    while(newnode != NULL)
    {
        printf("ID : %d\n",newnode -> emplid);
        printf("Name: %s",newnode -> ename);
        printf("Designation: %s\n",newnode -> edesignation);
        printf("Salary : %d/-\n",newnode -> salary);
        printf("---------------------------------------\n");
        newnode = newnode->link;
    }
    printf("\n\n");
}

///Search and delete Function
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
            printf("Salary : %d\n",newnode -> salary);
            return;
        }
        else
            newnode = newnode->link;
    }
    printf("\nEmployee Number %d not found !\n", empidno);
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

//==========================================================
///       THIS FUNCTION IS FOR SALARY MANAGEMENT
//==========================================================
void Salary_management()
{
    int val1,val2;
    printf("----------------------------------\n");//34
    printf("|        SALARY MANAGEMENT        |\n");
    printf("----------------------------------\n\n");
again2:
    printf(">> %-35s [Press 1]\n","View all employee's salary");
    printf(">> %-35s [Press 2]\n","Change Salary");
    printf(">> %-35s [Press 3]\n","Go to Main Menu");
    scanf("%d",&val1);
    if(val1 == 1)
    {
        display();
        goto again2;
    }
    else if(val1 == 2)
    {
        printf("Enter Employee ID: [Example: 1001]\n");
        scanf("%d",&val2);
        searchsal(val2);
        goto again2;
    }
    else if(val1 == 3)
    {
        return;
    }
    else
    {
        printf("INVALID INPUT !\n");
        goto again2;
    }

}

void searchsal(int salar)
{
    int newsal;
    struct employeenode* newnode = emplinklist;
    while(newnode != NULL)
    {
        if (newnode -> emplid == salar)
        {
            printf("\nEMPLOYEE FOUND! \n\n");
            printf("Current Salary : %d/-\n",newnode -> salary);
            printf("Change to: ");
            scanf("%d",&newsal);
            newnode -> salary = newsal;
            printf("Change Successful !");
            printf("Changed Salary : %d/-\n",newnode -> salary);
            return;
        }
        else
            newnode = newnode->link;
    }
    printf("\nEmployee Number %d not found !\n\n", salar);
}
//==========================================================
///       SALARY MANAGEMENT SYSTEM ENDS
//==========================================================

//==========================================================
///       THIS FUNCTION IS FOR CUSTOMER MANAGEMENT
//==========================================================
struct node
{
    int data; ///We will use as Account number
    int contact;
    int balance;
    char name[size];
    char address[size];
    struct node *right_child;
    struct node *left_child;
};


struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) 
        return find_minimum(root->left_child); 
    return root;
}
struct node* new_node(int x, int cont, int balc, char nam[],char add[])
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p -> data = x;
    p -> contact = cont;
    p -> balance = balc;
    strcpy(p -> name,nam);
    strcpy(p -> address,add);
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x, int cont, int balc, char nam[],char add[])
{

    if(root==NULL)
    {
        return new_node(x,cont,balc,nam,add);
    }
    else if(x>root->data)
    {
        root->right_child = insert(root->right_child, x,cont,balc,nam,add);
    }
    else
    {
        root->left_child = insert(root->left_child,x,cont,balc,nam,add);
    }
    return root;
}

void pre_defined_customers(struct node *root)
{

    int acc1 = 3031,acc2 = 3032,acc3 = 3033,acc4 = 3034,acc5 = 3035;
    int cnt1 = 1750458479, cnt2 = 1957886496, cnt3 = 1774383469;
    int cnt4 = 1303034996, cnt5 = 1854795479;
    int balc1 = 150650, balc2 = 256100, balc3 = 500050, balc4 = 1000200, balc5 = 982002;
    char cname1[]= "Md. Rustom Chowdhuri\n";
    char cname2[]= "Md. Bodrul Alamin\n";
    char cname3[]= "Ms. Hasina Begum\n";
    char cname4[]= "Ms. Bilimoria\n";
    char cname5[]= "Sourav Pal\n";
    char addr1[]= "Keranipara, Rangpur";
    char addr2[]= "Uttara, Dhaka";
    char addr3[]= "Banani, Dhaka";
    char addr4[]= "Taraganj, Rangpur";
    char addr5[]= "Guptapara, Sylhet";

    ///AssignNode(ename,edesignation,ID,i,salary);
    insert(root,acc1,cnt1,balc1,cname1,addr1);
    insert(root,acc2,cnt2,balc2,cname2,addr2);
    insert(root,acc3,cnt3,balc3,cname3,addr3);
    insert(root,acc4,cnt4,balc4,cname4,addr4);
    insert(root,acc5,cnt5,balc5,cname5,addr5);
}
//Search Function
struct node* searchtree(struct node *root, int x)
{
    if(root==NULL || root->data==x)
    {
        printf("----------------------------------\n\n");
        printf("\nAccount Number       :%d\n",root-> data);
        printf("Name                 :%s",root -> name);
        printf("Address              :%s\n",root -> address);
        printf("Contact Number       :%d\n",root -> contact);
        printf("Balance              :%d/-\n",root -> balance);
        printf("----------------------------------\n\n");
        return 0;
    }
    else if(x>root->data)
    {
        searchtree(root->right_child, x);
    }
    else if(x <= root->data)
    {
        searchtree(root->left_child,x);
    }
    else
    {
        printf("Not Found !\n\n");
    }
    return 0;
}
//This function is for delete
struct node* delete(struct node *root, int x)
{

    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}



void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child);
        printf("\nAccount Number       :%d\n",root-> data);
        printf("Name                 :%s",root -> name);
        printf("Address              :%s\n",root -> address);
        printf("Contact Number       :%d\n",root -> contact);
        printf("Balance              :%d/-\n",root -> balance);
        printf("----------------------------------\n\n");
        inorder(root->right_child);
    }
}

void Customer()
{
    int val1,val2,val3,val4,val5,val6;
    char namee[size],addre[size];
    printf("----------------------------------\n");//34
    printf("|      CUSTOMER MANAGEMENT       |\n");
    printf("----------------------------------\n\n");
    struct node *root;
    root = new_node(3036,176354,602305,"Md. Rashed Mia\n","Munshipara,Rangpur");
    pre_defined_customers(root);
again3:
    printf(">> %-35s [Press 1]\n","View all Customers Info");
    printf(">> %-35s [Press 2]\n","Add New Customers");
    printf(">> %-35s [Press 3]\n","Search Customers");
    printf(">> %-35s [Press 4]\n","Remove Customers");
    printf(">> %-35s [Press 5]\n","Go to Main Menu");

    scanf("%d",&val1);
    if(val1 == 1)
    {
        inorder(root);
        goto again3;
    }
    else if(val1 == 2)
    {
        printf("Account No    : [Example: 3034]\n");
        scanf("%d",&val4);
        printf("Name          : \n");
        getchar();
        fgets(namee,size,stdin);
        printf("Address       : \n");
        fgets(addre,size,stdin);
        printf("Contact Number: \n");
        scanf("%d",&val5);
        printf("Balance       : \n");
        scanf("%d",&val6);
        ///struct node *root, int x, int cont, int balc, char nam[],char add[]
        insert(root,val4,val5,val6,namee,addre);
        goto again3;
    }
    else if(val1 == 3)
    {
        printf("Enter Customer Account No: [Example: 3034]\n");
        scanf("%d",&val2);
        searchtree(root,val2);
        goto again3;
    }
    else if(val1 == 4)
    {
        printf("Enter Customer Account No: [Example: 3034]\n");
        scanf("%d",&val3);
        delete(root,val3);
        printf("Delete Successful !\n\n");
        goto again3;
    }
    else if(val1 == 5)
    {
        return;
    }
    else
    {
        printf("INVALID INPUT !\n\n");
        goto again3;
    }
    printf("\n");
}
//==========================================================
///       CUSTOMER MANAGEMENT SYSTEM ENDS
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
    printf("New Here?\n>> Create Account [Press 1], or\n");
    printf(">> Login          [Press 2]\n");

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

    pre_defined_employee();
main1:
    mainmenu();
take1:
    scanf("%d",&val2);
    switch (val2)
    {
    case 1:
        Employee();
        break;
    case 2:
        Salary_management();
        break;
    case 3:
        Customer();
        break;
    case 4:
        goto login1;
        break;
    case 5:
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
