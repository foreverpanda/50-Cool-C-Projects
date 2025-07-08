#include<iostream>
#include<string>

static int finaldiff;

struct player{
    short int highscore ;
    std::string name;
};

void clrscr(){
    std::cout << "\033[2J\033[H";
}

void getUserInput(int *difficulty){
    int userInput;
    std::cin>>userInput;

    if(userInput<1 || userInput>3){
        clrscr();
        std::cout<<"Please enter correct number : ";
        getUserInput(difficulty);
    }
    else{
        *difficulty = userInput;
        finaldiff = userInput;   
    }
}

void showMode(){
    if(finaldiff == 1){
        std::cout<<"NOOB\n";
    }
    else if(finaldiff == 2){
        std::cout<<"MEDIOCRE\n";
    }
    else {
        std::cout<<"HARDCORE\n";
    }
}

void welcomeScreen(){
    clrscr();
    int difficulty;
    std::cout<<"GUESS THE NUMBER [ROAST EDITION]\n";
    std::cout<<"Select Difficulty\n1. Easy\n2. Medium\n3. Hard \nEnter Difficulty [1-3] : ";
    getUserInput(&difficulty);
    clrscr();
    std::cout<<"MODE : ";
    showMode();
}


void createPlayer(player * p){
    std::cout<<"Player : ";
    std::getline(std::cin,p->name);
    for(auto  i : p->name){
        if(!isalpha(i)){
           clrscr();     

            std::cout<<"Please only use A-Z or a-z \n";
            createPlayer(p);
        }
    }
    
    clrscr();     

}

void userData(player *p){
    clrscr();
    std::cout<<"GUESS NUMBER [ROAST EDITION]\n";
    std::cout<<"MODE : ";
    showMode();
    std::cout<<"Player : "<<p->name<<"\n";

}

int main(){

    player * p = new player;

    welcomeScreen();
    createPlayer(p);
    userData(p);




}