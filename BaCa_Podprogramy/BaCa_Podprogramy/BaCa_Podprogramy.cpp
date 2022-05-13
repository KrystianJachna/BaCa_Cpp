// Krystian Jachna
#include <iostream>
#include <string>
#include <cstdarg>
using namespace std;


// string na inta
int strToInt(string l) {
    return (l[0] - '0');
}

// int na stringa
string intToStr(int l) {
    string str = "";

    if (l < 10)
        str += l + '0';
    else {
        int tmp = l % 10;
        str += (l - tmp) / 10 + '0';
        str += tmp + '0';
    }
    return str;
}

// dodawanie 0 na poczatku
string fixNumber(string number, int sizeToDo, int sizeNow) {
    if (sizeNow == sizeToDo)
        return number;
    else
        return "0" + fixNumber(number, sizeToDo, ++sizeNow);
}

// dodawanie 
string summing(string f_n, string s_n, int leng, string carry = "0") {
    leng--;

    if (leng >= 0) {
        int firstDigit = f_n[leng] - '0';
        int secondDigit = s_n[leng] - '0';
        int cr = carry[0] - '0';
        int sum = +cr + firstDigit + secondDigit;

        if (sum < 10) {
            return summing(f_n, s_n, leng, "0") + intToStr(sum);
        }
        else {
            string c = intToStr(sum);
            string carryStr = "";
            carryStr += c[0];
            return summing(f_n, s_n, leng, carryStr) + c[1];
        }
    }
    else
        return carry;
}

// sprowadzenie do takich samych postaci (tyle samo cyf) 
string sum(string f_n, string s_n) {
    if (f_n.length() > s_n.length())
        s_n = fixNumber(s_n, f_n.length(), s_n.length());
    else
        f_n = fixNumber(f_n, s_n.length(), f_n.length());

    return summing(f_n, s_n, f_n.length());
}

// czy pierwsza wieksza od drugiej
bool isBigger(string f_n, string s_n, int i = 0) {
    if (i < f_n.length()) {
        if (f_n[i] == s_n[i])
            return isBigger(f_n, s_n, ++i);
        else
            return (f_n[i] > s_n[i]);
    }
    else
        return (f_n[i] > s_n[i]);
}

// szukanie pozyczki
void findCredit(string& f_n, int i) {
    i--;

    if (i >= 0) {
        int dig = f_n[i] - '0';
        if (dig != 0) {
            dig--;
            f_n[i] = intToStr(dig)[0];
        }
        else {
            f_n[i] = '9';
            return findCredit(f_n, i);
        }
    }
    else
        return;

}

// odejmowanie
string subbing(string f_n, string s_n, int leng) {
    leng--;

    if (leng > 0) {
        int firstDigit = f_n[leng] - '0';
        int secondDigit = s_n[leng] - '0';
        int sub = firstDigit - secondDigit;

        if (sub >= 0)
            return subbing(f_n, s_n, leng) + intToStr(sub);
        else {
            int prevDigit = f_n[leng - 1] - '0';
            if (prevDigit != 0) {
                prevDigit--;
                f_n[leng - 1] = intToStr(prevDigit)[0];
                sub = 10 + firstDigit - secondDigit;
                return subbing(f_n, s_n, leng) + intToStr(sub);
            }
            else {
                findCredit(f_n, leng);
                sub = 10 + firstDigit - secondDigit;
                return subbing(f_n, s_n, leng) + intToStr(sub);
            }
        }
    }
    else {
        int firstDigit = f_n[leng] - '0';
        int secondDigit = s_n[leng] - '0';
        int sub = firstDigit - secondDigit;

        return intToStr(sub);
    }
}

// sprowadzanie do takich samych postaci (tyle samo cyf)
string sub(string f_n, string s_n) {
    if (f_n.length() > s_n.length())
        s_n = fixNumber(s_n, f_n.length(), s_n.length());
    else
        f_n = fixNumber(f_n, s_n.length(), f_n.length());

    return subbing(f_n, s_n, f_n.length());
}

