

struct Node {
    int ID; // Nodens ID/key/nøkkel/navn (et tall).
    Node *left, *right; // Referanse til begge subtrærne (evt. nullptr/NULL).
    Node* parent; // Peker oppover igjen til forelder/mor,
};

// A
Node* nestePreorder(const Node* n){
    if(n->left) return n->left;
    else if(n->right) return n->right;
    else{
        Node* p = n->parent;
        if(p->right==n){
            while(!p->parent->right || p->parent->right==p){ 
                p=p->parent;
                if(p->parent==nullptr){
                    return nullptr;
                }
            }
            return p->parent->right;
        }
        else
            return p->right;
    }
}

// B
Node* forrigePreorder(const Node* n) {
    if(n->parent==nullptr){
        return nullptr;
    }
    else if(n->parent->left==n){
        return n->parent;
    }
    else{
        Node* p=n->parent;
        while(!p->left){ // Klatre opp
            if(!p->parent)
                return n->parent;
            p=p->parent;
        }
        p=p->left;
        while(p->left || p->right){
            if(p->right){
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
        return p;
    }
}