#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct records {
	char date[11];
	char time[6];
	int steps;
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

    //Creates file pointer and opens file in read mode
    FILE *fptr;
    fptr = fopen("FitnessData_2023.csv", "r");

    char line[50];
    int number_of_records = 0;

    // Counts the number of records in the input file
    while (fgets(line, 50, fptr)) 
    {
        number_of_records++;
    }

    fclose(fptr);


    // Closes and re-opens fiel to reset pointer to the start of the file
    fptr = fopen("FitnessData_2023.csv", "r");
    struct records file_data[number_of_records];
    char steps[10];
    int stepsint;
    int i = 0;

    while (fgets(line, 50, fptr)) 
    {
        tokeniseRecord(line, ",", file_data[i].date, file_data[i].time, steps);

        // Converts character array to integer
        // https://stackoverflow.com/questions/10204471/convert-char-array-to-a-int-number-in-c
        sscanf(steps, "%d", &stepsint);
        
        file_data[i].steps = stepsint;
        i++;
    }
    
    // Prints out the required information
    printf("Number of records in file: %d\n", number_of_records);
    
    for (int j = 0; j < 3; j++) {
        printf("%s/%s/%d\n", file_data[j].date, file_data[j].time, file_data[j].steps);
    }

    fclose(fptr);

}
