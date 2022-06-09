#include<iostream> 
#include<cstring>
using namespace std;

#define BUFFER_SIZE 1024
#define WORDS_BUFFER_SIZE 64
#define WORD_DELIMINITERS " "


char *read_line(){
    int pos = 0;
    int current_buffer_size = BUFFER_SIZE;
    char *buffer = (char*)malloc(sizeof(char) * current_buffer_size);
    int c; 

    
    if(! buffer){
        cout << "Allocation Error!" << endl;
        exit(1);
    }

    while(1){
        c = getchar();
        if(c == '\n'){
            buffer[pos] = '\0';
            return buffer;
        }
        else{
            buffer[pos] = c;
        }
        pos++;

        if(pos >= BUFFER_SIZE){
            current_buffer_size += BUFFER_SIZE;
            buffer = (char*)realloc(buffer, current_buffer_size);
            if(! buffer){
                cout << "Allocation error!" << endl;
                exit(1);
            }
        }
    }
}

char **split_line(char *line){
    int current_buffer_size = WORDS_BUFFER_SIZE;
    int pos = 0;
    char **words = (char**)malloc(sizeof(char*) * current_buffer_size);
    char *word;

    if(!words){
        cout << "Allocation error!" << endl;
        exit(1);
    }

    word = strtok(line, WORD_DELIMINITERS);
    while(word != NULL){
        words[pos] = word;
        pos++;

        if(pos >= current_buffer_size){
            current_buffer_size += WORDS_BUFFER_SIZE;
            words = (char**)realloc(words, current_buffer_size * sizeof(char*));
            if(!words){
                cout << "Allocation Error !" << endl;
                exit(1);
            }
        }

        word = strtok(NULL, WORD_DELIMINITERS);
    }
    words[pos] = NULL;
    return words; 
}


int main(){
    char* line; 
    char** words;
    int current_buffer_size = BUFFER_SIZE;
    char* target = (char*)malloc(current_buffer_size*sizeof(char));
    int pos = 0;

    cout << "Enter the line: " << endl;


    line = read_line();

    words = split_line(line);

  
    while(words[pos] != NULL){
       
        if(strlen(target) + strlen(words[pos]) >= current_buffer_size){
            current_buffer_size += BUFFER_SIZE;
            target = (char*)realloc(target, current_buffer_size * sizeof(char));
        }

        cout << words[pos] << endl;
        strcat(target, words[pos]);
        strcat(target, " ");
        if(words[pos][0] == 'A' || words[pos][0] == 'a'){
            strcat(target, words[pos]);
            strcat(target, " ");
        }
        pos++;
    }

    cout << target << endl;
    return 0;
}