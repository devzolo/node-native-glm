#include "vec3.hh";

Napi::FunctionReference Vec3::constructor;
Napi::Object Vec3::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "vec3", {
        // Register a class instance accessor with getter and setter functions.
        InstanceAccessor("x", &Vec3::GetX, &Vec3::SetX),
        InstanceAccessor("y", &Vec3::GetY, &Vec3::SetY),
        InstanceAccessor("z", &Vec3::GetZ, &Vec3::SetZ),
        InstanceMethod("add", &Vec3::Add),
        InstanceMethod("sub", &Vec3::Sub),
        InstanceMethod("mul", &Vec3::Mul),
        InstanceMethod("div", &Vec3::Div),
        InstanceMethod("copy", &Vec3::Copy)
    });

    Vec3::constructor = Napi::Persistent(func);
    Vec3::constructor.SuppressDestruct();
    exports.Set("vec3", func);

    return exports;
}

Napi::Value Vec3::Add(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value += num;
        return Vec3::Create(info, &this->value);
    }

    JS_VEC3_ARG(0, vec);
    this->value += vec->GetValue();
    return Vec3::Create(info, &this->value);
}

Napi::Value Vec3::Sub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value -= num;
        return Vec3::Create(info, &this->value);
    }

    JS_VEC3_ARG(0, vec);
    this->value -= vec->GetValue();
    return Vec3::Create(info, &this->value);
}

Napi::Value Vec3::Mul(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value *= num;
        return Vec3::Create(info, &this->value);
    }

    JS_VEC3_ARG(0, vec);
    this->value *= vec->GetValue();
    return Vec3::Create(info, &this->value);
}

Napi::Value Vec3::Div(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    JS_ARGS(1);

    if (info[0].IsNumber()) {
        JS_FLOAT_ARG(0, num);
        this->value /= num;
        return Vec3::Create(info, &this->value);
    }

    JS_VEC3_ARG(0, vec);
    this->value /= vec->GetValue();
    return Vec3::Create(info, &this->value);
}

Napi::Value Vec3::Copy(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    return Vec3::Create(info, &this->value);
}
Vec3::Vec3(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Vec3>(info) {
    Napi::Env env = info.Env();

    if(info.Length() < 1) {
        this->value = glm::vec3(0,0,0);
    } else if(info.Length() == 1) {
        this->value = *info[0].As<Napi::External<glm::vec3>>().Data();
    } else {
        Napi::Number x = info[0].As<Napi::Number>();
        Napi::Number y = info[1].As<Napi::Number>();
        Napi::Number z = info[2].As<Napi::Number>();
        this->value = glm::vec3(x, y, z);
    }
}


Napi::Value Vec3::GetX(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.x);
}

void Vec3::SetX(const Napi::CallbackInfo &info, const Napi::Value &value) {
    Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.x = arg.FloatValue();
}

Napi::Value Vec3::GetY(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.y);
}

void Vec3::SetY(const Napi::CallbackInfo &info, const Napi::Value &value) {
    Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.y = arg.FloatValue();
}

Napi::Value Vec3::GetZ(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->value.z);
}

void Vec3::SetZ(const Napi::CallbackInfo &info, const Napi::Value &value) {
    Napi::Env env = info.Env();
    Napi::Number arg = value.As<Napi::Number>();
    this->value.z = arg.FloatValue();
}


