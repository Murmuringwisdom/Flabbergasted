#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
    srand(time(NULL));
    char guessword[][20]={
        "google",
        "facebook",
        "youtube",
        "instagram",
        "linkedin",
        "hackerrank",
        "stackoverflow"
    };
    int randIndex=rand()%7;
    int i=0;
    int lives=5;
    int numcorrect=0;
    int oldcorrect=0;
    int len_word=strlen(guessword[randIndex]);
    int letterguessed[8]={0,0,0,0,0,0,0,0};
    int letterentered;
    int quit=0;
    char guess[20];
    while(numcorrect<len_word){
        printf("\n\n---New Turn---\nHangMan Game:");
        for(i=0;i<len_word;i++){
            if(letterguessed[i]==1){
                printf("%c",guessword[randIndex][i]);
            }
            else{
                printf("-");
            }
            }
            printf("\n");
        
        printf("No. of correct letter so far: %d\n",numcorrect);
        printf("Enter a guess letter: ");
        fgets(guess,20,stdin);
        if(strncmp(guess,"quit",4)==0){
            quit=1;
            break;
        }
        letterentered=guess[0];
        printf("Letter guessed: %c\n",letterentered);
        oldcorrect=numcorrect;
        for(i=0;i<len_word;i++){
            if(letterguessed[i]==1){
                continue;
            }
            if(letterentered==guessword[randIndex][i]){
                letterguessed[i]=1;
                numcorrect++;
            }
        }
        if (oldcorrect==numcorrect){
            lives--;
            printf("%d lives remaining.\n",lives);
            if(lives==0){
                break;
            }
        }
    }
    
    if(quit==1){
        printf("\nUser quit early\n");
    }
    else if(lives==0){
        printf("You are dead.\n");
        printf("The word was: [%s]\n",guessword[randIndex]);
    }
    else{
        printf("You win.\n");
    }
return 0;
}