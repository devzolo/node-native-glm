#include "mat4.hh"
Napi::FunctionReference Mat4::constructor;

Napi::Object Mat4::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "mat4", {
        // Register a class instance accessor with getter and setter functions.
        InstanceMethod("getAsFloat32Array", &Mat4::GetAsFloat32Array),
        InstanceMethod("mul", &Mat4::Mul)
    });

    Mat4::constructor = Napi::Persistent(func);
    Mat4::constructor.SuppressDestruct();
    exports.Set("mat4", func);

    return exports;
}

Mat4::Mat4(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Mat4>(info) {
    Napi::Env env = info.Env();
    if (info.Length() < 1) {
        this->value = glm::mat4(1.0f);

    }

    if (info.Length() == 1) {
        this->value = *info[0].As<Napi::External<glm::mat4>>().Data();
    }
}

glm::mat4 Mat4::GetValue() { return this->value; }

Napi::Value Mat4::GetAsFloat32Array(const Napi::CallbackInfo &info) {
    return Napi::External<float>::New(info.Env(), &this->value[0][0]);
}

Napi::Value Mat4::Mul(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value *= num;
        return Mat4::Create(info, &this->value);
    }

    JS_MAT4_ARG(0, vec);
    this->value *= vec->GetValue();
    return Mat4::Create(info, &this->value);
}
