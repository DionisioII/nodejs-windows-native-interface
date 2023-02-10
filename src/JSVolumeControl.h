
#include <napi.h>
#include <string>
#include "audio_control/audio_control.h"
#include <iostream>


class JSVolumeControl : public Napi::ObjectWrap<JSVolumeControl> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    JSVolumeControl(const Napi::CallbackInfo& info);
    static Napi::Value CreateNewItem(const Napi::CallbackInfo& info);

private:
    std::unique_ptr<VolumeControl> _VolumeControl_instance;
    Napi::Value isMuted(const Napi::CallbackInfo& info);
    Napi::Value setMuted(const Napi::CallbackInfo& info);
    Napi::Value getVolume(const Napi::CallbackInfo& info);
    Napi::Value setVolume(const Napi::CallbackInfo& info);
    Napi::Value getMicrophoneStatuses(const Napi::CallbackInfo& info);
};