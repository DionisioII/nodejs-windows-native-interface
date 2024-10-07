#include <string>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <stdio.h>
#include <wrl/client.h>





class ProcessMonitor {
private:
    //Microsoft::WRL::ComPtr<IAudioEndpointVolume> device;
public:
    ProcessMonitor();
    ~ProcessMonitor();

    std::string getActiveProcesses();


};