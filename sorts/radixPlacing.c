#include "../sortingUtils/sortingStructs.c"
#include <time.h>
#include <math.h>
#include <string.h>
#define NBUCKETS 10
struct sortStats radixSort(int *array, int length) {
  clock_t start, end;
  double cpu_time_used;
  struct sortStats s;
  long long permutations = 0;
  long long comparasons = 0;
  int hold;
  int i = 0;

  int bucketArray[NBUCKETS][length];

  memset( bucketArray, 0, length*length*sizeof(int) );
  start = clock();

  /* For 32 bit numbers, we need to do 7 passes */
  for (i = 0; i < 5; i++) {
  int bucketCount[NBUCKETS] = { 0 };
  int j = 0;
    for (j = 0; j < length; j++){
        int selectedBucket = (array[j]/(int)(pow(10, i))) % 10;
        bucketArray[selectedBucket][bucketCount[selectedBucket]] = array[j];
        bucketCount[selectedBucket] += 1;
    }
    /* Resume the list */
    int bucketIndex = 0;
    int nPosition = 0;
    for (bucketIndex = 0; bucketIndex < NBUCKETS; bucketIndex++){
        int bucketItemIndex = 0;
        for (bucketItemIndex = 0; bucketIndex < bucketCount[bucketIndex]; bucketItemIndex++){
            array[nPosition] = bucketArray[bucketIndex][bucketItemIndex];
            nPosition++;
        }
    }
  }

  end = clock();
  s.comparasons = comparasons;
  s.permutations = permutations;
  s.timeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;
  return s;
}