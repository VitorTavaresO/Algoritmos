#include <stdio.h>

// function definition for linear search
int linearSearch(int arr[], int size, int key)
{
    int index;
    // loop for traversing the array from 0 to the number of elements-1
    for (index = 0; index < size; index++)
        if (arr[index] == key) // comparing each element with the key element
            return index;
    return -1;
}
// Driver code
int main()
{
    // declaration of the array and other variables
    int arr[20], size, key, i, index;
    printf("Number of elements in the list: ");
    scanf("%d", &size);

    printf("Enter elements of the list: ");
    // loop for the input of elements from 0 to number of elements-1
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search ie. key element: ");
    scanf("%d", &key);

    index = linearSearch(arr, size, key); // calling the function

    if (index == -1) // condition to check whether key found or not
        printf("Key element not found");
    else
        printf("Key element found at index %d", index); // printing the index if key found

    return 0;
}