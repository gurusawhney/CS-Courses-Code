//Gurumeher Sawhney gs2605
//Project 4
#include "proj4.h"

/*
Bug 1: Bug 1 is fixed in procline.c on line 12 when I initialized narg to 0. Originally
narg was not initialized so the shell could not keep track of the arguments. This also allows
narg to be initialized to 0 for every command in the shell.

Bug 2: Bug 2 was fixed in procline.c on lines 42-56. This was fixed by checking the arguments
of the command line. If it was just 'cd', 'cd ..' or 'cd *directory_name*' there is corresponding 
code using chdir().

Bug 3: Bug 3 was fixed in procline.c on lines 57. This was fixed by checking the arguments of
the command for 'exit'. When called the shell is exited.

Bug 4: Bug 4 was fixed in proj4.c in line 26 and runcommand.c in line 15. This was fixed by 
ignoring the signal that ctrl+c gives when its run during the shell in main() with SIG_IGN but allowing 
ctrl+c to work during the running of a command via SIG_DFL.

Bug 5: Bug 5 was fixed in proj4.c in line 29. This was fixed by killing the background process 
and then the zombie processes are reaped automatically. I set the handler to sig_ign because 
the handler did not need to do anything else besides wait.
*/

int main()
{
    //run the shell until EOF (keyboard Ctrl+D) is detected 
    while (userinput(  ) != EOF ) {
		if (signal(SIGINT, SIG_IGN) == SIG_ERR) { //ctrl+c calls the signal SIGINT but its ignored
			perror(0);
		}
		if (signal(SIGCHLD, SIG_IGN) == SIG_ERR) { //the process is killed and will be reaped automatically
			perror(0);
		}

        procline();
    }
    return 0;
}
