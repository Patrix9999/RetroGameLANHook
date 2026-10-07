# Introduction

You propably tried to play some old games with builtin LAN Lobby (for example: `Settlers IV` or `Age of Mythology`).  
The problem with such games is that they pick up the network adapter that is using network connection, which is a big problem when you want to play with your friends over the internet.

## Why is that?

Most of these games rely on `WinSock.dll` or `WS2_32.dll` for socket-based networking. Some games may select the wrong network adapter when resolving the local hostname, which can prevent LAN functionality from working correctly.

To fix this problem, we need to tell the socket library to use the proper network adapter. We can do this by replacing the `gethostbyname` function with our own implementation.

In short, that's what **RetroGameLANHook** does: it replaces the `gethostbyname` function and makes sure that the IP address associated with the network adapter specified in the configuration is used.

## Configuration

Before using **RetroGameLANHook**, you need to configure it first.

To do this, create `RetroGameLANHook.ini` (or edit the file if you downloaded it from the **releases page**) and place it in the appropriate directory:

* **ASI plugin:** the same directory as `RetroGameLANHook.asi` (e.g. `GAME_EXE_DIR/plugins/`)
* **Proxy:** the game's main directory, next to the game's executable

Here's an example configuration with an explanation of what each option does:

```ini
[Settings]
; [REQUIRED] Adapter name that the game will use, you can get it from: Control Panel -> Network and Internet -> Network Connections, or just type ncpa.cpl in windows run bar (WINDOWS + R)
AdapterName = "Radmin VPN"
```

## How to use

### Proxy

> [!WARNING]
> The game must use **`wsock32.dll`** for the proxy to work. Some games use **`ws2_32.dll`** instead and are not compatible with the `wsock32.dll` proxy.

The proxy version can be used when you want to load the mod without an ASI Loader.

1. [Download](https://github.com/Patrix9999/RetroGameLANHook/releases) a release.
2. Download the `wsock32.dll` proxy and `RetroGameLANHook.ini` configuration file from the release.
3. Place both files in the game's main directory, next to the game's executable.
4. Make sure to follow the [configuration](#configuration) guide.
5. Start the game. The proxy will load automatically.

To uninstall the mod, remove the `wsock32.dll` proxy and `RetroGameLANHook.ini` from the game's directory.

### ASI Plugin

You need an ASI Loader to use this plugin. I recommend [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader), as it works with most games. You just need to pick one of the DLL files that your game uses and install it properly.

1. [Download](https://github.com/Patrix9999/RetroGameLANHook/releases) a release.
2. Unpack the files into your `plugins` directory.
3. Make sure to follow the [configuration](#configuration) guide.
4. Start the game. The mod will load automatically.

To uninstall the mod, remove `RetroGameLANHook.asi` from your `plugins` directory.

If, for some reason, your game doesn't support any DLL provided by the **ASI Loader**, you can use an injector instead. I recommend [Auto DLL Injector](https://sourceforge.net/projects/autodllinjector/); it is easy to use and allows you to inject the DLL automatically when the game starts.

If the game starts with administrator rights, be sure to run the injector as administrator as well, otherwise the DLL won't be injected.

# Contribute

The official repository of this project is available at: https://github.com/Patrix9999/RetroGameLANHook.

# Compile it yourself

1. Download and install `Visual Studio` with the `C++ toolchain` and `CMake Tools for Visual Studio`.
2. Open the project folder via `Visual Studio`
3. Pick the proper configuration, e.g: `Windows-x86-Release`
4. Build the project