// Krystian Jachna
#include <iostream>

class GARDEN_CLASS;
class TREE_CLASS;
class BRANCH_CLASS;
class FRUIT_CLASS;

class TREE_CLASS {

};

class BRANCH_CLASS {
private:
    unsigned int branchLength;
    TREE_CLASS* branchTree;
    FRUIT_CLASS* firstFruit;
    FRUIT_CLASS* lastFruit;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
    unsigned int treeHeight;

public:
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getHeight();
    unsigned int getLength();
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int fruitWeight);
    void cutBranch (unsigned int branchLength);
    FRUIT_CLASS* getFruitPointer(unsigned int length);
    TREE_CLASS* getTreePointer();
};

class FRUIT_CLASS {
private:
    BRANCH_CLASS* fruitBranch;
    unsigned int fruitWeight;
    unsigned int fruitBranchLength;         // na jakiej dlugosci jest owoc
    FRUIT_CLASS* next;
    FRUIT_CLASS* prev;

public:
    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS* getBranchPointer();
    FRUIT_CLASS(BRANCH_CLASS* fruitBranch, unsigned int fruitWeight, unsigned int fruitBranchLength);
    ~FRUIT_CLASS();
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

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* fruitBranch, unsigned int fruitWeight, unsigned int fruitBranchLength) {
    this->fruitBranch = fruitBranch;
    this->fruitWeight = fruitWeight;
    this->fruitBranchLength = fruitBranchLength;

    this->next = NULL;
    this->prev = NULL;
}

FRUIT_CLASS::~FRUIT_CLASS() {
    if (this->next != NULL && this->prev != NULL) {
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
}





int main() {


    return 0;
}
