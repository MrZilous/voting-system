/**Project Name : Voting System 
 * Features : {
   Register voters (Voter ID, Name)
   Cast vote for candidates
   Display vote count
   Declare winner
   Prevent multiple voting by same voter
 * }
**/

//Imports 
#include<stdio.h>
#include<string.h>
#include<math.h>

//Defining Section
#define Max_Candidate_Count 5
#define Max_Voter_Count 10

struct Voter {
    char name[50];
    int id;
    int isVoted ; //0 -> Not Voted , 1 -> Voted
};
int VoterCount = 0 ; //Shows that how many voter has registered ...

struct Candidates {
    char name[50];
    int voteCount;
};

//Party Lists : Struct structure_name array_Name[size] -----IMP------
struct Candidates partyList[Max_Candidate_Count];
struct Voter voterList[Max_Voter_Count];


//Function Declaration
void intializeCandidates();
int checkAdminId(int id);
void registerVoter();
int validId(int id);
void updateVoteCount();
void PrintParty()
{
    for(int i=0 ; i<Max_Candidate_Count ; i++)
    {
        printf("\n%d - %s",i+1,partyList[i].name);
    }
}
void findWinner();


//Global variables 



//main function
void main() {

    //declaration 
    int adminId, adminDescision ;


    intializeCandidates();

    //Varifying admin 
    askId : printf("\nEnter Admin Id : ");
    scanf("%d", &adminId);
    if(!checkAdminId(adminId)){
        printf("AdminId is incorrect ");
        goto askId;
    }

    //Descision of Admin : Stop or Continue Voting ....
    printf("\nAdmin Choice : \nStop Voting : 0\nContinue Voting : 1\n ");
    scanf("%d", &adminDescision);

    if(!adminDescision){
        findWinner();
        return ;
    }

    printf("--------- Voter Registration -------\n");
    registerVoter();
    PrintParty();


}

//Functions Logic
void intializeCandidates() {

    //Candidate - A
    //Since We can not directly gave string name to variable so we use strcpy
    strcpy(partyList[0].name, "BJP");
    partyList[0].voteCount = 0;

    //Candidate - B
    strcpy(partyList[1].name, "Congress");
    partyList[1].voteCount = 0;

    //Candidate - C
    strcpy(partyList[2].name, "Aam_Aadmi");
    partyList[2].voteCount = 0;

    //Candidate - D
    strcpy(partyList[3].name, "Red_Robin");
    partyList[3].voteCount = 0;

    //Candidate - E
    strcpy(partyList[4].name, "Blue-Cherry");
    partyList[4].voteCount = 0;

}

int checkAdminId(int id){
    if(id == 53|| id == 54){
        return 1;
    }else{
        return 0;
    }
}

void registerVoter () {
    int id ;

    //Asking name
    printf("\n Enter your name : ");
    scanf("%s", voterList[VoterCount].name);

    //Asking for Unique id
    askId : printf("\n Enter your Id : ");
    scanf("%d", &id);
    if(validId){
        voterList[VoterCount].id = id;
    }else{
        goto askId;
    }  
    
    printf("Voter is Successfully Registered ... !!");
}

int validId(int id){
    int i ;
    for(i = 0 ; i < VoterCount ; i++){
        if(voterList[i].id == id){
            return 0;  //Id already present
        }
    }

    return 1;
}

void updateVoteCount(){

    int choice;

    printf("Your Choice : ");
    scanf("%d", &choice);

    partyList[choice].voteCount++;   
    printf("... Vote Successfully ...");
}

void findWinner(){

    int max = 0 ;
    int curr ; 
    int winner = 0; //Gives the Winner candidate's index number
    for(int i = 0 ; i < Max_Candidate_Count ; i++){
        curr = partyList[i].voteCount;
        winner = curr > max ? i : winner;
        max = fmax(curr , max);
    }

    printf("The Winner of the Election is : %s \n Candidate have total Votes : %d", partyList[winner].name , partyList[winner].voteCount);

}