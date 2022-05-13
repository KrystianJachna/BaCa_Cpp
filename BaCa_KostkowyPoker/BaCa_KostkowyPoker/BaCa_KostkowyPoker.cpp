#include <iostream>

using namespace std;

int main()
{
    int liczba_rozgrywek = 0;
    int i = 0;

    float a_p = 0;
    float b_p = 0;
    float c_p = 0;
    float d_p = 0;
    float e_p = 0;

    float a_w = 0;
    float b_w = 0;
    float c_w = 0;
    float d_w = 0;
    float e_w = 0;

    float a_r = 0;
    float b_r = 0;
    float c_r = 0;
    float d_r = 0;
    float e_r = 0;

    char gracz_1 = ' ';
    char gracz_2 = ' ';

    int kosc_1 = 0;
    int kosc_2 = 0;
    int kosc_3 = 0;
    int kosc_4 = 0;

    int kosc_5 = 0;
    int kosc_6 = 0;
    int kosc_7 = 0;
    int kosc_8 = 0;

    int pktG1 = 0;
    int pktG2 = 0;

    cin >> liczba_rozgrywek;

    while (i < liczba_rozgrywek)
    {
        cin >> gracz_1 >> kosc_1 >> kosc_2 >> kosc_3 >> kosc_4 >> gracz_2 >> kosc_5 >> kosc_6 >> kosc_7 >> kosc_8;

        if (kosc_1 == kosc_2 && kosc_2 == kosc_3 && kosc_3 == kosc_4)
        {
            pktG1 = 5;
            //cout << "wszystko rowne u g1";
        }
        if (kosc_5 == kosc_6 && kosc_6 == kosc_7 && kosc_7 == kosc_8)
        {
            pktG2 = 5;
            //cout << "wszystko rowne u g2";
        }
        if (kosc_1 != kosc_2 && kosc_1 != kosc_3 && kosc_1 != kosc_4 && kosc_2 != kosc_3 && kosc_2 != kosc_4 && kosc_3 != kosc_4)
        {
            pktG1 = 4;
            //cout << "wszystko rozne u g1";
        }
        if (kosc_5 != kosc_6 && kosc_5 != kosc_7 && kosc_5 != kosc_8 && kosc_6 != kosc_7 && kosc_6 != kosc_8 && kosc_7 != kosc_8)
        {
            pktG2 = 4;
            //cout << "wszykostko rozne u g2";
        }
        if ((kosc_1 == kosc_2 && kosc_3 == kosc_4 && kosc_1 != kosc_3) || (kosc_1 == kosc_3 && kosc_2 == kosc_4 && kosc_1 != kosc_2) || (kosc_1 == kosc_4 && kosc_2 == kosc_3 && kosc_1 != kosc_2))
        {
            pktG1 = 3;
            //cout << "dwie rozne pary g1";
        }
        if ((kosc_5 == kosc_6 && kosc_7 == kosc_8 && kosc_5 != kosc_7) || (kosc_5 == kosc_7 && kosc_6 == kosc_8 && kosc_5 != kosc_6) || (kosc_5 == kosc_8 && kosc_6 == kosc_7 && kosc_5 != kosc_6))
        {
            pktG2 = 3;
            //cout << "dwie rozne pary g2";
        }
        if ((kosc_1 == kosc_2 && kosc_2 == kosc_3 && kosc_4 != kosc_1) || (kosc_1 == kosc_2 && kosc_2 == kosc_4 && kosc_3 != kosc_1) || (kosc_1 == kosc_3 && kosc_3 == kosc_4 && kosc_4 != kosc_2) || (kosc_3 == kosc_4 && kosc_2 == kosc_3 && kosc_4 != kosc_1))
        {
            pktG1 = 2;
            //cout << "dokladnie trzy jednakowe wyniki g1";
        }
        if ((kosc_5 == kosc_6 && kosc_6 == kosc_7 && kosc_8 != kosc_5) || (kosc_5 == kosc_6 && kosc_6 == kosc_8 && kosc_7 != kosc_5) || (kosc_5 == kosc_7 && kosc_7 == kosc_8 && kosc_8 != kosc_6) || (kosc_7 == kosc_8 && kosc_6 == kosc_7 && kosc_8 != kosc_5))
        {
            pktG2 = 2;
            //cout << "dokladnie trzy jednakowe wyniki g2";
        }
        if ((kosc_1 == kosc_2 && kosc_3 != kosc_1 && kosc_4 != kosc_1 && kosc_3 != kosc_4) || (kosc_1 == kosc_3 && kosc_2 != kosc_1 && kosc_4 != kosc_1 && kosc_2 != kosc_4) || (kosc_1 == kosc_4 && kosc_2 != kosc_1 && kosc_3 != kosc_1 && kosc_2 != kosc_3) || (kosc_2 == kosc_3 && kosc_1 != kosc_2 && kosc_4 != kosc_2 && kosc_1 != kosc_4) || (kosc_2 == kosc_4 && kosc_1 != kosc_2 && kosc_3 != kosc_2 && kosc_1 != kosc_3) || (kosc_3 == kosc_4 && kosc_1 != kosc_2 && kosc_1 != kosc_3 && kosc_2 != kosc_3))
        {
            pktG1 = 1;
            //cout << "dokladnie jedna para g1";
        }
        if ((kosc_5 == kosc_6 && kosc_7 != kosc_5 && kosc_8 != kosc_5 && kosc_7 != kosc_8) || (kosc_5 == kosc_7 && kosc_6 != kosc_5 && kosc_8 != kosc_5 && kosc_6 != kosc_8) || (kosc_5 == kosc_8 && kosc_6 != kosc_5 && kosc_7 != kosc_5 && kosc_6 != kosc_7) || (kosc_6 == kosc_7 && kosc_5 != kosc_6 && kosc_8 != kosc_6 && kosc_5 != kosc_8) || (kosc_6 == kosc_8 && kosc_5 != kosc_6 && kosc_7 != kosc_6 && kosc_5 != kosc_7) || (kosc_7 == kosc_8 && kosc_5 != kosc_6 && kosc_5 != kosc_7 && kosc_6 != kosc_7))
        {
            pktG2 = 1;
            // cout << "dokladnie jedna para g2";
        }
        //=============================================================dla 5 2 1
        if (pktG1 == 5 && pktG2 == 5)
        {
            if (kosc_1 > kosc_5)
            {
                pktG1++;
            }
            if (kosc_1 < kosc_5)
            {
                pktG2++;
            }

        }
        if (pktG1 == 2 && pktG2 == 2)
        {
            int wynik_G1;
            int wynik_G2;

            if (kosc_1 == kosc_2)
            {
                wynik_G1 = kosc_1;
            }
            else // tu moze else
            {
                wynik_G1 = kosc_3;
            }
            if (kosc_5 == kosc_6)
            {
                wynik_G2 = kosc_5;
            }
            else
            {
                wynik_G2 = kosc_7;
            }
            if (wynik_G1 > wynik_G2)
            {
                pktG1++;
            }
            if (wynik_G2 > wynik_G1)
            {
                pktG2++;
            }
        }
        if (pktG1 == 1 && pktG2 == 1)
        {
            int wynik_G1;
            int wynik_G2;

            if (kosc_1 == kosc_2 || kosc_1 == kosc_3 || kosc_1 == kosc_4)
            {
                wynik_G1 = kosc_1;
            }
            if (kosc_2 == kosc_3 || kosc_2 == kosc_4)
            {
                wynik_G1 = kosc_2;
            }
            if (kosc_3 == kosc_4)
            {
                wynik_G1 = kosc_3;
            }
            if (kosc_5 == kosc_6 || kosc_5 == kosc_7 || kosc_5 == kosc_8)
            {
                wynik_G2 = kosc_5;
            }
            if (kosc_6 == kosc_7 || kosc_6 == kosc_8)
            {
                wynik_G2 = kosc_6;
            }
            if (kosc_7 == kosc_8)
            {
                wynik_G2 = kosc_7;
            }
            if (wynik_G1 > wynik_G2)
            {
                pktG1++;
            }
            if (wynik_G2 > wynik_G1)
            {
                pktG2++;
            }
        }
        if (pktG1 == 3 && pktG2 == 3)
        {
            int wynik_G1;
            int wynik_G2;

            if (kosc_1 == kosc_2)
            {
                if (kosc_1 > kosc_3)
                {
                    wynik_G1 = kosc_1;
                }
                if (kosc_1 < kosc_3)
                {
                    wynik_G1 = kosc_3;
                }
            }
            if (kosc_1 == kosc_3)
            {
                if (kosc_1 > kosc_2)
                {
                    wynik_G1 = kosc_1;
                }
                if (kosc_1 < kosc_2)
                {
                    wynik_G1 = kosc_2;
                }
            }
            if (kosc_1 == kosc_4)
            {
                if (kosc_1 > kosc_2)
                {
                    wynik_G1 = kosc_1;
                }
                if (kosc_1 < kosc_2)
                {
                    wynik_G1 = kosc_2;
                }
            }
            if (kosc_5 == kosc_6)
            {
                if (kosc_5 > kosc_7)
                {
                    wynik_G2 = kosc_5;
                }
                if (kosc_5 < kosc_7)
                {
                    wynik_G2 = kosc_7;
                }
            }
            if (kosc_5 == kosc_7)
            {
                if (kosc_5 > kosc_6)
                {
                    wynik_G2 = kosc_5;
                }
                if (kosc_5 < kosc_6)
                {
                    wynik_G2 = kosc_6;
                }
            }
            if (kosc_5 == kosc_8)
            {
                if (kosc_5 > kosc_6)
                {
                    wynik_G2 = kosc_5;
                }
                if (kosc_5 < kosc_6)
                {
                    wynik_G2 = kosc_6;
                }
            }
            if (wynik_G1 > wynik_G2)
            {
                pktG1++;
            }
            if (wynik_G2 > wynik_G1)
            {
                pktG2++;
            }
        }
        if (pktG1 == pktG2)
        {
            int suma_oczek_G1;
            int suma_oczek_G2;

            suma_oczek_G1 = kosc_1 + kosc_2 + kosc_3 + kosc_4;
            suma_oczek_G2 = kosc_5 + kosc_6 + kosc_7 + kosc_8;

            if (suma_oczek_G1 > suma_oczek_G2)
            {
                pktG1++;
            }
            if (suma_oczek_G2 > suma_oczek_G1)
            {
                pktG2++;
            }
        }
        if (pktG1 > pktG2)
        {
            if (gracz_1 == 'a')
            {
                a_w++;
            }
            if (gracz_1 == 'b')
            {
                b_w++;
            }
            if (gracz_1 == 'c')
            {
                c_w++;
            }
            if (gracz_1 == 'd')
            {
                d_w++;
            }
            if (gracz_1 == 'e')
            {
                e_w++;
            }
            if (gracz_2 == 'a')
            {
                a_p++;
            }
            if (gracz_2 == 'b')
            {
                b_p++;
            }
            if (gracz_2 == 'c')
            {
                c_p++;
            }
            if (gracz_2 == 'd')
            {
                d_p++;
            }
            if (gracz_2 == 'e')
            {
                e_p++;
            }
        }
        if (pktG1 < pktG2)
        {
            if (gracz_1 == 'a')
            {
                a_p++;
            }
            if (gracz_1 == 'b')
            {
                b_p++;
            }
            if (gracz_1 == 'c')
            {
                c_p++;
            }
            if (gracz_1 == 'd')
            {
                d_p++;
            }
            if (gracz_1 == 'e')
            {
                e_p++;
            }
            if (gracz_2 == 'a')
            {
                a_w++;
            }
            if (gracz_2 == 'b')
            {
                b_w++;
            }
            if (gracz_2 == 'c')
            {
                c_w++;
            }
            if (gracz_2 == 'd')
            {
                d_w++;
            }
            if (gracz_2 == 'e')
            {
                e_w++;
            }
        }
        //das d
        if (pktG1 == pktG2)
        {
            if (gracz_1 == 'a')
            {
                a_r++;
            }
            if (gracz_1 == 'b')
            {
                b_r++;
            }
            if (gracz_1 == 'c')
            {
                c_r++;
            }
            if (gracz_1 == 'd')
            {
                d_r++;
            }
            if (gracz_1 == 'e')
            {
                e_r++;
            }
            if (gracz_2 == 'a')
            {
                a_r++;
            }
            if (gracz_2 == 'b')
            {
                b_r++;
            }
            if (gracz_2 == 'c')
            {
                c_r++;
            }
            if (gracz_2 == 'd')
            {
                d_r++;
            }
            if (gracz_2 == 'e')
            {
                e_r++;
            }
        }
        i++;
    }
    if (a_p != 0 || a_w != 0 || a_r != 0)
    {
        cout << "gracz a" << endl;
        if (a_w != 0)
        {
            cout << "    wygrane: " << (a_w / (a_w + a_p + a_r)) * 100 << "%" << endl;
        }
        if (a_r != 0)
        {
            cout << "    remisy: " << (a_r / (a_w + a_p + a_r)) * 100 << "%" << endl;
        }
        if (a_p != 0)
        {
            cout << "    przegrane: " << (a_p / (a_w + a_p + a_r)) * 100 << "%" << endl;
        }
        cout << endl;
    }
    if (b_p != 0 || b_w != 0 || b_r != 0)
    {
        cout << "gracz b" << endl;
        if (b_w != 0)
        {
            cout << "    wygrane: " << (b_w / (b_w + b_p + b_r)) * 100 << "%" << endl;
        }
        if (b_r != 0)
        {
            cout << "    remisy: " << (b_r / (b_w + b_p + b_r)) * 100 << "%" << endl;
        }
        if (b_p != 0)
        {
            cout << "    przegrane: " << (b_p / (b_w + b_p + b_r)) * 100 << "%" << endl;
        }
        cout << endl;
    }
    if (c_p != 0 || c_w != 0 || c_r != 0)
    {
        cout << "gracz c" << endl;
        if (c_w != 0)
        {
            cout << "    wygrane: " << (c_w / (c_w + c_p + c_r)) * 100 << "%" << endl;
        }
        if (c_r != 0)
        {
            cout << "    remisy: " << (c_r / (c_w + c_p + c_r)) * 100 << "%" << endl;
        }
        if (c_p != 0)
        {
            cout << "    przegrane: " << (c_p / (c_w + c_p + c_r)) * 100 << "%" << endl;
        }
        cout << endl;
    }
    if (d_p != 0 || d_w != 0 || d_r != 0)
    {
        cout << "gracz d" << endl;
        if (d_w != 0)
        {
            cout << "    wygrane: " << (d_w / (d_w + d_p + d_r)) * 100 << "%" << endl;
        }
        if (d_r != 0)
        {
            cout << "    remisy: " << (d_r / (d_w + d_p + d_r)) * 100 << "%" << endl;
        }
        if (d_p != 0)
        {
            cout << "    przegrane: " << (d_p / (d_w + d_p + d_r)) * 100 << "%" << endl;
        }
        cout << endl;
    }
    if (e_p != 0 || e_w != 0 || e_r != 0)
    {
        cout << "gracz e" << endl;
        if (e_w != 0)
        {
            cout << "    wygrane: " << (e_w / (e_w + e_p + e_r)) * 100 << "%" << endl;
        }
        if (e_r != 0)
        {
            cout << "    remisy: " << (e_r / (e_w + e_p + e_r)) * 100 << "%" << endl;
        }
        if (e_p != 0)
        {
            cout << "    przegrane: " << (e_p / (e_w + e_p + e_r)) * 100 << "%" << endl;
        }
        cout << endl;
    }




    return 0;
}