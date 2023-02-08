//const addon = require( 'D:\\Librerie\\node_libraries\\projects\\emoj_proctor_win_addon\\build\\Release\\proctor_controls' );
//console.log( addon.testFunction( 'World' ) );



//const JSVolumeControl  = require('D:\\Librerie\\node_libraries\\projects\\emoj_proctor_win_addon\\build\\Release\\proctor_controls')
const JSVolumeControl  = require('.\\build\\Release\\proctor_controls')
console.log(JSVolumeControl)

example = new JSVolumeControl.JSVolumeControl()

example.setMuted(false);
example.setVolume(0.7)
console.log("\nvolume : " + example.getVolume());



