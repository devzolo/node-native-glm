#pragma once

#include "glm.hh"

class Mat4 : public Napi::ObjectWrap<Mat4> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Mat4(const Napi::CallbackInfo &info);
    glm::mat4 GetValue();

    void SetValue(glm::mat4 mat) {
      this->value = mat;
    }

    static Napi::Value Create(const Napi::CallbackInfo &info, glm::mat4* mat) {
        Napi::External<glm::mat4> external = Napi::External<glm::mat4>::New(info.Env(), mat);
        return constructor.New({external});
    }

  private:
    static Napi::FunctionReference constructor;
    glm::mat4 value;

    Napi::Value GetAsFloat32Array(const Napi::CallbackInfo &info);
    Napi::Value Mul(const Napi::CallbackInfo& info);
};