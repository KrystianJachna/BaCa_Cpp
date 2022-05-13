#include <iostream>
using namespace std;

void Insertion(int n, int tab[])
{
    int i = 0;
    int pos = 0;
    int temp = 0;

    while (tab[i] != -1)
    {
        if ((tab[i + 1] != -1 && tab[i] < n && tab[i + 1]>n) || (tab[i + 1] == -1 && tab[i] < n))
        {
            pos = i + 1;
            break;
        }
        i++;
    }
    temp = tab[pos];
    tab[pos] = n;
    while (tab[pos] != -1)
    {
        swap(tab[pos + 1], temp);
        pos++;
    }
}

void Sort(int tab[])
{
    int i = 0;

    while (tab[i] != -1)
    {
        int j = 1;
        while (tab[j + i] != -1)
        {
            if (tab[j - 1] > tab[j])
                swap(tab[j - 1], tab[j]);
            j++;
        }
        i++;
    }
}

bool Element(int n, int tab[])
{
    int i = 0;

    if (n > 0 && n < 4096)
    {
        while (tab[i] != -1)
        {
            if (tab[i] == n)
                return true;
            i++;
        }
    }
    return false;
}

bool Empty(int tab[])
{
    if (tab[0] == -1)
        return true;
    return false;
}

bool Nonempty(int tab[])
{
    if (tab[0] != -1)
        return true;
    return false;
}

void Add(int n, int tab[])
{
    int i = 0;

    if (n > 0 && n < 4096)
    {
        if (Element(n, tab) == false)
        {
            Sort(tab);
            Insertion(n, tab);
        }
    }
}

void Create(int n, int num[], int tab[])
{
    int i = 0;
    tab[0] = -1;

    while (i < n)
    {
        if (num[i] > 0 && num[i] < 4096 && !Element(num[i], tab))
        {
            Insertion(num[i], tab);
        }
        i++;
    }
}

void Union(int t1[], int t2[], int tab[])
{
    int i = 0;
    tab[0] = -1;

    while (t1[i] != -1)
    {
        Insertion(t1[i], tab);
        i++;
    }
    i = 0;
    while (t2[i] != -1)
    {
        if (Element(t2[i], tab) == false)
            Insertion(t2[i], tab);
        i++;
    }
}

void Intersection(int t1[], int t2[], int tab[])
{
    int i = 0;
    tab[0] = -1;

    while (t1[i] != -1)
    {
        if (Element(t1[i], t2) == true)
            Insertion(t1[i], tab);
        i++;
    }
}

void Difference(int t1[], int t2[], int tab[])
{
    int i = 0;
    tab[0] = -1;

    while (t1[i] != -1)
    {
        if (Element(t1[i], t2) == false)
            Insertion(t1[i], tab);
        i++;
    }
}

void Symmetric(int t1[], int t2[], int tab[])
{
    int i = 0;
    tab[0] = -1;

    while (t1[i] != -1)
    {
        if (Element(t1[i], t2) == false)
            Insertion(t1[i], tab);
        i++;
    }
    i = 0;
    while (t2[i] != -1)
    {
        if (Element(t2[i], t1) == false)
            Insertion(t2[i], tab);
        i++;
    }
}

void Complement(int t1[], int tab[])
{
    tab[0] = -1;

    for (int i = 1; i < 4096; i++)
    {
        if (Element(i, t1) == false)
        {
            Insertion(i, tab);
        }
    }
}

bool Subset(int t1[], int t2[])
{
    int i = 0;

    while (t1[i] != -1)
    {
        if (Element(t1[i], t2) == false)
            return false;
        i++;
    }
    return true;
}

bool Equal(int t1[], int t2[])
{
    if (Subset(t1, t2) == true && Subset(t2, t1) == true)
        return true;
    return false;
}

double Arithmetic(int tab[])
{
    int i = 0;
    double sum = 0;

    if (Empty(tab) == true)
        return 0;
    else
    {
        while (tab[i] != -1)
        {
            sum += tab[i];
            i++;
        }
        return (sum / i);
    }
}

double Harmonic(int tab[])
{
    int i = 0;
    double sum = 0;

    if (Empty(tab) == true)
        return 1;
    else
    {
        while (tab[i] != -1)
        {
            sum += 1.0 / tab[i];
            i++;
        }
        return i / sum;
    }
}

void MinMax(int tab[], int* min, int& max)
{
    int i = 1;

    if (Empty(tab) == false)
    {
        *min = tab[0];
        max = tab[0];
        while (tab[i] != -1)
        {
            if (tab[i] > max)
                max = tab[i];
            if (tab[i] < *min)
                *min = tab[i];
            i++;
        }
    }
}

void Cardinality(int tab[], int* power)
{
    int i = 0;

    while (tab[i] != -1)
        i++;
    *power = i;
}

void Properties(int tab[], char mark[], double& ar, double* har, int& min, int* max, int& power)
{
    int i = 0;

    while (mark[i] != 0)
    {
        switch (mark[i])
        {
        case 'a':
            ar = Arithmetic(tab);
            break;
        case 'h':
            *har = Harmonic(tab);
            break;
        case 'm':
            MinMax(tab, &min, *max);
            break;
        case 'c':
            Cardinality(tab, &power);
            break;
        }
        i++;
    }
}