
const proctorControls  = require('.\\build\\Release\\proctor_controls')
console.log(proctorControls)

JSVolumeControl = new proctorControls.JSVolumeControl()

JSVolumeControl.setMuted(false);
JSVolumeControl.setVolume(0.7)
console.log("\nvolume : " + JSVolumeControl.getVolume());