// usuwanie zer z przodu
string corretNumber(string& number, int i = 0) {
    if (number[i] == '-' || number[i] == '+')
        i++;
    if (i < number.length()) {
        if (number[i] != '0')
            return number;
        else {
            string temp = "";
            if (number[0] == '-' || number[0] == '+') {
                temp += number[0];
                temp += number.substr(i + 1);
            }
            else
                temp = number.substr(i + 1);
            return corretNumber(temp, i);
        }
    }
    else {
        string temp = "";
        if (number[0] == '-' || number[0] == '+')
            temp += number[0];
        temp += "0";
        return temp;
    }
}

// sprawdzenie czy odejmowanie czy dodawanie
string getResult(string f, string s) {
    string f_tadd = f;
    string s_tadd = s;
    string result = "";

    if (f[0] == '+' || f[0] == '-')
        f_tadd = f.substr(1, f.length() - 1);
    if (s[0] == '+' || s[0] == '-')
        s_tadd = s.substr(1, s.length() - 1);

    s_tadd = corretNumber(s_tadd);
    f_tadd = corretNumber(f_tadd);

    if ((f[0] == '-' && s[0] == '-') || (f[0] != '-' && s[0] != '-')) {
        if (f[0] == '-')
            result += '-';
        result += sum(f_tadd, s_tadd);
    }
    else {
        if ((f[0]) == '-')
            swap(f_tadd, s_tadd);

        if (f_tadd.size() < s_tadd.size() || f_tadd.size() == s_tadd.size() && isBigger(f_tadd, s_tadd) == false) {
            swap(f_tadd, s_tadd);
            result += '-';
        }
        result += sub(f_tadd, s_tadd);
    }
    return result;
}

// sumowanie z zerami na poczatku
string SumOwn(int l_Arg, const string* arg, int i = 0) {
    if (i == l_Arg - 1)
        return *arg;
    else {
        string prevRes = SumOwn(l_Arg, arg + 1, ++i);
        string toAdd = *arg;
        string result = getResult(prevRes, toAdd);
        return corretNumber(result);
    }
}

string Sum(int l_Arg, const string* arg) {
    string sum = SumOwn(l_Arg, arg);

    if (sum == "+0" || sum == "-0")
        sum = "0";
    return sum;
}

void Sum(string* result, int l_Arg, const string* arg) {
    *result = Sum(l_Arg, arg);
}

void Sum(string& result, int l_Arg, const string* arg) {
    result = Sum(l_Arg, arg);
}

// wypelnianie tablicy lista
void addTabElem(va_list& arguments, string* tab, int tabSize, int i = 0) {
    if (i < tabSize) {
        string xd = (string)va_arg(arguments, char*);
        *(tab + i) = xd;
        addTabElem(arguments, tab, tabSize, ++i);
    }
    else
        return;
}

string Sum(int l_Arg, ...) {
    string* tab = new string[l_Arg];
    va_list arguments;
    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    string sum = Sum(l_Arg, tab);

    delete[]tab;

    return sum;
}

void Sum(string* res, int l_Arg, ...) {
    string* tab = new string[l_Arg];

    va_list arguments;

    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    *res = Sum(l_Arg, tab);

    delete[]tab;
}

void Sum(string& res, int l_Arg, ...) {
    string* tab = new string[l_Arg];
    va_list arguments;
    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    res = Sum(l_Arg, tab);

    delete[]tab;
}

// mnozenie cyfry przez cala liczbe
string multByOne(string f_n, int f_nLen, int one, string carry = "0") {
    f_nLen--;
    if (f_nLen >= 0) {
        int digit = f_n[f_nLen] - '0';
        int cr = strToInt(carry);
        int multedAdded = digit * one + cr;

        string mA = intToStr(multedAdded);
        string m = "";
        m += mA[0];
        if (multedAdded < 10)
            return multByOne(f_n, f_nLen, one, "0") + mA[0];
        else
            return multByOne(f_n, f_nLen, one, m) + mA[1];
    }
    else
        return carry;
}

