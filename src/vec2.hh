#pragma once

#include "glm.hh"

class Vec2 : public Napi::ObjectWrap<Vec2> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Vec2(const Napi::CallbackInfo &info);
    glm::vec2 GetValue() { return this->value; };

  private:
    static Napi::FunctionReference constructor;
    glm::vec2 value;
    
    Napi::Value GetX(const Napi::CallbackInfo &info);
    void SetX(const Napi::CallbackInfo &info, const Napi::Value &value);

    Napi::Value GetY(const Napi::CallbackInfo &info);
    void SetY(const Napi::CallbackInfo &info, const Napi::Value &value);
};