#include "JSVolumeControl.h"



Napi::Object JSVolumeControl::Init(Napi::Env env, Napi::Object exports) {
    // This method is used to hook the accessor and method callbacks
    Napi::Function func = DefineClass(env, "JSVolumeControl", {
        InstanceMethod<&JSVolumeControl::isMuted>("isMuted", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        InstanceMethod<&JSVolumeControl::setMuted>("setMuted", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        InstanceMethod<&JSVolumeControl::getVolume>("getVolume", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        InstanceMethod<&JSVolumeControl::setVolume>("setVolume", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        InstanceMethod<&JSVolumeControl::getMicrophoneStatuses>("getMicrophoneStatuses", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        StaticMethod<&JSVolumeControl::CreateNewItem>("CreateNewItem", static_cast<napi_property_attributes>(napi_writable | napi_configurable)),
        });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();

    // Create a persistent reference to the class constructor. This will allow
    // a function called on a class prototype and a function
    // called on instance of a class to be distinguished from each other.
    *constructor = Napi::Persistent(func);
    exports.Set("JSVolumeControl", func);

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


JSVolumeControl::JSVolumeControl(const Napi::CallbackInfo& info) :
    Napi::ObjectWrap<JSVolumeControl>(info) {
    Napi::Env env = info.Env();
    // ...
    //Napi::Number value = info[0].As<Napi::Number>();
    this->_VolumeControl_instance = std::make_unique < VolumeControl>();
}

Napi::Value JSVolumeControl::isMuted(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    //this->_VolumeControl_instance.isMuted();
    return Napi::Number::New(env, this->_VolumeControl_instance->isMuted());
}

Napi::Value JSVolumeControl::setMuted(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Number value = info[0].As<Napi::Number>();
    this->_VolumeControl_instance->setMuted(value.ToBoolean());
    return Napi::Number::New(env, this->_VolumeControl_instance->isMuted());
}

Napi::Value JSVolumeControl::getVolume(const Napi::CallbackInfo& info) {

    //Napi::Number value = info[0].As<Napi::Number>();
    //this->_VolumeControl_instance.setMuted(value.ToBoolean());
    try
    {
        Napi::Env env = info.Env();
        return Napi::Number::New(env, this->_VolumeControl_instance->getVolume());
    }
    catch (const std::exception&)
    {
        Napi::Env env = info.Env();
        std::cout << "error getting volume\n";
        return Napi::Number::New(env, -1.0);

    }

}

Napi::Value JSVolumeControl::setVolume(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Number value = info[0].As<Napi::Number>();
    this->_VolumeControl_instance->setVolume(value.DoubleValue());
    return Napi::Number::New(env, this->_VolumeControl_instance->getVolume());
}


Napi::Value JSVolumeControl::getMicrophoneStatuses(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    //Napi::Number value = info[0].As<Napi::Number>();
    std::wstring str = this->_VolumeControl_instance->getMicrophoneStatuses();

    return Napi::String::New(env, ((char16_t*)str.c_str()));
}

// Create a new item using the constructor stored during Init.
Napi::Value JSVolumeControl::CreateNewItem(const Napi::CallbackInfo& info) {
    // Retrieve the instance data we stored during `Init()`. We only stored the
    // constructor there, so we retrieve it here to create a new instance of the
    // JS class the constructor represents.
    Napi::FunctionReference* constructor =
        info.Env().GetInstanceData<Napi::FunctionReference>();
    return constructor->New({  });
}