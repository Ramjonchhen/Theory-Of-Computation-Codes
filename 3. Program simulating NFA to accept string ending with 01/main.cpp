#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


vector <int> v1;

void state0(char input) {
    if (input=='0') {
        v1.push_back(0);
        v1.push_back(1);
    } else if(input=='1') {
        v1.push_back(0);
    }
}

void state1(char input) {
    if(input=='1') {
        v1.push_back(2);
    }
}

void state2(char input) {
    return;
}

void displayVector() {
    printf("\n The vector is: ");
    for(int i=0; i<v1.size(); i++) {
        cout<<v1[i]<<"\t";
    }
    cout<<endl;
}

int doesContinFinalState() {
    for(int i=0; i<v1.size(); i++) {
            if(v1[i]==2) {
                return 1;
            }
    }
    return 0;
}

int isAccepted(string str)
{
     v1.clear();
    // store length of string
    int i,j;
    state0(str[0]);
    //displayVector();

    for (i = 1; i <str.length(); i++) {
            //cout<<"i: "<<i<<endl;
            //cout<<"str: "<<str[i]<<endl;
        if(v1.empty()) {
            return 0;
        }else {
            //displayVector();
            int prevSize = v1.size();
            for(j=0; j<prevSize; j++){
                    //cout<<"v1[j]: "<<v1[j]<<endl;
                if(v1[j]==0) {
                    state0(str[i]);
                } else if(v1[j]==1) {
                    state1(str[i]);
                } else {
                    state2(str[i]);
                }
            }
            //displayVector();
            for(j=0; j<prevSize; j++) {
                v1.erase(v1.begin());
            }
            //displayVector();
        }
    }
    if(doesContinFinalState()) {
        return 1;
    }else {
        return 0;
    }


}

int main()
{
    while(1) {
        string str;
        cout<<"\n Enter the String to check: ";
        cin>>str;

        if(isAccepted(str)){
            cout<<"\n String Is Accepted \n";
        }
        else {
            cout<<"\n Sting Is not aceepted \n\n";
        }
    }

    return 0;
}
