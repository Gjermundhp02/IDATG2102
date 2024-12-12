Node* gRoot = nullptr, // Rot-peker (har altså ikke at head->right er rota).
    * gForrige = nullptr; // Den forrige noden i preorder rekkefølge (jfr. oppg.3b)

struct Node {
char ID; // Nodens ID/key/nøkkel/navn (ett tegn).
Node *left, *right; // Referanser til begge subtrærne eller neste i preorder rekkefølge
                    // eller nullptr/NULL (se resten av oppgaveteksten).
bool nesteIPreorder; // Er false dersom høyre subtre finnes,
                     // er true dersom tomt høyre subtre og at right
                     // da i stedet peker til neste node i preorder rekkefølge.
                     // Har noden er tomt høyre subtre, og er den aller siste i
                     // preorder rekkefølge, vil den også være true,
                     // bare at right da vil peke til nullptr/NULL.
Node (char id, int p) // Constructor:
    { ID = id; nesteIPreorder = false; left = right = nullptr; }
};

// A
Node* neste(Node* node) {
    if(node){
        if(node->nesteIPreorder)
            return node->right;
        else
            return node->left;
    }
    else
        return nullptr;
}

// B
void settNeste(Node* node) {
    if(node){
        settNeste(node->right);
        settNeste(node->left);
        if(!node->right){
            if(node->left){
                node->nesteIPreorder = true;
                node->right = node->left;
            }
            else {
                node->nesteIPreorder = true;
                node->right = gForrige;
            }
        }

        gForrige = node;
    }
}

// Hvis høyrebarn gå dit
// Hvis venstrebarn gå dit