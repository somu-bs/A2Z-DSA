// TC - O(nlogn)
// SC - O(1)

void quickSort(int arr[], int low, int high)
    {
        if(low < high) {
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex -1);
            quickSort(arr, partitionIndex +1, high);
        }
    }
   
int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot = arr[low];
   int i = low, j = high;
   while(i < j) {
       while(arr[i] <= pivot && i < high) i++;
       while(arr[j] > pivot && j > low) j--;
       if(i < j) swap(arr[i], arr[j]);
   }
   swap(arr[low], arr[j]);
   return j;
}
