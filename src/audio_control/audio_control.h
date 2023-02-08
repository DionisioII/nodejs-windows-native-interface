#include <string>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <stdio.h>
#include <wrl/client.h>

std::string helloUser( std::string name );



class VolumeControl {
private:
    Microsoft::WRL::ComPtr<IAudioEndpointVolume> device;
public:
    VolumeControl();
    ~VolumeControl();

    BOOL isMuted();

    void setMuted(BOOL muted);

    double getVolume();

    void setVolume(float volume);


};