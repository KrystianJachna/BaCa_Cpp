// Krystian Jachna
#include <iostream>
//#include "memory_check.h"
using namespace std;

struct Link {
    int idC = 0;

    char id1 = 0;
    char id2 = 0;
    char id3 = 0;

    Link* next = NULL;
};

struct Coral {
    int idC = 0;

    Coral* next = NULL;
    Link* firstLink = NULL;
};

struct Rope {                    // sznur
    char id1 = 0;                   
    char id2 = 0;                    
    char id3 = 0;                    

    Coral* firstCoral = NULL;
    Rope* next = NULL;                 // wskaznik na kolejny sznur
};

void delMemory(Rope* firstRope) {          
    Rope* delRope = firstRope;
    Coral* delCoral = NULL;
    Link* delLink = NULL;

    while (delRope != NULL) {
        delCoral = delRope->firstCoral;
        while (delCoral != NULL) {
            delLink = delCoral->firstLink;
            while (delLink != NULL) {
                Link* saveLink = delLink->next;
                delete delLink;
                delLink = saveLink;
            }
            Coral* saveCoral = delCoral->next;
            delete delCoral;
            delCoral = saveCoral;
        }
        Rope* saveRope = delRope->next;
        delete delRope;
        delRope = saveRope;
    }
}

Rope* findRopePlace(Rope* firstRope, char id1, char id2, char id3) {    
    Rope* prev = NULL;                                             

    for (Rope* walkElem = firstRope; walkElem != NULL; walkElem = walkElem->next) {
        if (walkElem->id1 > id1)
            return prev;
        if (walkElem->id1 == id1) 
            if (walkElem->id2 > id2)
                return prev;
        if (walkElem->id1 == id1)
            if (walkElem->id2 == id2)
                if (walkElem->id3 > id3)
                    return prev;
        prev = walkElem;
    }
    return prev;
}

void addRope(Rope** firstRope, char id1, char id2, char id3) {  
    Rope* newElem = new Rope;                                   
    Rope* place = findRopePlace(*firstRope, id1, id2, id3);         
    
    if (place == NULL) {
        newElem->id1 = id1;
        newElem->id2 = id2;
        newElem->id3 = id3;
        newElem->firstCoral = NULL;
        newElem->next = *firstRope;
        *firstRope = newElem;
    }
    else {
        newElem->next = place->next;
        place->next = newElem;
        newElem->id1 = id1;
        newElem->id2 = id2;
        newElem->id3 = id3;
        newElem->firstCoral = NULL;
    }      
}

Rope* findRope(Rope* firstRope, char id1, char id2, char id3) {
    for (Rope* walkElem = firstRope; walkElem != NULL; walkElem = walkElem->next) 
        if (walkElem->id1 == id1 && walkElem->id2 == id2 && walkElem->id3 == id3)
            return walkElem;
    return NULL;
}

Rope* findRopeb4(Rope* firstRope, char id1, char id2, char id3, Rope* check) {
    Rope* prevRope = NULL;
    for (Rope* walkElem = firstRope; walkElem != NULL; walkElem = walkElem->next) {
        if (walkElem->id1 == id1 && walkElem->id2 == id2 && walkElem->id3 == id3)
            return prevRope;
        prevRope = walkElem;
    }
    return check;
}

Coral* findCoralPlace(Rope* rope, int idC) {
    Coral* prev = NULL;

    for (Coral* walkElem = rope->firstCoral; walkElem != NULL; walkElem = walkElem->next) {
        if (walkElem->idC > idC)
            return prev;
        
        prev = walkElem;
    }
    return prev;
}

