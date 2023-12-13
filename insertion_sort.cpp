class Solution
{
    // the array arr has the sorted part in the left and the unsorted part in the right
    // separated by the number at index i.
    // this function will insert this number at index i into the right place in the sorted part
    void insert(int arr[], int i)
    {
        while (i >= 1)
        {
            if (arr[i - 1] > arr[i])
            {
                // swap
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;

                i--;
            }
            else
            {
                break;
            }
        }
    }

public:
    // n: the length of the array
    void insertionSort(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            insert(arr, i);
        }
    }
};
