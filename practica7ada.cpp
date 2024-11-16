#include <stdio.h>

// Funci�n para calcular la suma de los primeros k elementos
int suma_inicial(int *arr, int k) {
	int suma = 0;
	for (int i = 0; i < k; i++) {
		suma += arr[i];
	}
	return suma;
}

// Funci�n para contar sub-arreglos
int numOfSubarrays(int *arr, int arr_size, int k, int threshold) {
	threshold *= k;  // Multiplicamos el threshold por k para obtener la suma m�nima requerida
	int s = suma_inicial(arr, k);  // Sumamos de la primera ventana de tama�o k
	int ans = (s >= threshold) ? 1 : 0;
	
	// Desplazamos la ventana a trav�s del arreglo
	for (int i = k; i < arr_size; i++) {
		s += arr[i] - arr[i - k];  // Actualizamos la suma de la ventana
		if (s >= threshold) {
			ans++;
		}
	}
	
	return ans;
}

int main() {
	int arr[] = {2, 2, 2, 2, 5, 5, 5, 8};
	int k = 3;
	int threshold = 4;
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	int result = numOfSubarrays(arr, arr_size, k, threshold);
	printf("N�mero de sub-arreglos que cumplen la condici�n(output): %d\n", result);
	
	return 0;
}
