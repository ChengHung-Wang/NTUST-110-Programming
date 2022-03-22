#pragma once
#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// print data in array with length n
/// </summary>
/// <param name="seq">input array</param>
/// <param name="n">length of array</param>
void print_data(int* seq, int n)
{
  for (size_t index = 0; index < n; index++) {
    printf("%d", *seq++);
    if (index != n - 1) {
      putchar(' ');
    }
  }
  putchar('\n');
}

/// <summary>
/// insert seq2 into seq1 at position p
/// </summary>
/// <param name="seq1">data in seq1</param>
/// <param name="n1">length of seq1</param>
/// <param name="seq2">data in seq2</param>
/// <param name="n2">length of seq2</param>
/// <param name="seq_out">buffer to store insertion result</param>
/// <param name="n_total">total sequence length after insertion</param>
/// <param name="p">insert position in seq1</param>
void insert_sequence(int* seq1, int n1, int* seq2, int n2, int* seq_out, int* n_total, int p)
{
  *n_total = n1 + n2;
  for (size_t index = 0; index < *n_total; index++) {
    if (index < p) {
      seq_out[index] = seq1[index];
    } else if (index < p + n2) {
      seq_out[index] = seq2[index - p];
    } else {
      seq_out[index] = seq1[index - n2];
    }
  }
}