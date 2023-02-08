//#pragma once
#define _WINSOCKAPI_
#include <iostream>
#include <string>
#include "audio_control.h"

#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <stdio.h>
#include <wrl/client.h>




//using Microsoft::WRL::ComPtr;

template<typename ... Args>
std::string string_format(std::string format, Args ... args) {
    size_t size = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, format.c_str(), args ...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

void checkErrors(HRESULT hr, std::string error_message) {
    if (FAILED(hr)) {
        //throw string_format("%s (0x%X)", error_message.c_str(), hr);
        std::cout << error_message;
    }
    else {
        //std::cout<<"HR result was correct\n";
    }
}




VolumeControl::VolumeControl() {
        // The IMMDeviceEnumerator interface provides methods for enumerating multimedia device resources. Basically the interface of the requested object.
        
        Microsoft::WRL::ComPtr<IMMDeviceEnumerator> deviceEnumerator;
        
        // Creates a single uninitialized object of the class associated with a specified CLSID
        CoInitialize(NULL);
       
        checkErrors(
            CoCreateInstance(
                __uuidof(MMDeviceEnumerator),   // Requested COM device enumerator id
                NULL,                           // If NULL, indicates that the object is not being created as part of an aggregate.
                CLSCTX_INPROC_SERVER,           // Context in which the code that manages the newly created object will run (Same process).
                IID_PPV_ARGS(&deviceEnumerator) // Address of pointer variable that receives the interface pointer requested in riid.
            ),
            "Error when trying to get a handle to MMDeviceEnumerator device enumerator"
        );
       
        // Device interface pointer where we will dig the audio device endpoint
        Microsoft::WRL::ComPtr<IMMDevice> defaultDevice;
        
        checkErrors(
            deviceEnumerator->GetDefaultAudioEndpoint(
                eRender,          // Audio rendering stream. Audio data flows from the application to the audio endpoint device, which renders the stream. eCapture would be the opposite
                eConsole,         // The role that the system has assigned to an audio endpoint device. eConsole for games, system notification sounds, and voice commands
                &defaultDevice    // Pointer to default audio enpoint device
            ),
            "Error when trying to get a handle to the default audio enpoint"
        );
        
        checkErrors(
            defaultDevice->Activate(            // Creates a COM object with the specified interface.
                __uuidof(IAudioEndpointVolume),   // Reference to a GUID that identifies the interface that the caller requests be activated
                CLSCTX_INPROC_SERVER,             // Context in which the code that manages the newly created object will run (Same process).
                NULL,                             // Set NULL to activate the IAudioEndpointVolume endpoint https://msdn.microsoft.com/en-us/library/ms679029.aspx
                &this->device                           //  Pointer to a pointer variable into which the method writes the address of the interface specified by parameter iid. Through this method, the caller obtains a counted reference to the interface.
            ),
            "Error when trying to get a handle to the volume endpoint"
        );
        
        
    }

BOOL VolumeControl::isMuted() {
        BOOL muted = false;

        try{

        checkErrors(device->GetMute(&muted), "Error trying getting muted state");
        }
        catch (...) {
            std::cout << "Catched Error setting micrphone muted\n";
        }

        return muted;
    }

void  VolumeControl::setMuted(BOOL muted) {
    try
    {
        checkErrors(device->SetMute(muted, NULL), "setting mute");
    }
    catch (...)
    {
        std::cout << "Catched Error setting micrphone muted\n";
        

    }
        
    }

double  VolumeControl::getVolume() {
        float currentVolume = 0;

        try
        {            
            checkErrors(this->device->GetMasterVolumeLevelScalar(&currentVolume), "Error getting volume");
                    }
        catch (...)
        {
           
            std::cout << "Catched Error getting volume\n";
            return -1.0;
        }

       

        return (double)currentVolume;
    }

void  VolumeControl::setVolume(float volume) {
        if (volume < 0.0 || volume > 1.0) {
            //throw std::string("Volume needs to be between 0.0 and 1.0 inclusive");
            std::cout<<("Volume needs to be between 0.0 and 1.0 inclusive");
            return;
        }

        try {
            checkErrors(
                device->SetMasterVolumeLevelScalar(volume, NULL),
                "error setting volume"
            );
        }
        catch (...) {
            std::cout << "Catched Error setting volume\n";
        }

       

    }

VolumeControl::~VolumeControl() {
    //device->Release();
}





