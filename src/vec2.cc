#include "vec2.hh"

Napi::Object Vec2::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "vec2", {
        // Register a class instance accessor with getter and setter functions.
        InstanceAccessor("x", &Vec2::GetX, &Vec2::SetX),
        InstanceAccessor("y", &Vec2::GetY, &Vec2::SetY)
    });

    Vec2::constructor = Napi::Persistent(func);
    Vec2::constructor.SuppressDestruct();
    exports.Set("vec2", func);

    return exports;
}

Vec2::Vec2(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Vec2>(info) {
    // Napi::Env env = info.Env();

    Napi::Number x = info[0].As<Napi::Number>();
    Napi::Number y = info[1].As<Napi::Number>();
    this->value = glm::vec2(x, y);
}

Napi::FunctionReference Vec2::constructor;

Napi::Value Vec2::GetX(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.x);
}

void Vec2::SetX(const Napi::CallbackInfo &info, const Napi::Value &value) {
    // Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.x = arg.FloatValue();
}

Napi::Value Vec2::GetY(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.y);
}

void Vec2::SetY(const Napi::CallbackInfo &info, const Napi::Value &value) {
    // Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.y = arg.FloatValue();
}

