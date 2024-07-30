#include "libft.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

// void sort_int_tab(int *tab, unsigned int size)
// {
// 	unsigned int pass; 		// Переменная для отслеживания количества проходов
// 	unsigned int i; 		// Индекс текущего элемента
// 	int temp;			   // Временная переменная для обмена элементов

// 	pass = 0;
// 	i = 0;
// 	// Повторяем проходы по массиву, пока он не будет полностью отсортирован n-1 povtorenij
// 	while (pass < size - 1)
// 	{
// 		// Проходим по всем элементам до предпоследнего
// 		while (i < size - 1 - pass)
// 		{
// 			// Если текущий элемент больше следующего, меняем их местами
// 			if (tab[i] > tab[i + 1])
// 			{
// 				temp = tab[i];
// 				tab[i] = tab[i + 1];
// 				tab[i + 1] = temp;
// 			}
// 			i++; // Переходим к следующей паре элементов
// 		}
// 		pass++; // Увеличиваем количество проходов
// 	}
// }


int main()
{
    int arr[] = {5, 2, 9, 1, 7, 1};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (unsigned int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort_int_tab(arr, size);

    printf("Sorted array: ");
    for (unsigned int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

