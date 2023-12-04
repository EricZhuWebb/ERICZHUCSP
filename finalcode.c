#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000


int *readFile(string fileName, int size, int size2);
int linearSearch(int array[], int guess, int size);
int binarySearch(int array[], int guess, int size);
int *bubbleSort(int array[], int size);
int *selectionSort(int array[], int size);
void printArray(int array[], int size);
void Menu();
void writeArray(int array[], int size);


int main(void)
{
    int choice;
    do {
        Menu();
        choice = get_int("Please enter your choice 1-5: ");
    } while (choice != 5);


    return 0;
}


int *readFile(string fileName, int size, int size2)
{
    FILE* file = fopen(fileName, "r");
    char line[size2];
    char options[size][size2];
    static int numbers[SIZE2];
    for (int i = 0; i < size; i++)
    {
        fscanf(file, "%s", options[i]);
        numbers[i] = atoi(options[i]);
    }
    fclose(file);
    return numbers;
}


int linearSearch(int array[], int guess, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == guess)
        {
            return i;
        }
    }
    return -1;
}


int binarySearch(int array[], int guess, int size)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == guess)
            return mid;
        if (array[mid] < guess)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


int *bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}


int *selectionSort(int array[], int size)
{
    int index;
    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[index])
            {
                index = j;
            }
        }
        if (index != i)
        {
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
    return array;
}


void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", array[i]);
    }
}


void Menu()
{
    printf("=====================================\n");
    printf("#               MENU                #\n");
    printf("#   1) Read a file                  #\n");
    printf("#   2) Sort an Array                #\n");
    printf("#   3) Search for a value in array  #\n");
    printf("#   4) Write an array to File       #\n");
    printf("#   5) Exit                         #\n");
    printf("=====================================\n");
}


void writeArray(int array[], int size)
{
    string name = get_string("How do you want to call your file? ");
    char filename[50];
    sprintf(filename, "%s.txt", name);
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", array[i]);
    }
    fclose(file);
}
