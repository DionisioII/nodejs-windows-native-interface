
const win_native_interface  = require('.\\build\\Release\\win_native_interface')
console.log(win_native_interface)

JSVolumeControl = new win_native_interface.JSVolumeControl()
JSDisplayControl = new win_native_interface.JSDisplayControl()
JSProcessMonitor = new win_native_interface.JSProcessMonitor()
console.log(JSDisplayControl.getActiveDisplays())

JSVolumeControl.setMuted(false);
JSVolumeControl.setVolume(0.7)
console.log("\nvolume : " + JSVolumeControl.getVolume());
console.log(JSVolumeControl.getMicrophoneStatuses());
console.log("\nvolume : " + JSVolumeControl.getVolume());

console.log("\nprocesses : " + JSProcessMonitor.getActiveProcesses());



