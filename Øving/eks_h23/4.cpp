#include <iostream>


int main(int argc, char const *argv[]){
    float nr;
    bool funnet = false;
    std::cout << "skriv inn gangefaktor: ";
    std::cin >> nr;
    for(int i = 0; i<=1000000; i++){
        int nyttNr = i*nr,
            førsteSiffer = i,
            modMed = 1;
        if(nyttNr==int(nyttNr)){
            while(førsteSiffer/10>1) {
                modMed*=10;
                førsteSiffer/=10;
            }
            int nyttNrKontroll = (i%modMed)*10+førsteSiffer;
            if(nyttNr==nyttNrKontroll){
                funnet=true;
                std::cout << nr << '*' << i << '=' << nyttNr << '\n';
            }
        }
    }
    if(!funnet){
        std::cout << "Det finnes ingen slike regnestykker med dette nummeret";
    }
    return 0;
}
