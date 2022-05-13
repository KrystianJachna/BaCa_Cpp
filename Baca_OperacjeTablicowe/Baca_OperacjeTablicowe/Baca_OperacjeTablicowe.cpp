#include <iostream>

using namespace std;

int main()
{
	int ilosc_sesji;
	char operacja = { ' ' };

	cin >> ilosc_sesji;

	while (ilosc_sesji > 0)
	{
		int liczba_elementow_tablicy;
		int iterator = 0;

		cin >> liczba_elementow_tablicy;

		int tab[liczba_elementow_tablicy];

		while (iterator < liczba_elementow_tablicy)
		{
			cin >> tab[iterator];
			iterator++;
		}

		iterator = 0;

		while (iterator < liczba_elementow_tablicy)
		{
			if (iterator != liczba_elementow_tablicy - 1)
			{
				cout << tab[iterator] << " ";
			}
			else
			{
				cout << tab[iterator] << endl;
			}
			iterator++;
		}


		do
		{
			int indeks_pierwszego_elementu;
			int dlugosc_fragmentu;
			int przesuniecie;
			iterator = liczba_elementow_tablicy;

			cin >> operacja;

			if (operacja == 'R')
			{
				cin >> indeks_pierwszego_elementu >> dlugosc_fragmentu;

				if (dlugosc_fragmentu > 1)
				{



					if (indeks_pierwszego_elementu < 0)
						indeks_pierwszego_elementu = (((indeks_pierwszego_elementu) % liczba_elementow_tablicy) + liczba_elementow_tablicy) % liczba_elementow_tablicy;

					while (iterator >= dlugosc_fragmentu)
					{
						int liczba_zamian = dlugosc_fragmentu / 2;
						int temp;
						int i = 0;


						while (i < liczba_zamian)
						{
							temp = tab[(indeks_pierwszego_elementu + dlugosc_fragmentu - 1 - i) % liczba_elementow_tablicy];															// tymczasowa zmienna = ostatni element fragmentu
							tab[(indeks_pierwszego_elementu + dlugosc_fragmentu - 1 - i) % liczba_elementow_tablicy] = tab[(indeks_pierwszego_elementu + i) % liczba_elementow_tablicy];	// ostatni element = pierwszy element fragmentu
							tab[(indeks_pierwszego_elementu + i) % liczba_elementow_tablicy] = temp;																						// pierwszy element = tymczasowa zmienna

							i++;
						}
						indeks_pierwszego_elementu += dlugosc_fragmentu;
						iterator -= dlugosc_fragmentu;
					}
				}
			}
			else if (operacja == 'C')
			{
				cin >> indeks_pierwszego_elementu >> dlugosc_fragmentu >> przesuniecie;

				int przesuniecie_org = przesuniecie;

				if (dlugosc_fragmentu != 0 && przesuniecie != 0)
				{

					if (indeks_pierwszego_elementu < 0)
						indeks_pierwszego_elementu = (((indeks_pierwszego_elementu) % liczba_elementow_tablicy) + liczba_elementow_tablicy) % liczba_elementow_tablicy;



					int i = 0;
					int ilosc_fragmentow;
					bool maly_fragment = false;

					if (liczba_elementow_tablicy % dlugosc_fragmentu == 0)
					{
						ilosc_fragmentow = liczba_elementow_tablicy / dlugosc_fragmentu;
					}
					else
					{
						ilosc_fragmentow = (liczba_elementow_tablicy / dlugosc_fragmentu) + 1;
						maly_fragment = true;
					}

					int indeks;
					int temp;

					while (i < ilosc_fragmentow)
					{
						if ((i == ilosc_fragmentow - 1) && maly_fragment == true)
						{
							dlugosc_fragmentu = liczba_elementow_tablicy % dlugosc_fragmentu;
							przesuniecie = (((przesuniecie_org) % dlugosc_fragmentu) + dlugosc_fragmentu) % dlugosc_fragmentu;
						}

						if (przesuniecie < 0)
							przesuniecie = (((przesuniecie) % dlugosc_fragmentu) + dlugosc_fragmentu) % dlugosc_fragmentu;

						int j = 0;

						int temp_2 = tab[indeks_pierwszego_elementu % liczba_elementow_tablicy];

						while (j < przesuniecie)
						{
							int pozycja;
							int temp;

							tab[indeks_pierwszego_elementu % liczba_elementow_tablicy] = tab[((indeks_pierwszego_elementu % liczba_elementow_tablicy) + dlugosc_fragmentu - 1) % liczba_elementow_tablicy];

							int k = 1;
							while (k < dlugosc_fragmentu)
							{
								pozycja = (((indeks_pierwszego_elementu % liczba_elementow_tablicy) + (k % dlugosc_fragmentu)) % liczba_elementow_tablicy);

								temp = tab[pozycja];
								tab[pozycja] = temp_2;
								temp_2 = temp;

								k++;
							}
							j++;


						}
						indeks_pierwszego_elementu += dlugosc_fragmentu;
						i++;
					}
				}
			}
			else if (operacja == 'S')
			{
				cin >> indeks_pierwszego_elementu >> dlugosc_fragmentu;


				if (indeks_pierwszego_elementu < 0)
					indeks_pierwszego_elementu = (((indeks_pierwszego_elementu) % liczba_elementow_tablicy) + liczba_elementow_tablicy) % liczba_elementow_tablicy;

				if (dlugosc_fragmentu != 0)
				{
					int zamiana_par = (liczba_elementow_tablicy / dlugosc_fragmentu) / 2;
					int i = 0;
					int temp;
					int odleglosc_co2_elementu = 0;

					while (i < zamiana_par)
					{
						int j = 0;

						while (j < dlugosc_fragmentu)
						{
							temp = tab[(j + indeks_pierwszego_elementu + odleglosc_co2_elementu) % liczba_elementow_tablicy];
							tab[(j + indeks_pierwszego_elementu + odleglosc_co2_elementu) % liczba_elementow_tablicy] = tab[(j + indeks_pierwszego_elementu + odleglosc_co2_elementu + dlugosc_fragmentu) % liczba_elementow_tablicy];
							tab[(j + indeks_pierwszego_elementu + odleglosc_co2_elementu + dlugosc_fragmentu) % liczba_elementow_tablicy] = temp;

							j++;
						}
						odleglosc_co2_elementu += dlugosc_fragmentu * 2;
						i++;
					}
				}
			}
		} while (operacja != 'F');

		int i = 0;

		ilosc_sesji--;

		while (i < liczba_elementow_tablicy)
		{
			if (i != liczba_elementow_tablicy - 1)
			{
				cout << tab[i] << " ";
			}
			else if (i == liczba_elementow_tablicy - 1 && ilosc_sesji != 0)
			{
				cout << tab[i] << endl;
			}
			else if (i == liczba_elementow_tablicy - 1 && ilosc_sesji == 0)
			{
				cout << tab[i];
			}
			i++;
		}

	}


	return 0;
}