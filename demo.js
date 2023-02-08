
const JSVolumeControl  = require('.\\build\\Release\\proctor_controls')
console.log(JSVolumeControl)

example = new JSVolumeControl.JSVolumeControl()

example.setMuted(false);
example.setVolume(0.7)
console.log("\nvolume : " + example.getVolume());



