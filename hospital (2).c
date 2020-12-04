#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
    char name[50];
    char address[50];
    int age,room_num,id,year,month,day;
    char gender;
    char disease[30];
    float m_payed,payed,change;
} patients;

int num=0,sum=0,f=0,not_found=1; // global definition

// prototype
void read (patients [],FILE*readptr);
void add ( patients []);
void search ( patients []);
void edit(patients []);
void delet(patients []);
void list(patients []);
void write(patients [],FILE*writeptr);


int main ()
{
    int test,g;
    int c=0;
    patients data[100];

    FILE*filePtr=NULL;//creating pointer on file
    filePtr=fopen("Hospital.txt","rb+");//open file
    if(filePtr==NULL)
    {
        printf(" Error \n the file is not exist \n");
        return 1;
    }

    read(data,filePtr);//call function read to read the file and put data in the array of struct
    printf("\t\t\t\t\t     -------------------------------------\n");
    printf("\t\t\t\t\t***|@| WELCOME TO OM ELMASRYEEN HOSPITAL |@|***\n");
    printf("\t\t\t\t\t     -------------------------------------\n\n\n");

    while(1)            // infinite loop
    {
        fflush(stdin);
        printf(" *press 1 -for add new patient \n *press 2 -for search for a record \n *press 3 -for edit a record \n *press 4 -for list the patients records  \n *press 5 -for delet a record  \n *PRESS 6 -FOR EXIT\n");
        test=scanf("%d",&c);

        while(test!=1)
        {
            while((g=getchar()) != EOF && g != '\n');
            printf("Invalid input... please enter a number: \a");
            test = scanf("%d", &c);
        }

        switch(c)
        {

        case 1:
            system("cls");  // clear screen
            printf("There are %d patients\n",num); // printing number of patients
            add(data);   // call add function
            write(data,filePtr);   // call write function
            break;

        case 2:
            system("cls");
            search(data); // call search function
            break;

        case 3:
            system("cls");
            edit(data);  //call edit function
            write(data,filePtr);  // call write function
            break;
        case 4:
            system("cls");
            list(data); //call list function
            break;
        case 5:
            system("cls");
            delet(data); //call delete function
            write(data,filePtr); // call write function
            break;
        case 6:
            printf("Closing...\n\n\a");
            return 0;  // exit from the program
            break;
        default:
            system("cls");
            printf ("\n#Error\n#invalid input please enter valid value\n\n\n\a");
            break;
        }
    }
    return 0;
}


