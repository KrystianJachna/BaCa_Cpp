#include <iostream>
using namespace std;

struct place {
    unsigned short int amout = 0;
    unsigned char label_0 = 0;
    unsigned char label_1 = 0;
};

struct shelf {
    place places[128];
    unsigned short int size = 0;
};

struct rack {
    shelf shelves[128];
    unsigned short int size = 0;
};

struct warehouse {
    rack racks[128];
    shelf handyShelf;
    unsigned short int size = 0;
};

struct storage {
    warehouse warehouses[128];
    rack handyRack;
    shelf handyShelf;
    unsigned short int size = 0;
};

storage store;
long long unsigned int totalGoods = 0;

bool actionChoice(unsigned char inputCode[], const char operationCode[])
{
    unsigned char i = 0;

    while (inputCode[i] != 0 && operationCode[i] != 0) {
        if (inputCode[i] != operationCode[i])
            return false;
        i++;
    }
    if (inputCode[i] == 0 && operationCode[i] != 0 || inputCode[i] != 0 && operationCode[i] == 0)
        return false;
    return true;
}

bool inRange(unsigned short int parameter, unsigned short int size)
{
    if (parameter >= size || parameter < 0)//size = ?
        return false;
    return true;
}

void fill(unsigned short int W, unsigned short int R, unsigned short int S, unsigned short int P, long long int A)
{
    if (inRange(W, 129) == true && inRange(R, 129) == true && inRange(S, 129) == true && inRange(P, 129) == true && A >= 0 && A <= 65535) {
        store.size = W;
        for (int i = 0; i < W; i++) {
            store.warehouses[i].size = R;
            for (int j = 0; j < R; j++) {
                store.warehouses[i].racks[j].size = S;
                for (int k = 0; k < S; k++) {
                    store.warehouses[i].racks[j].shelves[k].size = P;
                    for (int l = 0; l < P; l++) {
                        store.warehouses[i].racks[j].shelves[k].places[l].amout = A;
                        store.warehouses[i].racks[j].shelves[k].places[l].label_0 = 0;
                        store.warehouses[i].racks[j].shelves[k].places[l].label_1 = 0;
                    }
                }
            }
        }
        store.handyShelf.size = P;
        for (int i = 0; i < P; i++) {
            store.handyShelf.places[i].amout = A;
            store.handyShelf.places[i].label_0 = 0;
            store.handyShelf.places[i].label_1 = 0;
        }
        store.handyRack.size = S;
        for (int i = 0; i < S; i++) {
            store.handyRack.shelves[i].size = P;
            for (int j = 0; j < P; j++) {
                store.handyRack.shelves[i].places[j].amout = A;
                store.handyRack.shelves[i].places[j].label_0 = 0;
                store.handyRack.shelves[i].places[j].label_1 = 0;
            }
        }
        for (int i = 0; i < W; i++) {
            store.warehouses[i].handyShelf.size = P;
            for (int j = 0; j < P; j++) {
                store.warehouses[i].handyShelf.places[j].amout = A;
                store.warehouses[i].handyShelf.places[j].label_0 = 0;
                store.warehouses[i].handyShelf.places[j].label_1 = 0;
            }
        }
        totalGoods = (long long unsigned int)W * R * S * P * A;
        totalGoods += (long long unsigned int)W * P * A;
        totalGoods += (long long unsigned int)S * P * A;
        totalGoods += (long long unsigned int)P * A;

    }
    else
        cout << "error" << endl;
}

void get_e()
{
    cout << totalGoods << endl;
}

void get_w(unsigned short int W)
{
    if (inRange(W, store.size) == true) {

        long long unsigned int sum = 0;

        for (int i = 0; i < store.warehouses[W].size; i++) {
            for (int j = 0; j < store.warehouses[W].racks[i].size; j++) {
                for (int k = 0; k < store.warehouses[W].racks[i].shelves[j].size; k++) {
                    sum += store.warehouses[W].racks[i].shelves[j].places[k].amout;
                }
            }
        }
        for (int i = 0; i < store.warehouses[W].handyShelf.size; i++) {
            sum += store.warehouses[W].handyShelf.places[i].amout;
        }
        cout << sum << endl;
    }
    else
        cout << "error" << endl;
}

void get_rw(unsigned short int W, unsigned short int R)
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true) {

        long long unsigned int sum = 0;

        for (int i = 0; i < store.warehouses[W].racks[R].size; i++) {
            for (int j = 0; j < store.warehouses[W].racks[R].shelves[i].size; j++) {
                sum += store.warehouses[W].racks[R].shelves[i].places[j].amout;
            }
        }
        cout << sum << endl;
    }
    else
        cout << "error" << endl;
}

