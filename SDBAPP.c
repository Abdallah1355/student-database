#include<stdio.h>
#include"STD.h"
#include"SDB.c"






//switch case to choose action what user need
void SDB_action (uint8 choice)
{
    switch(choice)
    {
    case 1 :
        ;
        printf("Please Enter New Data\n");
        SDB_AddEntry();
        break;
    case 2 :
        ;
        SDB_GetUsedSize();
        printf("The number of entries is : %d\n",count) ;
        break;
    case 3 :
        ;
        printf("Enter ID ! \n");
        scanf("%d",&id);
        SDB_ReadEntry( id);
        break;
    case 4 :
        ;
        SDB_GetList( &count, list);
        break;
    case 5 :
        ;
        printf("Enter ID ! \n");
        scanf("%d",&id);

        uint8 v= SDB_IsIdExist( id);
        if (v==0)
        {
            printf("ID doesn't exist \n");
        }
        else if (v==1)
        {
            printf("ID exist\n");
        }
        break;
    case 6 :
        ;
        printf("Enter ID ! \n");
        scanf("%d",&id);
        SDB_DeletEntry( id);
        break;
    case 7 :
        ;
        uint8 x=  SDB_IsFull();
        if (x==0)
        {
            printf("DATA BASE IS NOT FULL\n");
        }
        else if (x==1)
        {
            printf("DATA BASE IS FULL\n");
        }
        break;
    case 8:
        ;
        printf("you're Welcome\n");
        printf("DESIGNED BY ABDALLAH .. \n\n");
        e =1;

        break;
    }

}



void SDB_APP (void) //function to know user what in program
{
    printf("\n-------Welcome to student data base-------\n");
    printf("Please select your operation\n");
    printf("\t\t 1-Add new entry\n");
    printf("\t\t 2-Get Used Size in Data base\n");
    printf("\t\t 3-Read Student Data\n");
    printf("\t\t 4-Get the list of IDs of the students\n");
    printf("\t\t 5-Check if the ID exist\n");
    printf("\t\t 6-Delete student data\n");
    printf("\t\t 7-Check if the data base is full\n");
    printf("\t\t 8-End program\n");
    scanf("%d",&choice);
    SDB_action (choice);
}




