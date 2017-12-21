#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void selection ();
void play (char name [30]);
void arcade(char name[30]);
void viewScore();


main ()
{
	system("COLOR 0d");
	printf("\n*************** NUMBER GUESSING GAME MENU v1.0 *******************\n");
	printf("\t \t 1. Create player name \n");
	printf("\t \t 2. Play \n");
	printf("\t \t 3. Arcade Mode \n");
	printf("\t \t 4. View Score \n");
	printf("\t \t 5. Quit \n");
	printf("******************************************************************\n");
	selection();
}

void selection ()
{
//	FILE* fpointer1;
	int i;
	char name [30];
	int response;
//	char view_score_mou;
//	FILE* fpointer;
	printf("Your option: ");
	scanf("%d",&i);
	switch (i)
	{
		case 1 :
		printf("Enter your name : ");
		scanf(" %s",&name);
		system("cls");
		play(name);
		printf("Do you want to try out arcade mode? (1.YES 2. NO)");
		scanf("%d",&response);
		if (response==1)
		{
			system("cls");
			arcade(name);
			viewScore();	
			break;
		}
		else 
		{
			viewScore();
			break;
		}
		viewScore();
		case 2 :
		strcpy(name,"Anonymous");
		system("cls");
		play(name);
		printf("Do you want to try out arcade mode? (1.YES 2. NO)");
		scanf("%d",&response);
		if (response==1)
		{
			system("cls");
			arcade(name);
			viewScore();	
			break;
		}
		else 
		{
			viewScore();
			break;
		}
		viewScore();
		
		break;
		case 3:
    	strcpy(name,"Anonymous");
    	system("cls");
    	arcade(name);
    	printf("Do you want to try out normal mode? (1.YES 2. NO)");
		scanf("%d",&response);
		if (response==1)
		{
			system("cls");
			play(name);
			viewScore();	
			break;
		}
		else 
		{
			viewScore();
			break;
		}
    	viewScore();
    	break;
    	case 4:
   		viewScore();
   		break;
   		case 5:
   		printf("\nThank you for your time !\n");
   		exit(0);
   		default:
   		printf("\ninvalid input\n");
   		selection();
   		
	}
	
}

void play(char name [30])
{
	//declare var
	int i;

	srand( time( NULL ));
	int r ;
	r= rand() % 100 +1;
    int correct = 0; 
    int num; 
    int counter = 0; 
    int score [40];
	int response;
	char view_score_mou;
	FILE* fpointer;
	
	printf("\t  _   _   _____   ______   _   _   _      ___      _           _   _   _   _____   _____    ______      \n");
	printf("\t [ . [ ] [  _  ] [  __  ] [ . [ ] / ]    / _ .    [ ]         [ . [ ] / ] [  _  ] [ ___ .  [ _____]     \n");
	printf("\t [  .[ ] [ ] [ ] [ ]__[ ] [  .[ ]/  ]   / / . .   [ ]         [  .[ ]/  ] [ ] [ ] [ ]  [ ] [ ]____      \n");
	printf("\t [ ].[ ] [ ] [ ] [    __] [ ].   /[ ]  / /___. .  [ ]         [ ].   /[ ] [ ] [ ] [ ]  [ ] [  ____]     \n");
	printf("\t [ ] . ] [ ]_[ ] [ ]. .   [ ] . / [ ] / /     . . [ ]____     [ ] . / [ ] [ ]_[ ] [ ]__[ ] [ ]____      \n");
	printf("\t [_] [_] [_____] [ ] .__  {_] [_] [_][_]       [_][______]    [_] [_] [_] [_____] [_____.  [______]     \n");
	printf("Let's start!\n");
	
		do {
		
			do {
    			printf("What is my number?! ;) "); 
        		scanf("%d", &num);
        		if (num == r) 
			{
       		 	counter++;
       		 	printf("You guessed correctly in %d tries! Congratulations!\n", counter);
       		 	
       		 	fpointer=fopen("Score Sheet.txt","a+");
				fprintf(fpointer,"\nNAME: %s \n",name);
				fprintf(fpointer,"SCORE: %d \n",counter);
				fprintf(fpointer,"*************************");
				fclose(fpointer);
            	correct = 1; 
  			}

		        if (num < r) 
				{
    	    	    counter++;
        	    	printf("Your guess is too low. Guess again.\a ");
	 			}

		        if (num > r) 
				{ 
        		    counter++; 
            		printf("Your guess is too high. Guess again.\a ");
        		}
    		} while (correct == 0);
    		
    		printf("Do you want to play again? (1. YES 2. NO):");
    		scanf("%d",&response);
    		correct=0;
    		counter=0;
	}while(response==1);
	

}

