/* For this assignment, you'll be implementing heapsort in the LEG subset of
 * the ARMv8 ISA.  Heapsort is an O(n lg n) comparison sort which you should
 * all be familiar with from your data structures course.
 */

#define SIZE 512

#include <stdio.h>
#include <stdint.h>

/* a: address of array of unsigned 64-bit int
 * s: number of elements in a
 *
 * Initializes the contents of a with the numbers 0 through (s - 1).  The
 * array is initialized with even number to the left in descending order, and
 * odd number on the right in ascending order.
 */
void fill(uint64_t *a, uint64_t s)
{
  uint64_t i = 0;

  if (s >= 2) {
    for (; i < s / 2; i++) {
      a[((s + 1) / 2) - (i + 1)] = i * 2;
      a[((s + 1) / 2) + i] = i * 2 + 1;
    }
  }

  if (s & 1) {
    a[0] = s - 1;
  }
}

/* a: address of an unsigned 64-bit int
 * b: address of an unsigned 64-bit int
 *
 * Swaps the values addressed by a and b.
 */
void swap(uint64_t *a, uint64_t *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

/* a: address of array of unsigned 64-bit int
 * s: number of elements in a
 * i: an index in a
 *
 * i is the index of the root of a subtree within a.  The children of i are
 * maxheaps.  If the tree rooted at i is not a maxheap, swap the value at i
 * with that of its largest child and repeat this process at the child node
 * until the value origionally at i reaches a position such that i is the
 * root of a maxheap.
 */
void percolate_down(uint64_t *a, uint64_t s, uint64_t i)
{
  uint64_t child;

  for (child = (2 * i) + 1; child < s; i = child, child = (2 * i) + 1) {
    if (child + 1 < s && a[child] < a[child + 1]) {
      child++;
    }
    if (a[i] < a[child]) {
      swap(a + i, a + child);
    }
  }
}

/* a: address of array of unsigned 64-bit int
 * s: number of elements in a
 *
 * Arrange the elements of a such that a is a maxheap wherein the children of
 * each index, i, are in indices((i * 2) + 1) and ((i * 2) + 2).
 */
void heapify(uint64_t *a, uint64_t s)
{
  uint64_t i;

  for (i = (s + 1) / 2; i; i--) {
    percolate_down(a, s, i);
  }
  percolate_down(a, s, 0);
}

/* a: address of array of unsigned 64-bit int
 * s: number of elements in a
 *
 * Sorts elements of a using the heapsort algorithm.
 */
void heapsort(uint64_t *a, uint64_t s)
{
  uint64_t i;

  heapify(a, s);

  for (i = 1; i < s; i++) {
    swap(a + 0, a + (s - i));
    percolate_down(a, s - i, 0);
  }
}

/* Your main function should allocate space for an array, call fill to fill
 * it with numbers, and then call heapsort to sort it.  Use the HALT emulator
 * instruction to see the memory contents and confirm that your functions
 * work.  You may choose any array size you like (up to the default limit of
 * memory, 4096 bytes or 512 8-byte integers).
 *                                                                      
 * After completing all of the above, HALT the emulator to force a core dump
 * so that you (and the TAs) can examine the contents of memory.
 *                                                                                                                                   
 */
int main(int argc, char *argv[])
{

  uint64_t a[SIZE];

  fill(a, SIZE);
  
  heapsort(a, SIZE);

  /*
  int i;
  for (i = 0; i < SIZE; i++) {
    // Depending on your compiler, you may need %lu instead of %llu
    printf("%llu\t", a[i]);
  }
  printf("\n");
  */

  return 0;
}