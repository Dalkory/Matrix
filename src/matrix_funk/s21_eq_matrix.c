#include "../s21_matrix.h"

// Сравнение матриц (eq_matrix):
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;  // Переменная для хранения статуса создания матрицы (0 -
                   // успешно, 1 - некорректная матрица, 2 - ошибка вычисления)
  if (!A || !B) {
    status = 0;  // Проверка на нулевые указатели на матрицы
  } else if (A->rows != B->rows || A->columns != B->columns) {
    status = 0;  // Проверка на различные размеры матриц
  } else {
    // Цикл по индексу i для итерации по строкам матрицы A и B
    for (int i = 0; i < A->rows; i++) {
      // Цикл по индексу j для итерации по столбцам матрицы A и B
      for (int j = 0; j < A->columns; j++) {
        // Сравнение элементов матриц A и B с учетом погрешности EPSILON
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
          status = 0;  // Проверка на различные значения элементов матриц
          break;  // Прерываем внутренний цикл, если найдено различие
        }
      }
      if (status == 0) {
        break;  // Прерываем внешний цикл, если найдено различие
      }
    }
  }
  return status;  // Возвращаем статус сравнения матриц
}