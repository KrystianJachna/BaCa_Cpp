// Krystian Jachna
#include <iostream>
using namespace std;

class GARDEN_CLASS {
private:
    unsigned int treesNumber;
    TREE_CLASS trees;

};

class TREE_CLASS {
private: 
    unsigned int treeID;
    unsigned int treeHight;
    unsigned int branchNumber;
    BRANCH_CLASS branches;

};

class BRANCH_CLASS {
private:
    unsigned int branchLength;
    unsigned int fruitsNumber;
    FRUIT_CLASS fruits;

};

class FRUIT_CLASS {
private:
    unsigned int weight;

};

int main()
{
    std::cout << "Hello World!\n";
}