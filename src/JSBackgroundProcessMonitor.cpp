#include "JSBackgroundProcessMonitor.h"


Napi::Object JSProcessMonitor::Init(Napi::Env env, Napi::Object exports) {
    // This method is used to hook the accessor and method callbacks
    Napi::Function func = DefineClass(env, "JSProcessMonitor", {
        InstanceMethod<&JSProcessMonitor::getActiveProcesses>("getActiveProcesses", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),

        });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();

    // Create a persistent reference to the class constructor. This will allow
    // a function called on a class prototype and a function
    // called on instance of a class to be distinguished from each other.
    *constructor = Napi::Persistent(func);
    exports.Set("JSProcessMonitor", func);

    // Store the constructor as the add-on instance data. This will allow this
    // add-on to support multiple instances of itself running on multiple worker
    // threads, as well as multiple instances of itself running in different
    // contexts on the same thread.
    //
    // By default, the value set on the environment here will be destroyed when
    // the add-on is unloaded using the `delete` operator, but it is also
    // possible to supply a custom deleter.
    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}


JSProcessMonitor::JSProcessMonitor(const Napi::CallbackInfo& info) :
    Napi::ObjectWrap<JSProcessMonitor>(info) {
    Napi::Env env = info.Env();
    // ...
    //Napi::Number value = info[0].As<Napi::Number>();
    this->_ProcessMonitor_instance = ProcessMonitor();
}

Napi::Value JSProcessMonitor::getActiveProcesses(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    //this->_VolumeControl_instance.isMuted();
    return Napi::String::New(env, this->_ProcessMonitor_instance.getActiveProcesses());
}








// Create a new item using the constructor stored during Init.
Napi::Value JSProcessMonitor::CreateNewItem(const Napi::CallbackInfo& info) {
    // Retrieve the instance data we stored during `Init()`. We only stored the
    // constructor there, so we retrieve it here to create a new instance of the
    // JS class the constructor represents.
    Napi::FunctionReference* constructor =
        info.Env().GetInstanceData<Napi::FunctionReference>();
    return constructor->New({  });
}
