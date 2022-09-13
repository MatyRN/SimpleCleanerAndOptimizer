#include <iostream>
#include "Window.h"

int main(){
//SEND A MESSAGE SAYING THE WINDOW IS OPENING.
    std::cout << "Creando Ventana\n";
//CREATE A WINDOW FROM WINDOW.H and WINDOW.CPP
    Window* pWindow = new Window();

/*Running Variable As long as it is True IT WILL REFRESH THE SCREEN*/
bool running = true;
while(running){
    if(!pWindow->ProcessMessages()){
        std::cout << "Cerrar Ventana\n";
        running = false;
    }
    ///Renderizar
    Sleep(10);
    }
        delete pWindow;
    return 0;
}
