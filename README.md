
# react-native-yeefx

## Getting started

`$ npm install react-native-yeefx --save`

### Mostly automatic installation

`$ react-native link react-native-yeefx`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-yeefx` and add `RNYeefxReactNative.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNYeefxReactNative.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.yeefx.react.RNYeefxReactNativePackage;` to the imports at the top of the file
  - Add `new RNYeefxReactNativePackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-yeefx'
  	project(':react-native-yeefx').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-yeefx/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-yeefx')
  	```


## Usage
```javascript
import RNYeefxReactNative from 'react-native-yeefx';

// TODO: What to do with the module?
RNYeefxReactNative;
```
  