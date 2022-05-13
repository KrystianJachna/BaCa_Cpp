//Krystian Jachna
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996);
// c
void PRT(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	int i = 0;
	int j = 0;

	if (*rowsNum == 0) {
		printf("%d\n", *rowsNum);
		return;
	}

	printf("%d\n", *rowsNum);
	for (i; i < *rowsNum; ++i) {
		printf("%d ", *(*eachRowElemsNum + i));
		for (j; j < *(*eachRowElemsNum + i); ++j)
			printf("%d ", *(*(*array + i) + j));
		printf("\n");
		j = 0;
	}
}
// c
void AFR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	
	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newRow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int tempInt = 0;	
	for (i; i < elemsNum; ++i) {		
		scanf("%d", &tempInt);
		*(newRow + i) = tempInt;
	}

	int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));	

	*newArray = newRow;										

	i = 1;
	int j = 0;
	for (i; i < *rowsNum + 1; ++i, ++j)
		*(newArray + i) = *(*array + j);					
	
	free(*array);//nowe
	*array = newArray;
	
	unsigned short int * newEachRowElems;
	newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int ));
	*newEachRowElems = elemsNum;

	i = 1;
	j = 0;
	for (i; i < *rowsNum + 1; ++i, ++j) 
		*(newEachRowElems + i) = *(*eachRowElemsNum + j);
	free(*eachRowElemsNum);//nowe
	*eachRowElemsNum = newEachRowElems;
	*rowsNum = *rowsNum + 1;
}
// c
void ALR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newRow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int tempInt = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &tempInt);
		*(newRow + i) = tempInt;
	}

	int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));	// nowa tablica 2D

	i = 0;
	for (i; i < *rowsNum; ++i)
		*(newArray + i) = *(*array + i);					// zapisuje wszystkie elementy ze starej 2D do nowej
	*(newArray + i) = newRow;

	free(*array);//nowe
	*array = newArray;

	unsigned short int* newEachRowElems;
	newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < *rowsNum; ++i)
		*(newEachRowElems + i) = *(*eachRowElemsNum + i);
	*(newEachRowElems + i) = elemsNum;

	free(*eachRowElemsNum);//nowe
	*eachRowElemsNum = newEachRowElems;
	*rowsNum = *rowsNum + 1;
}
//c
void AFC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int elemsNum = 0;			// liczba elementow nowej kolumny
	scanf("%hu", &elemsNum);					

	if (elemsNum <= 0)
		return;

	int* newCol = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int tempInt = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &tempInt);
		*(newCol + i) = tempInt;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < elemsNum && i < *rowsNum; ++i) {
		int* newRow = (int*)malloc((*(*eachRowElemsNum + i) + 1) * sizeof(int));
		*newRow = *(newCol + i);
		j = 1;
		k = 0;
		for (j; j < (*(*eachRowElemsNum + i) + 1); ++j, k++) 
			*(newRow + j) = *(*(*array + i) + k);
		
		*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + 1;
		free(*(*array + i));//nowe
		*(*array + i) = newRow;
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));
		int* newRow = (int*)malloc(sizeof(int));
		*newRow = *(newCol + i);
		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newArray + j) = *(*array + j);					
		*(newArray + j) = newRow;
		
		free(*array);//nowe
		*array = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newEachRowElems + j) = *(*eachRowElemsNum + j);
		*(newEachRowElems + j) = 1;
		free(*eachRowElemsNum);//nowe
		*eachRowElemsNum = newEachRowElems;
		*rowsNum = *rowsNum + 1;
		i = i + 1;
	}
	free(newCol);//nowe
}
//c
void ALC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int elemsNum = 0;			// liczba elementow nowej kolumny
	scanf("%hu", &elemsNum);

	if (elemsNum <= 0)
		return;

	int* newCol = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int tempInt = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &tempInt);
		*(newCol + i) = tempInt;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < elemsNum && i < *rowsNum; ++i) {
		int* newRow = (int*)malloc((*(*eachRowElemsNum + i) + 1) * sizeof(int));
		j = 0;
		for (j; j < *(*eachRowElemsNum + i); ++j)
			*(newRow + j) = *(*(*array + i) + j);
		*(newRow + j) = *(newCol + i);

		*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + 1;
		free(*(*array + i));//nowe
		*(*array + i) = newRow;
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));
		int* newRow = (int*)malloc(sizeof(int));
		*newRow = *(newCol + i);
		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newArray + j) = *(*array + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newArray + j) = newRow;

		free(*array);//nowe
		*array = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newEachRowElems + j) = *(*eachRowElemsNum + j);
		*(newEachRowElems + j) = 1;
		free(*eachRowElemsNum);//nowe
		*eachRowElemsNum = newEachRowElems;
		*rowsNum = *rowsNum + 1;
		i = i + 1;
	}
	free(newCol);//nowe
}
//c
void IBR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int rowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &rowIndex);

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newRow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int tempInt = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &tempInt);
		*(newRow + i) = tempInt;
	}

	if (rowIndex < 0 || rowIndex >(*rowsNum - 1)) {
		free(newRow); //nowe
		return;
	}

	int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));	
	unsigned short int* newEachRowElems;						
	newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < rowIndex; ++i) {
		*(newArray + i) = *(*array + i);					
		*(newEachRowElems + i) = *(*eachRowElemsNum + i);	
	}

	*(newArray + i) = newRow;
	*(newEachRowElems + i) = elemsNum;
	int j = i;
	i++;

	for (i; i < *rowsNum + 1; ++i, ++j) {
		*(newArray + i) = *(*array + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newEachRowElems + i) = *(*eachRowElemsNum + j);	// zapisuje wszystke dlguosci wierwszy do nowej
	}
	free(*eachRowElemsNum);//nowe
	*eachRowElemsNum = newEachRowElems;
	free(*array); //nowe
	*array = newArray;
	*rowsNum = *rowsNum + 1;
}
//c
void IAR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int rowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &rowIndex);

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* newRow = (int*)malloc(elemsNum * sizeof(int));

	int i = 0;
	int tempInt = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do wiersza
		scanf("%d", &tempInt);
		*(newRow + i) = tempInt;
	}

	if (rowIndex < 0 || rowIndex >(*rowsNum - 1)) {
		free(newRow);//nowe
		return;
	}

	int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));	// nowa tablica 2D
	unsigned short int* newEachRowElems;							// nowa tablica dlugosci wierszy
	newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int));

	i = 0;
	for (i; i < rowIndex + 1; ++i) {
		*(newArray + i) = *(*array + i);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newEachRowElems + i) = *(*eachRowElemsNum + i);	// zapisuje wszystke dlguosci wierwszy do nowej
	}

	*(newArray + i) = newRow;
	*(newEachRowElems + i) = elemsNum;
	int j = i;
	i++;

	for (i; i < *rowsNum + 1; ++i, ++j) {
		*(newArray + i) = *(*array + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newEachRowElems + i) = *(*eachRowElemsNum + j);	// zapisuje wszystke dlguosci wierwszy do nowej
	}
	free(*eachRowElemsNum);//nowe
	*eachRowElemsNum = newEachRowElems;
	free(*array);//nowe
	*array = newArray;
	*rowsNum = *rowsNum + 1;
}
//c
void IBC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int colIndex = 0;
	scanf("%hu", &colIndex);
	if (colIndex < 0)
		return;

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* elemsCol = (int*)malloc(elemsNum * sizeof(int));	// nowa kolumna

	int i = 0;
	int tempInt = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do kolumny
		scanf("%d", &tempInt);
		*(elemsCol + i) = tempInt;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < elemsNum && i < *rowsNum; ++i) {
		if (colIndex >= *(*eachRowElemsNum + i)) {			// jesli sie nie miesci to na koniec
			int* newRow = (int*)malloc((*(*eachRowElemsNum + i) + 1) * sizeof(int));
			j = 0;
			for (j; j < *(*eachRowElemsNum + i); ++j)
				*(newRow + j) = *(*(*array + i) + j);
			*(newRow + j) = *(elemsCol + i);

			*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + 1;
			free(*(*array + i));//nowe
			*(*array + i) = newRow;
		}
		else {
			int* newRow = (int*)malloc((*(*eachRowElemsNum + i) + 1) * sizeof(int));
			j = 0;
			for (j; j < colIndex; ++j)
				*(newRow + j) = *(*(*array + i) + j);
			*(newRow + j) = *(elemsCol + i);
			k = j;
			j++;
			for (j; j < (*(*eachRowElemsNum + i) + 1); ++j, ++k)
				*(newRow + j) = *(*(*array + i) + k);
			*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + 1;
			free(*(*array + i));//nowe
			*(*array + i) = newRow;
		}
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));
		int* newRow = (int*)malloc(sizeof(int));
		*newRow = *(elemsCol + i);
		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newArray + j) = *(*array + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newArray + j) = newRow;
		free(*array);//nowe
		*array = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newEachRowElems + j) = *(*eachRowElemsNum + j);
		*(newEachRowElems + j) = 1;
		free(*eachRowElemsNum);//nowe
		*eachRowElemsNum = newEachRowElems;
		*rowsNum = *rowsNum + 1;
		i = i + 1;
	}
	free(elemsCol);//nowe
}
//c
void IAC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int colIndex = 0;
	scanf("%hu", &colIndex);
	if (colIndex < 0)
		return;

	unsigned short int elemsNum = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &elemsNum);

	int* elemsCol = (int*)malloc(elemsNum * sizeof(int));	// nowa kolumna

	int i = 0;
	int tempInt = 0;
	for (i; i < elemsNum; ++i) {		// zapisuje elementy do kolumny
		scanf("%d", &tempInt);
		*(elemsCol + i) = tempInt;
	}

	i = 0;
	int j = 0;
	int k = 0;
	for (i; i < elemsNum && i < *rowsNum; ++i) {
		if (colIndex >= *(*eachRowElemsNum + i)) {			// jesli sie nie miesci to na koniec
			int* newRow = (int*)malloc((*(*eachRowElemsNum + i) + 1) * sizeof(int));
			j = 0;
			for (j; j < *(*eachRowElemsNum + i); ++j)
				*(newRow + j) = *(*(*array + i) + j);
			*(newRow + j) = *(elemsCol + i);

			*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + 1;
			free(*(*array + i));//nowe
			*(*array + i) = newRow;
		}
		else {
			int* newRow = (int*)malloc((*(*eachRowElemsNum + i) + 1) * sizeof(int));
			j = 0;
			for (j; j <= colIndex; ++j)
				*(newRow + j) = *(*(*array + i) + j);
			*(newRow + j) = *(elemsCol + i);
			k = j;
			j++;
			for (j; j < (*(*eachRowElemsNum + i) + 1); ++j, ++k)
				*(newRow + j) = *(*(*array + i) + k);
			*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + 1;
			free(*(*array + i));//nowe
			*(*array + i) = newRow;
		}
	}
	while (i < elemsNum) {
		int** newArray = (int*)malloc((*rowsNum + 1) * sizeof(int*));
		int* newRow = (int*)malloc(sizeof(int));
		*newRow = *(elemsCol + i);
		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newArray + j) = *(*array + j);					// zapisuje wszystkie elementy ze starej 2D do nowej
		*(newArray + j) = newRow;

		free(*array);//nowe
		*array = newArray;

		unsigned short int* newEachRowElems;
		newEachRowElems = (unsigned short int*)malloc((*rowsNum + 1) * sizeof(unsigned short int));

		j = 0;
		for (j; j < *rowsNum; ++j)
			*(newEachRowElems + j) = *(*eachRowElemsNum + j);
		*(newEachRowElems + j) = 1;

		free(*eachRowElemsNum);//nowe
		*eachRowElemsNum = newEachRowElems;
		*rowsNum = *rowsNum + 1;
		i = i + 1;
	}
	free(elemsCol);//nowe
}
//c
void SWR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int fsRowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &fsRowIndex);

	unsigned short int scRowIndex = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &scRowIndex);

	if (fsRowIndex < 0 || fsRowIndex >(*rowsNum - 1) || scRowIndex < 0 || scRowIndex >(*rowsNum - 1))
		return;

	int* fsRow = *(*array + fsRowIndex);
	*(*array + fsRowIndex) = *(*array + scRowIndex);
	*(*array + scRowIndex) = fsRow;

	unsigned short* fsRowNumber = *(*eachRowElemsNum + fsRowIndex);
	*(*eachRowElemsNum + fsRowIndex) = *(*eachRowElemsNum + scRowIndex);
	*(*eachRowElemsNum + scRowIndex) = fsRowNumber;
}
//c
void SWC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int fsColIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &fsColIndex);

	unsigned short int scColIndex = 0;			// liczba elementow nowego wiersza
	scanf("%hu", &scColIndex);

	if (fsColIndex < 0 || scColIndex < 0)
		return;

	int i = 0;
	for (i; i < *rowsNum; ++i) {
		if (fsColIndex > (*(*eachRowElemsNum + i) - 1) || scColIndex >(*(*eachRowElemsNum + i) - 1))
			continue;
		int fsCol = *(*(*array + i) + fsColIndex);
		*(*(*array + i) + fsColIndex) = *(*(*array + i) + scColIndex);
		*(*(*array + i) + scColIndex) = fsCol;
	}
}
//c
void DFR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	if (*rowsNum == 0)
		return;
	
	int i = 0;
	unsigned short firstRowNum = **eachRowElemsNum;
	int* firstRow = **array;
	
	for (i; i < (*rowsNum - 1); ++i) {		
		*(*array + i) = *(*array + i + 1);
		*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i + 1);
	}
	*(*array + i) = firstRow;
	*(*eachRowElemsNum + i) = firstRowNum;
	free(firstRow);
	*array = (int*)realloc(*array, (*rowsNum - 1) * sizeof(int*));
	*eachRowElemsNum = (unsigned short int*)realloc(*eachRowElemsNum, (*rowsNum - 1) * sizeof(unsigned short int));
	*rowsNum = *rowsNum - 1;
}
//c
void DLR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	if (*rowsNum == 0)
		return;

	free(*(*array + *rowsNum - 1));
	*array = (int*)realloc(*array, (*rowsNum - 1) * sizeof(int*));
	*eachRowElemsNum = (unsigned short int*)realloc(*eachRowElemsNum, (*rowsNum - 1) * sizeof(unsigned short int));
	*rowsNum = *rowsNum - 1;
}
//c
void clearMem(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	while (*rowsNum != 0)
		DLR(rowsNum, eachRowElemsNum, array);
}
//c
void DFC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	if (*rowsNum == 0)
		return;

	int i = 0;
	int j = 0;
	unsigned short RowNum = 0;
	int* Row = NULL;
	int tmpInt = 0;

	for (i; i < *rowsNum; ++i) {
		if (*(*eachRowElemsNum + i) == 1) { // usuwanie wiersza
			RowNum = *(*eachRowElemsNum + i);
			Row = *(*array + i);
			j = i;
			for (j; j < *rowsNum - 1; ++j) {
				*(*array + j) = *(*array + j + 1);
				*(*eachRowElemsNum + j) = *(*eachRowElemsNum + j + 1);
			}
			*(*array + j) = Row;
			*(*eachRowElemsNum + j) = RowNum;
			DLR(rowsNum, eachRowElemsNum, array);
			i = i - 1;
		}
		else {
			tmpInt = **(*array + i);
			j = 0;
			for (j; j < (*(*eachRowElemsNum + i) - 1) ; ++j)
				*(*(*array + i) + j) = *(*(*array + i) + j + 1);
			
			*(*(*array + i) + j) = tmpInt;
			*(*array + i) = (int*)realloc(*(*array + i), (*(*eachRowElemsNum + i) - 1 ) * sizeof(int*));
			*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) - 1;
		}
	}
}
//c
void DLC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	if (*rowsNum == 0)
		return;

	int i = 0;
	int j = 0;
	unsigned short RowNum = 0;
	int* Row = NULL;

	for (i; i < *rowsNum; ++i) {
		if (*(*eachRowElemsNum + i) == 1) { // usuwanie wiersza
			RowNum = *(*eachRowElemsNum + i);
			Row = *(*array + i);
			j = i;
			for (j; j < *rowsNum - 1; ++j) {
				*(*array + j) = *(*array + j + 1);
				*(*eachRowElemsNum + j) = *(*eachRowElemsNum + j + 1);
			}
			*(*array + j) = Row;
			*(*eachRowElemsNum + j) = RowNum;
			DLR(rowsNum, eachRowElemsNum, array);
			i = i - 1;
		}
		else {
			*(*array + i) = (int*)realloc(*(*array + i), (*(*eachRowElemsNum + i) - 1) * sizeof(int*));
			*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) - 1;
		}
	}
}
//c
void RMR(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int rowIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &rowIndex);

	if (rowIndex < 0 || rowIndex >(*rowsNum - 1))
		return;

	unsigned short RowNum = *(*eachRowElemsNum + rowIndex);
	int* Row = *(*array + rowIndex);

	int i = rowIndex;
	for (i; i < *rowsNum - 1; ++i) {
		*(*array + i) = *(*array + i + 1);
		*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i + 1);
	}
	*(*array + i) = Row;
	*(*eachRowElemsNum + i) = RowNum;

	DLR(rowsNum, eachRowElemsNum, array);
}
//c
void RMC(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int colIndex = 0;			// wczytanie numeru wiersza
	scanf("%hu", &colIndex);
	
	if (colIndex < 0)
		return;

	int i = 0;
	int j = 0;
	int tmpInt = 0;
	for (i; i < *rowsNum; ++i) {
		if (colIndex >= *(*eachRowElemsNum + i))
			continue;
		else {
			if (*(*eachRowElemsNum + i) - 1 == 0) {
				unsigned short RowNum = *(*eachRowElemsNum + i);
				int* Row = *(*array + i);
				j = i;
				for (j; j < *rowsNum - 1; ++j) {
					*(*array + j) = *(*array + j + 1);
					*(*eachRowElemsNum + j) = *(*eachRowElemsNum + j + 1);
				}
				*(*array + j) = Row;
				*(*eachRowElemsNum + j) = RowNum;
				DLR(rowsNum, eachRowElemsNum, array);
				i = i - 1;
			}
			else {
				j = colIndex;
				tmpInt = *(*(*array + i) + colIndex);
				for (j; j < *(*eachRowElemsNum + i) - 1; ++j) 
					*(*(*array + i) + j) = *(*(*array + i) + j + 1);
				
				*(*(*array + i) + j) = tmpInt;
				*(*array + i) = (int*)realloc(*(*array + i), (*(*eachRowElemsNum + i) - 1) * sizeof(int*));
				*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) - 1;
			}
		}
	}

}
//c
void RMB(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int rowIndex = 0;			
	scanf("%hu", &rowIndex);
	
	unsigned short int rowCount = 0;			
	scanf("%hu", &rowCount);

	unsigned short int colIndex = 0;			
	scanf("%hu", &colIndex);

	unsigned short int colNumber = 0;			
	scanf("%hu", &colNumber);

	if (rowIndex >= *rowsNum)
		return;

	int i = rowIndex;
	int j = 0;
	int k = 0;
	int l = 0;
	int tmp = 0;
	for (i; i < *rowsNum && k < rowCount; ++i, ++k) {
		if (colIndex >= *(*eachRowElemsNum + i))
			continue;
		else if (colIndex == 0 && *(*eachRowElemsNum + i) <= colNumber) { 
			unsigned short RowNum = *(*eachRowElemsNum + i);
			int* Row = *(*array + i);
			j = i;
			for (j; j < *rowsNum - 1; ++j) {
				*(*array + j) = *(*array + j + 1);
				*(*eachRowElemsNum + j) = *(*eachRowElemsNum + j + 1);
			}
			*(*array + j) = Row;
			*(*eachRowElemsNum + j) = RowNum;
			DLR(rowsNum, eachRowElemsNum, array);
			i = i - 1;
		}
		else {
			j = colIndex;
			for (j; j + colNumber < *(*eachRowElemsNum + i); ++j) 
				*(*(*array + i) + j) = *(*(*array + i) + j + colNumber);
			j = colIndex;
			l= 0;
			for (j; j < *(*eachRowElemsNum + i) && l < colNumber; ++l, ++j);

			*(*array + i) = (int*)realloc(*(*array + i), (*(*eachRowElemsNum + i) - l) * sizeof(int*));
			*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) - l;
		}
	}



}
//c
void ISB(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	unsigned short int rowIndex = 0;
	scanf("%hu", &rowIndex);

	unsigned short int colIndex = 0;
	scanf("%hu", &colIndex);

	unsigned short int rowNumber = 0;
	scanf("%hu", &rowNumber);

	unsigned short int colNumber = 0;
	scanf("%hu", &colNumber);

	if (*rowsNum - 1 < rowIndex) {
		int i = 0;
		for (i; i < rowNumber; ++i) {

			int* newRow = (int*)malloc(colNumber * sizeof(int));

			int j = 0;
			int tempInt = 0;
			for (j; j < colNumber; ++j) {		// zapisuje elementy do wiersza
				scanf("%d", &tempInt);
				*(newRow + j) = tempInt;
			}

			*array = (int*)realloc(*array, (*rowsNum + 1) * sizeof(int*));	// nowa tablica 2D
			*(*array + *rowsNum) = newRow;									// zapisuje pierwszy nowy elemnt


			*eachRowElemsNum = (unsigned short int*)realloc(*eachRowElemsNum, (*rowsNum + 1) * sizeof(unsigned short int));
			*(*eachRowElemsNum + *rowsNum) = colNumber;

			*rowsNum = *rowsNum + 1;
		}
	}
	else {
		int i = rowIndex;
		int j = 0;
		int tempInt;
		for (i; i < *rowsNum && j< rowNumber; ++i, ++j) {
			if (colIndex >= *(*eachRowElemsNum + i)) {	// jesli index sie nie miejsci
				*(*array + i) = (int*)realloc(*(*array + i), (*(*eachRowElemsNum + i) + colNumber) * sizeof(int));
				unsigned short int k = *(*eachRowElemsNum + i);
				for (k; k < *(*eachRowElemsNum + i) + colNumber; ++k) {
					scanf("%d", &tempInt);
					*(*(*array + i) + k) = tempInt;
				}
				*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + colNumber;
			}
			else {
				int* newRow = (int*)malloc((*(*eachRowElemsNum + i) + colNumber) * sizeof(int));
				unsigned short int k = 0;
				for (k; k < colIndex; ++k) 
					*(newRow + k) = *(*(*array + i) + k);
				unsigned short int l = 0;
				unsigned short int s = k;
				for (l; l < colNumber; ++l, ++k) {
					scanf("%d", &tempInt);
					*(newRow + k) = tempInt;
				}
				for (s; s < *(*eachRowElemsNum + i); ++k, ++s)
					*(newRow + k) = *(*(*array + i) + s);
				
				free(*(*array + i));
				*(*array + i) = newRow;
				*(*eachRowElemsNum + i) = *(*eachRowElemsNum + i) + colNumber;
			}
		}
		for (j; j < rowNumber; ++j) {
			int* newRow = (int*)malloc(colNumber * sizeof(int));

			int j = 0;
			int tempInt = 0;
			for (j; j < colNumber; ++j) {		// zapisuje elementy do wiersza
				scanf("%d", &tempInt);
				*(newRow + j) = tempInt;
			}

			*array = (int*)realloc(*array, (*rowsNum + 1) * sizeof(int*));	// nowa tablica 2D
			*(*array + *rowsNum) = newRow;									// zapisuje pierwszy nowy elemnt


			*eachRowElemsNum = (unsigned short int*)realloc(*eachRowElemsNum, (*rowsNum + 1) * sizeof(unsigned short int));
			*(*eachRowElemsNum + *rowsNum) = colNumber;

			*rowsNum = *rowsNum + 1;
		}
	}

}

