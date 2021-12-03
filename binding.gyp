{
  'variables': {
    'platform': '<(OS)',
    'build_arch': '<!(node -p "process.arch")',
    'build_win_platform': '<!(node -p "process.arch==\'ia32\'?\'Win32\':process.arch")',
  },
  'conditions': [
    # Replace gyp platform with node platform, blech
    ['platform == "mac"', {'variables': {'platform': 'darwin'}}],
    ['platform == "win"', {'variables': {'platform': 'win32'}}],
  ],
  'targets': [
    {
      'target_name': 'native-glm',
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      'sources': [
        'src/glm.hh',
        'src/glm.cc',
        'src/vec2.hh',
        'src/vec2.cc',
        'src/vec3.hh',
        'src/vec3.cc',
        'src/vec4.hh',
        'src/vec4.cc',
        'src/mat4.hh',
        'src/mat4.cc'
      ],
      'defines' : ['NAPI_DISABLE_CPP_EXCEPTIONS','UNICODE'],
      'libraries': [],
      "include_dirs": [
        "./deps/glm-0.9.9.8/glm",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'library_dirs' : [],
    },
    {
      "target_name": "copy_modules",
      "type":"none",
      "dependencies" : [ "native-glm" ],
      "copies":[
        {
          'destination': '<(module_root_dir)/bin/<(platform)/<(target_arch)',
          'files': [
            '<(module_root_dir)/build/Release/native-glm.node',
          ]
        },
        {
          'destination': '<(module_root_dir)/dist',
          'files': [
            '<(module_root_dir)/src/types/index.d.ts',
          ]
        },
        {
          'destination': '<(module_root_dir)/../node-native-engine/node_modules/@devzolo/node-native-glm/bin/<(platform)/<(target_arch)',
          'files': [
            '<(module_root_dir)/build/Release/native-glm.node',
          ]
        },
        {
          'destination': '<(module_root_dir)/../node-native-engine/node_modules/@devzolo/node-native-glm/dist',
          'files': [
            '<(module_root_dir)/src/types/index.d.ts',
          ]
        },
      ]
    }
  ]
}
