#include "pch.h"
#include "classes.h"
#include "UltimateProxyDLL.h"
#include "utilities.h"
#include "Windows.h"

#define OFFSET_ACTIVATEFREECAMFUNCTION 0x140412100
#define OFFSET_DEACTIVATEFREECAMFUNCTION 0x140412230

DWORD WINAPI MainThread(LPVOID arg)
{
    bool debounce = false;
    bool debounce2 = false;

    bool freecamEnabled = false;

    while (true) {

        if (utilities::IsGameFocused()) {
            // Freecam toggle logic
            if (GetAsyncKeyState(86)) {

                if (debounce == false) {
                    ClientGameContext* GameContext = ClientGameContext::GetInstance();

                    debounce = true;

                    if (freecamEnabled == false) {

                        GameContext->GameView->SetFreeCameraMode(1);

                        using activateFreeCameraFunction = void(__fastcall*)(FreecamData*, int, int);
                        activateFreeCameraFunction activateFreeCamera = (activateFreeCameraFunction)OFFSET_ACTIVATEFREECAMFUNCTION;

                        activateFreeCamera(GameContext->GameView->FreeCamera->FreecamData, 32, 0);

                        freecamEnabled = true;
                    }
                    else {

                        GameContext->GameView->SetFreeCameraMode(2);

                        using deactivateFreeCameraFunction = void(__fastcall*)(FreecamData*, int);
                        deactivateFreeCameraFunction activateFreeCamera = (deactivateFreeCameraFunction)OFFSET_DEACTIVATEFREECAMFUNCTION;

                        activateFreeCamera(GameContext->GameView->FreeCamera->FreecamData, 0);

                        freecamEnabled = false;
                    }
                }
            }
            else {
                debounce = false;
            }

            // UI toggle logic
            if (GetAsyncKeyState(85)) {

                if (debounce2 == false) {
                    BFServerSettings* Settings = BFServerSettings::GetInstance();
                    Settings->UISettings->DrawEnable = !Settings->UISettings->DrawEnable;
                    debounce2 = true;
                }
            }
            else {
                debounce2 = false;
            }
        }
    }
    return 0;
}

BOOL WINAPI DllMain(HMODULE hmodule, DWORD dwReason, LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        UPD::CreateProxy(hmodule);

        HANDLE handle = CreateThread(0, 0, &MainThread, 0, 0, 0);
        if (handle)
            CloseHandle(handle);

    }
    return TRUE;
}