#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
		/**
		 * Tutaj należy umieścić właściwą implemntację.
		**/
	/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
	// Matrix[wiersz][kolumna]
	// Zaczynamy od ostatniego wiersza
	
	const int ilosc_rownan = x->r;
	if(x->r != mat->r || mat->r) return 2;

	for (int r = ilosc_rownan - 1; r >= 0; r--) {		
		const double mat_a = mat->data[r][r];
		const double mat_b = b->data[r][0];

		if(mat_a == 0) return 1;
		x->data[r][0] = mat_b/mat_a;

	}
	
	return 0;
}


