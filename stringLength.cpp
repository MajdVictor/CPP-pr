#include <iostream>

using namespace std;

int stringLength(char *word){
    int cnt = 0;
    while(word[cnt] != '\0'){
        cnt++;
    }
    return cnt;
}

int main(){

    char inputWord[50];

    cout<<"Enter a word: ";
    cin>>inputWord;
    
    cout<<"length of word in character is : "<<stringLength(inputWord)<<endl;


    return 0;
}