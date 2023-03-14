# GBAdvanceulator
GBAdvanceulator is a Gameboy Advance emulator that runs on Linux. This program provides a GUI interface for the emulator.

## Prerequisites
To run this program, you will need the following dependencies:

X11 library

Xft library

Freetype library

QT5

p7zip

On Ubuntu or other debian with apt/apt-get, you can install these dependencies using the following command:

```csharp
sudo apt-get install libx11-dev libxft-dev libfreetype6-dev p7zip qt5-default
```

## Building and Running
To build this program, run the following command:

```make```

it will automaticaly compile, move assets and run the program

to compile for release, just run this command:

```make release```

it will drop a .7z file called Gameboy_Advanceulator in the root directory, make sure you have p7zip installed

## Controls
The emulator can be controlled using the following keyboard keys:

1: Open ROM (in the title screen) (not yet made)

2: Exit (in the title screen)

Up, Down, Left, Right: D-pad controls

Z, X: A and B buttons

## License
This program is licensed under the MIT License. See the [LICENSE]() file for details.

## NOTICE!
this is in heavy beta, and won't be avalabe for a while, please be patient whilst i program it!