/**
 *   Hovedrisset til oblig nr 2.
 *
 *   For programmets funksjonalitet se:  Oblig2.pdf
 *
 *   @file    OBLIG2.CPP
 *   @author  Frode Haug, NTNU
 */


#include <iostream>             //  cout
using namespace std;


/**
 *  Node (med ID/key/data og venstre/h�yre pekere til nodens barn).
 */
struct Node {
    int ID;                  //  Nodens ID/key/n�kkel/navn (et tall).
    Node *left, *right;      //  Peker til begge subtr�rne (evt. 'nullptr').
    Node(int id) { ID = id;  left = right = nullptr; }
};


Node* gRoot = nullptr;  ///<  Peker til treets rot.
int   gNivaa,           ///<  N�v�rende nodeniv� (rota er p� niv� nr.0).
      gNoder[50];       ///<  IDene for nodene p� n�v�rende sti fra rota til
                        ///<  bladnoder (oppg A). 0 eller 1 til om node lengst
                        ///<  til h�yre enn� er sett p� niv� nr.'i' (oppg B).

Node* byggTre();
void  finnOgSkrivAlleStier(Node* node);      //  Oppgave A
void  skrivHoyreView(Node* node);            //  Oppgave B


/**
 *  Hovedprogrammet:
 */
int main() {

    gRoot = byggTre();


    cout << "\n\nTester oppgave A - ALLE stier fra rot til ALLE bladnoder:\n";
    gNivaa = -1;
    finnOgSkrivAlleStier(gRoot);                //  Oppgave A
                                                //  Utskriften b�r v�re:
                                                //       1 2 4
                                                //       1 2 5 8
                                                //       1 3 6 9 11
                                                //       1 3 7 10

    cout << "\n\nTester oppgave B - H�yre view:\n";
    gNivaa = -1;                                //  Nullstiller dataene igjen:
    for (int i = 0; i < 50; i++)  gNoder[i] = 0;
    
    skrivHoyreView(gRoot);                      //  Oppgave B
                                                //  Utskriften b�r v�re:
                                                //       1  3  7  10  11
    cout << "\n\n";
    return 0;
}


/**
 *  Bygger et bin�rt testtre.
 *
 *  @return   Peker til rota i treet som er bygd
 */
Node* byggTre() {                                //  Bygger treet:          //
    Node* p[12];                                 //           1             //
    for (int i = 1; i <= 11; i++)                //       /       \         //
        p[i] = new Node(i);                      //      2         3        //
    p[1]->left = p[2];    p[1]->right = p[3];    //    /   \     /   \      //
    p[2]->left = p[4];    p[2]->right = p[5];    //   4     5   6     7     //
    p[3]->left = p[6];    p[3]->right = p[7];    //        /     \   /      //
    p[5]->left = p[8];    p[6]->right = p[9];    //       8       9 10      //
    p[7]->left = p[10];   p[9]->left = p[11];    //              /          //
    return p[1];                                 //             11          //
}


/**
 *  OPPGAVE A- Genererer og skriver ALLE stier fra rota og ned til bladnodene.
 *
 *  @param   node  -  Aktuell node � behandle
 */
void finnOgSkrivAlleStier(Node* node) {
    gNivaa++;                                   //  G�r ned et niv�:
    gNoder[gNivaa] = node->ID;                  //  Setter inn ID'en i stien
    if(node->left == nullptr && node->right == nullptr){
       for(int i = 0; i <= gNivaa; i++){
          cout << gNoder[i] << " ";
       }
       cout << "\n";
    }
    else{
       if(node->left != nullptr){
          finnOgSkrivAlleStier(node->left);
       }
       if(node->right != nullptr){
          finnOgSkrivAlleStier(node->right);
       }
    }
    gNivaa--;                                   //  G�r opp et niv� igjen
}


/**
 *  OPPGAVE B - Finner og skriver ALLE nodene lengst til H�YRE p� ALLE niv�er.
 *
 *  @param   node  -  Aktuell node � behandle
 */
void skrivHoyreView(Node* node) {
    gNivaa++;
    if(gNoder[gNivaa] == false){
       gNoder[gNivaa] = true;
       cout << node->ID << " ";
    }
    if(node->right != nullptr){
       skrivHoyreView(node->right);
    }
    if(node->left != nullptr){
       skrivHoyreView(node->left);
    }
    gNivaa--;
}