void get_rh()
{
    long long unsigned int sum = 0;

    for (int i = 0; i < store.handyRack.size; i++) {
        for (int j = 0; j < store.handyRack.shelves[i].size; j++) {
            sum += store.handyRack.shelves[i].places[j].amout;
        }
    }
    cout << sum << endl;
}

void get_sw(unsigned short int W, unsigned short int R, unsigned short int S)
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(S, store.warehouses[W].racks[R].size) == true) {

        long long unsigned int sum = 0;

        for (int i = 0; i < store.warehouses[W].racks[R].shelves[S].size; i++) {
            sum += store.warehouses[W].racks[R].shelves[S].places[i].amout;
        }
        cout << sum << endl;
    }
    else
        cout << "error" << endl;
}

void get_sh(unsigned short int W)
{
    if (inRange(W, store.size) == true) {

        long long unsigned int sum = 0;

        for (int i = 0; i < store.warehouses[W].handyShelf.size; i++) {
            sum += store.warehouses[W].handyShelf.places[i].amout;
        }
        cout << sum << endl;
    }
    else
        cout << "error" << endl;
}

void get_sr(unsigned short int S)
{
    if (inRange(S, store.handyRack.size) == true) {

        long long unsigned int sum = 0;

        for (int i = 0; i < store.handyRack.shelves[S].size; i++) {
            sum += store.handyRack.shelves[S].places[i].amout;
        }
        cout << sum << endl;
    }
    else
        cout << "error" << endl;
}

void get_s()
{
    long long unsigned int sum = 0;

    for (int i = 0; i < store.handyShelf.size; i++) {
        sum += store.handyShelf.places[i].amout;
    }

    cout << sum << endl;
}

void set_lw(unsigned short int W, unsigned short int R, unsigned short int S, unsigned short int P, unsigned char DD[])
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(S, store.warehouses[W].racks[R].size) == true && inRange(P, store.warehouses[W].racks[R].shelves[S].size) == true) {
        store.warehouses[W].racks[R].shelves[S].places[P].label_0 = DD[0];
        store.warehouses[W].racks[R].shelves[S].places[P].label_1 = DD[1];
    }
    else
        cout << "error" << endl;
}

void get_lw(unsigned short int W, unsigned short int R, unsigned short int S, unsigned short int P)
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(S, store.warehouses[W].racks[R].size) == true && inRange(P, store.warehouses[W].racks[R].shelves[S].size) == true) {
        if (store.warehouses[W].racks[R].shelves[S].places[P].label_0 != 0 && store.warehouses[W].racks[R].shelves[S].places[P].label_1 != 0)
            cout << store.warehouses[W].racks[R].shelves[S].places[P].label_0 << store.warehouses[W].racks[R].shelves[S].places[P].label_1 << endl;
        else
            cout << "--" << endl;
    }
    else
        cout << "error" << endl;
}

void set_lh(unsigned short int W, unsigned short int P, unsigned char DD[])
{
    if (inRange(W, store.size) == true && inRange(P, store.handyShelf.size) == true) {
        store.warehouses[W].handyShelf.places[P].label_0 = DD[0];
        store.warehouses[W].handyShelf.places[P].label_1 = DD[1];
    }
    else
        cout << "error" << endl;
}

void get_lh(unsigned short int W, unsigned short int P)
{
    if (inRange(W, store.size) == true && inRange(P, store.handyShelf.size) == true) {
        if (store.warehouses[W].handyShelf.places[P].label_0 != 0 && store.warehouses[W].handyShelf.places[P].label_1 != 0)
            cout << store.warehouses[W].handyShelf.places[P].label_0 << store.warehouses[W].handyShelf.places[P].label_1 << endl;
        else
            cout << "--" << endl;
    }
    else
        cout << "error" << endl;
}

void set_lr(unsigned short int S, unsigned short int P, unsigned char DD[])
{
    if (inRange(S, store.handyRack.size) == true && inRange(P, store.handyRack.shelves[S].size) == true) {
        store.handyRack.shelves[S].places[P].label_0 = DD[0];
        store.handyRack.shelves[S].places[P].label_1 = DD[1];
    }
    else
        cout << "error" << endl;
}

