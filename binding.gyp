{
  "targets": [
    {
      "target_name": "win_native_interface",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/audio_control/audio_control.cpp",
        "./src/audio_control/audio_control.h",
        "./src/display_control/display_control.cpp",
        "./src/display_control/display_control.h",
        "./src/background_process_monitor/background_process_monitor.cpp",
        "./src/background_process_monitor/background_process_monitor.h",
        "./src/JSVolumeControl.cpp",
        "./src/JSVolumeControl.h",
        "./src/JSDisplayControl.cpp",
        "./src/JSDisplayControl.h",
        "./src/JSBackgroundProcessMonitor.cpp",
        "./src/JSBackgroundProcessMonitor.h",
        "./src/index.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
    }
  ]
}