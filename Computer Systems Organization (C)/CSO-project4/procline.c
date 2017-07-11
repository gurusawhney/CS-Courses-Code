//Gurumeher Sawhney gs2605 
//Project 4
#include "proj4.h"


/* shell input line */
int procline(void)
{

    char *arg[MAXARG + 1];  // pointer array for runcommand
    //BUG 1: narg initialized to 0
    int narg = 0;           // number of arguments. 
    int toktype;            // type of token in command
    int type;               // type =  FOREGROUND or BACKGROUND


    while ( 1 ) // loop forever
    {
        // take action according to token type
        switch(toktype = gettok(&arg[narg]))

        {

        case ARG:
            if(narg<MAXARG)
                narg++;
            break;

        case EOL:
        case SEMICOLON:
        case AMPERSAND:
            if(toktype == AMPERSAND)
                type = BACKGROUND;
            else
                type = FOREGROUND;

            if(narg != 0)
            {
                arg[narg] = 0;
                
                //BUG 2: the cd command
                if (strcmp(arg[0],"cd") == 0) //Checks if 'cd' is an argument
                {
                    if (arg[1] == 0) {      //If no second argument
                        chdir(getenv("HOME")); //if just 'cd' takes user to home directory
                    } 
                    else {
                        if ( strcmp(arg[1], "..") == 0) { //if the second argument is '..'
                            chdir("../"); //changes directory to the parent
                        }
                        else  { 
                            chdir(arg[1]); //changes directory to the second argument
                        }
                    }                   
                }
                //BUG 3: the exit command
                else if (strcmp(arg[0], "exit") == 0) {  //Checks if 'exit' is an argument
                    exit(0); //exits the program with status 0.
                }
                else {
                    runcommand(arg,type); //run command
                }           
            }

            narg = 0; //this resets the arguments to 0 every line
            
            if( toktype == EOL )
                return;
            break;
        }
    }
}
