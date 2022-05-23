// Krystian Jachna

#include <iostream>

class GARDEN_CLASS;
class TREE_CLASS;
class BRANCH_CLASS;
class FRUIT_CLASS;

// ==================================================== GARDEN =========================================================

class GARDEN_CLASS {
private:
    unsigned int treesNumber;
    unsigned int branchesNumber;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
    unsigned int holesNumber;
    TREE_CLASS* firstTree;
    TREE_CLASS* lastTree;

public:
    unsigned int getTreesTotal();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void plantTree();
    void extractTree(unsigned int treeNumber);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int weight);
    TREE_CLASS* getTreePointer(unsigned int treeNumber);
    void cloneTree(unsigned int treeNumber);
    GARDEN_CLASS();
    ~GARDEN_CLASS();
    void displayAll();
    void decreseWeight(unsigned int amount);
    void increseWeight(unsigned int amount);
    void increseFruitNumber(unsigned int count);
    void decreseFruitNumber(unsigned int count);
    void decreseBranchNumber(unsigned int number);
    void increseBranchNumber(unsigned int number);
    void decreseTreesNumber(unsigned int number);
    void increseTreesNumber(unsigned int number);
};

// =================================================== TREE ============================================================

class TREE_CLASS {
private:
    GARDEN_CLASS* treeGarden;
    unsigned int treeNumber;
    unsigned int treeHeight;
    unsigned int branchesNumber;
    unsigned int fruitsNumber;
    unsigned int fruitsWeight;
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
    TREE_CLASS(unsigned int treeNumber, GARDEN_CLASS*  treeGarden);
    ~TREE_CLASS();
    void setNextTree(TREE_CLASS* treePTR);
    void setprevTree(TREE_CLASS* treePTR);
    TREE_CLASS* nextTree();
    TREE_CLASS* prevTree();
    TREE_CLASS();
    TREE_CLASS(TREE_CLASS &treeToCopy, unsigned int treeNumber = 0, GARDEN_CLASS* treeGarden = NULL);
    void displayAll();
    void decreseWeight(unsigned int amount);
    void increseWeight(unsigned int amount);
    void increseFruitNumber(unsigned int count);
    void decreseFruitNumber(unsigned int count);
    void decreseBranchesNumber(unsigned int number);
    void increseBranchesNumber(unsigned int number);
};

// ================================================ BRANCH =============================================================

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
    BRANCH_CLASS();
    void displayAll();
    void decreseWeight(unsigned int amount);
    void increseWeight(unsigned int amount);
    void decreseFruitNumber(unsigned int number);
    void increseFruitNumber(unsigned int number);
};

// ============================================== FRUIT ================================================================

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
    FRUIT_CLASS(FRUIT_CLASS &fruitToCopy, BRANCH_CLASS* fruitBranch = NULL);
    ~FRUIT_CLASS();
    void setNextFruit(FRUIT_CLASS* fruitPTR);
    void setPrevFruit(FRUIT_CLASS* fruitPTR);
    FRUIT_CLASS();
};

// ================================================= FUNCTION INVESTING ITS PARENTS ====================================

