#ifndef AUDIO_CONTROL
#define AUDIO_CONTROL
#include <string>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <stdio.h>
#include <wrl/client.h>
#include <vector>
#include <map>





class VolumeControl {
private:
    Microsoft::WRL::ComPtr<IAudioEndpointVolume> device;
    //Microsoft::WRL::ComPtr<IMMDeviceCollection> devices;
    //std::vector<Microsoft::WRL::ComPtr<IAudioEndpointVolume>> devices;
    std::vector<std::pair<LPWSTR, Microsoft::WRL::ComPtr<IAudioEndpointVolume>>> devices;

    BOOL initializeDevicesVector();
public:
    VolumeControl();
    ~VolumeControl();

    

    BOOL isMuted();

    void setMuted(BOOL muted);

    double getVolume();

    void setVolume(float volume);

    std::wstring getMicrophoneStatuses();


};

#endif // !1