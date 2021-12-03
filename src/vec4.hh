#pragma once

#include "glm.hh"

class Vec4 : public Napi::ObjectWrap<Vec4> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Vec4(const Napi::CallbackInfo &info);
    glm::vec4 GetValue() { return this->value; };

    static Napi::Value Create(const Napi::CallbackInfo &info, glm::vec4* vec) {
        Napi::External<glm::vec4> external = Napi::External<glm::vec4>::New(info.Env(), vec);

        return constructor.New({external});
    }

  private:
    static Napi::FunctionReference constructor;
    glm::vec4 value;

    Napi::Value GetX(const Napi::CallbackInfo &info);
    void SetX(const Napi::CallbackInfo &info, const Napi::Value &value);

    Napi::Value GetY(const Napi::CallbackInfo &info);
    void SetY(const Napi::CallbackInfo &info, const Napi::Value &value);

    Napi::Value GetZ(const Napi::CallbackInfo &info);
    void SetZ(const Napi::CallbackInfo &info, const Napi::Value &value);

    Napi::Value GetW(const Napi::CallbackInfo &info);
    void SetW(const Napi::CallbackInfo &info, const Napi::Value &value);

    Napi::Value Add(const Napi::CallbackInfo& info);
    Napi::Value Sub(const Napi::CallbackInfo& info);
    Napi::Value Mul(const Napi::CallbackInfo& info);
    Napi::Value Div(const Napi::CallbackInfo& info);
    Napi::Value Copy(const Napi::CallbackInfo& info);
};
