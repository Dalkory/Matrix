#include "../s21_matrix.h"

// Очистка матрицы
void s21_remove_matrix(matrix_t *A) {
  if (A) {
    if (A->matrix) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);  // Освобождение памяти для элементов в каждой
                             // строке матрицы
      }
      free(A->matrix);  // Освобождение памяти для указателей на строки
                        // матрицы
    }
    A->matrix = NULL;  // Установка указателя на матрицу в NULL
    A->rows = 0;  // Установка количества строк в 0
    A->columns = 0;  // Установка количества столбцов в 0
  }
}