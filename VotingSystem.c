#include<stdio.h>
// Admin Control Panel
// ------------------------start of function ----------------------------------
int adminchoice()
{
    int choice;
    printf("Choices : \n enter 0 for stop voting \n enter 1 for continue voting\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);

    if(choice == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
// ------------------------end of functions --------------------------------

// Admin verification function 
//-------------------------start of function---------------------------------
int checkAdmin(int id, int list[])
{

    int n = 3;
    //iterate to each id
    for(int i = 0 ; i < n ; i++){
        if(list[i] == id){
            printf("The Admin Found !!");
            adminchoice();
            return 1;
        }
    }

    printf("Admin not found !!\n");

    return 0;
}
//------------------------- end of function---------------------------------



void main() 
{
    int ids[5];
    ids[0] = 12345;
    ids[1] = 2345;
    ids[2] = 990;

    checkAdmin(1000, ids);

}