void get_lr(unsigned short int S, unsigned short int P)
{
    if (inRange(S, store.handyRack.size) == true && inRange(P, store.handyRack.shelves[S].size) == true) {
        if (store.handyRack.shelves[S].places[P].label_0 != 0 && store.handyRack.shelves[S].places[P].label_1 != 0)
            cout << store.handyRack.shelves[S].places[P].label_0 << store.handyRack.shelves[S].places[P].label_1 << endl;
        else
            cout << "--" << endl;
    }
    else
        cout << "error" << endl;
}

void set_ls(unsigned short int P, unsigned char DD[])
{
    if (inRange(P, store.handyShelf.size) == true) {
        store.handyShelf.places[P].label_0 = DD[0];
        store.handyShelf.places[P].label_1 = DD[1];
    }
    else
        cout << "error" << endl;
}

void get_ls(unsigned short int P)
{
    if (inRange(P, store.handyShelf.size) == true)
        if (store.handyShelf.places[P].label_0 != 0 && store.handyShelf.places[P].label_1 != 0)
            cout << store.handyShelf.places[P].label_0 << store.handyShelf.places[P].label_1 << endl;
        else
            cout << "--" << endl;
    else
        cout << "error" << endl;
}

void put_w(unsigned short int W, unsigned short int R, unsigned short int S, unsigned short int P, long long int A)
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(S, store.warehouses[W].racks[R].size) == true && inRange(P, store.warehouses[W].racks[R].shelves[S].size) == true && A >= 0) {
        if ((store.warehouses[W].racks[R].shelves[S].places[P].amout + A) >= 65535) {
            totalGoods += (65535 - store.warehouses[W].racks[R].shelves[S].places[P].amout);
            store.warehouses[W].racks[R].shelves[S].places[P].amout = 65535;
        }
        else {
            totalGoods += A;
            store.warehouses[W].racks[R].shelves[S].places[P].amout += A;
        }
    }
    else
        cout << "error" << endl;
}

void put_h(unsigned short int W, unsigned short int P, long long int A)
{
    if (inRange(W, store.size) == true && inRange(P, store.warehouses[W].handyShelf.size) == true && A >= 0) {
        if ((store.warehouses[W].handyShelf.places[P].amout + A) >= 65535) {
            totalGoods += (65535 - store.warehouses[W].handyShelf.places[P].amout);
            store.warehouses[W].handyShelf.places[P].amout = 65535;
        }
        else {
            totalGoods += A;
            store.warehouses[W].handyShelf.places[P].amout += A;
        }
    }
    else
        cout << "error" << endl;
}

void put_r(unsigned short int S, unsigned short int P, long long int A)
{
    if (inRange(S, store.handyRack.size) == true && inRange(P, store.handyRack.shelves[S].size) == true && A >= 0) {
        if ((store.handyRack.shelves[S].places[P].amout + A) >= 65535) {
            totalGoods += (65535 - store.handyRack.shelves[S].places[P].amout);
            store.handyRack.shelves[S].places[P].amout = 65535;
        }
        else {
            totalGoods += A;
            store.handyRack.shelves[S].places[P].amout += A;
        }
    }
    else
        cout << "error" << endl;
}

void put_s(unsigned short int P, long long int A)
{
    if (inRange(P, store.handyShelf.size) == true && A >= 0) {
        if ((store.handyShelf.places[P].amout + A) >= 65535) {
            totalGoods += (65535 - store.handyShelf.places[P].amout);
            store.handyShelf.places[P].amout = 65535;
        }
        else {
            totalGoods += A;
            store.handyShelf.places[P].amout += A;
        }
    }
    else
        cout << "error" << endl;
}

void pop_w(unsigned short int W, unsigned short int R, unsigned short int S, unsigned short int P, long long int A)
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(S, store.warehouses[W].racks[R].size) == true && inRange(P, store.warehouses[W].racks[R].shelves[S].size) == true && A >= 0) {
        if ((store.warehouses[W].racks[R].shelves[S].places[P].amout - A) < 0) {
            totalGoods -= store.warehouses[W].racks[R].shelves[S].places[P].amout;
            store.warehouses[W].racks[R].shelves[S].places[P].amout = 0;
        }
        else {
            totalGoods -= A;
            store.warehouses[W].racks[R].shelves[S].places[P].amout -= A;
        }
    }
    else
        cout << "error" << endl;
}