void BRANCH_CLASS::decreseWeight(unsigned int amount) {
    fruitsWeight -= amount;
}
void BRANCH_CLASS::increseWeight(unsigned int amount) {
    fruitsWeight += amount;
}
void TREE_CLASS::decreseWeight(unsigned int amount) {
    fruitsWeight -= amount;
}
void TREE_CLASS::increseWeight(unsigned int amount) {
    fruitsWeight += amount;
}
void TREE_CLASS::decreseFruitNumber(unsigned int count) {
    fruitsNumber -= count;
}
void TREE_CLASS::increseFruitNumber(unsigned int count) {
    fruitsNumber += count;
}
void GARDEN_CLASS::decreseWeight(unsigned int amount) {
    fruitsWeight -= amount;
}
void GARDEN_CLASS::increseWeight(unsigned int amount) {
    fruitsWeight += amount;
}
void GARDEN_CLASS::increseFruitNumber(unsigned int count) {
    fruitsNumber += count;
}
void GARDEN_CLASS::decreseFruitNumber(unsigned int count) {
    fruitsNumber -= count;
}
void GARDEN_CLASS::increseBranchNumber(unsigned int number) {
    branchesNumber += number;
}
void GARDEN_CLASS::decreseBranchNumber(unsigned int number) {
    branchesNumber -= number;
}
void BRANCH_CLASS::increseFruitNumber(unsigned int number) {
    fruitsNumber += number;
}
void BRANCH_CLASS::decreseFruitNumber(unsigned int number) {
    fruitsNumber -= number;
}
void TREE_CLASS::decreseBranchesNumber(unsigned int number) {
    branchesNumber -= number;
}
void TREE_CLASS::increseBranchesNumber(unsigned int number) {
    branchesNumber += number;
}
void GARDEN_CLASS::decreseTreesNumber(unsigned int number) {
    treesNumber -= number;
}
void GARDEN_CLASS::increseTreesNumber(unsigned int number) {
    treesNumber += number;
}

// ========================================== FRUIT FUNCTIONS ==========================================================

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

    if(fruitBranch != NULL) {
        fruitBranch->increseWeight(1);
        if (fruitBranch->getTreePointer() != NULL) {
            fruitBranch->getTreePointer()->increseWeight(1);
            if (fruitBranch->getTreePointer()->getGardenPointer() != NULL)
                fruitBranch->getTreePointer()->getGardenPointer()->increseWeight(1);
        }
    }
}

void FRUIT_CLASS::fadeFruit() {
    if (fruitWeight > 0) {
        fruitWeight -= 1;

        if(fruitBranch != NULL) {
            fruitBranch->decreseWeight(1);
            if (fruitBranch->getTreePointer() != NULL) {
                fruitBranch->getTreePointer()->decreseWeight(1);
                if (fruitBranch->getTreePointer()->getGardenPointer() != NULL)
                    fruitBranch->getTreePointer()->getGardenPointer()->decreseWeight(1);
            }
        }
    }
}

