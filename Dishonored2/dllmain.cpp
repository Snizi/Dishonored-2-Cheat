// dllmain.cpp : Defines the entry point for the DLL application.
#include "playerClass.h"
#include <Windows.h>
#include "Imgui/imgui.h"
#include "menu.h"




DWORD WINAPI HackThread(HMODULE)
{
    toogle cheats;

    uintptr_t moduleBase = reinterpret_cast<GetModuleHandle>(L"Dishonored2.exe");

    ent* localPlayer = *(ent**)(moduleBase + 0x02ED4580);


    while (true)
    {

        if (GetAsyncKeyState(VK_NUMPAD1) & 1)
        {
            cheats.health = !cheats.health;
        }
        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            cheats.mana = !cheats.mana;
        }
        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            cheats.choke = !cheats.choke;
        }
        if (GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            cheats.oxygen = !cheats.oxygen;
        }
        if (GetAsyncKeyState(VK_NUMPAD5) & 1)
        {
            cheats.ammo = !cheats.ammo;
        }
        if (GetAsyncKeyState(VK_NUMPAD7))
        {
            localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->playerPhysicsPtr->playerBodyPointer->CharacterProxyPointer->playerPosition.z += 0.7;
        }
        if (GetAsyncKeyState(VK_NUMPAD8))
        {
            localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->playerPhysicsPtr->playerBodyPointer->CharacterProxyPointer->playerPosition.z -= 0.7;
        }


        


        
        if (localPlayer)
        {

            if (cheats.health)
            {
                localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->statusPtr->health = 500;
            }

            if (cheats.mana)
            {
                localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->statusPtr->manaPtr->mana = 100;
            }

            if (cheats.choke)
            {
                localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->playerStateMachinePtr->playerStateChokePtr->choke = 3;
            }

            if (cheats.oxygen)
            {
                localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->playerBreathPtr->oxygen = 100;
            }

            if (cheats.ammo)
            {
                uintptr_t* inventoryPtr = (uintptr_t*)(localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->playerStateMachinePtr->playerStateEquipChangePtr->inventoryPtr);
                if (inventoryPtr)
                    localPlayer->callBackBindMemPtr->playerControllerPtr->playerStatePtr->playerStateMachinePtr->playerStateEquipChangePtr->inventoryPtr->ammo = 50;

            }

    
            
        }
        Sleep(5);
    }
    

    FreeLibraryAndExitThread(hModule, 0);
    return 0;

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
if(ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
       CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(HackThread), hModule, 0, nullptr);
    }
    return TRUE;
}