void WRF(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	char* fname = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", fname);

	if (fname == "")
		return;

	FILE* fileVar = fopen(fname, "wb");

	fprintf(fileVar, "%d\n", *rowsNum);
	if (*rowsNum > 0) {
		int i = 0;
		for (i; i < *rowsNum; ++i) {
			int x = ((*(*eachRowElemsNum + i) >> 8) & 255);
			fputc(((*(*eachRowElemsNum + i) >> 8) & 255), fileVar);
			fputc(((*(*eachRowElemsNum + i) >> 0) & 255), fileVar);
			int j = 0;
			for (j; j < *(*eachRowElemsNum + i); ++j) {
				fputc(((*(*(*array +i ) + j) >> 24) & 255), fileVar);
				fputc(((*(*(*array +i ) + j) >> 16) & 255), fileVar);
				fputc(((*(*(*array +i ) + j) >> 8) & 255), fileVar);
				fputc(((*(*(*array +i ) + j) >> 0) & 255), fileVar);
			}
		}
	}
	fclose(fileVar);
	free(fname);
}

void RDF(unsigned short* rowsNum, unsigned short** eachRowElemsNum, int*** array) {
	clearMem(rowsNum, eachRowElemsNum, array);

	*array = NULL;
	*rowsNum = 0;
	*eachRowElemsNum = NULL;

	char* fname = (char*)malloc(sizeof(char) * 17);
	scanf("%16s", fname);
	unsigned char ch = ' ';
	unsigned short rN = 0;
	FILE* fileVar = fopen(fname, "rb");
	while (1) {
		fread(&ch, sizeof(char), 1, fileVar);
		if (ch == '\n')
			break;
		rN *= 10;
		rN += ch - '0';
	}
	*rowsNum = rN;
	*array = (int**)malloc((*rowsNum) * sizeof(int*));
	*eachRowElemsNum = (unsigned short int*)malloc(*rowsNum * sizeof(unsigned short int));
	int i = 0;
	for (i = 0; i < *rowsNum; ++i) {
		unsigned short int lk;
		lk = (fgetc(fileVar) << 8) + (fgetc(fileVar) << 0);
		*(*eachRowElemsNum + i) = lk;
		*(*array + i) = (int*)malloc(lk * sizeof(int));
		int j = 0;
		for (j; j < lk; ++j) {
			int elem = 0;
			elem = (fgetc(fileVar) << 24) + (fgetc(fileVar) << 16) + (fgetc(fileVar) << 8) + (fgetc(fileVar) << 0);
			*(*(*array + i) + j) = elem;
		}
	}
	fclose(fileVar);
	free(fname);
}


