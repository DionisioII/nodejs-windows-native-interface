#include"display_control.h"
#include <iostream>

DisplayControl::DisplayControl() {
   
    std::cout << "prova";

}

BOOL DisplayControl::initializeDevicesVector() {

    

    return true;

}

void DisplayControl::PrintDisplayDeviceMode(const DEVMODE* mode)
{
    wprintf(L"%u x %u, %u%s Hz, %u bpp",
        mode->dmPelsWidth,
        mode->dmPelsHeight,
        mode->dmDisplayFrequency,
        (mode->dmDisplayFrequency <= 1 ? L" (Default)" : L""),
        mode->dmBitsPerPel);

    // Somehow this flag is documented but not exists in header.
    //if(mode->dmDisplayFlags & DM_GRAYSCALE)
    //    wprintf(L" GRAYSCALE");
    if (mode->dmDisplayFlags & DM_INTERLACED)
        wprintf(L" INTERLACED");
}

void DisplayControl::PrintDisplayDeviceStateFlags(DWORD stateFlags)
{
    if (stateFlags & DISPLAY_DEVICE_ACTIVE)
        wprintf(L" ACTIVE");
    if (stateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER)
        wprintf(L" MIRRORING_DRIVER");
    if (stateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER)
        wprintf(L" MODESPRUNED");
    if (stateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE)
        wprintf(L" PRIMARY_DEVICE");
    if (stateFlags & DISPLAY_DEVICE_REMOVABLE)
        wprintf(L" REMOVABLE");
    if (stateFlags & DISPLAY_DEVICE_VGA_COMPATIBLE)
        wprintf(L" VGA_COMPATIBLE");
}


DisplayControl::~DisplayControl() {
    //device->Release();
}

std::string DisplayControl::getActiveDisplays()
{
    std::string result;

    
    DWORD           DispNum = 0;
    DISPLAY_DEVICE  DisplayDevice;
    /*LONG            Result;
    TCHAR           szTemp[200];
    int             i = 0;*/
    DEVMODE   defaultMode;

    // initialize DisplayDevice
    ZeroMemory(&DisplayDevice, sizeof(DisplayDevice));
    DisplayDevice.cb = sizeof(DisplayDevice);

    // get all display devices


    while (EnumDisplayDevices(NULL, DispNum, &DisplayDevice, 0))
    {
        ZeroMemory(&defaultMode, sizeof(DEVMODE));
        defaultMode.dmSize = sizeof(DEVMODE);
        if (!EnumDisplaySettings((LPSTR)DisplayDevice.DeviceName, ENUM_REGISTRY_SETTINGS, &defaultMode)) {
            OutputDebugString("Store default failed\n");
            std::cout << "Store default failed\n";
        }
        //this->PrintDisplayDeviceMode(&defaultMode);
        //this->PrintDisplayDeviceStateFlags(DisplayDevice.StateFlags);




        if ((DisplayDevice.StateFlags & DISPLAY_DEVICE_ACTIVE))
        {

            char szDeviceName[32];
            lstrcpy(szDeviceName, DisplayDevice.DeviceName);
            int monitorIndex = 0;
            //std::wcout << DisplayDevice.DeviceName << L", " << DisplayDevice.DeviceString << DisplayDevice.DeviceID <<  L"\n";
            //std::wcout << "Device name: " << DisplayDevice.DeviceName << std::endl;
            //std::wcout << "Device string: " << DisplayDevice.DeviceString << std::endl;
            //std::wcout << "Device ID: " << DisplayDevice.DeviceID << std::endl;
            //std::wcout << "Device key: " << DisplayDevice.DeviceKey << std::endl;
            
            //std::wcout << DisplayDevice.DeviceName << L", " << DisplayDevice.DeviceString << L", " << DisplayDevice.DeviceID << L"\n";
            while (EnumDisplayDevices(szDeviceName, monitorIndex, &DisplayDevice, 0)) {
                if (monitorIndex > 0) result += ";;;";
                result += std::string(DisplayDevice.DeviceName) + ":"
                        + std::string(DisplayDevice.DeviceString) + ":"
                        + std::string(DisplayDevice.DeviceID) + ":::";
                if (monitorIndex > 0) result += "Duplicate:1"; else result += "Duplicate:0";

                //std::cout << DisplayDevice.DeviceName << ": " << DisplayDevice.DeviceString << DisplayDevice.DeviceID << "\n";
                //std::cout << "Device name: " << DisplayDevice.DeviceName << std::endl;
                //std::cout << "Device string: " << DisplayDevice.DeviceString << std::endl;
                //std::cout << "Device ID: " << DisplayDevice.DeviceID << std::endl;
                //std::cout << "Device key: " << DisplayDevice.DeviceKey << std::endl;
                //std::cout << "MonitorIndex : " << monitorIndex;
                ++monitorIndex;

            }


            

        }


        // Reinit DisplayDevice just to be extra clean

        ZeroMemory(&DisplayDevice, sizeof(DisplayDevice));
        DisplayDevice.cb = sizeof(DisplayDevice);
        ++DispNum;

    } // end while for all display devices
    

    return result;
}
