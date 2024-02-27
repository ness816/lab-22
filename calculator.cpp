#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    static HWND hEdit1, hEdit2;
    static HWND hButtonPlus, hButtonMinus, hButtonMultiply, hButtonDivide;
    switch(Message) {
        case WM_CREATE: {
            CreateWindowEx(0, "STATIC", "Please input two numbers", WS_CHILD | WS_VISIBLE, 20, 10, 200, 20, hwnd, NULL, NULL, NULL);
            hEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE, 40, 40, 160, 20, hwnd, NULL, NULL, NULL);
            hEdit2 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE, 40, 70, 160, 20, hwnd, NULL, NULL, NULL);

            hButtonPlus = CreateWindow("BUTTON", "+", WS_CHILD | WS_VISIBLE, 30, 120, 30, 20, hwnd, (HMENU)1, NULL, NULL);
            hButtonMinus = CreateWindow("BUTTON", "-", WS_CHILD | WS_VISIBLE, 80, 120, 30, 20, hwnd, (HMENU)2, NULL, NULL);
            hButtonMultiply = CreateWindow("BUTTON", "*", WS_CHILD | WS_VISIBLE, 130, 120, 30, 20, hwnd, (HMENU)3, NULL, NULL);
            hButtonDivide = CreateWindow("BUTTON", "/", WS_CHILD | WS_VISIBLE, 180, 120, 30, 20, hwnd, (HMENU)4, NULL, NULL);

            break; 
        }
        case WM_COMMAND: {
            if((HWND)lParam == hButtonPlus) {
                char num1[20], num2[20];
                GetWindowText(hEdit1, num1, 20);
                GetWindowText(hEdit2, num2, 20);
                double x = atof(num1);
                double y = atof(num2);
                double result = x + y;
                char buffer[50];
                sprintf(buffer, "Result: %.2f", result);
                MessageBox(hwnd, buffer, "Result", MB_OK);
            }
            else if((HWND)lParam == hButtonMinus) {
                char num1[20], num2[20];
                GetWindowText(hEdit1, num1, 20);
                GetWindowText(hEdit2, num2, 20);
                double x = atof(num1);
                double y = atof(num2);
                double result = x - y;
                char buffer[50];
                sprintf(buffer, "Result: %.2f", result);
                MessageBox(hwnd, buffer, "Result", MB_OK);
            }
            else if((HWND)lParam == hButtonMultiply) {
                char num1[20], num2[20];
                GetWindowText(hEdit1, num1, 20);
                GetWindowText(hEdit2, num2, 20);
                double x = atof(num1);
                double y = atof(num2);
                double result = x * y;
                char buffer[50];
                sprintf(buffer, "Result: %.4f", result);
                MessageBox(hwnd, buffer, "Result", MB_OK);
            }
            else if((HWND)lParam == hButtonDivide) {
                char num1[20], num2[20];
                GetWindowText(hEdit1, num1, 20);
                GetWindowText(hEdit2, num2, 20);
                double x = atof(num1);
                double y = atof(num2);
                if(y == 0) {
                    MessageBox(hwnd, "Cannot divide by zero!", "Error", MB_OK | MB_ICONERROR);
                }
                else {
                    double result = x / y;
                    char buffer[50];
                    sprintf(buffer, "Result: %.4f", result);
                    MessageBox(hwnd, buffer, "Result", MB_OK);
                }
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    memset(&wc,0,sizeof(wc));
    wc.cbSize         = sizeof(WNDCLASSEX);
    wc.lpfnWndProc    = WndProc;
    wc.hInstance      = hInstance;
    wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground  = CreateSolidBrush(RGB(255, 0, 0));
    wc.lpszClassName  = "WindowClass";
    wc.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm        = LoadIcon(NULL, IDI_APPLICATION);


    if(!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "My Calculator", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 250, 200, NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
