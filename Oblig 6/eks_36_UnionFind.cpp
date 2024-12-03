/**
 *   Programeksempel nr 36 - Union-Find.
 *
 *   Noen ganger er sp�rsm�let om node A er i samme komponent / (sub)graf /
 *   set / ekvivalensklasse som node B (path'en imellom er uinteressant).
 *   NB:  Det bygges IKKE en lignende graf, men et tre/flere tr�r av de som
 *        er i samme komponent/subgraf.
 *
 *   Funksjonen 'unionerOgFinn' setter noder til � v�re i samme komponent
 *   om 'unioner' er lik 'true', dvs. en unionering skal skje.
 *   Er 'unioner' lik 'false' er det interessant hva funksjonen returnerer,
 *   dvs. om nodene allerede befinner seg i samme komponent eller ei.
 *
 *
 *   Algoritme/virkem�te:
 *     gForeldre[i] > 0 (=x) n�r node nr.'i' har 'x' som foreldre/mor
 *     gForeldre[i] = 0      n�r node nr.'i' enn� ikke har noen foreldre,
 *                           eller ender opp som rot for et tre
 *     unioner = true      om noder skal knyttes sammen
 *             = false     om det skal finnes ut om noder er i samme komponent
 *
 *   @file     EKS_36_UnionFind.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>
#include <iomanip>                //  setw
using namespace std;


const int ANTNODER  = 6;         ///<  Nodene har 'ID' lik  'A'-'J'  (1-10).
const int ANTKANTER = 6;         ///<  Antall kanter i grafen.


int gForeldre[ANTNODER+1];        ///<  I "skuff" nr.i er foreldre til nr.i.
                                  //  NB: MEGET viktig at alle er nullstilt!
                                  //  Bruker indeksene 1 t.o.m. ANTNODER.

                                  ///<  Grafkantene:
char gKanter[ANTKANTER][3] = { "BA", "CD", "FC", "ED", "AF", "AE" };

/*  Grafen ser slik ut:      A------------B---------D
                             |          / | \     /   \
                             |        /   |   \  /     \
                             |      /     |     C       E----F
                             |    /       |    / \     /
                             |  /         |  /    \   /
                             |/           | /      \ /
                             J------I-----H         G
*/

void skriv();
bool unionerOgFinn2(int nr1, int nr2, const bool unioner);


/**
 *  Hovedprogrammet:
 */
int main() {
    int nr1 = 0, nr2 = 0;

    for (int i = 0; i < ANTKANTER; i++) {
        nr1 = static_cast <int> (gKanter[i][0]-'A'+1);
        nr2 = static_cast <int> (gKanter[i][1]-'A'+1);

        unionerOgFinn2(nr1, nr2, true);            //  Unionerer.
                                                  //  Skriver nodenes navn:
        cout << '\n' << gKanter[i][0] << ' ' << gKanter[i][1] << ':';
        skriv();
        // cout << "\t\t'D' og 'H' er "           //  'D' = nr.4,  'H' = nr.8
        //      << (!unionerOgFinn(4, 8, false) ? "IKKE " : "")  // Finnes i samme
        //      << "i samme komponent";                          //   komponent?
        getchar();
    }

    cout << "\n\n";
    return 0;
}


/**
 *  Skriver 'gForeldres' innhold som bokstaver og evt. antall barn i subtre.
 */
void skriv() {
    cout << '\t';
    for (int i = 1; i <= ANTNODER; i++)     //  Linje med bokstavoverskrift:
        cout << "  " << static_cast <char> (i+'A'-1);
    cout << "\n\t";
    for (int i = 1; i <= ANTNODER; i++)     //  G�r gjennom 'gForeldre':
        if (gForeldre[i] > 0)               //  Inneholder foreldre:
            cout << "  " << static_cast <char> (gForeldre[i]+'A'-1);
        else if (gForeldre[i] == 0)         //  Hittil ingen foreldre:
            cout << "  -";
        else                                //  Rot for -'gForeldre[i]' noder:
            cout << setw(3) << (-gForeldre[i]);  //  KUN aktuelt ved WB.
}


/**
 *  Om 'unioner' er 'true' vil node 'nr1' og 'nr2' bli satt til � v�re
 *  i samme komponent, eller returneres det om de allerede ER det.
 *
 *  @param    nr1      -  Indeks for 1.node (blir mor til eller barn av 'nr2')
 *  @param    nr2      -  Indeks for 2.node (blir mor til eller barn av 'nr1')
 *  @param    unioner  -  Skal nodene havne i samme komponent eller ei
 *  @return   Er 'nr1' og 'n2' i samme komponent eller ei?
 */
bool unionerOgFinn2(int nr1, int nr2, const bool unioner) {
    int i = nr1, j = nr2;                         //  Initierer indekser.

    while (gForeldre[i] > 0)  i = gForeldre[i];   //  Finner rot for i/nr1.

    while (gForeldre[j] > 0)  j = gForeldre[j];   //  Finner rot for j/nr2.


//  **************************************************************************
//  NYTT (ned til stjernelinje) ift. EKS_36 ifm. Path Compression (PC):

    int indeks = 0;          //  ALLE p� stien fra 'nr1' flyttes opp til rota:
    while (gForeldre[nr1] > 0) {    //  Enn� ikke n�dd rota:
        indeks = nr1;               //  'indeks' er aktuell node.
        nr1 = gForeldre[nr1];       //  'nr1' settes til mora.
        gForeldre[indeks] = i;      //  'indeks' flyttes oppunder rota.
    }
                             //  ALLE p� stien fra 'nr2' flyttes opp til rota:
    while (gForeldre[nr2] > 0) {
        indeks = nr2;
        nr2 = gForeldre[nr2];
        gForeldre[indeks] = j;
    }

//  **************************************************************************
//  NYTT (ned til stjernelinje) ift. EKS_36 ifm. Weight Balancing (WB):

    if (unioner  &&  (i != j)) {                //  Hekter evt. sammen.
        if (gForeldre[j] < gForeldre[i])  {     //  'j' sitt tre er st�rst:
             gForeldre[j] += gForeldre[i]-1;    //  �ker antall barn under seg
                                                //    -1 pga. nr.'i'.
             gForeldre[i] = j;                  //  Hekter 'i' under 'j'.
        } else  {                     //  'i' sitt tre er st�rst (eller lik!):
            gForeldre[i] += gForeldre[j]-1;     //  �ker antall barn under seg
                                                //   -1 pga. nr.'j'
            gForeldre[j] = i;                   //  Hekter 'j' under 'i'.
        }
    }
//  **************************************************************************

    return (i == j);     //  Returnerer om i samme komponent eller ei.
                         //    (Aktuelt KUN n�r 'unioner' er 'false'
} 
