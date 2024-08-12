# Introduction

You propably tried to play some old games with builtin LAN Lobby (for example: `Settlers IV` or `Age of Mythology`).  
The problem with such games is that they pick up the network adapter that is using network connection, which is a big problem when you want to play with your friends over the internet.

Why is that? Most of those games rely on `WinSock.dll` or `WS2_32.dll`, which is a socket networking protocol, most of those game that do have the described problem above use it.  
To fix this problem, we need to tell the `sockets library` to use proper adapter, we can do that by replacing `gethostbyname` function with our own.

In short, that's all that my **ASI plugin** does, it replaces the `gethostbyname` function with my own, in which i make sure to use the network adapter that we want to find.

# Configuration

Before you start using this **ASI plugin**, you need to configure it first.  
To do that, create the `RetroGameLANHook.ini` (or edit it if you've downloaded it from **releases page**) and place it in the same directory as `RetroGameLANHook.asi` (e.g: `GAME_EXE_DIR/plugins/`).  
Here's the example config with explanation what each options does:

```ini
[Settings]
; [REQUIRED] Adapter name that the game will use, you can get it from: Control Panel -> Network and Internet -> Network Connections, or just type ncpa.cpl in windows run bar (WINDOWS + R)
AdapterName = "Radmin VPN"
```

## How to use

You need an ASI Loader to use this plugin. I recommend [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) as it works with most of the games, you just need to pick one of the dll files that your game uses and replace it properly.  

If for some reason your game doesn't support any dll provided by the **ASI Loader**, you need to use injector, i can recommend [Auto DLL Injector](https://sourceforge.net/projects/autodllinjector/), it's easy to use and allows you to inject the dll automatically when game starts.  
If the game starts with admin rights, be sure to run the injector also as admin, otherwise dll won't be injected.

1. [Download](https://github.com/Patrix9999/RetroGameLANHook/releases) a release.
2. Unpack the files into your `plugins` directory.
3. Make sure to follow [configuration](#Configuration) guide.
4. Start the game. The mod will load automatically.

To uninstall the mod remove `RetroGameLANHook.asi` from your `plugins` directory. 

# Contribute

The official repository of this project is available at: https://github.com/Patrix9999/RetroGameLANHook.

# Compile it yourself

1. Download and install `Visual Studio` with the `C++ toolchain` and `CMake Tools for Visual Studio`.
2. Open the project folder via `Visual Studio`
3. Pick the proper configuration, e.g: `Windows-x86-Release`
4. Build the project