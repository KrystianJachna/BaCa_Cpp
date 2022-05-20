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
    TREE_CLASS* branchTree;
    unsigned int treeHeight;
    unsigned int branchLength;
    FRUIT_CLASS* firstFruit;
    FRUIT_CLASS* lastFruit;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;

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
    BRANCH_CLASS(unsigned int branchLength, TREE_CLASS* branchTree,unsigned int treeHeight,
                 FRUIT_CLASS* firstFruit, FRUIT_CLASS *lastFruit, unsigned int fruitsNumber, unsigned int fruitsWeight);
    BRANCH_CLASS(TREE_CLASS* branchTree,unsigned int treeHeight, unsigned int branchLength);
};

// =============================================

class FRUIT_CLASS {
private:
    BRANCH_CLASS* fruitBranch;
    unsigned int fruitWeight;
    unsigned int fruitBranchLength;         // na jakiej dlugosci jest owoc
    FRUIT_CLASS* next;
    FRUIT_CLASS* prev;

public:
    FRUIT_CLASS* nextFruit();
    FRUIT_CLASS* prevFruit();
    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS* getBranchPointer();
    FRUIT_CLASS(BRANCH_CLASS* fruitBranch, unsigned int fruitWeight, unsigned int fruitBranchLength);
    ~FRUIT_CLASS();
    void setNextFruit(FRUIT_CLASS* fruitPTR);
    void setPrevFruit(FRUIT_CLASS* fruitPTR);
};

FRUIT_CLASS* FRUIT_CLASS::nextFruit() {
    return next;
}

FRUIT_CLASS* FRUIT_CLASS::prevFruit() {
    return prev;
}

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
    if (next != NULL && prev != NULL) {
        prev->next = next;
        next->prev = prev;
    }
}

void FRUIT_CLASS::setNextFruit(FRUIT_CLASS* fruitPTR) {
    next = fruitPTR;
}

void FRUIT_CLASS::setPrevFruit(FRUIT_CLASS *fruitPTR) {
    prev = fruitPTR;
}

// ==================================================

unsigned int BRANCH_CLASS::getFruitsTotal() {
    return fruitsNumber;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    return fruitsWeight;
}

unsigned int BRANCH_CLASS::getHeight() {
    return treeHeight;
}

unsigned int BRANCH_CLASS::getLength() {
    return branchLength;
}

void BRANCH_CLASS::growthBranch() {
    branchLength += 1;

    FRUIT_CLASS* walkingElem = firstFruit;

    while (walkingElem != NULL) {
        walkingElem->growthFruit();
        fruitsWeight += 1;
        walkingElem = walkingElem->nextFruit();
    }

    if(branchLength > 0 && branchLength % 2 == 0) {
        fruitsNumber += 1;

        FRUIT_CLASS* fruitPTR =  new FRUIT_CLASS(this, 0, branchLength);

        if (firstFruit = NULL) {
            firstFruit = fruitPTR;
            firstFruit->setPrevFruit(NULL);
            firstFruit->setNextFruit(NULL);

            lastFruit = firstFruit;
        }
        else {
            lastFruit->setNextFruit(fruitPTR);
            FRUIT_CLASS* tmp = lastFruit;
            lastFruit = fruitPTR;
            lastFruit->setPrevFruit(tmp);
            lastFruit->setNextFruit(NULL);
        }
    }
}

void BRANCH_CLASS::fadeBranch() {
    if (branchLength == 0)
        return;

    if (branchLength % 2 == 0) {
        if (lastFruit == NULL)
            return;

        fruitsNumber -= 1;
        fruitsWeight -= lastFruit->getWeight();

        FRUIT_CLASS* newLAST = lastFruit->prevFruit();
        if(newLAST == NULL) {
            firstFruit = NULL;
            delete lastFruit;
            lastFruit = NULL;
        }
        else {
            newLAST->setNextFruit(NULL);
            delete lastFruit;
            lastFruit = newLAST;
        }
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int fruitWeight) {
    FRUIT_CLASS* walkingElem = firstFruit;

    while (walkingElem != NULL) {
        if (walkingElem->getWeight() >= fruitWeight) {
            fruitsWeight -= walkingElem->getWeight();
            walkingElem->pluckFruit();

            walkingElem = walkingElem->nextFruit();
        }
    }
}

void BRANCH_CLASS::cutBranch(unsigned int branchLength) {
    this->branchLength = branchLength;

    FRUIT_CLASS* walkingElem = firstFruit;

    while(walkingElem != NULL) {
        if (walkingElem->getLength() > branchLength) {
            break;
        }

        walkingElem = walkingElem->nextFruit();
    }

    if (walkingElem == NULL)
        return;

    if (walkingElem == firstFruit && walkingElem->getLength() > branchLength) {
        fruitsNumber -= 1;
        fruitsWeight -= walkingElem->getWeight();

        delete firstFruit;
        firstFruit = NULL;
        lastFruit = NULL;
    }
    else {
        FRUIT_CLASS *walkingBackwardsElem = lastFruit;

        while (walkingBackwardsElem != walkingElem ) {                                          // todo:: tutaj && rozne od NULL ?!
            FRUIT_CLASS* tmp = walkingBackwardsElem->prevFruit();
            fruitsNumber -= 1;
            fruitsWeight -= walkingBackwardsElem->getWeight();

            delete walkingBackwardsElem;
            walkingBackwardsElem = tmp;
        }

        lastFruit = walkingElem;
        lastFruit->setNextFruit(NULL);
    }

}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int length) {
    FRUIT_CLASS* walkingElem = firstFruit;

    while(walkingElem != NULL) {
        if (walkingElem->getLength() == length)
            return walkingElem;

        walkingElem = walkingElem->nextFruit();
    }
    return NULL;
}

TREE_CLASS* BRANCH_CLASS::getTreePointer() {
    return branchTree;
}

BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS *branchTree, unsigned int treeHeight, unsigned int branchLength = 0) {
    this->branchTree = branchTree;
    this->treeHeight = treeHeight;
    this->branchLength = branchLength;

    firstFruit = NULL;
    lastFruit = NULL;
    fruitsNumber = 0;
    lastFruit = 0;
    fruitsNumber = 0;
    fruitsWeight = 0;
}

BRANCH_CLASS::BRANCH_CLASS(unsigned int branchLength, TREE_CLASS *branchTree, unsigned int treeHeight,
                           FRUIT_CLASS *firstFruit, FRUIT_CLASS *lastFruit, unsigned int fruitsNumber,
                           unsigned int fruitsWeight) {
    this->branchTree = branchTree;
    this->treeHeight = treeHeight;
    this->branchLength = branchLength;
    this->firstFruit = firstFruit;
    this->lastFruit = lastFruit;
    this->fruitsNumber = fruitsNumber;
    this->fruitsWeight = fruitsWeight;
}






int main() {




    return 0;
}