void addCoral(Rope* firstRope, char id1, char id2, char id3, int idC) {
    Rope* ropeToAdd = findRope(firstRope, id1, id2, id3);
    if (ropeToAdd == NULL)
        return;
    Coral* place = findCoralPlace(ropeToAdd, idC);
    Coral* newElem = new Coral;

    if (place == NULL) {
        newElem->idC = idC;
        newElem->firstLink = NULL;
        newElem->next = ropeToAdd->firstCoral;
        ropeToAdd->firstCoral = newElem;
    }
    else {
        newElem->next = place->next;
        place->next = newElem;
        newElem->idC = idC;
        newElem->firstLink = NULL;
    }
}

Coral* findCoral(Rope* rope, int idC) {
    for (Coral* walkElem = rope->firstCoral; walkElem != NULL; walkElem = walkElem->next)
        if (walkElem->idC == idC)
            return walkElem;
    return NULL;
}

Coral* findCoralb4(Rope* rope, int idC, Coral* check) {
    Coral* prevCoral = NULL;
    for (Coral* walkElem = rope->firstCoral; walkElem != NULL; walkElem = walkElem->next) {
        if (walkElem->idC == idC)
            return prevCoral;
        prevCoral = walkElem;
    }
    return check;
}

Link* findLinkPlace(Coral* coral, char t_idR1, char t_idR2, char t_idR3, int t_idC) {
    Link* prev = NULL;

    for (Link* walkElem = coral->firstLink; walkElem != NULL; walkElem = walkElem->next) {
        if (walkElem->id1 > t_idR1)
            return prev;
        if (walkElem->id1 == t_idR1)
            if (walkElem->id2 > t_idR2)
                return prev;
        if (walkElem->id1 == t_idR1)
            if (walkElem->id2 == t_idR2)
                if (walkElem->id3 > t_idR3)
                    return prev;
        if (walkElem->id1 == t_idR1)
            if (walkElem->id2 == t_idR2)
                if (walkElem->id3 == t_idR3)
                    if (walkElem->idC > t_idC)
                        return prev;
        prev = walkElem;
    }
    return prev;
}

void addLink(Rope* firstRope, char f_idR1, char f_idR2, char f_idR3, int f_idC, char t_idR1, char t_idR2, char t_idR3, int t_idC) {
    Rope* ropeToAdd = findRope(firstRope, f_idR1, f_idR2, f_idR3);
    if (ropeToAdd == NULL)
        return;
    Coral* coralToAdd = findCoral(ropeToAdd, f_idC);
    if (coralToAdd == NULL)
        return;
    Link* place = findLinkPlace(coralToAdd, t_idR1, t_idR2, t_idR3, t_idC);
    Link* newElem = new Link;

    if (place == NULL) {
        newElem->idC = t_idC;
        newElem->id1 = t_idR1;
        newElem->id2 = t_idR2;
        newElem->id3 = t_idR3;
        newElem->next = coralToAdd->firstLink;
        coralToAdd->firstLink = newElem;
    }
    else {
        newElem->next = place->next;
        place->next = newElem;
        newElem->idC = t_idC;
        newElem->id1 = t_idR1;
        newElem->id2 = t_idR2;
        newElem->id3 = t_idR3;
    }
}

Link* findLinkb4(Coral* coral, char t_idR1, char t_idR2, char t_idR3, int t_idC, Link* check) {
    Link* prevLink = NULL;
    for (Link* walkElem = coral->firstLink; walkElem != NULL; walkElem = walkElem->next) {
        if (walkElem->idC == t_idC && walkElem->id1 == t_idR1 && walkElem->id2 == t_idR2 && walkElem->id3 == t_idR3)
            return prevLink;
        prevLink = walkElem;
    }
    return check;
}

