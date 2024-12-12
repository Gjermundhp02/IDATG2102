Node* gRoot = nullptr; // Rot-peker (har altså ikke at head->right er rota)

struct Node {
    int ID; // Nodens ID/key/nøkkel/navn (et tall).
    Node *left, *right; // Referanse til begge subtrærne (evt. 'nullptr/NULL').
    Node(int id) { ID = id; left = right = nullptr; }
};

// A
bool erSosken(const Node* t, const Node* s1, const Node* s2){
    if(t && s1 && s2){
        if(t->right==s1&&t->left==s2 || 
        t->right==s2&&t->left==s1 ||
        erSosken(t->right, s1, s2)||
        erSosken(t->left, s1, s2))
            return true;
        else
            return false;
    }
    else
        return false;
}

// B
void kappTreNedentil(Node* t, const int verdi) {
    if(t){
        if(t->right && t->right->ID>verdi){
            t->right = nullptr;
        }
        else
            kappTreNedentil(t->right, verdi);
        if(t->left && t->left->ID>verdi){
            t->left = nullptr;
        }
        else
            kappTreNedentil(t->left, verdi);
    }
}
