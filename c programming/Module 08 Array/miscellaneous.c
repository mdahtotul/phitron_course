#include <stdio.h>

int main()
{
  int n, arr[200001], i, found;
  printf("Total no of input: ");
  scanf("%d", &n);

  for (i = 1; i < n;i++){
    scanf("%d", &found);
    arr[found] = 1;
  }

  printf("Array positions\n");
  for (i = 1; i <= n;i++){
    if(arr[i] == 0){
      printf("Missing number is %d\n", i);
      break;
    }
  }
    return 0; 
}


// better way to solve this problem

// #include <stdio.h>

// int main()
// {
//   int i, arr[] = {1,3,5,2};

//   int N = sizeof(arr) / sizeof(arr[0]);
//   // printf("%d", sizeof(arr[0]));

//   int m1 = arr[0], m2 = 1;

//   for (i = 1; i < N; i++){
//     m1 = m1 ^ arr[i];
//     // printf("M1 %d\n", m1);
//   }

//   for (i = 2; i <= N + 1; i++){
//     m2 = m2 ^ i;
//     // printf("M2 %d\n", m2);
//   }

//   printf("Missing %d", m1 ^ m2);
// }