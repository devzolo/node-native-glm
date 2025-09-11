#include "vec4.hh"

Napi::FunctionReference Vec4::constructor;
Napi::Object Vec4::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "vec4", {
        InstanceAccessor("x", &Vec4::GetX, &Vec4::SetX),
        InstanceAccessor("y", &Vec4::GetY, &Vec4::SetY),
        InstanceAccessor("z", &Vec4::GetZ, &Vec4::SetZ),
        InstanceAccessor("w", &Vec4::GetW, &Vec4::SetW),
        InstanceAccessor("r", &Vec4::GetX, &Vec4::SetX),
        InstanceAccessor("g", &Vec4::GetY, &Vec4::SetY),
        InstanceAccessor("b", &Vec4::GetZ, &Vec4::SetZ),
        InstanceAccessor("a", &Vec4::GetW, &Vec4::SetW),
        InstanceMethod("add", &Vec4::Add),
        InstanceMethod("sub", &Vec4::Sub),
        InstanceMethod("mul", &Vec4::Mul),
        InstanceMethod("div", &Vec4::Div),
        InstanceMethod("copy", &Vec4::Copy)
    });

    Vec4::constructor = Napi::Persistent(func);
    Vec4::constructor.SuppressDestruct();
    exports.Set("vec4", func);

    return exports;
}

Napi::Value Vec4::Add(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value += num;
        return Vec4::Create(info, &this->value);
    }

    JS_VEC4_ARG(0, vec);
    this->value += vec->GetValue();
    return Vec4::Create(info, &this->value);
}

Napi::Value Vec4::Sub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value -= num;
        return Vec4::Create(info, &this->value);
    }

    JS_VEC4_ARG(0, vec);
    this->value -= vec->GetValue();
    return Vec4::Create(info, &this->value);
}

Napi::Value Vec4::Mul(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value *= num;
        return Vec4::Create(info, &this->value);
    }

    JS_VEC4_ARG(0, vec);
    this->value *= vec->GetValue();
    return Vec4::Create(info, &this->value);
}

Napi::Value Vec4::Div(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value /= num;
        return Vec4::Create(info, &this->value);
    }

    JS_VEC4_ARG(0, vec);
    this->value /= vec->GetValue();
    return Vec4::Create(info, &this->value);
}

Napi::Value Vec4::Copy(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Vec4::Create(info, &this->value);
}

Vec4::Vec4(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Vec4>(info) {
    Napi::Env env = info.Env();

    if(info.Length() < 1) {
        this->value = glm::vec4(0,0,0,0);
    } else if(info.Length() == 1) {
        this->value = *info[0].As<Napi::External<glm::vec4>>().Data();
    } else {
        Napi::Number x = info[0].As<Napi::Number>();
        Napi::Number y = info[1].As<Napi::Number>();
        Napi::Number z = info[2].As<Napi::Number>();
        Napi::Number w = info[3].As<Napi::Number>();
        this->value = glm::vec4(x, y, z, w);
    }
}


Napi::Value Vec4::GetX(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.x);
}

void Vec4::SetX(const Napi::CallbackInfo &info, const Napi::Value &value) {
    Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.x = arg.FloatValue();
}

Napi::Value Vec4::GetY(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.y);
}

void Vec4::SetY(const Napi::CallbackInfo &info, const Napi::Value &value) {
    Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.y = arg.FloatValue();
}

Napi::Value Vec4::GetZ(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.z);
}

void Vec4::SetZ(const Napi::CallbackInfo &info, const Napi::Value &value) {
    Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.z = arg.FloatValue();
}

Napi::Value Vec4::GetW(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.w);
}

void Vec4::SetW(const Napi::CallbackInfo &info, const Napi::Value &value) {
    Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.w = arg.FloatValue();
}

