//David Hughes
//CSC 241 Canas
//Lab 3

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	while(1){
		int i,procid, numbIn;
		char line[400];
		char * temp;
		int amp = 0;
		 
		//Prompt
		printf("#>");

		 //Scan whole line
		gets(line);

		//To make sure that the input is the size of the largest possible word
		char *input[strlen(line)];

		//parsing
		temp = strtok(line," ");
		input[0]=temp;
		for(i = 1;; i++){
		    temp = strtok(NULL," ");
		    if(temp == NULL){
			numbIn = i;
			break;
		    }else if(strcmp(temp,"&")==0){
				amp = 1;	
		    }else{
			    input[i]=temp;   
		    }
		    
		}

		input[i] =(char*)NULL;

		//fork parent
		procid = fork();

		//Child do
		if(procid == 0){
		//Handle Child

		execvp(input[0],input);

		}else if(amp == 0){

		//parent do
		//wait child
		wait(procid);
		}

	}
}

