#include<stdio.h>

int checkAdmin(int id, int list[]);

void main() {
    int ids[5];
    ids[0] = 12345;
    ids[1] = 2345;
    ids[2] = 990;

    checkAdmin(990, ids);
}

int checkAdmin(int id, int list[]){

    int n = 3;
    //iterate to each id
    for(int i = 0 ; i < n ; i++){
        if(list[i] == id){
            printf("The Admin Found !!");
            return 1;
        }
    }

    printf("Admin not found !!");

    return 0;
}