void pop_h(unsigned short int W, unsigned short int P, long long int A)
{
    if (inRange(W, store.size) == true && inRange(P, store.warehouses[W].handyShelf.size) == true && A >= 0) {
        if ((store.warehouses[W].handyShelf.places[P].amout - A) < 0) {
            totalGoods -= store.warehouses[W].handyShelf.places[P].amout;
            store.warehouses[W].handyShelf.places[P].amout = 0;
        }
        else {
            totalGoods -= A;
            store.warehouses[W].handyShelf.places[P].amout -= A;
        }
    }
    else
        cout << "error" << endl;
}

void pop_r(unsigned short int S, unsigned short int P, long long int A)
{
    if (inRange(S, store.handyRack.size) == true && inRange(P, store.handyRack.shelves[S].size) == true && A >= 0) {
        if ((store.handyRack.shelves[S].places[P].amout - A) < 0) {
            totalGoods -= store.handyRack.shelves[S].places[P].amout;
            store.handyRack.shelves[S].places[P].amout = 0;
        }
        else {
            totalGoods -= A;
            store.handyRack.shelves[S].places[P].amout -= A;
        }
    }
    else
        cout << "error" << endl;
}

void pop_s(unsigned short int P, long long int A)
{
    if (inRange(P, store.handyShelf.size) == true && A >= 0) {
        if ((store.handyShelf.places[P].amout - A) < 0) {
            totalGoods -= store.handyShelf.places[P].amout;
            store.handyShelf.places[P].amout = 0;
        }
        else {
            totalGoods -= A;
            store.handyShelf.places[P].amout -= A;
        }
    }
    else
        cout << "error" << endl;
}

void mov_w(unsigned short int fW, unsigned short int fR, unsigned short int fS, unsigned short int tW, unsigned short tR, unsigned short int tS, unsigned short int P, long long int A)
{
    long long int amout = 0;

    if (inRange(fW, store.size) == true && inRange(fR, store.warehouses[fW].size) == true && inRange(fS, store.warehouses[fW].racks[fR].size) == true && inRange(P, store.warehouses[fW].racks[fR].shelves[fS].size) == true && inRange(tW, store.size) == true && inRange(tR, store.warehouses[tW].size) == true && inRange(tS, store.warehouses[tW].racks[tR].size) == true && inRange(P, store.warehouses[tW].racks[tR].shelves[tS].size) == true && A >= 0) {
        if (A > (store.warehouses[fW].racks[fR].shelves[fS].places[P].amout) && (store.warehouses[fW].racks[fR].shelves[fS].places[P].amout + store.warehouses[tW].racks[tR].shelves[tS].places[P].amout) <= 65535) {
            store.warehouses[tW].racks[tR].shelves[tS].places[P].amout += store.warehouses[fW].racks[fR].shelves[fS].places[P].amout;
            store.warehouses[fW].racks[fR].shelves[fS].places[P].amout = 0;
        }
        else if (A > (store.warehouses[fW].racks[fR].shelves[fS].places[P].amout) && (store.warehouses[fW].racks[fR].shelves[fS].places[P].amout + store.warehouses[tW].racks[tR].shelves[tS].places[P].amout) > 65535) {
            amout = 65535 - store.warehouses[tW].racks[tR].shelves[tS].places[P].amout;
            store.warehouses[fW].racks[fR].shelves[fS].places[P].amout -= amout;
            store.warehouses[tW].racks[tR].shelves[tS].places[P].amout = 65535;
        }
        else if (A <= (store.warehouses[fW].racks[fR].shelves[fS].places[P].amout) && (A + store.warehouses[tW].racks[tR].shelves[tS].places[P].amout) <= 65535) {
            store.warehouses[fW].racks[fR].shelves[fS].places[P].amout -= A;
            store.warehouses[tW].racks[tR].shelves[tS].places[P].amout += A;
        }
        else if (A <= (store.warehouses[fW].racks[fR].shelves[fS].places[P].amout) && (A + store.warehouses[tW].racks[tR].shelves[tS].places[P].amout) > 65535) {
            amout = 65535 - store.warehouses[tW].racks[tR].shelves[tS].places[P].amout;
            store.warehouses[fW].racks[fR].shelves[fS].places[P].amout -= amout;
            store.warehouses[tW].racks[tR].shelves[tS].places[P].amout = 65535;
        }
    }
    else
        cout << "error" << endl;
}

