#include <napi.h>
#include <string>
#include "display_control/display_control.h"
#include <iostream>


class JSDisplayControl : public Napi::ObjectWrap<JSDisplayControl> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    JSDisplayControl(const Napi::CallbackInfo& info);
    static Napi::Value CreateNewItem(const Napi::CallbackInfo& info);

private:
    std::unique_ptr< DisplayControl> _DisplayControl_instance;
    Napi::Value getActiveDisplays(const Napi::CallbackInfo& info);
    
   
};