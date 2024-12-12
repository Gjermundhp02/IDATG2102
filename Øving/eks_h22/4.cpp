#include <cmath>
#include <iostream>


int main(){
    int antall = 0;
    for(int i = 0; i<1000000; i++){
        int sumDiv = i;
        for(int j = 1; j<=i/2; j++){
            if(i%j==0){
                sumDiv+=i/j;
            }
        }
        if(sumDiv>i*2){
            float diffSqrt = sqrt(sumDiv-i*2);
            if(diffSqrt!=int(diffSqrt)){
                antall++;
            }
        }
    }
    std::cout << "Det er " << antall << "der differansen mellom summen av alle tallets divisorer og 2n er heltallelig kvadratisk" << std::endl;
}