void FRUIT_CLASS::pluckFruit() {
    if(fruitBranch != NULL) {
        fruitBranch->decreseWeight(fruitWeight);
        if (fruitBranch->getTreePointer() != NULL) {
            fruitBranch->getTreePointer()->decreseWeight(fruitWeight);
            if (fruitBranch->getTreePointer()->getGardenPointer() != NULL)
                fruitBranch->getTreePointer()->getGardenPointer()->decreseWeight(fruitWeight);
        }
    }
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

    if(fruitBranch != NULL) {
        fruitBranch->increseFruitNumber(1);
        fruitBranch->increseWeight(fruitWeight);
        if (fruitBranch->getTreePointer() != NULL) {
            fruitBranch->getTreePointer()->increseFruitNumber(1);
            fruitBranch->getTreePointer()->increseWeight(fruitWeight);
            if (fruitBranch->getTreePointer()->getGardenPointer() != NULL) {
                fruitBranch->getTreePointer()->getGardenPointer()->increseFruitNumber(1);
                fruitBranch->getTreePointer()->getGardenPointer()->increseWeight(fruitWeight);
            }
        }
    }

    this->next = NULL;
    this->prev = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(FRUIT_CLASS &fruitToCopy, BRANCH_CLASS* fruitBranch) {
    this->fruitBranch = fruitBranch;
    this->fruitWeight = fruitToCopy.fruitWeight;
    this->fruitBranchLength = fruitToCopy.fruitBranchLength;

    if (fruitBranch != NULL) {
        fruitBranch->increseWeight(this->fruitWeight);
        fruitBranch->increseFruitNumber(1);
        if (fruitBranch->getTreePointer() != NULL) {
            fruitBranch->getTreePointer()->increseWeight(this->fruitWeight);
            fruitBranch->getTreePointer()->increseFruitNumber(1);
            if (fruitBranch->getTreePointer()->getGardenPointer() != NULL) {
                fruitBranch->getTreePointer()->getGardenPointer()->increseWeight(this->fruitWeight);
                fruitBranch->getTreePointer()->getGardenPointer()->increseFruitNumber(1);
            }
        }
    }
    next = NULL;
    prev = NULL;
}

FRUIT_CLASS::~FRUIT_CLASS() {
    if (fruitBranch != NULL) {
        fruitBranch->decreseWeight(fruitWeight);
        fruitBranch->decreseFruitNumber(1);
        if (fruitBranch->getTreePointer() != NULL) {
            fruitBranch->getTreePointer()->decreseWeight(fruitWeight);
            fruitBranch->getTreePointer()->decreseFruitNumber(1);
            if (fruitBranch->getTreePointer()->getGardenPointer() != NULL) {
                fruitBranch->getTreePointer()->getGardenPointer()->decreseWeight(fruitWeight);
                fruitBranch->getTreePointer()->getGardenPointer()->decreseFruitNumber(1);
            }
        }
    }
}

void FRUIT_CLASS::setNextFruit(FRUIT_CLASS* fruitPTR) {
    next = fruitPTR;
}

void FRUIT_CLASS::setPrevFruit(FRUIT_CLASS *fruitPTR) {
    prev = fruitPTR;
}

FRUIT_CLASS::FRUIT_CLASS() {
    fruitBranch = NULL;
    fruitWeight = 0;
    fruitBranchLength = 0;
    next = NULL;
    prev = NULL;
}

// =============================================== BRANCH FUNCTIONS ====================================================

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
        walkingElem = walkingElem->nextFruit();
    }

    if(branchLength > 0 && branchLength % 2 == 0) {
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
        walkingElem = walkingElem->nextFruit();
    }

    if ( lastFruit != NULL && lastFruit->getLength() == branchLength) {
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
        if (walkingElem->getWeight() >= fruitWeight)
            walkingElem->pluckFruit();
        walkingElem = walkingElem->nextFruit();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int branchLength) {
    if (this->branchLength <= branchLength)
        return;

    this->branchLength = branchLength;

    FRUIT_CLASS* walkingElem = lastFruit;

    if (walkingElem == NULL)
        return;

    FRUIT_CLASS* prevWalkingElem;
    while (walkingElem != NULL && walkingElem->getLength() > branchLength) {
        prevWalkingElem = walkingElem;
        walkingElem = walkingElem->prevFruit();
        delete prevWalkingElem;
    }


    lastFruit = walkingElem;
    if (walkingElem != NULL)
        lastFruit->setNextFruit(NULL);
    if (walkingElem == NULL)
        firstFruit = NULL;
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

    if (branchTree != NULL) {
        branchTree->increseBranchesNumber(1);
        if(branchTree->getGardenPointer() != NULL) {
            branchTree->getGardenPointer()->increseBranchNumber(1);
        }
    }

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

    if (branchTree != NULL) {
        branchTree->decreseBranchesNumber(1);
        if (branchTree->getGardenPointer() != NULL)
            branchTree->getGardenPointer()->decreseBranchNumber(1);
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
    this->fruitsNumber = 0;
    this->fruitsWeight = 0;
    this->next = NULL;
    this->prev = NULL;

    if (branchToCopy.firstFruit == NULL) {
        firstFruit = NULL;
        lastFruit = NULL;
        if (branchTree != NULL) {
            branchTree->increseBranchesNumber(1);
            if (branchTree->getGardenPointer() != NULL)
                branchTree->getGardenPointer()->increseBranchNumber(1);
        }
        return;
    }

    firstFruit = new FRUIT_CLASS(*(branchToCopy.firstFruit), this);

    FRUIT_CLASS* walkingElemToCopy = branchToCopy.firstFruit;
    FRUIT_CLASS* walkingElem = firstFruit;
    FRUIT_CLASS* prevt = NULL;

    while (walkingElemToCopy->nextFruit() != NULL) {
        walkingElem->setNextFruit(new FRUIT_CLASS(*(walkingElemToCopy->nextFruit()), this));
        walkingElem->setPrevFruit(prevt);

        prevt = walkingElem;
        walkingElem = walkingElem->nextFruit();
        walkingElemToCopy = walkingElemToCopy->nextFruit();
    }
    walkingElem->setPrevFruit(prevt);
    walkingElem->setNextFruit(NULL);
    lastFruit = walkingElem;

    if (branchTree != NULL) {
        branchTree->increseBranchesNumber(1);
        if (branchTree->getGardenPointer() != NULL)
            branchTree->getGardenPointer()->increseBranchNumber(1);
    }
}

BRANCH_CLASS::BRANCH_CLASS() {
    branchTree = NULL;
    treeHeight = 0;
    branchLength = 0;
    firstFruit = NULL;
    lastFruit = NULL;
    fruitsNumber = 0;
    fruitsWeight = 0;
    next = NULL;
    prev = NULL;
}

// =============================================== TREE FUNCTIONS ======================================================

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

    while (walkingElem != NULL) {
        walkingElem->growthBranch();
        walkingElem = walkingElem->nextBranch();
    }

    if(treeHeight > 0 && treeHeight % 3 == 0) {
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
        walkingElem->fadeBranch();
        walkingElem = walkingElem->nextBranch();
    }

    if (treeHeight % 3 == 0) {
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
        walkingElem->harvestBranch(fruitWeight);
        walkingElem = walkingElem->nextBranch();
    }
}

