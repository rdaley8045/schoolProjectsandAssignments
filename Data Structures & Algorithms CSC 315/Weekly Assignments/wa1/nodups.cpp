#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n);
void swapNumbers(int *leftNumber, int *rightNumber);
int removeDuplicate(int arr[], int n);


int main()
{

    int listOfNumbersInputed [1000];
    int i = 0;
    int totalNumberOfInputs = 0;
    int newNumberOfNums;

    while (cin>>listOfNumbersInputed[i])
    {
        i++;
        totalNumberOfInputs++;
    }

    bubbleSort(listOfNumbersInputed, totalNumberOfInputs);

    newNumberOfNums = removeDuplicate(listOfNumbersInputed,totalNumberOfInputs);

    for (i=0; i < newNumberOfNums; i++)
    {
        cout << listOfNumbersInputed[i] << endl;
    }

    return 0;
}

void bubbleSort(int arr[], int n)
{
 
    int i,j;
    for (i=0; i<n-1;i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                swapNumbers(&arr[j], &arr[j+1]);
        }
    }
}


void swapNumbers(int *leftNumber, int *rightNumber)
{
    int temp = *leftNumber;
    *leftNumber  = *rightNumber;
    *rightNumber = temp;
}

int removeDuplicate(int arr[], int n)
{
    int i,j;
    int temp[n];
    
    if (n==0 || n == 1)
        return n;
    
    j=0;

    for(i=0; i<n-1; i++)
    {
        if (arr[i] != arr[i+1])
            temp[j++]= arr[i];
    }

    temp[j++] = arr[n-1];

    for (i=0; i < j; i++)
    {
        arr[i] = temp[i];
    }

    return j;
}
