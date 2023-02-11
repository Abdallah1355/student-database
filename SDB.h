#ifndef SDB_H_
#define SDB_H_
#include"STD.h"


//struct definition
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_Year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} student;

//Array of type struct
student DB [size];

//Function Deceleration
bool SDB_IsFull(void);
uint8 SDb_GetUsedSize (void);
bool SDB_AddEntry(void);
void SDB_DeletEntry(uint32 );
bool SDB_ReadEntry(uint32 );
void SDB_GetList(uint8*,uint32* );
bool SDB_IsIdExist(uint32 );
void SDB_APP(void);
void SDB_action(uint8 );
uint8 AvailableEntry (void);
uint8 check (uint32*);

#endif // SDB_H_