void mov_h(unsigned short int W, unsigned short int R, unsigned short int S, unsigned short int P, long long int A)
{
    long long int amout = 0;

    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(S, store.warehouses[W].racks[R].size) == true && inRange(P, store.warehouses[W].racks[R].shelves[S].size) == true && inRange(P, store.warehouses[W].handyShelf.size) == true) {
        if (A > (store.warehouses[W].racks[R].shelves[S].places[P].amout) && (store.warehouses[W].racks[R].shelves[S].places[P].amout + store.warehouses[W].handyShelf.places[P].amout) <= 65535) {
            store.warehouses[W].handyShelf.places[P].amout += store.warehouses[W].racks[R].shelves[S].places[P].amout;
            store.warehouses[W].racks[R].shelves[S].places[P].amout = 0;
        }
        else if (A > (store.warehouses[W].racks[R].shelves[S].places[P].amout) && (store.warehouses[W].racks[R].shelves[S].places[P].amout + store.warehouses[W].handyShelf.places[P].amout) > 65535) {
            amout = 65535 - store.warehouses[W].handyShelf.places[P].amout;
            store.warehouses[W].racks[R].shelves[S].places[P].amout -= amout;
            store.warehouses[W].handyShelf.places[P].amout = 65535;
        }
        else if (A <= (store.warehouses[W].racks[R].shelves[S].places[P].amout) && (A + store.warehouses[W].handyShelf.places[P].amout) <= 65535) {
            store.warehouses[W].racks[R].shelves[S].places[P].amout -= A;
            store.warehouses[W].handyShelf.places[P].amout += A;
        }
        else if (A <= (store.warehouses[W].racks[R].shelves[S].places[P].amout) && (A + store.warehouses[W].handyShelf.places[P].amout) > 65535) {
            amout = 65535 - store.warehouses[W].handyShelf.places[P].amout;
            store.warehouses[W].racks[R].shelves[S].places[P].amout -= amout;
            store.warehouses[W].handyShelf.places[P].amout = 65535;
        }
    }
    else
        cout << "error" << endl;
}

void mov_r(unsigned short int W, unsigned short int R, unsigned short int fS, unsigned short int tS, unsigned short int P, long long int A)
{
    long long int amout = 0;

    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(fS, store.warehouses[W].racks[R].size) == true && inRange(tS, store.handyRack.size) == true && inRange(P, store.warehouses[W].racks[R].shelves[fS].size) == true && inRange(P, store.handyRack.shelves[tS].size) == true && A >= 0) {
        if (A > (store.warehouses[W].racks[R].shelves[fS].places[P].amout) && (store.warehouses[W].racks[R].shelves[fS].places[P].amout + store.handyRack.shelves[tS].places[P].amout) <= 65535) {
            store.handyRack.shelves[tS].places[P].amout += store.warehouses[W].racks[R].shelves[fS].places[P].amout;
            store.warehouses[W].racks[R].shelves[fS].places[P].amout = 0;
        }
        else if (A > (store.warehouses[W].racks[R].shelves[fS].places[P].amout) && (store.warehouses[W].racks[R].shelves[fS].places[P].amout + store.handyRack.shelves[tS].places[P].amout) > 65535) {
            amout = 65535 - store.handyRack.shelves[tS].places[P].amout;
            store.warehouses[W].racks[R].shelves[fS].places[P].amout -= amout;
            store.handyRack.shelves[tS].places[P].amout = 65535;
        }
        else if (A <= (store.warehouses[W].racks[R].shelves[fS].places[P].amout) && (A + store.handyRack.shelves[tS].places[P].amout) <= 65535) {
            store.warehouses[W].racks[R].shelves[fS].places[P].amout -= A;
            store.handyRack.shelves[tS].places[P].amout += A;
        }
        else if (A <= (store.warehouses[W].racks[R].shelves[fS].places[P].amout) && (A + store.handyRack.shelves[tS].places[P].amout) > 65535) {
            amout = 65535 - store.handyRack.shelves[tS].places[P].amout;
            store.warehouses[W].racks[R].shelves[fS].places[P].amout -= amout;
            store.handyRack.shelves[tS].places[P].amout = 65535;
        }
    }
    else
        cout << "error" << endl;
}

