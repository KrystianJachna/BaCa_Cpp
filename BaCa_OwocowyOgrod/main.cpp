// Krystian Jachna
#include <iostream>


class BRANCH_CLASS {

};

class FRUIT_CLASS {
private:
    BRANCH_CLASS* fruitBranch;
    unsigned int fruitWeight;
    unsigned int fruitBranchLength;
    FRUIT_CLASS* next;
    FRUIT_CLASS* prev;

public:
    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS* getBranchPointer();
    FRUIT_CLASS() ;
};

unsigned int FRUIT_CLASS::getLength() {
    return fruitBranchLength;
}

unsigned int FRUIT_CLASS::getWeight() {
    return fruitWeight;
}

void FRUIT_CLASS::growthFruit() {
    fruitWeight += 1;
}

void FRUIT_CLASS::fadeFruit() {
    fruitWeight -= 1;
}

void FRUIT_CLASS::pluckFruit() {
    fruitWeight = 0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer() {
    return fruitBranch;
}

int main() {


    return 0;
}
