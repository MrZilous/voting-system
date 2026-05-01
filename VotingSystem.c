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

struct Candidates {
    char name[50];
    int voteCount;
};

//Party Lists : Struct structure_name array_Name[size] -----IMP------
struct Candidates partyList[Max_Candidate_Count];
struct Voter voterList[Max_Voter_Count];


//Function Declaration
void fetchVoters();
void intializeCandidates();
int checkAdminId(int id);
void registerVoter();
int validId(int id);
void addVoter(struct Voter v);
void updateVoteCount();
void PrintParty();
void findWinner();


//Global variables 
int VoterCount = 0 ; //Shows that how many voter has registered ...


//main function
void main() {

    //declaration 
    int adminId, adminDescision ;

   //Initializing the System
    fetchVoters();
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
    updateVoteCount();
    goto askId;

}

//Functions Logic

void fetchVoters(){

    FILE *fptr = fopen("voters.txt", "r");
    if(fptr == NULL){
        return ;
    }
    while(fscanf(fptr, "%s %d", voterList[VoterCount].name, voterList[VoterCount].id ) != EOF){
        VoterCount++;
    }

    fclose(fptr);
}

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
    if(validId(id)){
        voterList[VoterCount].id = id;
    }else{
        printf("Voter id has alrady in use !! Try New one");
        goto askId;
    }
   addVoter( voterList[VoterCount] );
   VoterCount++;
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

void addVoter(struct Voter v){
    FILE *ftr = fopen("voters.txt", "a");

    if(ftr == NULL) return ;

    fprintf(ftr, "%s %d\n", v.name, v.id);
    fclose(ftr);
}

void updateVoteCount(){

    int choice;

    printf("\nYour Choice : ");
    scanf("%d", &choice);

    partyList[choice - 1].voteCount++;   
    printf("... Vote Successfully ...");
}

void PrintParty()
{
    for(int i=0 ; i<Max_Candidate_Count ; i++)
    {
        printf("\n%d - %s",i+1,partyList[i].name);
    }
}


void findWinner(){

    int max = 0 ;
    int curr ; 
    int winner = 0; //Gives the Winner candidate's index number
    for(int i = 0 ; i < Max_Candidate_Count ; i++){
        curr = partyList[i].voteCount;
        winner = curr > max ? i : winner;
        max = fmax(curr , max);
        for(i=0 ; i<Max_Candidate_Count ; i++)
        {
            if(i == winner)
            {
                continue;
            }
            else if(max == partyList[i].voteCount)
            {
                printf("Draw \n %s-%s",partyList[winner].name,partyList[i].name);
                return;
            }
        }
    }

    printf("The Winner of the Election is : %s \n Candidate have total Votes : %d", partyList[winner].name , partyList[winner].voteCount);

}