void mov_s(unsigned short int S, unsigned short int P, long long int A)
{
    long long int amout = 0;

    if (inRange(S, store.handyRack.size) == true && inRange(P, store.handyRack.shelves[S].size) == true && inRange(P, store.handyShelf.size) == true && A >= 0) {
        if (A > store.handyRack.shelves[S].places[P].amout && (store.handyShelf.places[P].amout + store.handyRack.shelves[S].places[P].amout) <= 65535) {
            store.handyShelf.places[S].amout += store.handyRack.shelves[S].places[P].amout;
            store.handyRack.shelves[S].places[P].amout = 0;
        }
        else if (A > store.handyRack.shelves[S].places[P].amout && (store.handyShelf.places[P].amout + store.handyRack.shelves[S].places[P].amout) > 65535) {
            amout = 65535 - store.handyShelf.places[P].amout;
            store.handyRack.shelves[S].places[P].amout -= amout;
            store.handyShelf.places[P].amout = 65535;
        }
        else if (A < store.handyRack.shelves[S].places[P].amout && (store.handyShelf.places[P].amout + A) <= 65535) {
            store.handyRack.shelves[S].places[P].amout -= A;
            store.handyShelf.places[P].amout += A;
        }
        else if (A < store.handyRack.shelves[S].places[P].amout && (store.handyShelf.places[P].amout + A) > 65535) {
            amout = 65535 - store.handyShelf.places[P].amout;
            store.handyRack.shelves[S].places[P].amout -= amout;
            store.handyShelf.places[P].amout = 65535;
        }

    }
    else
        cout << "error" << endl;
}

void set_ap(unsigned short int W, unsigned short int R, unsigned short int S, long long int P)
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && inRange(S, store.warehouses[W].racks[R].size) == true && P >= 0 && P <= 128) {
        unsigned short int prevP = store.warehouses[W].racks[R].shelves[S].size;

        store.warehouses[W].racks[R].shelves[S].size = P;

        if (P > prevP) {
            for (int i = prevP; i < P; i++) {
                store.warehouses[W].racks[R].shelves[S].places[i].amout = 0;
                store.warehouses[W].racks[R].shelves[S].places[i].label_0 = 0;
                store.warehouses[W].racks[R].shelves[S].places[i].label_1 = 0;
            }
        }
        else if (P < prevP) {
            for (int i = P; i < prevP; i++) {
                totalGoods -= store.warehouses[W].racks[R].shelves[S].places[i].amout;
            }
        }
    }
    else
        cout << "error" << endl;
}

void set_as(unsigned short int W, unsigned short int R, long long int S, long long int P)
{
    if (inRange(W, store.size) == true && inRange(R, store.warehouses[W].size) == true && S >= 0 && S <= 128 && P >= 0 && P <= 128) {
        unsigned short int prevS = store.warehouses[W].size;
        store.warehouses[W].racks[R].size = S;
        if (prevS < S) {
            for (int i = prevS; i < S; i++) {
                set_ap(W, R, i, P);
            }
        }
        else if (prevS > S) {
            for (int i = S; i < prevS; i++) {
                for (int j = 0; j < store.warehouses[W].racks[R].shelves[i].size; j++) {
                    totalGoods -= store.warehouses[W].racks[R].shelves[i].places[j].amout;
                }
            }
        }
        for (int i = 0; i < S; i++) {
            set_ap(W, R, i, P);
        }
    }
    else
        cout << "error" << endl;
}

void set_ar(unsigned short int W, long long int R, long long int S, long long int P)
{
    if (inRange(W, store.size) == true && R >= 0 && R <= 128 && S >= 0 && S <= 128 && P >= 0 && P <= 128) {
        unsigned short int prevR = store.warehouses[W].size;

        store.warehouses[W].size = R;

        if (prevR < R) {
            for (int i = prevR; i < R; i++) {
                set_as(W, i, S, P);
            }
        }
        else if (prevR > R) {
            for (int i = R; i < prevR; i++) {
                for (int j = 0; j < store.warehouses[W].racks[i].size; j++) {
                    for (int k = 0; k < store.warehouses[W].racks[i].shelves[j].size; k++) {
                        totalGoods -= store.warehouses[W].racks[i].shelves[j].places[k].amout;
                    }
                }
            }
        }
        //store.warehouses[W].size = R;
        for (int i = 0; i < R; i++) {
            set_as(W, i, S, P);
        }
    }
    else
        cout << "error" << endl;
}

void set_aw(long long int W, long long int R, long long int S, long long int P)
{
    if (W >= 0 && W <= 128 && R >= 0 && R <= 128 && S >= 0 && S <= 129 && P >= 0 && P <= 128) {

        unsigned short int prevW = store.size;

        store.size = W;

        if (prevW < W) {
            for (int i = prevW; i < W; i++) {
                set_ar(i, R, S, P);
            }
        }
        else if (prevW > W) {
            for (int i = W; i < prevW; i++) {
                for (int j = 0; j < store.warehouses[i].size; j++) {
                    for (int k = 0; k < store.warehouses[i].racks[j].size; k++) {
                        for (int l = 0; l < store.warehouses[i].racks[j].shelves[k].size; l++) {
                            totalGoods -= store.warehouses[i].racks[j].shelves[k].places[l].amout;
                        }
                    }
                }
            }
        }
        //store.size = W;

        for (int i = 0; i < W; i++)
            set_ar(i, R, S, P);
    }
    else
        cout << "error" << endl;
}

