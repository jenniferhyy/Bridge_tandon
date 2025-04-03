
// Given an array of numbers, write a function to move all 0s 
// to the end of the array while maintaining the relative order of the non-zero elements. 
// Do this in-place.
  
void ArrangeNums(int arr[], size){
  int j = 0;
  for (int i = 0; i < size; i++){
    if (arr[i] != 0){
      arr[j] = arr[i];
      j++;
    }
  }
  for (int i = j; i < size; i++{
    arr[i] = 0;
  }
}

/* Given an array of nums, find the length of the longest sequence of zeroes recursively. You can
use the std::max function. */

maxZeroLength(int arr[], size, startIndex){
  if (startIndex == 0){
    return 0;
  } else {
    int maxlength = 0;
    for (startIndex = 0; startIndex < size; startIndex++){
      if (arr[startIndex] == 0){
        maxlength++;
      } 
    }
  }
  return max(maxlength, maxZeroLength(arr, size, startIndex));
}
