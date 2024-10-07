# Native Node.js  Interface for Windows

Integrate windows native APIs in cpp to your nodejs application.

 - List all active Displays (external monitors attached to the machine)
 - List all available microphones, mute them, set volume, get volume level
 - get a list of all applications running in the background of your windows machine

## How to Use
```javascript
const win_native_interface  = require('.\\build\\Release\\nodejs-windows-process-monitor')
console.log(win_native_interface)

JSVolumeControl = new win_native_interface.JSVolumeControl()
JSDisplayControl = new win_native_interface.JSDisplayControl()
JSProcessMonitor = new win_native_interface.JSProcessMonitor()

//Examples
JSVolumeControl.setMuted(false);
JSVolumeControl.setVolume(0.7)
console.log(JSVolumeControl.getMicrophoneStatuses());
console.log("processes : " + ProcessMonitor.getActiveProcesses());
```


# Native Node.js Process Monitor for Windows

A native Windows API binding to have a list of running processes on windows.

## How to Use
```javascript
const Controls  = require('.\\build\\Release\\nodejs-windows-process-monitor')
console.log(Controls)

ProcessMonitor = new Controls.JSProcessMonitor()


console.log("processes : " + ProcessMonitor.getActiveProcesses());
```
#### Note
Returns list of comma separated active process running in windows.

## Development

#### node-gyp install for node version <= [17.9.1]
To build the project you need in Windows to install [windows-build-tools](https://github.com/felixrieseberg/windows-build-tools) in an elevated PowerShell prompt `npm install --global --production windows-build-tools` and then `npm install` or if you have `node-gyp` installed globally

#### node-gyp install for node version >= [17.9.1]
`npm install -g node-gyp`

#### Build

```bash
$ node-gyp configure
$ node-gyp build

```
#### Run
The repository contains a demo of the usage
```bash
$ node demo.js
```