void add(patients add[])
{
    int n,test,g, L_id=0;

    for(int j=0; j<num; j++)
    {
        if((add[j].id) > L_id)
        {
            L_id=add[j].id;
        }
    }
    printf("\n*Enter the number of patients you want to add \n");

    test=scanf("%d",&n);
    while(test!=1)
    {
        while((g=getchar()) != EOF && g != '\n');
        printf("Invalid input... please enter a number: \a");
        test = scanf("%d", &n);
    }

    if(n>0)
    {
        system("cls");

        sum=num+n;
        for(int i=num; i<sum; i++)
        {

            printf( "*Enter Name of patient %d: ",i+1);
            fflush(stdin);
            gets(add[i].name);
            strlwr(add[i].name);  // make the name characters lower case
            printf("\n*Enter address of patient %d: ",i+1);
            fflush(stdin);
            gets(add[i].address);
            printf("\n*Enter gender of patient %d (M/F): ",i+1);
            fflush(stdin);
            scanf("%c",&(add[i].gender));
            printf("\n*Enter age of patient %d: ",i+1);
            fflush(stdin);
            test = scanf("%d",&(add[i].age));
            while(test!=1 || (add[i].age) <= 0)
            {
                while((g=getchar()) != EOF && g != '\n');
                printf("Invalid Age... please enter a number: \a");
                test = scanf("%d",&(add[i].age));
            }
            printf("\n*Enter patient room number: ");
            fflush(stdin);
            test = scanf("%d",&(add[i].room_num));
            while(test!=1 ||(add[i].room_num) <= 0)
            {
                while((g=getchar()) != EOF && g != '\n');
                printf("Invalid room number... please enter a number: \a");
                test = scanf("%d",&(add[i].room_num));
            }
            printf("\n*>>> FOR EMERGENCY CASES YOU SHOULD WRITE IN PATIENT DISEASE (Y or y)\nElSE WRITE THE DESEASE DESCRIPTION<<<*\n\n");

            printf("\n*Enter disease of patient %d: ",i+1);
            fflush(stdin);
            gets(add[i].disease);
            strlwr(add[i].disease);
            if (!(strcmp("y",add[i].disease)))
            {
                strcpy(add[i].disease,"Emergency");
            }

            printf("\n*Enter the year: ");
            fflush(stdin);
            test = scanf("%d",&(add[i].year));
            while(test!=1 || (add[i].year) < 2020)
            {
                while((g=getchar()) != EOF && g != '\n');
                printf("Invalid Year input... please enter a number: \a");
                test = scanf("%d",&(add[i].year));
            }

            printf("\n*Enter the month: ");
            fflush(stdin);
            test=scanf("%d",&add[i].month);
            while(test!=1 ||(add[i].month) <= 0|| (add[i].month) > 12)
            {
                while((g=getchar()) != EOF && g != '\n');
                printf("Invalid Month input... please enter a number: \a");
                test = scanf("%d",&(add[i].month));
            }

            printf("\n*Enter the day: ");
            fflush(stdin);
            test=scanf("%d",&add[i].day);
            while(test!=1 ||(add[i].day) <= 0|| (add[i].day) > 31)
            {
                while((g=getchar()) != EOF && g != '\n');
                printf("Invalid Month input... please enter a number: \a");
                test = scanf("%d",&(add[i].day));
            }

            printf("\n*Enter must payed money : ");
            fflush(stdin);
            test=scanf("%f",&(add[i].m_payed));
            while(test!=1 || (add[i].m_payed) < 0)
            {
                while((g=getchar()) != EOF && g != '\n');
                printf("Invalid Money input... please enter a number: \a");
                test = scanf("%f",&(add[i].m_payed));
            }

            printf("\n*Enter the payed money : ");
            fflush(stdin);
            test = scanf("%f",&(add[i].payed));
            while(test!=1 || (add[i].payed) < 0)
            {
                while((g=getchar()) != EOF && g != '\n');
                printf("Invalid Money input... please enter a number: \a");
                test = scanf("%f",&(add[i].payed));
            }

            add[i].change=(add[i].m_payed)-(add[i].payed);
            printf("-> change = %0.2f$\n",add[i].change);

            add[i].id=L_id+1;
            printf("-> patient number %d ID is : %d\n",i+1,add[i].id);
            printf("\n\n");
            num++;
            L_id++;
            printf("\n-> Data saved successfully\n\n\a");
        }
    }

    else
    {
        system("cls");
        printf("\n#Error\n#invalid input please enter valid value\n\n\a");
    }
}

void search ( patients search[])
{
    int x,test,h,g;
    char name[50];
    printf("*BY WHAT WAY YOU WANT TO SEARCH \n");
    printf ("*press 1 -for search by id \n*press 2 -for search by name\n");
    test=scanf("%d",&h);
    while(test!=1)
    {
        while((g=getchar()) != EOF && g != '\n');
        printf("Invalid input... please enter a number: \a");
        test = scanf("%d", &h);
    }
    system("cls");
    if(h==1)
    {
        f=0;
        printf("\n*Enter id of the patient : ");
        test=scanf("%d",&x);
        while(test!=1)
        {
            while((g=getchar()) != EOF && g != '\n');
            printf("Invalid input... please enter a number: \a");
            test = scanf("%d", &x);
        }
        if(x>=0)
        {
            for(int i=0; i<num; i++)
            {
                if(x==search[i].id)
                {
                    system("cls");

                    printf("\n-> ID: ");
                    printf("%d",search[i].id);
                    printf("\n-> Name: ");
                    puts(search[i].name);
                    printf("-> address: ");
                    puts(search[i].address);
                    printf("-> gender: %c",search[i].gender);
                    printf("\n-> disease: ");
                    puts(search[i].disease);
                    printf("-> room number: %d\n-> age: %d  \n",search[i].room_num,search[i].age);
                    printf("-> date : %d/%d/%d\n",search[i].year,search[i].month,search[i].day);
                    printf("-> must payed   // payed   // change\n");
                    printf("   %0.2f$      %0.2f$   %0.2f$\n\n",search[i].m_payed,search[i].payed,search[i].change);
                    f=1;
                    not_found = 1;
                }
            }
            if(f==0)
            {
                printf("\n\n#patient not found\n\n\a");
                not_found=0;
            }
        }
        else
        {
            printf("\n\n#invalid input please enter valid value\n\n\a");
            not_found=0;

        }
    }
    else if(h==2)
    {
        f=0;
        fflush(stdin);
        printf("\n*Enter patient name :");
        gets(name);
        strlwr(name);// make the name lower
        fflush(stdin);
        for(int i=0; i<num; i++)
        {
            if(strcmp(name,search[i].name)==0)
            {
                printf("\n-> Name: ");
                puts(search[i].name);
                printf("-> address: ");
                puts(search[i].address);
                printf("-> gender: %c",search[i].gender);
                printf("\n-> disease: ");
                puts(search[i].disease);
                printf("-> room number: %d\n-> age: %d \n-> ID: %d\n",search[i].room_num,search[i].age,search[i].id);
                printf("-> date : %d/%d/%d\n",search[i].year,search[i].month,search[i].day);
                printf("-> must payed   // payed   // change\n");
                printf("   %0.2f$      %0.2f$   %0.2f$\n\n",search[i].m_payed,search[i].payed,search[i].change);
                f=1;
                not_found = 1;
            }
        }
        if(f==0)
        {
            printf(" \n\n#patient not found\n\n\n\a");
            not_found=0;
        }
    }
    else
    {
        printf ("\n#invalid input please enter valid value \n\n\a");
        not_found=0;

    }
}

