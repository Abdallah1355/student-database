#include<stdio.h>
#include"STD.h"
#include"SDB.h"
#include"SDBAPP.c"



int main(void)
{
    uint32 i;

//initialization of array to make sure that no garbage in it
    for ( i=0; i<size ; i++)
    {
        DB[i].Student_ID = 0;


    }
//super loop to make program always open until user choose to exit
    while(1)
    {
        SDB_APP();

                if (e==1) //in case user want to exit
        {
            break;

        }
    }
}

