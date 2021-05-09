/*
    program to seperate vowel and consonat word using dfa

    The program is designed to seperate vowels and consonate from a file

    currently the file to seperate vowels and consonant is paragraph.txt
    location of paragraph.txt is stored in e:\\try\\paragraph.txt

    the programs sepeartes the vowels and consonant and stores in two different files

    consonant.txt storing all the consonant word contained in paragraph.txt
    vowels.txt storing all the vowel word contained in paragraph.txt

    consonants.txt and vowels.txt are both store in the directory e:\\try
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dfa = 0;


void state0(char input) {
    printf("input %c \n",input);
    if(input=='a' || input=='e' || input=='i' || input=='o' || input=='u') {
        dfa = 1;
    } else {
        dfa = 2;
    }
}

void state1(char input) {
    dfa = 1;
}

void state2(char input) {
    dfa = 2;
}

int seperate(char* str) {
    int len = strlen(str);
    int i;
    for(i=0; i<len; i++) {
       if(dfa==0) {
        state0(str[i]);
       } else if(dfa==1) {
            state1(str[i]);
       } else if(dfa==2){
            state2(str[i]);
       }
    }
    printf("%d \n",dfa);
    return dfa==1? 1: 0;
}

int main()
{
    FILE *fptr,*fptr1,*fptr2;
    char buff[255];
    char temp[255];

    fptr=fopen("E:\\try1\\paragraph.txt","r");
    fptr1 = fopen("E:\\try1\\vowels.txt","w");
    fptr2 = fopen("E:\\try1\\consonant.txt","w");

    if(fptr==NULL) {
        printf("\n Error while reading the file");
        exit(1);
    } else {
        printf("\n Reading from the file");
    }


    int countv = 1 , countc = 1;
    while(fscanf(fptr, "%s", buff)!=EOF){
            dfa = 0;
        strcpy(temp,buff);
        strlwr(temp);
        if(seperate(temp)) {
            fprintf(fptr1,"Vowel %d: %s \n",countv++,buff);
        } else {
            fprintf(fptr2,"Consonant %d: %s \n",countc++,buff);
        }
   }
   fclose(fptr);
    return 0;
}
