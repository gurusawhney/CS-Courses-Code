
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Decodes the nursery rhyme "Mary Had a Little Lamb"
 */ 
// ./prob2 mary_corrupt.txt mary_fixed.txt

int main (int argc, char *argv[] )  {
    if(argc == 1) { //makes sure there are arguments (assuming you know there need to be 2)
    	return 0;
    }
    FILE * inputfile; 
    FILE * outputfile;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    inputfile = fopen(argv[1],"r"); //opening the input file for reading
    outputfile = fopen(argv[2],"w"); //opening/creating the output file for writing

    if (inputfile == NULL) { //error check that the reading file opened
    	printf("Error opening reading file\n");
    }
    else {
    	printf("Opened reading file\n");
    }

    while((read = getline(&line, &len, inputfile)) != -1) { //reading the file line by line
        char * temp; //iterator through the line
        unsigned char fixed; //character for bitwise operating- need to use an unsigned char
        for(temp = line;*temp != '\0';temp++) {
            fixed = (unsigned char) *temp; 
            fixed = (fixed << 4) ^ (fixed >> 4); //the swap method
            *temp = (char) fixed; 
        }
    	fwrite(line,sizeof(*line),read,outputfile); //writing the decoded 
    }
    printf("Wrote the writing file\n");
    
    free(line);
    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
