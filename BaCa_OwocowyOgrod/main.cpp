// Krystian Jachna
#include <iostream>

class GARDEN_CLASS;
class TREE_CLASS;
class BRANCH_CLASS;
class FRUIT_CLASS;

class TREE_CLASS {
private:
    GARDEN_CLASS* treeGarden;
    unsigned int branchesNumber;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
    unsigned int treeNumber;
    unsigned int treeHeight;
    BRANCH_CLASS* firstBranch;
    BRANCH_CLASS* lastBranch;
    TREE_CLASS* next;
    TREE_CLASS* prev;

public:
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getNumber();
    unsigned int getHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int fruitWeight);
    void cutTree(unsigned int treeHeight);
    void cloneBranch(BRANCH_CLASS* branch);
    GARDEN_CLASS* getGardenPointer();
    BRANCH_CLASS* getBranchPointer(unsigned int height);
    TREE_CLASS(GARDEN_CLASS* treeGarden, unsigned int treeHeight, unsigned int treeNumber, unsigned int branchesNumber);

};

// =====================================================================================================================

class BRANCH_CLASS {
private:
    TREE_CLASS* branchTree;
    unsigned int treeHeight;
    unsigned int branchLength;
    FRUIT_CLASS* firstFruit;
    FRUIT_CLASS* lastFruit;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
    BRANCH_CLASS* next;
    BRANCH_CLASS* prev;

public:
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getHeight();           // na jakiej wysokosci rosnie
    unsigned int getLength();
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int fruitWeight);
    void cutBranch (unsigned int branchLength);
    FRUIT_CLASS* getFruitPointer(unsigned int length);
    TREE_CLASS* getTreePointer();
    BRANCH_CLASS(TREE_CLASS* branchTree,unsigned int treeHeight);
    ~BRANCH_CLASS();
    BRANCH_CLASS(BRANCH_CLASS &branchToCopy,  unsigned int treeHeight = 0, TREE_CLASS* branchTree = NULL);
    void setNextBranch(BRANCH_CLASS* branchPTR);
    void setPrevBranch(BRANCH_CLASS* branchPTR);
    BRANCH_CLASS* nextBranch();
    BRANCH_CLASS* prevBranch();
};

