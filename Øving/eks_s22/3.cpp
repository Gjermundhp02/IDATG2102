#include <iostream>

Node* gRoot = nullptr; // Rot-peker (har altså ikke at head->right er rota)

struct Node {
    int ID; // Nodens ID/key/nøkkel/navn (et tall).
    Node *left, *right; // Referanse til begge subtrærne (evt. nullptr/NULL).
    Node(int id) { ID = id; left = right = nullptr; }
};

// A
bool skrivNivaa(const Node* t, const int n, const int nivaa){
    if(t){
        if(n==nivaa){
            std::cout << t->ID << " ";
            return true;
        }
        else{
            return skrivNivaa(t->left, n+1, nivaa) || skrivNivaa(t->right, n+1, nivaa);
        }
    }
    else
        return false;
}

// B
Node* byggBalansertBST(const int arr[], const int start, const int slutt){
    if(start<=slutt){
        Node* node = new Node(arr[start+(slutt-start)/2]);
        node->left = byggBalansertBST(arr, start, start+(slutt-start)/2-1);
        node->right = byggBalansertBST(arr, start+(slutt-start)/2+1, slutt);
    }
    else
        return nullptr;
}