int main() {
	
	unsigned short  rowsNum= 0;						
	unsigned short *eachRowElemsNum = NULL;			
	int** array = NULL;								

	char* op = (char*)malloc(sizeof(char) * 100);

	while (1) {

		scanf("%3s", op);

		if (strcmp(op, "AFR") == 0)
			AFR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "ALR") == 0)
			ALR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "AFC") == 0)
			AFC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "ALC") == 0)
			ALC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "IBR") == 0)
			IBR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "IAR") == 0)
			IAR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "PRT") == 0)
			PRT(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "IBC") == 0)
			IBC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "IAC") == 0)
			IAC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "SWR") == 0)
			SWR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "SWC") == 0)
			SWC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "DFR") == 0)
			DFR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "DLR") == 0)
			DLR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "DFC") == 0)
			DFC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "DLC") == 0)
			DLC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "RMR") == 0)
			RMR(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "RMC") == 0)
			RMC(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "RMB") == 0)
			RMB(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "ISB") == 0)
			ISB(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "WRF") == 0)
			WRF(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "RDF") == 0)
			RDF(&rowsNum, &eachRowElemsNum, &array);
		else if (strcmp(op, "END") == 0)
			break;

		fflush(stdin);
	}
	clearMem(&rowsNum, &eachRowElemsNum, &array);
	free(op);
	return 0;
}