void set_hw(unsigned short int W, long long int P)
{
    if (inRange(W, store.size) == true && P >= 0 && P <= 128) {
        unsigned short int prevP = store.warehouses[W].handyShelf.size;

        store.warehouses[W].handyShelf.size = P;

        if (prevP < P) {
            for (int i = prevP; i < P; i++) {
                store.warehouses[W].handyShelf.places[i].amout = 0;
                store.warehouses[W].handyShelf.places[i].label_0 = 0;
                store.warehouses[W].handyShelf.places[i].label_1 = 0;
            }
        }
        else if (prevP > P) {
            for (int i = P; i < prevP; i++) {
                totalGoods -= store.warehouses[W].handyShelf.places[i].amout;
            }
        }
    }
    else
        cout << "error" << endl;
}

void set_hr(long long int S, long long int P)
{
    if (S >= 0 && S <= 128 && P >= 0 && P <= 128) {
        unsigned short int prevS = store.handyRack.size;

        store.handyRack.size = S;

        if (prevS < S) {
            for (int i = prevS; i < S; i++) {
                store.handyRack.shelves[i].size = P;
                for (int j = 0; j < P; j++) {
                    store.handyRack.shelves[i].places[j].amout = 0;
                    store.handyRack.shelves[i].places[j].label_0 = 0;
                    store.handyRack.shelves[i].places[j].label_1 = 0;
                }
            }
        }
        else if (prevS > S) {
            for (int i = S; i < prevS; i++) {
                for (int j = 0; j < store.handyRack.shelves[i].size; j++) {
                    totalGoods -= store.handyRack.shelves[i].places[j].amout;
                }
            }
        }
        unsigned short int prevP;
        for (int i = 0; i < S; i++) {
            prevP = store.handyRack.shelves[i].size;

            store.handyRack.shelves[i].size = P;

            if (prevP < P) {
                for (int j = prevP; j < P; j++) {
                    store.handyRack.shelves[i].places[j].amout = 0;
                    store.handyRack.shelves[i].places[j].label_0 = 0;
                    store.handyRack.shelves[i].places[j].label_1 = 0;
                }
            }
            else if (prevP > P) {
                for (int j = P; j < prevP; j++) {
                    totalGoods -= store.handyRack.shelves[i].places[j].amout;
                }
            }
        }
    }
    else
        cout << "error" << endl;
}

void set_hs(long long int P)
{
    if (P <= 128 && P >= 0) {
        unsigned short int prevP = store.handyShelf.size;

        store.handyShelf.size = P;

        if (prevP < P) {
            for (int i = prevP; i < P; i++) {
                store.handyShelf.places[i].amout = 0;
                store.handyShelf.places[i].label_0 = 0;
                store.handyShelf.places[i].label_1 = 0;
            }
        }
        else if (prevP > P) {
            for (int i = P; i < prevP; i++) {
                totalGoods -= store.handyShelf.places[i].amout;
            }
        }
    }
    else
        cout << "error" << endl;

}

