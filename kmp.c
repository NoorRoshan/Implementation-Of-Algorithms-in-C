#include <stdio.h>
#include <stdlib.h>

void find_substring(char * input_string, int len_input_string, char * pattern, int len_pattern){
    int failure[len_pattern];
    int i = 1, j = 0;
    failure[0] = -1;
    j = failure[0];
    while (i < len_pattern){
        while (j > -1 && pattern[i] != pattern[j]) {
            j = failure[j];
        }
        i = i + 1;
        j = j + 1;
        if(pattern[i] == pattern[j]){
            failure[i] = failure[j];
        }else{
            failure[i] = j;
        }
    }
    i = 0;
    j = 0;
    while (j < len_input_string) {
        while (i > -1 && input_string[i] != pattern[j]) {
            i = failure[i];
        }
        i = i + 1;
        j = j + 1;
        if (i >= len_pattern) {
            printf("Pattern found at %d\n", j-i);
            i = failure[i];
        }
    }
}

int main(){
    char * input_string, * pattern;
    int len_input_string, len_pattern;
    
    printf("Enter the length of the input string:\n");
    scanf("%d", &len_input_string);
    
    printf("Enter the length of the pattern:\n");
    scanf("%d", &len_pattern);
    
    input_string = (char *)calloc(len_input_string+1, sizeof(char));
    pattern = (char *)calloc(len_pattern+1, sizeof(char));
    
    printf("Enter the input string:");
    scanf("%s", input_string);

    input_string[len_input_string] = 0;
    
    printf("Enter the pattern string:");
    scanf("%s", pattern);

    pattern[len_pattern] = 0;

    printf("The input string is: %s$\n", input_string);
    
    printf("The pattern is: %s$\n", pattern);

    find_substring(input_string, len_input_string, pattern, len_pattern);

    return 0;
}