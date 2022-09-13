#include "Window.h"
#include "PrincipalFuntion.cpp"
#define LOWORD
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
 switch(uMsg){
case WM_CREATE:
    break;
    case WM_CLOSE:
    DestroyWindow(hWnd);
    break;
    case WM_DESTROY:
    PostQuitMessage(0);
    break;
    case WM_COMMAND:{
    if(LOWORD(wParam) ==1){
        MessageBox(hWnd,"You Computer is deleting cache...","Accion...",MB_ICONINFORMATION);
        Clean();
    }else if(LOWORD(wParam)== 2){
        MessageBox(hWnd,"You Computer is optimizing...","Accion...",MB_ICONINFORMATION);
        Optimization();
}else if(LOWORD(wParam)== 3){
        MessageBox(hWnd,"You Computer is I Dont know, Dont think in a Funtion...","Accion",MB_ICONINFORMATION);
        Nose();
}
}
    return 0;
    }
    return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

Window::Window(): m_hinstance(GetModuleHandle(nullptr)){
////////////////////////////////////////////
    const char* CLASS_NAME = "Ventanita";
    PrincipalFunction P;
///=====WINDOW PRELOAD======///
    WNDCLASS wndclass = {};
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.hInstance = m_hinstance;
    wndclass.hIcon = LoadIcon(NULL,IDI_WINLOGO);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpfnWndProc = WindowProc;
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW);

    RegisterClass(&wndclass);
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
//WIDTH AND HEIGHT OF THE WINDOW//
    int width = 640;
    int height = 480;
///==WINDOW MEASUREMENTS===========////
    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
///====================================///
    AdjustWindowRect(&rect, style, false);
///WINDOW PROPERTIES
m_hWnd = CreateWindowEx(0,CLASS_NAME,"Programita",style,rect.left,rect.top,rect.right - rect.left,rect.bottom - rect.top,NULL,NULL,m_hinstance,NULL);
    ShowWindow(m_hWnd,SW_SHOW);
///Create Buttons
HWND hwndButton_1 = CreateWindow(
    "BUTTON",  // Predefined class; Unicode assumed
    "Clean of Cache",      // Button text
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
    10,         // x position
    390,         // y position
    150,        // Button width
    80,        // Button height
    m_hWnd,     // Parent window
    (HMENU) 1,       // No menu.
    (HINSTANCE)GetWindowLongPtr(m_hWnd, GWLP_HINSTANCE),
    NULL);
HWND hwndButton_2 = CreateWindow(
    "BUTTON",  // Predefined class; Unicode assumed
    "Optimization",      // Button text
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
    173,         // x position
    390,         // y position
    135,        // Button width
    80,        // Button height
    m_hWnd,     // Parent window
    (HMENU) 2,       // No menu.
    (HINSTANCE)GetWindowLongPtr(m_hWnd, GWLP_HINSTANCE),
     NULL);
HWND hwndButton_3 = CreateWindow(
    "BUTTON",  // Predefined class; Unicode assumed
    "Nose",      // Button text
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
    320,         // x position
    390,         // y position
    135,        // Button width
    80,        // Button height
    m_hWnd,     // Parent window
    (HMENU) 3,       // No menu.
    (HINSTANCE)GetWindowLongPtr(m_hWnd, GWLP_HINSTANCE),
    NULL);
///Crea Texto
  HWND hWndEdit = CreateWindow(
        ("Edit"),
        (TextOfFuncion),
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        10,
        10,
        620,
        360,
        m_hWnd,
        NULL,
        NULL,
        NULL);
}
Window::~Window(){
////////////////////////////////////////////
  const char* CLASS_NAME = "Ventanita";
  UnregisterClass(CLASS_NAME, m_hinstance);
////////////////////////////////////////////
}
bool Window::ProcessMessages(){
    MSG msg ={};
//////////////////////////////////////////////////
   while(PeekMessage(&msg,nullptr,0u,0u,PM_REMOVE)){
        if(msg.message == WM_QUIT){
            return false;
        }
///////////////////////////////
TranslateMessage(&msg);
DispatchMessage(&msg);
///////////////////////////
    }
    return true;
}