void arcade(char name [30])
{
	int response;
	int iSecret, iGuess;
  	srand(time(NULL));
  	iSecret=rand()% 10+1;
  	int tries=0, success=0;
  	FILE* fpointer1;
  	fpointer1 = fopen("Diff Mode Score.txt","a");
  	
printf("\t        ___      ______    _____      ___      _____   ______         _   _   _   _____   _____    ______      \n");
printf("\t       / _ .    [  __  ] /______]    / _ .    [  __ . [ _____]       [ . [ ] / ] [  _  ] [ ___ .  [ _____]     \n");
printf("\t      / / . .   [ ]__[ ][ ]         / / . .   [ ]  [ ][ ]____        [  .[ ]/  ] [ ] [ ] [ ]  [ ] [ ]____      \n");
printf("\t     / /___. .  [    __][ ]        / /___. .  [ ]  [ ][ ]____]       [ ].   /[ ] [ ] [ ] [ ]  [ ] [  ____]     \n");
printf("\t    / /     . . [ ]. .  [ ]____   / /     . . [ ]__[ ][ ]____        [ ] . / [ ] [ ]_[ ] [ ]__[ ] [ ]____      \n");
printf("\t   [_]       [_][_] .__  .______][_]       [ ][_____. [______]       [_] [_] [_] [_____] [_____.  [______]     \n");
	do{
		printf("\nWelcome to the number guessing game!\nFor each game, you have at most 20 chances to guess a secret number from 1 to 10.\n" );
		for (tries=0; tries < 20; tries++)
		{
			printf("Please enter a number between 1 to 10!\n" );
			printf("Your guess is ");
  			scanf("%d",&iGuess );
 			 if (iGuess== iSecret) {
   				 printf("\nCongratulations!You've got it correctly!\n");
   
    			success++;
    			printf("Your number of successful tries : %d\n",success);
    			iSecret= rand()% 10+1;
 			 }
  			else if (iGuess> iSecret){
		 	printf ("\nYour guess was too high.\n\a");
 
 			 }
 			 else if (iGuess < iSecret){
 			 printf ("\nYour guess was too low.\n\a");

  			}
		}
		fprintf(fpointer1,"\nNAME: %s \n",name);
		fprintf(fpointer1,"\nSCORE: %d\n",success);
		fprintf(fpointer1,"*************************");
		fclose(fpointer1);
		printf("\nYour number of successful tries : %d\n",success);
  		printf ("You have reached your 20th trials. The correct number is %d.\n", iSecret);
  		printf("Do you want to play again? (1. YES 2. NO):");
  		scanf("%d",&response);
	}while (response==1);
  	
}

void viewScore()
{
	FILE * fpointer;
	FILE *fpointer1;
	char view_score_mou;
	int response;
	printf("Do you want to view score?(Y/N):");
	scanf(" %c",&view_score_mou);
	switch(view_score_mou)
	{
		case 'y':
		do 
		{
			printf("1. NORMAL MODE 2. ARCADE MODE:");
			scanf("%d",&response);
			if (response==1)
			{
				fpointer=fopen("Score Sheet.txt","r");
				char singleLine[150];
				while(!feof(fpointer))
				{
				fgets(singleLine,150,fpointer);
				puts(singleLine);
				}
				fclose(fpointer);
			}
			else if (response==2)
			{
				fpointer1=fopen("Diff Mode Score.txt","r");
				char singleLine[150];
				while(!feof(fpointer1))
				{
					fgets(singleLine,150,fpointer1);
					puts(singleLine);
				}
			}
			else
			{
			break;
			}
			
			printf("\nView score for other mode? (1.YES 2.NO): ");
			scanf("%d",&response);
		}while (response==1);

		}
			printf("\nThank you for your time !\n");
   	}



	
	

