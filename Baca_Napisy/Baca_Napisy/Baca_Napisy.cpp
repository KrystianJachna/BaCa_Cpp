#include <string>
using namespace std;

string UsunSlowo(string napis, int nrSlowa)
{
    string nowyNapis = "";
    unsigned short int slowo = 1;
    bool jestSlowem = false;

    for (int i = 0; i < napis.size(); i++) {
        if (napis[i] == ' ' && jestSlowem == true)
            slowo++;

        jestSlowem = napis[i] != ' ';

        if (nrSlowa != slowo || !jestSlowem)
            nowyNapis += napis[i];
    }
    return nowyNapis;
}


string NormalizujNapis(string napis)
{
    int i = 0;
    string nowyNapis = "";
    bool jestSlowem = true;

    while (napis[i] == ' ')
    {
        i++;
    }

    for (; i < napis.size(); i++) {
        if (napis[i] != ' ' && napis[i] != '.' && napis[i] != ',') {
            if (jestSlowem == false) {
                nowyNapis += ' ';
                nowyNapis += napis[i];
            }
            else
                nowyNapis += napis[i];
        }
        else if (napis[i] == ',' || napis[i] == '.')
            nowyNapis += napis[i];
        jestSlowem = napis[i] != ' ' && napis[i] != ',' && napis[i] != '.';
    }
    return nowyNapis;
}


string NajwiekszeSlowo(string napis)
{
    string najwiekszy = "";
    string temp = "";


    for (int i = 0; i < napis.size(); i++) {
        if (napis[i] != ' ') {
            temp += napis[i];
        }
        if (napis[i] == ' ' || i == napis.size() - 1) {
            if (temp > najwiekszy)
                najwiekszy = temp;
            temp = "";
        }
    }
    return najwiekszy;
}

string FormatujNapis(string napis, string param1, string param2, string param3)
{
    string nowyNapis = "";

    for (int i = 0; i < napis.size(); i++) {
        if (napis[i] == '{') {
            switch (napis[i + 1])
            {
            case 'p':
                for (int j = 0; j < napis[i + 3] - '0'; j++)
                    nowyNapis += napis[i + 5];
                i += 6;
                break;
            case 'u':
                if (i + napis[i + 3] - '0' + 4 > napis.size())
                    i = napis.size();
                else
                    i += napis[i + 3] - '0' + 4;
                break;
            case 'U':
                if ((int)nowyNapis.size() - napis[i + 3] + '0' < 0)
                    nowyNapis = "";
                else
                    nowyNapis.resize(nowyNapis.size() - napis[i + 3] + '0');
                i += 4;
                break;
            case 'w':
                if (napis[i + 3] == '1')
                    nowyNapis += param1;
                else if (napis[i + 3] == '2')
                    nowyNapis += param2;
                else if (napis[i + 3] == '3')
                    nowyNapis += param3;
                i += 4;
                break;
            case 'W':
                string param = "";
                if (napis[i + 3] == '1')
                    param = param1;
                else if (napis[i + 3] == '2')
                    param = param2;
                else if (napis[i + 3] == '3')
                    param = param3;
                if (param.size() < napis[i + 5] - '0') {
                    for (int j = param.size(); j < napis[i + 5] - '0'; j++)
                        param += ' ';
                }
                else if (param.size() > napis[i + 5] - '0')
                    param.resize(napis[i + 5] - '0');
                nowyNapis += param;
                i += 6;
                break;
            }
        }
        else if (napis[i] != 0)
            nowyNapis += napis[i];
    }
    return nowyNapis;
}
