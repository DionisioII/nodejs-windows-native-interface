#ifndef DISPLAY_CONTROL
#define DISPLAY_CONTROL
#include <string>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <stdio.h>
#include <wrl/client.h>
#include <vector>
#include <map>





class DisplayControl {
private:
    //DISPLAY_DEVICE  DisplayDevice;
    //std::vector<std::pair<LPWSTR, DISPLAY_DEVICE>> DisplayDevices;
   
    void PrintDisplayDeviceMode(const DEVMODE* mode);
    void PrintDisplayDeviceStateFlags(DWORD stateFlags);
    BOOL initializeDevicesVector();
public:
    DisplayControl();
    ~DisplayControl();

    std::string getActiveDisplays();



    


};

#endif // !1