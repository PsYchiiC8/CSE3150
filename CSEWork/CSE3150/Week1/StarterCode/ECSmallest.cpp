// You are given an array of integers (which can be positive or negative). You want to find the smallest integer in this array. If the array is empty, return 0; otherwise return the smallest value. 
// This tests whether you can do simple loop in C and handle basic logic
int ECSmallest(int *arrOfInts, int szArr)
{
  // arrOfInts: pointer to the array of integers
  // szArr: number of elements in the array
  // your code here

  if(szArr <= 0 || arrOfInts == nullptr){
      return 0;
  }


  int smallest = arrOfInts[0];

  int i;

  for(i = 0; i < szArr; i++){
      if(arrOfInts[i] < smallest){
          smallest = arrOfInts[i];
      }
  }

  return smallest;

}