// mnozenie
void multting(string f_n, string s_n, int scLen, string* tabAfter, string zeros = "") {
    scLen--;

    if (scLen >= 0) {
        int firstDigit = s_n[scLen] - '0';
        *(tabAfter + scLen) = multByOne(f_n, f_n.length(), firstDigit) + zeros;
        zeros += "0";
        multting(f_n, s_n, scLen, tabAfter, zeros);
    }
    else
        return;
}

// sprawdzanie znaku
string getResultMult(string f, string s) {
    string f_tadd = f;
    string s_tadd = s;
    string result = "";

    if (f[0] == '+' || f[0] == '-')
        f_tadd = f.substr(1, f.length() - 1);
    if (s[0] == '+' || s[0] == '-')
        s_tadd = s.substr(1, s.length() - 1);

    if ((f[0] == '-' && s[0] == '-') || (f[0] != '-' && s[0] != '-'));
    else
        result += '-';

    string* tabMultiples = new string[s_tadd.length()];
    multting(f_tadd, s_tadd, s_tadd.length(), tabMultiples);
    result += Sum(s_tadd.length(), tabMultiples);
    delete[] tabMultiples;
    return result;
}

// mnozenie po kolei
string MultOwn(int l_Arg, const string* arg, int i = 0) {
    if (i == l_Arg - 1) {
        return *arg;
    }
    else {
        string prevRes = MultOwn(l_Arg, arg + 1, ++i);
        string toAdd = *arg;
        string result = getResultMult(prevRes, toAdd);
        return corretNumber(result);
    }
}

string Mult(int l_Arg, const string* arg) {
    string mult = MultOwn(l_Arg, arg);

    if (mult == "+0" || mult == "-0")
        mult = "0";
    return mult;
}

void Mult(string* res, int l_Arg, const string* arg) {
    *res = Mult(l_Arg, arg);
}

void Mult(string& res, int l_Arg, const string* arg) {
    res = Mult(l_Arg, arg);
}

string Mult(int l_Arg, ...) {
    string* tab = new string[l_Arg];
    va_list arguments;
    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    string sum = Mult(l_Arg, tab);

    delete[]tab;

    return sum;
}

void Mult(string* res, int l_Arg, ...) {
    string* tab = new string[l_Arg];

    va_list arguments;

    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    *res = Mult(l_Arg, tab);

    delete[]tab;
}

void Mult(string& res, int l_Arg, ...) {
    string* tab = new string[l_Arg];

    va_list arguments;

    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    res = Mult(l_Arg, tab);

    delete[]tab;
}

string Operation(string(*op) (int, const string*), int l_Arg, const string* args) {
    return op(l_Arg, args);
}

string Operation(string(*op) (int, const string*), int l_Arg, ...) {
    string* tab = new string[l_Arg];
    string res;

    va_list arguments;

    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    res = op(l_Arg, tab);

    delete[]tab;

    return res;
}

void Operation(string* r, string(*op) (int, const string*), int l_Arg, ...) {
    string* tab = new string[l_Arg];
    string res;

    va_list arguments;

    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    res = op(l_Arg, tab);

    delete[]tab;

    *r = res;
}

void Operation(string* r, string(*op) (int, const string*), int l_Arg, const string* args) {
    *r = op(l_Arg, args);
}

void Operation(string& r, void(*op) (string*, int, const string*), int l_Arg, const string* args) {
    op(&r, l_Arg, args);
}

void Operation(string& r, void(*op) (string*, int, const string*), int l_Arg, ...) {
    string* tab = new string[l_Arg];

    va_list arguments;

    va_start(arguments, l_Arg);

    addTabElem(arguments, tab, l_Arg);

    va_end(arguments);

    op(&r, l_Arg, tab);

    delete[]tab;
}

int main() {

    cout << Mult(3, "345353534535590713289571329085732", "-00004132758545345915089", "+095834533429573420572");

    
    return 0;
}


