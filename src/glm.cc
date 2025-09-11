#include "glm.hh"

Napi::String helloMethod(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Value lookAt(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(3);
  JS_VEC3_ARG(0, position);
  JS_VEC3_ARG(1, target);
  JS_VEC3_ARG(2, up);

  glm::mat4 look = glm::lookAt(position->GetValue(), target->GetValue(), up->GetValue());
  return Mat4::Create(info, &look);
}

Napi::Value radians(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(1);
  JS_ARG_TYPE(0, Number);
  JS_FLOAT_ARG(0, degrees);

  return Napi::Number::New(env, glm::radians(degrees));
}

Napi::Value cross(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(2);
  JS_VEC3_ARG(0, vec1);
  JS_VEC3_ARG(1, vec2);

  glm::vec3 vecResult = glm::cross(vec1->GetValue(), vec2->GetValue());

  return Vec3::Create(info, &vecResult);
}

Napi::Value add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(2);
  JS_VEC3_ARG(0, vec1);
  JS_VEC3_ARG(1, vec2);

  glm::vec3 vecResult = vec1->GetValue() + vec2->GetValue();

  return Vec3::Create(info, &vecResult);
}

Napi::Value sub(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(2);
  JS_VEC3_ARG(0, vec1);
  JS_VEC3_ARG(1, vec2);

  glm::vec3 vecResult = vec1->GetValue() - vec2->GetValue();

  return Vec3::Create(info, &vecResult);
}

Napi::Value mult(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(2);
  JS_VEC3_ARG(0, vec1);
  JS_VEC3_ARG(1, vec2);

  glm::vec3 vecResult = vec1->GetValue() * vec2->GetValue();

  return Vec3::Create(info, &vecResult);
}

Napi::Value normalize(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(1);
  JS_VEC3_ARG(0, vec);

  glm::vec3 vecResult = glm::normalize(vec->GetValue());
  return Vec3::Create(info, &vecResult);
}

Napi::Value perspective(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(4);
  JS_ARG_TYPE(0, Number);
  JS_ARG_TYPE(1, Number);
  JS_ARG_TYPE(2, Number);
  JS_ARG_TYPE(3, Number);
  JS_FLOAT_ARG(0, fov);
  JS_FLOAT_ARG(1, aspect);
  JS_FLOAT_ARG(2, near);
  JS_FLOAT_ARG(3, far);

  glm::mat4 perspectiveMatrix = glm::perspective(fov, aspect, near, far);
  return Mat4::Create(info, &perspectiveMatrix);
}

Napi::Value translate(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  JS_ARGS(2);
  JS_MAT4_ARG(0, mat);
  JS_VEC3_ARG(1, vec);

  glm::mat4 translateMatrix = glm::translate(mat->GetValue(), vec->GetValue());
  return Mat4::Create(info, &translateMatrix);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  JS_GLM_SET_METHOD(helloMethod);
  JS_GLM_SET_METHOD(lookAt);
  JS_GLM_SET_METHOD(cross);
  JS_GLM_SET_METHOD(radians);
  JS_GLM_SET_METHOD(normalize);
  JS_GLM_SET_METHOD(add);
  JS_GLM_SET_METHOD(sub);
  JS_GLM_SET_METHOD(mult);
  JS_GLM_SET_METHOD(perspective);
  JS_GLM_SET_METHOD(translate);
  Vec2::Init(env, exports);
  Vec3::Init(env, exports);
  Mat4::Init(env, exports);

  return exports;
}

NODE_API_MODULE(hello, Init)
