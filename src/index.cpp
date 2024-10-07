#include <napi.h>
#include <string>
#include "audio_control/audio_control.h"
#include <iostream>

#include "JSVolumeControl.h"
#include "JSDisplayControl.h"
#include "JSBackgroundProcessMonitor.h"







// callback method when module is registered with Node.js
Napi::Object Init(Napi::Env env, Napi::Object exports) {

    JSVolumeControl::Init(env, exports);
    JSDisplayControl::Init(env, exports);
    JSProcessMonitor::Init(env, exports);

        
    // return `exports` object (always)
    return exports;
}




NODE_API_MODULE(win_native_interface, Init)