void eraseLink(Rope* firstRope, char f_idR1, char f_idR2, char f_idR3, int f_idC, char t_idR1, char t_idR2, char t_idR3, int t_idC) {
    Rope* rope = findRope(firstRope, f_idR1, f_idR2, f_idR3);
    if (rope == NULL)
        return;
    Coral* coral = findCoral(rope, f_idC);
    if (coral == NULL)
        return;
    Link* check = new Link;
    Link* linkb4 = findLinkb4(coral, t_idR1, t_idR2, t_idR3, t_idC, check);
    if (linkb4 == check)
        return;
    delete check;

    if (linkb4 == NULL) {
        Link* saveLink = coral->firstLink->next;
        delete coral->firstLink;
        coral->firstLink = saveLink;
    }
    else {
        Link* saveLink = linkb4->next->next;
        delete linkb4->next;
        linkb4->next = saveLink;
    }
}

void eraseCoral(Rope* firstRope, int idC, char idR1, char idR2, char idR3) {
    bool flag = false;

    for (Rope* walkRopes = firstRope; walkRopes != NULL; walkRopes = walkRopes->next) 
        for (Coral* walkCorales = walkRopes->firstCoral; walkCorales != NULL; walkCorales = walkCorales->next) 
            for (Link* walkLinks = walkCorales->firstLink; walkLinks != NULL; walkLinks = walkLinks->next) 
                if (walkLinks->idC == idC && walkLinks->id1 == idR1 && walkLinks->id2 == idR2 && walkLinks->id3 == idR3) {
                    if (walkLinks->next == NULL)
                        flag = true;
                    eraseLink(firstRope, walkRopes->id1, walkRopes->id2, walkRopes->id3, walkCorales->idC, idR1, idR2, idR3, idC);
                    if (flag == true)
                        break;
                    flag = false;
                }

    Rope* rope = findRope(firstRope, idR1, idR2, idR3);
    if (rope == NULL)
        return;
    Coral* check = new Coral;
    Coral* coralb4 = findCoralb4(rope, idC, check);
    if (coralb4 == check)
        return;
    delete check;

    if (coralb4 == NULL) {
        Coral* saveCoral = rope->firstCoral->next;
        Link* delLink = rope->firstCoral->firstLink;
        while (delLink != NULL) {
            Link* saveLink = delLink->next;
            delete delLink;
            delLink = saveLink;
        }
        delete rope->firstCoral;
        rope->firstCoral = saveCoral;
    }
    else {
        Coral* saveCoral = coralb4->next->next;
        Link* delLink = coralb4->next->firstLink;
        while (delLink != NULL) {
            Link* saveLink = delLink->next;
            delete delLink;
            delLink = saveLink;
        }
        delete coralb4->next;
        coralb4->next = saveCoral;
    }
}

void moveCoral(Rope* firstRope, int idC, char f_idR1, char f_idR2, char f_idR3, char t_idR1, char t_idR2, char t_idR3) {
    
    /*for (Rope* walkRopes = firstRope; walkRopes != NULL; walkRopes = walkRopes->next)
        for (Coral* walkCorales = walkRopes->firstCoral; walkCorales != NULL; walkCorales = walkCorales->next)
            for (Link* walkLinks = walkCorales->firstLink; walkLinks != NULL; walkLinks = walkLinks->next)
                if (walkLinks->idC == idC && walkLinks->id1 == f_idR1 && walkLinks->id2 == f_idR2 && walkLinks->id3 == f_idR3) {
                    walkLinks->id1 = t_idR1;
                    walkLinks->id2 = t_idR2;
                    walkLinks->id3 = t_idR3;
                }*/
    Rope* fromRope = findRope(firstRope, f_idR1, f_idR2, f_idR3);
    if (fromRope == NULL)
        return;
    Coral* coralToMove = findCoral(fromRope, idC);
    if (coralToMove == NULL)
        return;
    Coral* check = new Coral;
    Coral* coralb4 = findCoralb4(fromRope, idC, check);
    if (coralb4 == check)
        return;
    delete check;

    if (coralb4 == NULL) {
        fromRope->firstCoral = fromRope->firstCoral->next;
    }
    else {
        coralb4->next = coralb4->next->next;
    }

    addCoral(firstRope, t_idR1, t_idR2, t_idR3, coralToMove->idC);
    Coral* added = findCoral(findRope(firstRope, t_idR1,t_idR2, t_idR3), coralToMove->idC);
    added->firstLink = coralToMove->firstLink;
    delete coralToMove;
}

