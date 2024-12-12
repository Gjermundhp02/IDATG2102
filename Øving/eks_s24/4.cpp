#include <iostream>

void skrivDato(const int dagNr) {
    if(dagNr<1 || dagNr > 365){
        int dag = dagNr,
            måned = 0;
        while(måned==1 ? dag>28 : (måned%2==0 ? dag>31 : dag>30)){
            if(måned==1){
                dag-=28;
            }
            else {
                if(måned%2==0){
                    dag-=31;
                }
                else {
                    dag-=30;
                }
            }
            måned++;
        }
        std::cout << dag << '/' << måned+1;
    }
    else
        std::cout << "Skriv inn et gyldog nummer (1-365)";
}

// for(int i = 0; i<12; i++){
//             if(måned==1){
//                 if(dag<=28) 
//                     break;
//                 else
//                     dag-=28;
//             }
//             else {
//                 if(måned%2==0){
//                     if(dag<=31)
//                         break;
//                     else
//                         dag -= 31;
//                 }
//                 else {
//                     if(dag<=30)
//                         break;
//                     else
//                         dag -= 30;
//                 }
//             }