#include <iostream>

int tallene[1000000];

int main(int argc, char const *argv[]){
    int sum = 0,
        antall = 0,
        størst = 0;

    for(int i = 0; i<1000000; i++){
        if(tallene[i]>=størst){
            sum+=tallene[i];
            størst=tallene[i];
            antall++;
        }
    }
    std::cout << "Summen er: " << sum << " Summerte " << antall << " tall.";
    return 0;
}