void TREE_CLASS::cutTree(unsigned int treeHeight) {
    if (this->treeHeight <= treeHeight)
        return;

    this->treeHeight = treeHeight;

    BRANCH_CLASS* walkingElem = lastBranch;

    while (walkingElem != NULL && walkingElem->getHeight() > treeHeight){
        BRANCH_CLASS* tmp = walkingElem->prevBranch();
        delete walkingElem;
        walkingElem = tmp;
    }

    if (walkingElem == NULL)
        firstBranch = NULL;
    lastBranch = walkingElem;
    if (walkingElem != NULL)
        lastBranch->setNextBranch(NULL);

}

void TREE_CLASS::cloneBranch(BRANCH_CLASS *branch) {
    if (branch == NULL)
        return;

    bool findBranch = false;
    BRANCH_CLASS* walkingElem = firstBranch;
    while(walkingElem != NULL) {
        if (walkingElem->getLength() == 0){
            findBranch = true;
            break;
        }
        walkingElem = walkingElem->nextBranch();
    }
    if (!findBranch)
        return;

    if (walkingElem == firstBranch && walkingElem == lastBranch) {
        unsigned int tmpTreeHight = firstBranch->getHeight();
        delete firstBranch;

        firstBranch = new BRANCH_CLASS(*branch, tmpTreeHight, this);
        lastBranch = firstBranch;
        firstBranch->setNextBranch(NULL);
        firstBranch->setPrevBranch(NULL);
    }
    else if (walkingElem == firstBranch) {
        BRANCH_CLASS* scBranch = firstBranch->nextBranch();
        unsigned int deletingTreeHight = firstBranch->getHeight();
        delete firstBranch;

        firstBranch = new BRANCH_CLASS(*branch, deletingTreeHight, this);
        firstBranch->setNextBranch(scBranch);
        firstBranch->setPrevBranch(NULL);
        scBranch->setPrevBranch(firstBranch);
    }
    else if (walkingElem == lastBranch) {
        BRANCH_CLASS* scBranch = lastBranch->prevBranch();
        unsigned int deletingTreeHight = lastBranch->getHeight();
        delete lastBranch;

        lastBranch = new BRANCH_CLASS(*branch, deletingTreeHight, this);
        lastBranch->setNextBranch(NULL);
        lastBranch->setPrevBranch(scBranch);
        scBranch->setNextBranch(lastBranch);
    }
    else {
        BRANCH_CLASS* nextBranch = walkingElem->nextBranch();
        BRANCH_CLASS* prevBranch = walkingElem->prevBranch();
        unsigned int deletingTreeHight = walkingElem->getHeight();
        delete walkingElem;
        walkingElem = new BRANCH_CLASS(*branch, deletingTreeHight, this);
        walkingElem->setNextBranch(nextBranch);
        walkingElem->setPrevBranch(prevBranch);
        prevBranch->setNextBranch(walkingElem);
        nextBranch->setPrevBranch(walkingElem);
    }
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer() {
    return treeGarden;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int height) {
    BRANCH_CLASS* walkingElem = firstBranch;

    while(walkingElem != NULL) {
        if (walkingElem->getHeight() == height)
            return walkingElem;
        walkingElem = walkingElem->nextBranch();
    }
    return NULL;
}

TREE_CLASS::~TREE_CLASS() {
    BRANCH_CLASS* walkingElem = firstBranch;

    while(walkingElem != NULL) {
        BRANCH_CLASS* tmp = walkingElem->nextBranch();
        delete walkingElem;
        walkingElem = tmp;
    }

    if (treeGarden != NULL)
        treeGarden->decreseTreesNumber(1);
}

void TREE_CLASS::setNextTree(TREE_CLASS *treePTR) {
    next = treePTR;
}

void TREE_CLASS::setprevTree(TREE_CLASS *treePTR) {
    prev = treePTR;
}

TREE_CLASS* TREE_CLASS::nextTree() {
    return next;
}

TREE_CLASS* TREE_CLASS::prevTree() {
    return prev;
}

TREE_CLASS::TREE_CLASS(unsigned int treeNumber, GARDEN_CLASS* treeGarden) {
    this->treeNumber = treeNumber;
    this->treeGarden = treeGarden;
    this->branchesNumber = 0;
    this->fruitsNumber = 0;
    this->fruitsWeight = 0;
    this->treeHeight = 0;
    this->firstBranch = NULL;
    this->lastBranch = NULL;
    this->next = NULL;
    this->prev = NULL;

    if(treeGarden != NULL)
        treeGarden->increseTreesNumber(1);
}

TREE_CLASS::TREE_CLASS() {
    treeNumber = 0;
    treeGarden = NULL;
    branchesNumber = 0;
    fruitsNumber = 0;
    fruitsWeight = 0;
    treeHeight = 0;
    firstBranch = NULL;
    lastBranch = NULL;
    next = NULL;
    prev = NULL;
}

TREE_CLASS::TREE_CLASS(TREE_CLASS &treeToCopy, unsigned int treeNumber, GARDEN_CLASS *treeGarden) {
    this->treeNumber = treeNumber;
    this->treeGarden =  treeGarden;
    this->branchesNumber = 0;
    this->fruitsNumber = 0;
    this->fruitsWeight = 0;
    this->treeHeight = treeToCopy.treeHeight;
    this->next = NULL;
    this->prev = NULL;

    if (treeToCopy.firstBranch == NULL) {
        firstBranch = NULL;
        lastBranch = NULL;
        if(treeGarden != NULL)
            treeGarden->increseTreesNumber(1);
        return;
    }

    firstBranch = new BRANCH_CLASS(*(treeToCopy.firstBranch), treeToCopy.firstBranch->getHeight(), this);

    BRANCH_CLASS* walkingElemToCopy = treeToCopy.firstBranch;
    BRANCH_CLASS* walkingElem = firstBranch;
    BRANCH_CLASS* prevt = NULL;

    while (walkingElemToCopy->nextBranch() != NULL) {
        walkingElem->setNextBranch(new BRANCH_CLASS(*(walkingElemToCopy->nextBranch()),
                                                    walkingElemToCopy->nextBranch()->getHeight(), this));
        walkingElem->setPrevBranch(prevt);

        prevt = walkingElem;
        walkingElem = walkingElem->nextBranch();
        walkingElemToCopy = walkingElemToCopy->nextBranch();
    }
    walkingElem->setPrevBranch(prevt);
    walkingElem->setNextBranch(NULL);
    lastBranch = walkingElem;

    if(treeGarden != NULL)
        treeGarden->increseTreesNumber(1);
}

// ================================================ GARDEN FUNCTIONS ===================================================

GARDEN_CLASS::~GARDEN_CLASS() {
    TREE_CLASS* walkingElem = firstTree;

    while(walkingElem != NULL) {
        TREE_CLASS* tmp = walkingElem->nextTree();
        delete walkingElem;
        walkingElem = tmp;
    }
}

GARDEN_CLASS::GARDEN_CLASS() {
    this->treesNumber = 0;
    this->branchesNumber = 0;
    this->fruitsNumber = 0;
    this->fruitsWeight = 0;
    this->holesNumber = 0;

    this->firstTree = NULL;
    this->lastTree = NULL;
}

unsigned int GARDEN_CLASS::getTreesTotal() {
    return treesNumber;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    return branchesNumber;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    return fruitsNumber;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {
    return fruitsWeight;
}

void GARDEN_CLASS::plantTree() {
    if (treesNumber == 0) {
        firstTree = new TREE_CLASS(0, this);
        lastTree = firstTree;
    }
    else if (holesNumber == 0) {
        lastTree->setNextTree(new TREE_CLASS(lastTree->getNumber() + 1, this));
        lastTree->nextTree()->setprevTree(lastTree);
        lastTree = lastTree->nextTree();
        lastTree->setNextTree(NULL);
    }
    else {
        holesNumber -= 1;
        unsigned int prevNumber = firstTree->getNumber();

        TREE_CLASS* walkingElem = firstTree;
        if (firstTree->getNumber() != 0) {
            firstTree->setprevTree(new TREE_CLASS(firstTree->getNumber() - 1, this));
            firstTree->prevTree()->setNextTree(firstTree);
            firstTree = firstTree->prevTree();
            firstTree->setprevTree(NULL);
            return;
        }
        while (walkingElem->nextTree() != NULL) {
            if (walkingElem->nextTree()->getNumber() != (prevNumber + 1))
                break;


            walkingElem = walkingElem->nextTree();
            prevNumber = walkingElem->getNumber();
        }
        TREE_CLASS* afterWalking = walkingElem->nextTree();
        walkingElem->setNextTree(new TREE_CLASS(walkingElem->getNumber() + 1, this));
        walkingElem->nextTree()->setprevTree(walkingElem);
        walkingElem->nextTree()->setNextTree(afterWalking);
        afterWalking->setprevTree(walkingElem->nextTree());

    }
}

void GARDEN_CLASS::extractTree(unsigned int treeNumber) {
    bool findElem = false;

    TREE_CLASS* walkingELem = lastTree;
    while(walkingELem != NULL) {
        if(walkingELem->getNumber() == treeNumber) {
            findElem = true;
            break;
        }

        walkingELem = walkingELem->prevTree();
    }
    if (findElem) {
        if (walkingELem == firstTree && firstTree == lastTree) {
            delete walkingELem;
            firstTree = NULL;
            lastTree = NULL;
        }
        else if (walkingELem == firstTree) {
            TREE_CLASS* scTREE = firstTree->nextTree();
            firstTree->nextTree()->setprevTree(NULL);
            holesNumber += 1;
            delete firstTree;
            firstTree = scTREE;
        }
        else if (walkingELem == lastTree) {
            TREE_CLASS* b4LastTREE = lastTree->prevTree();
            lastTree->prevTree()->setNextTree(NULL);
            delete lastTree;
            lastTree = b4LastTREE;
        }
        else{
            walkingELem->prevTree()->setNextTree(walkingELem->nextTree());
            walkingELem->nextTree()->setprevTree(walkingELem->prevTree());
            holesNumber += 1;
            delete walkingELem;
        }
    }
}

void GARDEN_CLASS::growthGarden() {
    TREE_CLASS* walkingElem = firstTree;
    while (walkingElem != NULL) {
        walkingElem->growthTree();
        walkingElem = walkingElem->nextTree();
    }
}

void GARDEN_CLASS::fadeGarden() {
    TREE_CLASS* walkingElem = firstTree;
    while (walkingElem != NULL) {
        walkingElem->fadeTree();
        walkingElem = walkingElem->nextTree();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int weight) {
    TREE_CLASS* walkingElem = firstTree;
    while (walkingElem != NULL) {
        walkingElem->harvestTree(weight);
        walkingElem = walkingElem->nextTree();
    }
}

void GARDEN_CLASS::cloneTree (unsigned int treeNumber)
{
    TREE_CLASS* toClone = getTreePointer( treeNumber );

    if ( toClone == NULL )
        return;

    unsigned int newTreeNumber = 0;

    if (holesNumber == 0) {
        lastTree->setNextTree(new TREE_CLASS(*toClone, lastTree->getNumber() + 1, this));
        lastTree->nextTree()->setprevTree(lastTree);
        lastTree = lastTree->nextTree();
    }
    else {
        TREE_CLASS* walkingElem = firstTree;
        while(walkingElem != NULL) {
            if (walkingElem->getNumber() != newTreeNumber)
                break;
            walkingElem = walkingElem->nextTree();
        }

        TREE_CLASS* newTree = new TREE_CLASS(*toClone, newTreeNumber, this);

        if (walkingElem != NULL) {
            newTree->setNextTree(walkingElem);
            walkingElem->setprevTree(walkingElem->prevTree());
            if (walkingElem->prevTree() != NULL)
                walkingElem->prevTree()->setNextTree(newTree);
            walkingElem->setprevTree(newTree);
            holesNumber -= 1;
        }
        else {
            lastTree->setNextTree(newTree);
            newTree->setprevTree(lastTree);
            lastTree = newTree;
            holesNumber = 0;
        }
    }
}

TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int treeNumber) {
    TREE_CLASS* walkingELem = lastTree;
    while (walkingELem != NULL) {
        if(walkingELem->getNumber() == treeNumber)
            return walkingELem;

        walkingELem = walkingELem->prevTree();
    }
    return NULL;
}

void GARDEN_CLASS::displayAll() {
    std::cout << "GARDEN:" << std::endl;
    std::cout << "fruit_count:" << getFruitsTotal() << " ";
    std::cout << "tree_count:" << getTreesTotal() << " ";
    std::cout << "branch_count:" << getBranchesTotal() << " ";
    std::cout << "weights:" << getWeightsTotal() << std::endl;
    std::cout << "trees: \n";
    int max = getTreesTotal(), i = 0;
    while (i <= max){
        TREE_CLASS * Tree = getTreePointer(i);
        if (Tree != NULL) {
            std:: cout << "tree nr " << i << std::endl;
            Tree->displayAll();
            std::cout << std::endl;
        }
        i++;
    }
    std::cout << std::endl;
    std::cout << "/ / / / / / / /";
    std::cout << std::endl<< std::endl;
}

void TREE_CLASS::displayAll() {
    std::cout << ">>fruit_count:" << getFruitsTotal() << " ";
    std::cout << "branch_count:" << getBranchesTotal() << " ";
    std::cout << "weights:" << getWeightsTotal() << std::endl;
    int max = getBranchesTotal(), i = 3;
    if (max>0) std::cout << ">>branches: \n";
    while (i <= 3*max){
        BRANCH_CLASS * branch = getBranchPointer(i);
        if (branch != NULL) {
            std:: cout << "-----branch at " << i << std::endl;
            branch->displayAll();}
        i+=3;
    }
}

void BRANCH_CLASS::displayAll() {
    std::cout << "-----fruit_count:" << getFruitsTotal() << " ";
    std::cout << "weights:" << getWeightsTotal() << std::endl;
    int max = getFruitsTotal(), i = 2;
    if (max>0) std::cout << "-----fruits: \n";
    while (i <= 2*max){
        FRUIT_CLASS * fruit = getFruitPointer(i);
        if (fruit != NULL) {
            std:: cout << "       *fruit at " << i << std::endl;
            std::cout <<"       *length: " << fruit->getLength() << " weight: "<< fruit->getWeight() << std::endl;}
        i+=2;
    }
}

// =====================================================================================================================

int main() {
    GARDEN_CLASS* garden = new GARDEN_CLASS;

    for (int i = 0; i < 10; ++i) {
        garden->plantTree();
        garden->growthGarden();
    }

    garden->displayAll();
    delete garden;
}