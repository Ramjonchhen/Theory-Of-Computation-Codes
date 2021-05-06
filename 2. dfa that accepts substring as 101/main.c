#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// program to accept sub string of 101 as dfa

int dfa = 0;

void start(char c) {
    if(c=='0') {
        dfa = 0;
    } else if(c=='1'){
        dfa = 1;
    } else {
        dfa = -1;
    }
}

void state1(char c) {
    if(c=='0') {
        dfa = 2;
    } else if(c=='1'){
        dfa = 1;
    } else {
        dfa = -1;
    }
}

void state2(char c) {
    if(c=='0') {
        dfa = 0;
    } else if(c=='1'){
        dfa = 3;
    } else {
        dfa = -1;
    }
}

void state3(char c) {
    if(c=='0' || c=='1') {
       dfa = 3;
    } else {
        dfa = -1;
    }
}

int isAccepted(char str[])
{
    // store length of string
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
            printf("dfa %d\n",dfa);
        if (dfa == 0)
            start(str[i]);

        else if (dfa == 1)
            state1(str[i]);

        else if (dfa == 2)
            state2(str[i]);

        else if (dfa == 3)
            state3(str[i]);
        else
            return 0;
    }
    printf("dfa %d\n",dfa);
    if (dfa == 3){
        return 1;
    }
    else{
     return 0;
    }
}



int main()
{
    char str[100];
    while(1) {
            printf("\n Enter the String: ");
            dfa = 0;
        scanf("%s",&str);
        if (isAccepted(str)) {
         printf("\n ACCEPTED");
        }
        else{
           printf("\n NOT ACCEPTED \n");
        }

    }

    return 0;
}