void eraseRope(Rope** firstRope, char idR1, char idR2, char idR3) {
    
    Rope* ropeToErase = findRope(*firstRope, idR1, idR2, idR3);
    if (ropeToErase == NULL)
        return;
    bool flag = false;

    for (Coral* walkCoral = ropeToErase->firstCoral; walkCoral != NULL;) {
        eraseCoral(*firstRope, walkCoral->idC, ropeToErase->id1, ropeToErase->id2, ropeToErase->id3);
        walkCoral = ropeToErase->firstCoral;   
    }
    
    Rope* check = new Rope;
    Rope* ropeB4 = findRopeb4(*firstRope, idR1, idR2, idR3, check);
    if (ropeB4 == check)
        return;
    delete check;

    if (ropeB4 == NULL) {
        Rope* saveRope = (*firstRope)->next;
        delete* firstRope;
        *firstRope = saveRope;
    }
    else {
        Rope* saveRope = ropeB4->next->next;
        delete ropeB4->next;
        ropeB4->next = saveRope;
    }
}

void print(Rope* firstRope) {
    for (Rope* walkRope = firstRope; walkRope != NULL; walkRope = walkRope->next) {
        cout << walkRope->id1 << walkRope->id2 << walkRope ->id3 << endl;
        for (Coral* walkCoral = walkRope->firstCoral; walkCoral != NULL; walkCoral = walkCoral->next) {
            cout << walkCoral->idC << " ";
            for (Link* walkLink = walkCoral->firstLink; walkLink != NULL; walkLink = walkLink->next) {
                cout << walkLink->id1 << walkLink->id2 << walkLink->id3 << " " << walkLink->idC << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    char choice = 0;    

    char idR1 = 0;                      
    char idR2 = 0;
    char idR3 = 0;
    int idC = 0;

    char to_idR1 = 0;
    char to_idR2 = 0;
    char to_idR3 = 0;
    int to_idC = 0;

    Rope* firstRope = NULL;             

    do {                                
        cin >> choice;           
        
        switch (choice) {
        case 'S': 
            cin >> idR1 >> idR2 >> idR3;
            addRope(&firstRope, idR1, idR2, idR3);
            break;
        case 'B':
            cin >> idC >>idR1 >> idR2 >> idR3;
            addCoral(firstRope, idR1, idR2, idR3, idC);
            break;
        case 'L':
            cin >> idC >> idR1 >> idR2 >> idR3 >> to_idC >> to_idR1 >> to_idR2 >> to_idR3;
            addLink(firstRope, idR1, idR2, idR3, idC, to_idR1, to_idR2, to_idR3, to_idC);
            break;
        case 'U':
            cin >> idC >> idR1 >> idR2 >> idR3 >> to_idC >> to_idR1 >> to_idR2 >> to_idR3;
            eraseLink(firstRope, idR1, idR2, idR3, idC, to_idR1, to_idR2, to_idR3, to_idC);
            break;
        case 'D':
            cin >> idC >> idR1 >> idR2 >> idR3;
            eraseCoral(firstRope, idC, idR1, idR2, idR3);
            break;
        case 'M':
            cin >> idC >> idR1 >> idR2 >> idR3 >> to_idR1 >> to_idR2 >> to_idR3;
            moveCoral(firstRope, idC, idR1, idR2, idR3, to_idR1, to_idR2, to_idR3);
            break;
        case 'R':
            cin >> idR1 >> idR2 >> idR3;
            eraseRope(&firstRope, idR1, idR2, idR3);
            break;
        case 'P':
            print(firstRope);
            break;
        }
    } while (choice != 'F');
    
    delMemory(firstRope);
    //_MemoryCheck();
    return 0;
}
