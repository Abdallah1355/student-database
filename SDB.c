#include<stdio.h>
#include"STD.h"
#include"SDB.h"



bool SDB_IsFull(void) // to check if data base is full or not
{

    if (count == 10)
    {

        return true;
    }
    else
    {

        return false;
    }
}



bool SDB_IsIdExist(uint32 id) //to check if the id is exist or not
{
    uint8 i;
    for(i=0; i<size; i++)
    {
        if (id == DB[i].Student_ID)
        {

            return true;
        }

    }

    return false;
}



uint8 SDB_GetUsedSize (void) // to give the number of ids entered
{

    return count;
}

uint8 AvailableEntry (void) //to find an empty place for new id
{
    uint8 i;
    for(i=0; i<size; i++)
    {
        if ((DB[i].Student_ID)==0)
        {
            return i;
            break;
        }
    }
}



bool SDB_AddEntry(void) //to add new id
{
    //check if data base is full or not
    if(SDB_IsFull())
    {
        printf("Database is full\n");

    }

    else
    {

        uint8 a = AvailableEntry();

        printf("Enter Student ID\n");
        scanf("%d",&id);


        while (getchar() != '\n')  // check for char entry
        {
            printf("\nplease enter a digit value\n");
            scanf("%d",&id);
            continue;
        }
        if (SDB_IsIdExist(id))
        {
            // check if id exist or not

            printf("This ID is exist , please try to enter another ID\n");
            return 0;
        }

        DB[a].Student_ID = id;
        printf("Enter Student Year\n");
        scanf("%d",&DB[a].Student_Year);
        printf("Enter Course1 ID\n");
        scanf("%d",&DB[a].Course1_ID);
        printf("Enter Course1 Grade\n");
        scanf("%d",&DB[a].Course1_grade);
        printf("Enter Course2 ID\n");
        scanf("%d",&DB[a].Course2_ID);
        printf("Enter Course2 Grade\n");
        scanf("%d",&DB[a].Course2_grade);
        printf("Enter Course3 ID\n");
        scanf("%d",&DB[a].Course3_ID);
        printf("Enter Course3 Grade\n");
        scanf("%d",&DB[a].Course3_grade);

        printf("DATA is successfully added\n");
        count ++;
        return 1;
    }
}







void SDB_DeletEntry(uint32 id) //to delete an id
{
    // check ID exist
    if(SDB_IsIdExist(id))
    {
        uint8 i;
        for(i=0; i<size; i++)
        {
            if(id == DB[i].Student_ID) //if exist make it equal 0
            {
                DB[i].Student_ID = 0;
                printf("DATA is successfully deleted\n");
                count--;
                break;
            }
        }
    }
    else
    {
        printf("This ID is not exist to delete , please try to enter valid ID\n");

    }

}


bool SDB_ReadEntry(uint32 id) //to read all information about given id
{
    uint8 i ;
    if (SDB_IsIdExist(id)) //check if id exist
    {
        for( i=0; i<size; i++)
        {
            if (id==DB[i].Student_ID) //if exist print all information
            {
                printf("Information Data : \n\n");
                printf("Student ID : %d\n",DB[i].Student_ID);
                printf("Student Year : %d\n",DB[i].Student_Year);
                printf("Course 1 ID : %d\n",DB[i].Course1_ID);
                printf("Course 1 Grade : %d\n",DB[i].Course1_grade);
                printf("Course 2 ID : %d\n",DB[i].Course2_ID);
                printf("Course 2 Grade : %d\n",DB[i].Course2_grade);
                printf("Course 3 ID : %d\n",DB[i].Course3_ID);
                printf("Course 3 Grade : %d\n",DB[i].Course3_grade);

            }
        }
    }

    else
    {
        printf("This Data not Exist !!\n\n");
    }

}





void SDB_GetList(uint8* count,uint32* list) //to make a list that include the number of student and his id
{

    uint8 i=0;
    *count=SDB_GetUsedSize();
    if(!(SDB_GetUsedSize())) //check for number of entries
    {
        printf("\nThere is NO DATA to show\n");
    }
    else
    {

        for(i=0; i<size; i++)
        {
            if((DB[i].Student_ID)!=0)
            {
                printf(" Student %d ID --> %d\n",i+1,DB[i].Student_ID);
//

                *list=DB[i].Student_ID;
                list++;

            }


        }
    }


}