void edit(patients edit[])
{
    int n,g,test;
    fflush(stdin);
    search(edit);// call search function
    if(not_found == 0)
        return;
    printf("*enter the id of the patient you want to edit record : ");
    test=scanf("%d",&n);
    while(test!=1)
    {
        while((g=getchar()) != EOF && g != '\n');
        printf("Invalid input... please enter a number: \a");
        test = scanf("%d", &n);
    }

    fflush(stdin);
    system("cls");

    if(n>0)
    {
        f=0;
        for(int i=0; i<num; i++)
        {
            if(n==edit[i].id)
            {
                printf("*enter a new record\n\n");
                printf( "*Enter Name of patient %d: ",n);
                fflush(stdin);
                gets(edit[i].name);
                strlwr(edit[i].name);
                printf("\n*Enter address of patient %d: ",n);
                fflush(stdin);
                gets(edit[i].address);
                printf("\n*Enter gender of patient %d (M/F): ",n);
                fflush(stdin);
                scanf("%c",&(edit[i].gender));
                printf("\n*Enter age of patient %d: ",n);
                fflush(stdin);
                scanf("%d",&(edit[i].age));
                printf("\n*Update disease Description of patient %d: ",n);
                fflush(stdin);
                gets(edit[i].disease);
                printf("\n*Enter patient room number: ");
                fflush(stdin);
                scanf("%d",&(edit[i].room_num));
                printf("\n*Enter the year: ");
                fflush(stdin);
                scanf("%d",&edit[i].year);
                printf("\n*Enter the month: ");
                fflush(stdin);
                scanf("%d",&edit[i].month);
                printf("\n*Enter the day: ");
                fflush(stdin);
                scanf("%d",&edit[i].day);
                printf("\n*Enter must payed money : ");
                fflush(stdin);
                scanf("%f",&(edit[i].m_payed));
                printf("\n*Enter the payed money : ");
                fflush(stdin);
                scanf("%f",&(edit[i].payed));
                edit[i].change=(edit[i].m_payed)-(edit[i].payed);
                printf("-> change = %0.2f$\n",edit[i].change);
                printf("-> patient number %d -> ID is : %d\n",edit[i].id,edit[i].id);
                printf("\n-> Data saved successfully\n\n");
                f=1;
            }
        }
        if(f==0)
        {
            printf("\n#patient not found \n\n\a");
        }
    }
    else
    {
        printf("\n#invalid input please enter valid value \n\n\a");
    }
}

void delet(patients delet[])
{
    int d,g,test;
    fflush(stdin);
    search(delet);// call search function

    if(not_found == 0)
        return; //exit function if not patient

    printf("\n*enter the id of the patient then press ENTER to delete the record: ");
    test=scanf("%d",&d);
    while(test!=1)
    {
        while((g=getchar()) != EOF && g != '\n');
        printf("Invalid input... please enter a number: ");
        test = scanf("%d", &d);
    }

    system("cls");
    if(d>=0)
    {
        f=0;
        for(int i=0; i<num; i++)
        {
            if(d==delet[i].id)
            {
                for(int j=i; j<num; j++)
                {
                    delet[j]=delet[j+1];
                }
                num--;
                printf("\n\n #The patient is deleted \n");
                printf("\n-> Data saved successfully\n\n");
                f=1;
            }
        }
        if(f==0)
        {
            printf(" \n\n#patient not found\n\n\a");
        }
    }
    else
    {
        printf(" \n\n#invalid input please enter valid value\n\n\a");
    }
}

