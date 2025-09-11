#pragma once

#include <napi.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "vec2.hh"
#include "vec3.hh"
#include "vec4.hh"
#include "mat4.hh"

#define JS_GLM___________________________TODO(name) puts("TODO: GLM."#name)
#define JS_GLM_CONSTANT(name) exports.Set(Napi::String::New(env, #name), Napi::Number::New(env, GLUT_##name))
#define JS_GLM_SET_METHOD(name) exports.Set(Napi::String::New(env, #name), Napi::Function::New(env, name));
#define JS_ARGS(argc) \
if (info.Length() < argc) { \
  Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException(); \
  return env.Null(); \
}

#define JS_INT_ARG(pos, name) int32_t name = info[pos].As<Napi::Number>().Int32Value();
#define JS_LONG_ARG(pos, name) int64_t name = info[pos].As<Napi::Number>().Int64Value();
#define JS_UINT_ARG(pos, name) uint32_t name = info[pos].As<Napi::Number>().Uint32Value();
#define JS_STR_ARG(pos, name) std::string name = info[pos].As<Napi::String>().Utf8Value();
#define JS_DOUBLE_ARG(pos, name) double_t name = info[pos].As<Napi::Number>().DoubleValue();
#define JS_FLOAT_ARG(pos, name) float_t name = info[pos].As<Napi::Number>().FloatValue();
#define JS_PVOID_ARG(pos, name) void* name = (void*)info[pos].As<Napi::Number>().Int64Value();
#define JS_VEC2_ARG(pos, name) Vec2* name = Vec2::Unwrap(info[pos].As<Napi::Object>());
#define JS_VEC3_ARG(pos, name) Vec3* name = Vec3::Unwrap(info[pos].As<Napi::Object>());
#define JS_VEC4_ARG(pos, name) Vec4* name = Vec4::Unwrap(info[pos].As<Napi::Object>());
#define JS_MAT4_ARG(pos, name) Mat4* name = Mat4::Unwrap(info[pos].As<Napi::Object>());

#define JS_ARG_TYPE(pos, type)  if (!info[pos].Is##type()) { \
  Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException(); \
  return env.Null(); \
}


