
const proctorControls  = require('.\\build\\Release\\proctor_controls')
console.log(proctorControls)

JSVolumeControl = new proctorControls.JSVolumeControl()
JSDisplayControl = new proctorControls.JSDisplayControl

console.log(JSDisplayControl.getActiveDisplays())

JSVolumeControl.setMuted(false);
JSVolumeControl.setVolume(0.7)
console.log("\nvolume : " + JSVolumeControl.getVolume());
console.log(JSVolumeControl.getMicrophoneStatuses());
console.log("\nvolume : " + JSVolumeControl.getVolume());