// =====================================================================================================================

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
    FRUIT_CLASS(BRANCH_CLASS* fruitBranch, unsigned int fruitWeight,
                unsigned int fruitBranchLength);
    FRUIT_CLASS(FRUIT_CLASS &fruitToCopy);
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

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* fruitBranch, unsigned int fruitWeight,
                         unsigned int fruitBranchLength) {
    this->fruitBranch = fruitBranch;
    this->fruitWeight = fruitWeight;
    this->fruitBranchLength = fruitBranchLength;

    this->next = NULL;
    this->prev = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(FRUIT_CLASS &fruitToCopy) {
    this->fruitBranch = fruitToCopy.fruitBranch;
    this->fruitWeight = fruitToCopy.fruitWeight;
    this->fruitBranchLength = fruitToCopy.fruitBranchLength;
    next = NULL;
    prev = NULL;
}

FRUIT_CLASS::~FRUIT_CLASS() {
    if (next != NULL && prev != NULL) {
        prev->setNextFruit(next);
        next->setPrevFruit(prev);
    }
}

void FRUIT_CLASS::setNextFruit(FRUIT_CLASS* fruitPTR) {
    next = fruitPTR;
}

void FRUIT_CLASS::setPrevFruit(FRUIT_CLASS *fruitPTR) {
    prev = fruitPTR;
}

// =====================================================================================================================

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

        if (firstFruit == NULL) {
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

    FRUIT_CLASS* walkingElem = firstFruit;

    while (walkingElem != NULL) {
        walkingElem->fadeFruit();
        fruitsWeight -= 1;

        walkingElem = walkingElem->nextFruit();
    }

    if (branchLength % 2 == 0) {
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
    branchLength -= 1;
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

    FRUIT_CLASS* walkingElem = lastFruit;

    while(walkingElem != NULL) {
        if (walkingElem->getLength() <= branchLength)
            break;

        walkingElem = walkingElem->prevFruit();
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
    else if (walkingElem == lastFruit && walkingElem->getLength() > branchLength) {
        fruitsNumber -= 1;
        fruitsWeight -= walkingElem->getWeight();

        FRUIT_CLASS* newLAST = lastFruit->prevFruit();
        delete lastFruit;
        newLAST->setNextFruit(NULL);
        lastFruit = newLAST;
    }
    else if (walkingElem == firstFruit || walkingElem == lastFruit)
        return;
    else {
        FRUIT_CLASS *walkingBackwardsElem = lastFruit;

        while (walkingBackwardsElem != walkingElem ) {
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

BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS *branchTree, unsigned int treeHeight) {
    this->branchTree = branchTree;
    this->treeHeight = treeHeight;

    firstFruit = NULL;
    lastFruit = NULL;
    fruitsNumber = 0;
    fruitsWeight = 0;
    branchLength = 0;

    next = NULL;
    prev = NULL;
}

BRANCH_CLASS::~BRANCH_CLASS() {
    FRUIT_CLASS* walkingElem = firstFruit;

    while (walkingElem != NULL) {
        FRUIT_CLASS* tmp = walkingElem->nextFruit();
        delete walkingElem;
        walkingElem = tmp;
    }
}

void BRANCH_CLASS::setNextBranch(BRANCH_CLASS *branchPTR) {
    next = branchPTR;
}

void BRANCH_CLASS::setPrevBranch(BRANCH_CLASS *branchPTR) {
    prev = branchPTR;
}

BRANCH_CLASS* BRANCH_CLASS::nextBranch() {
    return next;
}

BRANCH_CLASS* BRANCH_CLASS::prevBranch() {
    return prev;
}

BRANCH_CLASS::BRANCH_CLASS(BRANCH_CLASS &branchToCopy,  unsigned int treeHeight, TREE_CLASS *branchTree) {
    this->treeHeight = treeHeight;
    this->branchTree = branchTree;
    this->branchLength = branchToCopy.branchLength;
    this->fruitsNumber = branchToCopy.fruitsNumber;
    this->fruitsWeight = branchToCopy.fruitsWeight;
    this->next = NULL;
    this->prev = NULL;

    if (branchToCopy.firstFruit == NULL) {
        firstFruit = NULL;
        lastFruit = NULL;
    }

    firstFruit = new FRUIT_CLASS(*(branchToCopy.firstFruit));

    FRUIT_CLASS* walkingElemToCopy = branchToCopy.firstFruit;
    FRUIT_CLASS* walkingElem = firstFruit;
    FRUIT_CLASS* prev = NULL;

    while (walkingElemToCopy->nextFruit() != NULL) {
        walkingElem->setNextFruit(new FRUIT_CLASS(*(walkingElemToCopy->nextFruit())));
        walkingElem->setPrevFruit(prev);


        prev = walkingElem;
        walkingElem = walkingElem->nextFruit();
        walkingElemToCopy = walkingElemToCopy->nextFruit();
    }
    walkingElem->setPrevFruit(prev);
    walkingElem->setNextFruit(NULL);
    lastFruit = walkingElem;
}

// =====================================================================================================================

unsigned int TREE_CLASS::getBranchesTotal() {
    return branchesNumber;
}

unsigned int TREE_CLASS::getFruitsTotal() {
    return fruitsNumber;
}

unsigned int TREE_CLASS::getWeightsTotal() {
    return fruitsWeight;
}

unsigned int TREE_CLASS::getNumber() {
    return treeNumber;
}

unsigned int TREE_CLASS::getHeight() {
    return treeHeight;
}

void TREE_CLASS::growthTree() {
    treeHeight += 1;

    BRANCH_CLASS* walkingElem = firstBranch;

    while (walkingElem != NULL) {                       // zwieksza sie ilosc owocow i waga
        unsigned int fruitsNumberTMP = walkingElem->getFruitsTotal();
        unsigned int fruitsWeightTMP = walkingElem->getWeightsTotal();

        walkingElem->growthBranch();

        fruitsNumber += walkingElem->getFruitsTotal() - fruitsNumberTMP;
        fruitsWeight += walkingElem->getWeightsTotal() - fruitsWeightTMP;

        walkingElem = walkingElem->nextBranch();
    }

    if(treeHeight > 0 && treeHeight % 3 == 0) {
        branchesNumber += 1;

        BRANCH_CLASS* branchPTR = new BRANCH_CLASS(this, treeHeight);

        if(firstBranch == NULL) {
            firstBranch = branchPTR;
            firstBranch->setPrevBranch(NULL);
            firstBranch->setNextBranch(NULL);

            lastBranch = firstBranch;
        }
        else {
            lastBranch->setNextBranch(branchPTR);
            BRANCH_CLASS* tmp = lastBranch;
            lastBranch = branchPTR;
            lastBranch->setPrevBranch(tmp);
            lastBranch->setNextBranch(NULL);
        }
    }
}

void TREE_CLASS::fadeTree() {
    if (treeHeight == 0)
        return;

    BRANCH_CLASS* walkingElem = firstBranch;

    while (walkingElem != NULL) {
        unsigned int fruitsNumberTMP = walkingElem->getFruitsTotal();
        unsigned int fruitsWeightTMP = walkingElem->getWeightsTotal();
        fruitsWeight -= fruitsWeightTMP;
        fruitsNumber -= fruitsNumberTMP;

        walkingElem->fadeBranch();

        fruitsNumber += walkingElem->getFruitsTotal();
        fruitsWeight += walkingElem->getWeightsTotal();

        walkingElem = walkingElem->nextBranch();
    }

    if (treeHeight % 3 == 0) {
        branchesNumber -= 1;

        fruitsNumber -= lastBranch->getFruitsTotal();
        fruitsWeight -= lastBranch->getWeightsTotal();

        BRANCH_CLASS* newLAST = lastBranch->prevBranch();
        if (newLAST == NULL) {
            firstBranch = NULL;
            delete lastBranch;
            lastBranch = NULL;
        }
        else {
            newLAST->setNextBranch(NULL);
            delete lastBranch;
            lastBranch = newLAST;
        }
    }
    treeHeight -= 1;
}

void TREE_CLASS::harvestTree(unsigned int fruitWeight) {
    BRANCH_CLASS* walkingElem = firstBranch;

    while (walkingElem != NULL) {
        unsigned int fruitsWeightTMP = walkingElem->getWeightsTotal();
        fruitsWeight -= fruitsWeightTMP;

        walkingElem->harvestBranch(fruitWeight);
        fruitsWeight += walkingElem->getWeightsTotal();

        walkingElem = walkingElem->nextBranch();
    }
}

void TREE_CLASS::cutTree(unsigned int treeHeight) {
    this->treeHeight = treeHeight;

    BRANCH_CLASS* walkingElem = lastBranch;

    while(walkingElem != NULL) {
        if (walkingElem->getHeight() <= treeHeight)
            break;

        walkingElem = walkingElem->prevBranch();
    }

    if (walkingElem == NULL)
        return;

    if (walkingElem == firstBranch && walkingElem->getHeight() > treeHeight) {
        branchesNumber -= 1;
        fruitsWeight -= walkingElem->getWeightsTotal();

        delete firstBranch;
        firstBranch = NULL;
        lastBranch = NULL;
    }
    else if (walkingElem == lastBranch && walkingElem->getHeight() >> treeHeight) {
        branchesNumber -= 1;
        fruitsWeight -= walkingElem->getWeightsTotal();

        BRANCH_CLASS* newLAST = lastBranch->prevBranch();
        delete lastBranch;
        newLAST->setNextBranch(NULL);
        lastBranch = newLAST;
    }
    else if (walkingElem == firstBranch || walkingElem == lastBranch)
        return;
    else {
        BRANCH_CLASS *walkingBackwardsElem = lastBranch;

        while (walkingBackwardsElem != walkingElem) {
            BRANCH_CLASS* tmp = walkingElem->prevBranch();
            branchesNumber -= 1;
            fruitsWeight -= walkingBackwardsElem->getWeightsTotal();
            fruitsNumber -= walkingBackwardsElem->getFruitsTotal();

            delete walkingBackwardsElem;
            walkingBackwardsElem = tmp;
        }

        lastBranch = walkingElem;
        lastBranch->setNextBranch(NULL);
    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS *branch) {
    fruitsWeight -= firstBranch->getWeightsTotal();
    fruitsNumber -= getFruitsTotal();

    BRANCH_CLASS* scBranch = firstBranch->nextBranch();
    unsigned int firstBranchHeight = firstBranch->getHeight();
    delete firstBranch;

    firstBranch = new BRANCH_CLASS(*branch, firstBranchHeight, this);
    firstBranch->setPrevBranch(NULL);
    firstBranch->setNextBranch(scBranch);
    fruitsWeight += firstBranch->getWeightsTotal();
    fruitsNumber += firstBranch->getFruitsTotal();
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer() {
    return treeGarden;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int height) {
    BRANCH_CLASS* walkingElem = firstBranch;

    while(walkingElem != NULL) {
        if (walkingElem->getHeight() == height)
            return walkingElem;
    }
    return NULL;
}

// =====================================================================================================================



int main() {




    return 0;
}