int main()
{
    unsigned char inputCode[8];
    unsigned short int W = 0;
    unsigned short int R = 0;
    unsigned short int S = 0;
    unsigned short int P = 0;
    unsigned short int toW = 0;
    unsigned short int toR = 0;
    unsigned short int toS = 0;
    unsigned short int toP = 0;
    long long int A = 0;
    long long int B = 0;
    long long int C = 0;
    long long int D = 0;
    unsigned char DD[3] = "\0";
    long long int value;


    do {
        cin >> inputCode;

        if (actionChoice(inputCode, "FILL") == true) {
            cin >> W >> R >> S >> P >> A;
            fill(W, R, S, P, A);
        }
        else if (actionChoice(inputCode, "GET-E") == true) {
            get_e();
        }
        else if (actionChoice(inputCode, "GET-W") == true) {
            cin >> W;
            get_w(W);
        }
        else if (actionChoice(inputCode, "GET-RW") == true) {
            cin >> W >> R;
            get_rw(W, R);
        }
        else if (actionChoice(inputCode, "GET-RH") == true) {
            get_rh();
        }
        else if (actionChoice(inputCode, "GET-SW") == true) {
            cin >> W >> R >> S;
            get_sw(W, R, S);

        }
        else if (actionChoice(inputCode, "GET-SH") == true) {
            cin >> W;
            get_sh(W);
        }
        else if (actionChoice(inputCode, "GET-SR") == true) {
            cin >> S;
            get_sr(S);
        }
        else if (actionChoice(inputCode, "GET-S") == true) {
            get_s();
        }
        else if (actionChoice(inputCode, "SET-LW") == true) {
            cin >> W >> R >> S >> P >> DD;
            set_lw(W, R, S, P, DD);
        }
        else if (actionChoice(inputCode, "SET-LH") == true) {
            cin >> W >> P >> DD;
            set_lh(W, P, DD);
        }
        else if (actionChoice(inputCode, "SET-LR") == true) {
            cin >> S >> P >> DD;
            set_lr(S, P, DD);
        }
        else if (actionChoice(inputCode, "SET-LS") == true) {
            cin >> P >> DD;
            set_ls(P, DD);
        }
        else if (actionChoice(inputCode, "GET-LW") == true) {
            cin >> W >> R >> S >> P;
            get_lw(W, R, S, P);
        }
        else if (actionChoice(inputCode, "GET-LH") == true) {
            cin >> W >> P;
            get_lh(W, P);
        }
        else if (actionChoice(inputCode, "GET-LR") == true) {
            cin >> S >> P;
            get_lr(S, P);
        }
        else if (actionChoice(inputCode, "GET-LS") == true) {
            cin >> P;
            get_ls(P);
        }
        else if (actionChoice(inputCode, "SET-AP") == true) {
            cin >> W >> R >> S >> A;
            set_ap(W, R, S, A);
        }
        else if (actionChoice(inputCode, "SET-AS") == true) {
            cin >> W >> R >> A >> B;
            set_as(W, R, A, B);

        }
        else if (actionChoice(inputCode, "SET-AR") == true) {
            cin >> W >> A >> B >> C;
            set_ar(W, A, B, C);
        }
        else if (actionChoice(inputCode, "SET-AW") == true) {
            cin >> A >> B >> C >> D;
            set_aw(A, B, C, D);
        }
        else if (actionChoice(inputCode, "SET-HW") == true) {
            cin >> W >> A;
            set_hw(W, A);
        }
        else if (actionChoice(inputCode, "SET-HR") == true) {
            cin >> A >> B;
            set_hr(A, B);
        }
        else if (actionChoice(inputCode, "SET-HS") == true) {
            cin >> A;
            set_hs(A);
        }
        else if (actionChoice(inputCode, "PUT-W") == true) {
            cin >> W >> R >> S >> P >> A;
            put_w(W, R, S, P, A);
        }
        else if (actionChoice(inputCode, "PUT-H") == true) {
            cin >> W >> P >> A;
            put_h(W, P, A);
        }
        else if (actionChoice(inputCode, "PUT-R") == true) {
            cin >> S >> P >> A;
            put_r(S, P, A);
        }
        else if (actionChoice(inputCode, "PUT-S") == true) {
            cin >> P >> A;
            put_s(P, A);
        }
        else if (actionChoice(inputCode, "POP-W") == true) {
            cin >> W >> R >> S >> P >> A;
            pop_w(W, R, S, P, A);
        }
        else if (actionChoice(inputCode, "POP-H") == true) {
            cin >> W >> P >> A;
            pop_h(W, P, A);
        }
        else if (actionChoice(inputCode, "POP-R") == true) {
            cin >> S >> P >> A;
            pop_r(S, P, A);
        }
        else if (actionChoice(inputCode, "POP-S") == true) {
            cin >> P >> A;
            pop_s(P, A);
        }
        else if (actionChoice(inputCode, "MOV-W") == true) {
            cin >> W >> R >> S >> toW >> toR >> toS >> P >> A;
            mov_w(W, R, S, toW, toR, toS, P, A);
        }
        else if (actionChoice(inputCode, "MOV-H") == true) {
            cin >> W >> R >> S >> P >> A;
            mov_h(W, R, S, P, A);
        }
        else if (actionChoice(inputCode, "MOV-R") == true) {
            cin >> W >> R >> S >> toS >> P >> A;
            mov_r(W, R, S, toS, P, A);
        }
        else if (actionChoice(inputCode, "MOV-S") == true) {
            cin >> S >> P >> A;
            mov_s(S, P, A);
        }
    } while (actionChoice(inputCode, "END") == false);

    return 0;
}