void list(patients list[])
{
    char ch;
    int x,g,test;
    patients temp;
    char em[10]="Emergency";
    fflush(stdin);
    printf("*press 1 -for Records of patients in alphabetical order\n*press 2 -for Records in date order\n*press 3 -for Records of Emergency patients\n");
    test=scanf("%d",&x);
    while(test!=1)
    {
        while((g=getchar()) != EOF && g != '\n');
        printf("Invalid input... please enter a number: \a");
        test = scanf("%d", &x);
    }
    system("cls");
    if(x<4&&x>0)
    {
        if(x==1)
        {
            f=0;
            for(int i=1; i<num; i++)
            {
                for(int j=0; j<num-1; j++)
                {
                    if(strcmp(list[j].name,list[j+1].name)>0)
                    {
                        temp=list[j];
                        list[j]=list[j+1];
                        list[j+1]=temp;
                    }
                }
            }
            system("cls");
            while(f<num)
            {
                printf("\n-> Name: ");
                puts(list[f].name);

                printf("-> address: ");
                puts(list[f].address);
                printf("-> gender: %c",list[f].gender);
                printf("\n-> disease: ");
                puts(list[f].disease);
                printf("-> room number: %d\n-> age: %d \n-> ID: %d\n",list[f].room_num,list[f].age,list[f].id);
                printf("-> date : %d/%d/%d\n",list[f].year,list[f].month,list[f].day);
                printf("-> must payed   // payed   // change\n");
                printf("   %0.2f$      %0.2f$   %0.2f$\n\n",list[f].m_payed,list[f].payed,list[f].change);
                printf("#Press ENTER for the next patient or any letter to exit: ");
                fflush(stdin);
                ch=fgetc(stdin);
                if(ch==0x0A)
                {
                    f++;
                }
                else
                {
                    return;
                }
            }

        }
        else if(x==2)
        {
            f=0;
            for(int i=1; i<num; i++)
            {
                for(int j=0; j<num-1; j++)
                {
                    if(list[j].id>list[j+1].id)
                    {
                        temp=list[j];
                        list[j]=list[j+1];
                        list[j+1]=temp;
                    }
                }
            }
            while(f<num)
            {
                printf("\n-> Name: ");
                puts(list[f].name);
                printf("-> address: ");
                puts(list[f].address);
                printf("-> gender: %c",list[f].gender);
                printf("\n-> disease: ");
                puts(list[f].disease);
                printf("-> room number: %d\n-> age: %d \n-> ID: %d\n",list[f].room_num,list[f].age,list[f].id);
                printf("-> date : %d/%d/%d\n",list[f].year,list[f].month,list[f].day);
                printf("-> must payed   // payed   // change\n");
                printf("   %0.2f$      %0.2f$   %0.2f$\n\n",list[f].m_payed,list[f].payed,list[f].change);
                printf("#Press ENTER for the next patient or any letter to exit: ");
                fflush(stdin);
                ch=fgetc(stdin);
                if(ch==0x0A)
                {
                    f++;
                }
                else
                {
                    return;
                }
            }
        }
        else if(x==3)
        {
            f=0;
            for(int e=0; e<num; e++)
            {
                if(!(strcmp(em,list[e].disease)))
                {

                    printf("\n-> Name: ");
                    puts(list[e].name);
                    printf("->address: ");
                    puts(list[e].address);
                    printf("->gender: %c",list[e].gender);
                    printf("\n-> disease: ");
                    puts(list[e].disease);
                    printf("-> room number: %d\n-> age: %d \n-> ID: %d\n",list[e].room_num,list[e].age,list[e].id);
                    printf("-> date : %d/%d/%d\n",list[e].year,list[e].month,list[e].day);
                    printf("-> must payed   // payed   // change\n");
                    printf("   %0.2f$      %0.2f$   %0.2f$\n\n",list[e].m_payed,list[e].payed,list[e].change);
                    f=1;
                }
            }
            if(f==0)
            {
                printf("\n#patient not found \n\n\a");
            }
        }
    }
    else
    {
        printf("\n#invalid input please enter valid value\n\n\a");
    }
}

void write(patients write[],FILE*writeptr)
{
    writeptr=fopen("Hospital.txt","wb+");
    if(writeptr==NULL)
    {
        printf(" Error \n the file is not exist \n\a");
        return ;
    }
    fwrite(write,sizeof(patients),num,writeptr);
    fclose(writeptr);
}

void read(patients read[],FILE*readptr)
{
    readptr=fopen("Hospital.txt","rb+");
    if(readptr==NULL)
    {
        printf(" Error \n the file is not exist \n\a");
        return ;
    }
    fseek(readptr,0,SEEK_END);
    num=(ftell(readptr)/sizeof(patients));
    rewind(readptr);
    fread(read,sizeof(patients),num,readptr);
}
