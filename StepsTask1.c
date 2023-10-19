#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct records {
	char date[11];
	char time[6];
	char steps[];
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FILE *fptr;
    fptr = fopen("FitnessData_2023.csv", "r");

    char line[50];
    char token[50];
    int number_of_records = 0;
    struct records data;

    while (fgets(line, 50, fptr)) {
        number_of_records++;
        if (number_of_records <= 3) {
            tokeniseRecord(line, ",", data.date, data.time, data.steps);

            int length = 0;
            printf("\n%s/%s/", data.date, data.time);
            printf("%s%n", data.steps, &length);
            printf("\nsteplength = %d", length);
        }
    }


}
