#include <libc.h>

// Function to find the LIS and store it in new array
void findLIS(int arr[], int n, int new[], int *len_new) {
    int lis[6];


    int i;
    int j;

    i = 0;
    while (i < n)
    {
        lis[i] = 1;
        j = 0;
        while(j < i)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
            j++;
        }
        i++;
    }

    // get the max from lis

    i = 0;
    int max_lis = 0;
    int index = 0;
    while(i < n)
    {
        if (lis[i] > max_lis)
        {
            max_lis = lis[i];
            index = i;
        }
        i++;
    }

    // while (index >= 0)
    // {
    //     if (lis[index] == max_lis)
    //     {
    //         new[max_lis - 1] = arr[index];
    //         max_lis--;
    //     }
    //     index--;
    // }




    // int i = 0;
    // while (i < n) {
    //     lis[i] = 1;
    //     int j = 0;
    //     while (j < i) {
    //         if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
    //             lis[i] = lis[j] + 1;
    //         }
    //         j++;
    //     }
    //     i++;
    // }
    
    // int max_lis = 0;
    // int index = 0;
    // i = 0;
    // while (i < n) {
    //     if (lis[i] > max_lis) {
    //         max_lis = lis[i];
    //         index = i;
    //     }
    //     i++;
    // }

    int current_lis = max_lis;
    *len_new = max_lis;
    i = index;
    while (i >= 0) {
        if (lis[i] == current_lis) {
            new[current_lis - 1] = arr[i];
            current_lis--;
        }
        i--;
    }
   int k = 0;
    while (k < ) {
        printf("%d, ", new[k]);
        k++;
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 0, 1, 12, 8, 18};
    int n = 6;  // Length of the array
    int new[6];  // Array to store the LIS
    int len_new = 0;  // Length of the LIS

    // Find the LIS and store it in new array
    findLIS(arr, n, new, &len_new);

    // Print the length of the LIS

    // Print the elements of the LIS
    int k = 0;
    while (k < len_new) {
        printf("%d, ", new[k]);
        k++;
    }
    printf("\n");

    return 0;
}
