#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
 //check if the right amount of argumenents is added
    if (argc != 2) {
        printf("Error: Expected one argument, found %d.\n", argc - 1);
        return -1;
    }

 //open the file but only read it
    int file = open(argv[1], O_RDONLY);

 //check if the file is opened correctly
    if (file == -1) {
        perror("Error");
        return -1;
    }


 //initialilze lines, words, and characters
 //initialize word detection flag
    int lines = 0, words = 0, characters = 0, inWord = 0;
    char ch;
    ssize_t status; //cehck if read was successful


 //read all characters one by one until EOF
    do {

        status = read(file, &ch, 1); //read one character at a time

 //handle the read errors
        if (status < 0) {
            perror("Error");
            close(file);
            return -1;
        } //check for end of file 
        else if (status == 0) {
            if (inWord) {
                words++;
                lines++;
            }
            break;
        } //process the read character 
        else {
            characters++;
            if (ch == '\n') { //chexk: is char \n?
                lines++;
                if (inWord) { //if a word is in progress, then ++wordcount and reset the word flag
                    words++;
                    inWord = 0;
                }
            }
            else if (isspace(ch)) { //check: is char a whitespace?
                if (inWord) { //if word is in progress, then ++wordcount and reset the word flag
                    words++;
                    inWord = 0;
                }
            } //check if word is printable character
            else {
                inWord = 1; //wordflag set to indicate word is in progress
            }
        }

    }
    while (status >= 1);

 //close the file
    close(file);
 //print lines, words, characters
    printf("%d, %d, %d\n", lines, words, characters);
    return 0;
}

