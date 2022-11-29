# The Settlers 4 Gold Edition: LAN_Adapter Plugin

This plugin is forcing game to use only one network adapter specified in LAN_Adapter.ini file.  
The game itself works really well with finding games hosted on VPNs as hamachi, however if we host the game, it will assign the ip address of our local area network adapter.  
It's possible to bypass this issue by temporarily disabling your global network adapter, then creating the host room, and enabling back the network adapter (internet), however  
this is a little bit burdensome when you have to do it every time you want to host the game.  

The idea for the fix is simple, Settlers IV uses WinSock library as the backend for the networking.  
We could leverage that to our advantage by fooling the game to only see one, preferred network adapter.  
That way the game will automatically pickup VPN adapter.  
The small downside of this approach is that we won't be able to see games hosted on multiple networks at once,  
however it's still better than disabling LAN adapter and enabling it again.

**NOTE!** This plugin works only with The Settlers 4 Gold Edition (GoG version).

## How to use

You need an ASI Loader to use this mod. I recommend [The Settlers 4: ASI Loader](https://github.com/nyfrk/Settlers4-ASI-Loader) as it works nicely with the Gold and History Edition of The Settlers 4 and does not require any configuration. 

1. [Download](https://github.com/Patrix9999/Settlers4-LAN_Adapter/releases) a release.
2. Unpack the files into your `plugins` directory.
3. Edit `LAN_Adapter.ini` file, set `AdapterName` to the adapter that you want to be pickup by the game, you can get the adapter name from Control Panel/Network Connections
4. Start the game. The mod will load automatically.

To uninstall the mod remove `LAN_Adapter.asi` from your`plugins` directory. 

# Contribute

The official repository of this project is available at: https://github.com/Patrix9999/Settlers4-LAN_Adapter.

Compile it yourself
Download Visual Studio 2017 or 2019 with the C++ toolchain. The project is configured to build it with the Windows 10 compatible v143 toolchain. However, you should be able to change the toolchain to whatever you like. No additional libraries are required so it should compile out of the box.
