#include <napi.h>
#include <string>

#include "background_process_monitor\background_process_monitor.h"
#include <iostream>





class JSProcessMonitor : public Napi::ObjectWrap<JSProcessMonitor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    JSProcessMonitor(const Napi::CallbackInfo& info);
    static Napi::Value CreateNewItem(const Napi::CallbackInfo& info);

private:
    ProcessMonitor _ProcessMonitor_instance;
    Napi::Value getActiveProcesses(const Napi::CallbackInfo& info);

};




