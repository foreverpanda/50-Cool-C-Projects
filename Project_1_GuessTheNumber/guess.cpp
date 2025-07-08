#include<iostream>
#include<string>
#include<cstring>
#include<chrono>
static int finaldiff;

struct player{
    short int highscore ;
    std::string name;
    short int life;
    short int difficulty;
};

void game(player *);
int generateRandomNumber(player * p){
    int number = 0;
    int seed = std::time(0);
    srand(seed);
    if(p->difficulty == 1){
        number = 1+rand()%10;
    }
    if(p->difficulty == 2){
        number = 1+rand()%20;
    }
    else{
        number = 1+rand()%50;
    }

    return number;
}

void clrscr(){
    std::cout << "\033[2J\033[H";
}

void getUserInput(int *difficulty){
    int userInput;
    std::cin>>userInput;
    std::cin.ignore();


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
        std::cout<<"NOOB\t\t";
    }
    else if(finaldiff == 2){
        std::cout<<"MEDIOCRE\t\t";
    }
    else {
        std::cout<<"HARDCORE\t\t";
    }
}

void welcomeScreen(){
    clrscr();
    int difficulty;
    std::cout<<"\t\t\tGUESS THE NUMBER [ROAST EDITION]\n";
    std::cout<<"Select Difficulty\n1. Easy\n2. Medium\n3. Hard \nEnter Difficulty [1-3] : ";
    getUserInput(&difficulty);
    clrscr();
    std::cout<<"MODE : ";
    showMode();
}


void createPlayer(player * p){
    std::cout<<"Player : ";
    std::string temp;
    std::getline(std::cin,temp);
    p->name = temp;
    bool flag = false;
    for(auto  i : p->name){
        if(!isalpha(i)){
          flag = true;
          break;
        }
    }
    if(flag){
        clrscr();     
        std::cout<<"Please only use A-Z or a-z \n";
        createPlayer(p);
    }

    clrscr();     
}

void userData(player *p){
    clrscr();
    std::cout<<"\tGUESS NUMBER [ROAST EDITION]\n";
    std::cout<<"MODE : ";
    showMode();
    std::cout<<"Player : "<<p->name;
    std::cout<<"\tLife : "<<p->life<<"\n";
}

void endScreen(player *p){
    clrscr();
        std::cout<<"MODE : ";
        showMode();
        std::cout<<"Player : "<<p->name<<std::endl;
        std::cout<<"Score : "<<p->highscore<<std::endl;
        std::cout<<"==================I HOPE WE DONT SEE EACH OTHER AGAIN=================\n";
        exit(0);
}


void resumeOrExit(player *p){
    std::cout<<"Do you want to continue ? [Y/N]";
    std::cin.ignore();
    char continueOrNot ;
    std::cin>>continueOrNot;
    if(continueOrNot == 'Y' || continueOrNot == 'y'){
        clrscr();
        game(p);
    }
    else{
        endScreen(p);

    }

}

void game(player *p){
    userData(p);
    int randomNumber = generateRandomNumber(p);
    std::cout<<"Cheat : "<<randomNumber<<std::endl;
    int playerGuess;
    while(p->life>0){
        std::cout<<"Guess the number : ";
        std::cin>>playerGuess;
        if(playerGuess == randomNumber){
        std::cout<<"Waah bete mauj krdi\n";
        p->highscore++;
        resumeOrExit(p);
        }
        else if(playerGuess > randomNumber){
            std::cout<<"You guessed a bit high\n";
           p->life--;

            std::cout<<"Life : "<<p->life<<"\n";

        }
        else{
            std::cout<<"You guessed a bit low.\n";
           p->life--;
           std::cout<<"Life : "<<p->life<<"\n";


        }
    }
    if(p->life == 0)
    endScreen(p);
}

int main(){

    player * p = new player;
    p->difficulty = finaldiff;
    p->life = 3;

    welcomeScreen();
    createPlayer(p);
    game(p);


}