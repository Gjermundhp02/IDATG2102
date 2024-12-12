Node* gRoot = nullptr; // Rot-peker (har altså ikke at head->right er rota).

struct Node {
    char ID; // Nodens ID/key/nøkkel/navn (ett tegn).
    int pos; // Posisjon i treet.
    Node *left, *right; // Referanser til begge subtrærne, evt. nullptr/NULL
    Node (char id, int p) // Constructor:
    { ID = id; pos = p; left = right = nullptr; }
};

// A
void speilvend(Node* n){
    if(n){
        n->left=n->right;
        n->right=n->left;
        speilvend(n->right);
        speilvend(n->left);
    }
}

void settPosisjoner(Node* n, int p){
    if(n){
        n->pos=p;
        settPosisjoner(n->left, p*2);
        settPosisjoner(n->right, p*2+1);
    }
}

// B
void speilvend(Node* n, int p){
    if(n){
        n->ID=p;
        n->left=n->right;
        n->right=n->left;
        speilvend(n->left, p*2);
        speilvend(n->right, p*2+1);
    }
}

// C
Node* finnNode(int p){
    Node* n = gRoot;
    while(true){
        if(n==nullptr || n->pos==p){
            return n;
        }
        else {
            int nextPos=p;
            while((nextPos/2)>n->pos) nextPos/=2;
            if(nextPos%2==0){
                n = n->left;
            }
            else{
                n = n->right;
            }
        }
    }
}