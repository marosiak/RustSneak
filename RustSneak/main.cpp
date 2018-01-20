#include <iostream>
#include <windows.h>

void holdCtrl(){
    // it's like pressing one time for real, but this was too fast,
    // so it has to be hold for around 150 ms
    INPUT ip;

    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "CTRL" key
    ip.ki.wVk = 0x11;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(300);
    // Release
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

int main(){
    std::cout << "Hold [SHIFT + C] to sneak quickly and have fun bullying your neighbors"<< std::endl
              << "Regards orzel1244" << std::endl;
    while(true){
        if(GetKeyState(VK_SHIFT) & 0x8000){
            if(GetKeyState(0x43) & 0x8000){
                holdCtrl();
                Sleep(250);
            }
        }
    }
    return 0;
}
