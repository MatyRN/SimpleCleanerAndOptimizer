/*This Call main function
of the primordia function that was assigned to the program
beyond its Visual section*/
#include "PrincipalFunction.h"
using namespace std;
void Clean();
void Optimization();
void Nose();
    //Clear the cache of the pc
void Clean(){
    system("SimpleClean.bat");
   // = "Inicializer Clean...\n";
    }
    //Optimize the PC a bit.
    void Optimization(){
    system("Optimization.bat");
    //PrincipalFunction.TEXTDECOMANDOS= "Inicializer Optimization...\n";
    }
    //It does something that I didn't think of.
    void Nose(){
    system("Nose.bat");
    //p.TEXTDECOMANDOS="Inicializer Nose...\n";
    }
