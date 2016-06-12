#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b)
{
  return ( *(int*)a - *(int*)b );
}

double easyversion(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  int temp[nums1Size + nums2Size];
  int i;
  for (i = 0; i < nums1Size; i++)
  {
    temp[i] = nums1[i];
  }
  for (i = 0; i < nums2Size; i++)
  {
    temp[nums1Size + i] = nums2[i];
  }
  qsort(temp, nums1Size + nums2Size, sizeof(int), compare);

  if ((nums1Size + nums2Size) % 2 == 1)
    return (double)temp[(nums1Size + nums2Size) / 2];
  else
    return (double)(temp[(nums1Size + nums2Size) / 2 - 1] +
                    temp[(nums1Size + nums2Size) / 2]) / 2;
}

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
  double mid1 = 0.0;
  double mid1_left = 0.0;
  double mid1_right = 0.0;
  double mid2 = 0.0;
  double mid2_left = 0.0;

  double mid2_right = 0.0;

  if (nums1Size <= 2 || nums2Size <= 2)
    return easyversion(nums1, nums1Size, nums2, nums2Size);



  int* nums1_new;
  int* nums2_new;
  int nums1Size_new;
  int nums2Size_new;
  int reduced_size;

  if (nums1Size % 2 == 0 && nums2Size % 2 == 0)
  {
    mid1 = (double)(nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2;
    mid2 = (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2;
    reduced_size = (nums1Size < nums2Size) ? (nums1Size / 2 - 1)
                                           : (nums2Size / 2 - 1);
  }

  if (nums1Size % 2 == 0 && nums2Size % 2 == 1)
  {
    mid1 = (double)(nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2;
    mid2 = (double)nums2[nums2Size / 2];
    reduced_size = (nums1Size < nums2Size) ? (nums1Size / 2 - 1)
                                           : (nums2Size / 2);
  }

  if (nums1Size % 2 == 1 && nums2Size % 2 == 0)
  {
    mid1 = (double)nums1[nums1Size / 2];
    mid2 = (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2;
    printf("2:mid1:%f, 2:mid2:%f\n", mid1, mid2);
    reduced_size = (nums1Size < nums2Size) ? (nums1Size / 2)
                                           : (nums2Size / 2 - 1);
  }

  if (nums1Size % 2 == 1 && nums2Size % 2 == 1)
  {
    mid1 = (double)nums1[nums1Size / 2];
    mid2 = (double)nums2[nums2Size / 2];
    reduced_size = (nums1Size < nums2Size) ? (nums1Size / 2)
                                           : (nums2Size / 2);
  }

  if (mid1 < mid2)
  {
    nums1_new = nums1 + reduced_size;
    nums2_new = nums2;
    nums1Size_new = nums1Size - reduced_size;
    nums2Size_new = nums2Size - reduced_size;
  }
  else
  {
    nums1_new = nums1;
    nums2_new = nums2 + reduced_size;
    nums1Size_new = nums1Size - reduced_size;
    nums2Size_new = nums2Size - reduced_size;
  }

  // printf("%d, %d, %d, %d\n", nums1_new[0], nums1Size_new,
  //                            nums2_new[0], nums2Size_new);
  return findMedianSortedArrays(nums1_new, nums1Size_new,
                                nums2_new, nums2Size_new);
}


int main(int argc, char** argv)
{
  int test1[4] = {2, 3, 5, 6};
  int test2[2] = {4, 7};
  double rtn = findMedianSortedArrays(test1, 4, test2, 2);
  printf("%f", rtn);
  return 0;
}



  // if (nums1Size == 1)
  // {
  //   mid1 = nums1[0];
  //   if (nums2Size % 2 == 0)
  //   {
  //     mid2_left = nums2[nums2Size / 2 - 1];
  //     mid2_right = nums2[nums2Size / 2];
  //     if (mid2_left > mid1) {return mid2_left;}
  //     else if(mid2_right < mid1) {return mid2_right;}
  //     else {return mid1;}
  //   }
  //   else
  //   {
  //     mid2 = nums2[nums2Size / 2];
  //     mid2_left = nums2[nums2Size / 2 - 1];
  //     mid2_right = nums2[nums2Size / 2 + 1];
  //     if (mid2_left > mid1) {return (mid2_left + mid2) / 2;}
  //     else if(mid2_right < mid1) {return (mid2_right + mid2) / 2;}
  //     else {return (mid1 + mid2) / 2;}
  //   }
  // }

  // if (nums2Size == 1)
  // {
  //   mid2 = nums2[0];
  //   if (nums1Size % 2 == 0)
  //   {
  //     mid1_left = nums1[nums1Size / 2 - 1];
  //     mid1_right = nums1[nums1Size / 2];
  //     if (mid1_left > mid2) {return mid1_left;}
  //     else if(mid1_right < mid2) {return mid1_right;}
  //     else {return mid2;}
  //   }
  //   else
  //   {
  //     mid1 = nums1[nums1Size / 2];
  //     mid1_left = nums1[nums1Size / 2 - 1];
  //     mid1_right = nums1[nums1Size / 2 + 1];
  //     if (mid1_left > mid2) {return (mid1_left + mid1) / 2;}
  //     else if(mid1_right < mid2) {return (mid1_right + mid1) / 2;}
  //     else {return (mid1 + mid2) / 2;}
  //   }
  // }
