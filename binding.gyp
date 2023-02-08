{
  "targets": [
    {
      "target_name": "proctor_controls",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/audio_control/audio_control.cpp",
        "./src/audio_control/audio_control.h",
        "./src/index.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
    }
  ]
}