#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "test.dat"
#define uint32_t u_int32_t

int  arg_test(int argc, char **argv);
void conversion_test();
void load_data(int **int_array, uint32_t *array_size);
int  find_nth(int *int_array, uint32_t array_size, int n);
void print_array(uint32_t size, int *arr);

int main(int argc, char **argv)
{
    int valid = arg_test(argc, argv);
    // Test function for atoi
    conversion_test();
    
    int nth = -3;
 
    if(valid) {
        int *int_array = NULL;
        uint32_t array_size = 0;
        load_data(&int_array, &array_size);

        // This function prints the content of the array - debugging tool
        print_array(array_size, int_array);

        // Insert your code here (1)
        int n = atoi(argv[1]);

        for (int i = 0; i < array_size-1; i++)
        {
            for (int j = 0; j < array_size-i-1; j++)
            {
                if(int_array[j] < int_array[j+1])
                {
                    int tmp = int_array[j];
                    int_array[j] = int_array[j+1];
                    int_array[j+1] = tmp;
                }

            }
        }
        // ------------------------

        nth = find_nth(int_array, array_size, n);
        if(nth >= 0) {
            printf("---- Answer ----\n");
            printf("The nth value is %d\n", int_array[nth]);
            printf("--------\n");
        } else if(nth == -1) {
            printf("n is too large!\n");
        } else if(nth == -2) {
            printf("Some error!\n");
        } else {
            // Do nothing
        }
    } else {
        // Do nothing
    }
    
    return 0;
}



int arg_test(int argc, char **argv)
{
    int return_val = 0;
    if(argc < 2) {
        fprintf(stderr, "Error: no input entered\n");
        fprintf(stderr, "usage: %s <n>\n", argv[0]);
        fprintf(stderr, "\n");
    } else if(argc > 2) {
        fprintf(stderr, "Error: too many inputs\n");
        fprintf(stderr, "usage: %s <n>\n", argv[0]);
        fprintf(stderr, "\n");
    } else {
        return_val = 1;
    }
    return return_val;
}

void conversion_test()
{
    printf("---- ATOI Sample Usage ----\n");
    char *num_str = "101";
    int num = atoi(num_str);
    printf("The number is %d\n", num);
    printf("--------\n\n");
}

void load_data(int **int_array, uint32_t *array_size)
{
    FILE *fp = NULL;
    fp = fopen(FILE_NAME, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error while loading the file\n");
        exit(EXIT_FAILURE);
    }

    int cnt = 0;
    int tmp = 0;
    while (fscanf(fp, "%d", &tmp) == 1) {
        cnt++;
    }
    fclose(fp);

    int *tmp_array = (int*) malloc(sizeof(int) * cnt);
    fp = fopen(FILE_NAME, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error while loading the file\n");
        exit(EXIT_FAILURE);
    }
    cnt = 0;
    tmp = 0;
    while (fscanf(fp, "%d", &tmp) == 1) {
        tmp_array[cnt] = tmp;
        cnt++;
    }
    fclose(fp);
    
    *int_array = tmp_array;
    *array_size = cnt;
}

// Given n as input, find the nth largest value
// in the list of integers loaded from the file.
// If n is larger than the number of integers,
// return -1.
// Return -2 for any other errors.
// NOTE 1:
// The file used for grading will be different from
// the file given with the homework - it will have
// different number of integers and different integer
// values
int find_nth(int *int_array, uint32_t array_size, int n)
{
    // Insert your code here (2)
    if (n > 0 && ((unsigned int)n) > array_size)
    {
        return -1;
    }

    else if (n > 0)
    {
        int nthIndex;
        int jthLargest;
        int j = 0;
        int i = 0;
        while (i < array_size)                 //This section handles issues with arrays such as [1 1 1 1 1]
        {                                     //In this case, there is not a 3rd largest number so if n is 3 return -2
            if (int_array[i] != jthLargest)
            {
                jthLargest = int_array[i];         //Keeps track of jth largest number and increments j if it reaches the next largest number
                j++;
            }
            if (j == n)                       //In the event that j = n then we have found nth largest number and exit while loop
            {
                nthIndex = i;
                i = array_size;
            }
            i++;
        }

        if(j != n)                         //If while loop completes and j never reaches n, example being [1 1 1 1 1] where n = 3
        {                                  //Then 
            return -2;
        }

        return nthIndex;
        
    }

    else 
    {
        return -2;
    }
    // ------------------------

}

void print_array(uint32_t size, int *arr)
{
   printf("---- Print Array ----\n");
    printf("This file has %d elements\n", size);
    printf("#\tValue\n");
    for(int i = 0; i < size; i++) {
        printf("%d\t%d\n", i, arr[i]);
    }
   printf("--------\n\n");
}

