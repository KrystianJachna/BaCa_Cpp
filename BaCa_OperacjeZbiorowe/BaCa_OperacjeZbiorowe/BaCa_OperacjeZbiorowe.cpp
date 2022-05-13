// Krystian Jachna

void ParseElem(char* ar, int* set) {
    
    int elem = (
        ((*(ar + 0) - '0') << 4) +
        ((*(ar + 1) - '0') << 3) +
        ((*(ar + 2) - '0') << 2) +
        ((*(ar + 3) - '0') << 1) +
        ((*(ar + 4) - '0') << 0)
        );

    *set = *set | (1 << elem);
}

void Insert(char* ar, int* set) {
    if (*ar == '\0')
        return;
    else if (*ar == ' ')
        return Insert(ar + 1, set);
    else {
        ParseElem(ar, set);
        Insert(ar + 5, set);
    }
}

void Emplace(char* ar, int* set) {
    *set = 0;
    Insert(ar, set);
}

void delElem(char* ar, int* set) {
    int elem = (
        ((*(ar + 0) - '0') << 4) +
        ((*(ar + 1) - '0') << 3) +
        ((*(ar + 2) - '0') << 2) +
        ((*(ar + 3) - '0') << 1) +
        ((*(ar + 4) - '0') << 0)
        );

    *set = (*set & ~(1 << elem));
}

void Erase(char* ar, int* set) {
    if (*ar == '\0')
        return;
    else if (*ar == ' ')
        return Erase(ar + 1, set);
    else {
        delElem(ar, set);
        Erase(ar + 5, set);
    }
}

void PrintToArray(int set, char* ar, int bit) {
    if (((1 << 4) & bit) != 0)
        *(ar + 0) = '1';
    else
        *(ar + 0) = '0';
    if (((1 << 3) & bit) != 0)
        *(ar + 1) = '1';
    else
        *(ar + 1) = '0';
    if (((1 << 2) & bit) != 0)
        *(ar + 2) = '1';
    else
        *(ar + 2) = '0';
    if (((1 << 1) & bit) != 0)
        *(ar + 3) = '1';
    else
        *(ar + 3) = '0';
    if (((1 << 0) & bit) != 0)
        *(ar + 4) = '1';
    else
        *(ar + 4) = '0';

    *(ar + 5) = ' ';
    *(ar + 6) = '\0';
}

void Print(int set, char* ar, int bit = 31) {
    if (set == 0) {
        *(ar + 0) = 'e';
        *(ar + 1) = 'm';
        *(ar + 2) = 'p';
        *(ar + 3) = 't';
        *(ar + 4) = 'y';
        *(ar + 5) = '\0';
    }
    else {
        if (bit == 0) {
            if (((1 << bit) & set) != 0) {
                PrintToArray(set, ar, bit);
                return;
            }
            return;
        }
        else {
            if (((1 << bit) & set) != 0) {
                PrintToArray(set, ar, bit);
                return Print(set, ar + 6, --bit);
            }
            else
                return Print(set, ar, --bit);
        }
    }
}

bool Emptiness(int set) {
    return set == 0;
}

bool Nonempty(int set) {
    return !(Emptiness(set));
}

bool Member(char* ar, int set) {
    int tempSet = set;
    Erase(ar, &tempSet);
    if (tempSet == set)
        return false;
    return true;
}

bool Disjoint(int set1, int set2) {
    return ((set1 & set2) == 0);
}

bool Conjunctive(int set1, int set2) {
    return !Disjoint(set1, set2);
}

bool Equality(int set1, int set2) {
    return set1 == set2;
}

bool Inclusion(int set1, int set2) {
    return ((set1 | set2) == set2);
}

void Union(int set1, int set2, int* set3) {
    *set3 = (set1 | set2);
}


void Intersection(int set1, int set2, int* set3) {
    *set3 = (set1 & set2);
}

void Symmetric(int set1, int set2, int* set3) {
    *set3 = (set1 ^ set2);
}

void Difference(int set1, int set2, int* set3) {
    *set3 = (set1 & ~set2);
}

void Complement(int set1, int* set2) {
    *set2 = (~set1);
}

int Cardinality(int set, int bit = 0) {
    if (bit == 31)
        return  ((((1 << bit) & set)) != 0);
    else
        if (((1 << bit) & set) != 0)
            return Cardinality(set, ++bit) + 1;
        else
            return Cardinality(set, ++bit);
}

bool LessThen(int set1, int set2) {
    if (Cardinality(set1) == Cardinality(set2))
        return (set1 < set2);
    else
        return (Cardinality(set1) < Cardinality(set2));
}


bool LessEqual(int set1, int set2)
{
    return (LessThen(set1, set2) || set1 == set2);
}

bool GreatEqual(int set1, int set2)
{
    return !LessThen(set1, set2);
}

bool GreatThen(int set1, int set2)
{
    return !LessEqual(set1, set2);
}
