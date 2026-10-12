#define PROXY_DLL_NAME "winmm.dll"
#include "proxy.hpp"

#include "patch_gethostbyname.hpp"
#include <mmsyscom.h>

#define DLLEXPORT __declspec(dllexport)

// predeclarations

struct tagAUXCAPSA;
struct tagAUXCAPSW;

using LPAUXCAPSA = tagAUXCAPSA*;
using LPAUXCAPSW = tagAUXCAPSW*;

struct tagJOYCAPSA;
struct tagJOYCAPSW;

using LPJOYCAPSA = tagJOYCAPSA*;
using LPJOYCAPSW = tagJOYCAPSW*;

struct joyinfo_tag;
struct joyinfoex_tag;

using LPJOYINFO = joyinfo_tag*;
using LPJOYINFOEX = joyinfoex_tag*;

struct midihdr_tag;
using LPMIDIHDR = midihdr_tag*;

struct tagMIDIINCAPSA;
struct tagMIDIINCAPSW;

using LPMIDIINCAPSA = tagMIDIINCAPSA*;
using LPMIDIINCAPSW = tagMIDIINCAPSW*;

struct tagMIDIOUTCAPSA;
struct tagMIDIOUTCAPSW;

using LPMIDIOUTCAPSA = tagMIDIOUTCAPSA*;
using LPMIDIOUTCAPSW = tagMIDIOUTCAPSW*;

struct tMIXERCONTROLDETAILS;
using LPMIXERCONTROLDETAILS = tMIXERCONTROLDETAILS*;

struct tagMIXERCAPSA;
struct tagMIXERCAPSW;

using LPMIXERCAPSA = tagMIXERCAPSA*;
using LPMIXERCAPSW = tagMIXERCAPSW*;

struct tagMIXERLINECONTROLSA;
struct tagMIXERLINECONTROLSW;

using LPMIXERLINECONTROLSA = tagMIXERLINECONTROLSA*;
using LPMIXERLINECONTROLSW = tagMIXERLINECONTROLSW*;

struct tagMIXERLINEA;
struct tagMIXERLINEW;

using LPMIXERLINEA = tagMIXERLINEA*;
using LPMIXERLINEW = tagMIXERLINEW*;

typedef DWORD (WINAPI *DRIVERMSGPROC)(DWORD, DWORD, DWORD_PTR, DWORD_PTR, DWORD_PTR);

typedef void(TASKCALLBACK)(DWORD_PTR dwInst);
typedef TASKCALLBACK *LPTASKCALLBACK;

struct _MMIOINFO;
using LPMMIOINFO = _MMIOINFO*;

struct _MMCKINFO;
using MMCKINFO = _MMCKINFO;
using LPMMCKINFO = _MMCKINFO*;

typedef LRESULT (CALLBACK MMIOPROC)(LPSTR lpmmioinfo, UINT uMsg, LPARAM lParam1, LPARAM lParam2);
typedef MMIOPROC *LPMMIOPROC;

struct _MMIOINFO;
using MMIOINFO = _MMIOINFO;
using LPMMIOINFO = _MMIOINFO*;
typedef const MMIOINFO *LPCMMIOINFO;

struct timecaps_tag;
using LPTIMECAPS = timecaps_tag*;

typedef void (CALLBACK TIMECALLBACK)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
typedef TIMECALLBACK *LPTIMECALLBACK;

struct wavehdr_tag;
using LPWAVEHDR = wavehdr_tag*;

struct tagWAVEINCAPSA;
struct tagWAVEINCAPSW;

using LPWAVEINCAPSA = tagWAVEINCAPSA*;
using LPWAVEINCAPSW = tagWAVEINCAPSW*;

struct tWAVEFORMATEX;
using WAVEFORMATEX = tWAVEFORMATEX*;
typedef const WAVEFORMATEX *LPCWAVEFORMATEX;

struct tagWAVEOUTCAPSA;
struct tagWAVEOUTCAPSW;

using LPWAVEOUTCAPSA = tagWAVEOUTCAPSA*;
using LPWAVEOUTCAPSW = tagWAVEOUTCAPSW*;

extern "C"
{
	DLLEXPORT BOOL WINAPI PlaySound_Unnamed(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound) { return CALL_ORIGINAL_FUNC_AS(PlaySound_Unnamed, PlaySoundA)(pszSound, hmod, fdwSound); }
	DLLEXPORT BOOL WINAPI mciExecute(LPCSTR pszCommand) { return CALL_ORIGINAL_FUNC(mciExecute)(pszCommand); }
	DLLEXPORT LRESULT WINAPI CloseDriver(HDRVR hDriver, LPARAM lParam1, LPARAM lParam2) { return CALL_ORIGINAL_FUNC(CloseDriver)(hDriver, lParam1, lParam2); }
	DLLEXPORT LRESULT WINAPI DefDriverProc(DWORD_PTR dwDriverIdentifier, HDRVR hdrvr, UINT uMsg, LPARAM lParam1, LPARAM lParam2) { return CALL_ORIGINAL_FUNC(DefDriverProc)(dwDriverIdentifier, hdrvr, uMsg, lParam1, lParam2); }
	DLLEXPORT BOOL WINAPI DriverCallback(DWORD_PTR dwCallback, DWORD dwFlags, HDRVR hDevice, DWORD dwMsg, DWORD_PTR dwUser, DWORD_PTR dwParam1, DWORD_PTR dwParam2) { return CALL_ORIGINAL_FUNC(DriverCallback)(dwCallback, dwFlags, hDevice, dwMsg, dwUser, dwParam1, dwParam2); }
	DLLEXPORT HMODULE WINAPI DrvGetModuleHandle(HDRVR hDriver) { return CALL_ORIGINAL_FUNC(DrvGetModuleHandle)(hDriver); }
	DLLEXPORT HMODULE WINAPI GetDriverModuleHandle(HDRVR hDriver) { return CALL_ORIGINAL_FUNC(GetDriverModuleHandle)(hDriver); }
	DLLEXPORT DWORD WINAPI NotifyCallbackData(UINT uDevID, UINT uMsg, DWORD dwInstance, DWORD dwParam1, LPVOID callbackDataPtr) { return CALL_ORIGINAL_FUNC(NotifyCallbackData)(uDevID, uMsg, dwInstance, dwParam1, callbackDataPtr); };
	DLLEXPORT HDRVR WINAPI OpenDriver(LPCWSTR szDriverName, LPCWSTR szSectionName, LPARAM lParam2) { return CALL_ORIGINAL_FUNC(OpenDriver)(szDriverName, szSectionName, lParam2); }
	DLLEXPORT BOOL WINAPI PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound) { return CALL_ORIGINAL_FUNC(PlaySound)(pszSound, hmod, fdwSound); }
	DLLEXPORT BOOL WINAPI PlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound) { return CALL_ORIGINAL_FUNC(PlaySoundA)(pszSound, hmod, fdwSound); }
	DLLEXPORT BOOL WINAPI PlaySoundW(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound) { return CALL_ORIGINAL_FUNC(PlaySoundW)(pszSound, hmod, fdwSound); }
	DLLEXPORT LRESULT WINAPI SendDriverMessage(HDRVR hDriver, UINT message, LPARAM lParam1, LPARAM lParam2) { return CALL_ORIGINAL_FUNC(SendDriverMessage)(hDriver, message, lParam1, lParam2); }
	DLLEXPORT BOOL WINAPI WOW32DriverCallback(DWORD dwCallback, DWORD dwFlags, WORD wID, WORD wMsg, DWORD dwUser, DWORD dw1, DWORD dw2) { return CALL_ORIGINAL_FUNC(WOW32DriverCallback)(dwCallback, dwFlags, wID, wMsg, dwUser, dw1, dw2); }
	DLLEXPORT BOOL WINAPI WOW32ResolveMultiMediaHandle(UINT uHandleType, UINT uMappingDirection, WORD wHandle16_In, LPWORD lpwHandle16_Out, DWORD dwHandle32_In, LPDWORD lpdwHandle32_Out) { return CALL_ORIGINAL_FUNC(WOW32ResolveMultiMediaHandle)(uHandleType, uMappingDirection, wHandle16_In, lpwHandle16_Out, dwHandle32_In, lpdwHandle32_Out); }
	DLLEXPORT void WOWAppExit(HANDLE hTask) { return CALL_ORIGINAL_FUNC(WOWAppExit)(hTask); }
	DLLEXPORT DWORD WINAPI aux32Message(UINT uDeviceID, UINT uMessage, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(aux32Message)(uDeviceID, uMessage, dwInstance, dwParam1, dwParam2); }
	DLLEXPORT MMRESULT WINAPI auxGetDevCapsA(UINT_PTR uDeviceID, LPAUXCAPSA pac, UINT cbac) { return CALL_ORIGINAL_FUNC(auxGetDevCapsA)(uDeviceID, pac, cbac); }
	DLLEXPORT MMRESULT WINAPI auxGetDevCapsW(UINT_PTR uDeviceID, LPAUXCAPSW pac, UINT cbac) { return CALL_ORIGINAL_FUNC(auxGetDevCapsW)(uDeviceID, pac, cbac); }
	DLLEXPORT UINT WINAPI auxGetNumDevs() { return CALL_ORIGINAL_FUNC(auxGetNumDevs)(); }
	DLLEXPORT MMRESULT WINAPI auxGetVolume(UINT uDeviceID, LPDWORD pdwVolume) { return CALL_ORIGINAL_FUNC(auxGetVolume)(uDeviceID, pdwVolume); }
	DLLEXPORT MMRESULT WINAPI auxOutMessage(UINT uDeviceID, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) { return CALL_ORIGINAL_FUNC(auxOutMessage)(uDeviceID, uMsg, dw1, dw2); }
	DLLEXPORT MMRESULT WINAPI auxSetVolume(UINT uDeviceID, DWORD dwVolume) { return CALL_ORIGINAL_FUNC(auxSetVolume)(uDeviceID, dwVolume); }
	DLLEXPORT DWORD WINAPI joy32Message(UINT uID, UINT uMessage, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(joy32Message)(uID, uMessage, dwInstance, dwParam1, dwParam2); }
	DLLEXPORT MMRESULT WINAPI joyConfigChanged(DWORD dwFlags) { return CALL_ORIGINAL_FUNC(joyConfigChanged)(dwFlags); }
	DLLEXPORT MMRESULT WINAPI joyGetDevCapsA(UINT_PTR uJoyID, LPJOYCAPSA pjc, UINT cbjc) { return CALL_ORIGINAL_FUNC(joyGetDevCapsA)(uJoyID, pjc, cbjc); }
	DLLEXPORT MMRESULT WINAPI joyGetDevCapsW(UINT_PTR uJoyID, LPJOYCAPSW pjc, UINT cbjc) { return CALL_ORIGINAL_FUNC(joyGetDevCapsW)(uJoyID, pjc, cbjc); }
	DLLEXPORT UINT WINAPI joyGetNumDevs() { return CALL_ORIGINAL_FUNC(joyGetNumDevs)(); }
	DLLEXPORT MMRESULT WINAPI joyGetPos(UINT uJoyID, LPJOYINFO pji) { return CALL_ORIGINAL_FUNC(joyGetPos)(uJoyID, pji); }
	DLLEXPORT MMRESULT WINAPI joyGetPosEx(UINT uJoyID, LPJOYINFOEX pji) { return CALL_ORIGINAL_FUNC(joyGetPosEx)(uJoyID, pji); }
	DLLEXPORT MMRESULT WINAPI joyGetThreshold(UINT uJoyID, LPUINT puThreshold) { return CALL_ORIGINAL_FUNC(joyGetThreshold)(uJoyID, puThreshold); }
	DLLEXPORT MMRESULT WINAPI joyReleaseCapture(UINT uJoyID) { return CALL_ORIGINAL_FUNC(joyReleaseCapture)(uJoyID); }
	DLLEXPORT MMRESULT WINAPI joySetCapture(HWND hwnd, UINT uJoyID, UINT uPeriod, BOOL fChanged) { return CALL_ORIGINAL_FUNC(joySetCapture)(hwnd, uJoyID, uPeriod, fChanged); }
	DLLEXPORT MMRESULT WINAPI joySetThreshold(UINT uJoyID, UINT uThreshold) { return CALL_ORIGINAL_FUNC(joySetThreshold)(uJoyID, uThreshold); }
	DLLEXPORT DWORD WINAPI mci32Message(DWORD dwApi, DWORD dwF1, DWORD dwF2, DWORD dwF3, DWORD dwF4) { return CALL_ORIGINAL_FUNC(mci32Message)(dwApi, dwF1, dwF2, dwF3, dwF4); }
	DLLEXPORT BOOL WINAPI mciDriverNotify(HANDLE hwndCallback, UINT wDeviceID, UINT uStatus) { return CALL_ORIGINAL_FUNC(mciDriverNotify)(hwndCallback, wDeviceID, uStatus); }
	DLLEXPORT UINT WINAPI mciDriverYield(UINT wDeviceID) { return CALL_ORIGINAL_FUNC(mciDriverYield)(wDeviceID); }
	DLLEXPORT BOOL APIENTRY mciFreeCommandResource(UINT wTable) { return CALL_ORIGINAL_FUNC(mciFreeCommandResource)(wTable); }
	DLLEXPORT HTASK WINAPI mciGetCreatorTask(UINT mciId) { return CALL_ORIGINAL_FUNC(mciGetCreatorTask)(mciId); }
	DLLEXPORT UINT WINAPI mciGetDeviceIDA(LPCSTR pszDevice) { return CALL_ORIGINAL_FUNC(mciGetDeviceIDA)(pszDevice); }
	DLLEXPORT UINT WINAPI mciGetDeviceIDFromElementIDA(DWORD dwElementID, LPCSTR lpstrType) { return CALL_ORIGINAL_FUNC(mciGetDeviceIDFromElementIDA)(dwElementID, lpstrType); }
	DLLEXPORT UINT WINAPI mciGetDeviceIDFromElementIDW(DWORD dwElementID, LPCWSTR lpstrType) { return CALL_ORIGINAL_FUNC(mciGetDeviceIDFromElementIDW)(dwElementID, lpstrType); }
	DLLEXPORT UINT WINAPI mciGetDeviceIDW(LPCWSTR pszDevice) { return CALL_ORIGINAL_FUNC(mciGetDeviceIDW)(pszDevice); }
	DLLEXPORT DWORD_PTR WINAPI mciGetDriverData(UINT wDeviceID) { return CALL_ORIGINAL_FUNC(mciGetDriverData)(wDeviceID); }
	DLLEXPORT BOOL WINAPI mciGetErrorStringA(DWORD mcierr, LPSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(mciGetErrorStringA)(mcierr, pszText, cchText); }
	DLLEXPORT BOOL WINAPI mciGetErrorStringW(DWORD mcierr, LPWSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(mciGetErrorStringW)(mcierr, pszText, cchText); }
	DLLEXPORT LPVOID WINAPI mciGetYieldProc(UINT mciId, LPDWORD pdwYieldData) { return CALL_ORIGINAL_FUNC(mciGetYieldProc)(mciId, pdwYieldData); }
	DLLEXPORT UINT WINAPI mciLoadCommandResource(HANDLE hInstance, LPCWSTR lpResName, UINT wType) { return CALL_ORIGINAL_FUNC(mciLoadCommandResource)(hInstance, lpResName, wType); }
	DLLEXPORT DWORD WINAPI mciSendCommandA(UINT mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2) { return CALL_ORIGINAL_FUNC(mciSendCommandA)(mciId, uMsg, dwParam1, dwParam2); }
	DLLEXPORT DWORD WINAPI mciSendCommandW(UINT mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2) { return CALL_ORIGINAL_FUNC(mciSendCommandW)(mciId, uMsg, dwParam1, dwParam2); }
	DLLEXPORT DWORD WINAPI mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength,HWND hwndCallback) { return CALL_ORIGINAL_FUNC(mciSendStringA)(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback); }
	DLLEXPORT DWORD WINAPI mciSendStringW(LPCWSTR lpstrCommand, LPWSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback) { return CALL_ORIGINAL_FUNC(mciSendStringW)(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback); }
	DLLEXPORT BOOL WINAPI mciSetDriverData(UINT wDeviceID, DWORD_PTR dwData) { return CALL_ORIGINAL_FUNC(mciSetDriverData)(wDeviceID, dwData); }
	DLLEXPORT BOOL WINAPI mciSetYieldProc(UINT mciId, LPVOID fpYieldProc, DWORD dwYieldData) { return CALL_ORIGINAL_FUNC(mciSetYieldProc)(mciId, fpYieldProc, dwYieldData); }
	DLLEXPORT DWORD WINAPI mid32Message(UINT uDeviceID, UINT uMessage, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(mid32Message)(uDeviceID, uMessage, dwInstance, dwParam1, dwParam2); }
	DLLEXPORT MMRESULT WINAPI midiConnect(HANDLE hmi, HANDLE hmo, LPVOID pReserved) { return CALL_ORIGINAL_FUNC(midiConnect)(hmi, hmo, pReserved); }
	DLLEXPORT MMRESULT WINAPI midiDisconnect(HANDLE hmi, HANDLE hmo, LPVOID pReserved) { return CALL_ORIGINAL_FUNC(midiDisconnect)(hmi, hmo, pReserved); }
	DLLEXPORT MMRESULT WINAPI midiInAddBuffer(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh) { return CALL_ORIGINAL_FUNC(midiInAddBuffer)(hmi, pmh, cbmh); }
	DLLEXPORT MMRESULT WINAPI midiInClose(HANDLE hmi) { return CALL_ORIGINAL_FUNC(midiInClose)(hmi); }
	DLLEXPORT MMRESULT WINAPI midiInGetDevCapsA(UINT_PTR uDeviceID, LPMIDIINCAPSA pmic, UINT cbmic) { return CALL_ORIGINAL_FUNC(midiInGetDevCapsA)(uDeviceID, pmic, cbmic); }
	DLLEXPORT MMRESULT WINAPI midiInGetDevCapsW(UINT_PTR uDeviceID, LPMIDIINCAPSW pmic, UINT cbmic) { return CALL_ORIGINAL_FUNC(midiInGetDevCapsW)(uDeviceID, pmic, cbmic); }
	DLLEXPORT MMRESULT WINAPI midiInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(midiInGetErrorTextA)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI midiInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(midiInGetErrorTextW)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI midiInGetID(HANDLE hmi, LPUINT puDeviceID) { return CALL_ORIGINAL_FUNC(midiInGetID)(hmi, puDeviceID); }
	DLLEXPORT UINT WINAPI midiInGetNumDevs() { return CALL_ORIGINAL_FUNC(midiInGetNumDevs)(); }
	DLLEXPORT MMRESULT WINAPI midiInMessage(HANDLE hmi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) { return CALL_ORIGINAL_FUNC(midiInMessage)(hmi, uMsg, dw1, dw2); }
	DLLEXPORT MMRESULT WINAPI midiInOpen(LPVOID phmi, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(midiInOpen)(phmi, uDeviceID, dwCallback, dwInstance, fdwOpen); }
	DLLEXPORT MMRESULT WINAPI midiInPrepareHeader(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh) { return CALL_ORIGINAL_FUNC(midiInPrepareHeader)(hmi, pmh, cbmh); }
	DLLEXPORT MMRESULT WINAPI midiInReset(HANDLE hmi) { return CALL_ORIGINAL_FUNC(midiInReset)(hmi); }
	DLLEXPORT MMRESULT WINAPI midiInStart(HANDLE hmi) { return CALL_ORIGINAL_FUNC(midiInStart)(hmi); }
	DLLEXPORT MMRESULT WINAPI midiInStop(HANDLE hmi) { return CALL_ORIGINAL_FUNC(midiInStop)(hmi); }
	DLLEXPORT MMRESULT WINAPI midiInUnprepareHeader(HANDLE hmi, LPMIDIHDR pmh, UINT cbmh) { return CALL_ORIGINAL_FUNC(midiInUnprepareHeader)(hmi, pmh, cbmh); }
	DLLEXPORT MMRESULT WINAPI midiOutCacheDrumPatches(HANDLE hmo, UINT uPatch, LPWORD pwkya, UINT fuCache) { return CALL_ORIGINAL_FUNC(midiOutCacheDrumPatches)(hmo, uPatch, pwkya, fuCache); }
	DLLEXPORT MMRESULT WINAPI midiOutCachePatches(HANDLE hmo, UINT uBank, LPWORD pwpa, UINT fuCache) { return CALL_ORIGINAL_FUNC(midiOutCachePatches)(hmo, uBank, pwpa, fuCache); }
	DLLEXPORT MMRESULT WINAPI midiOutClose(HANDLE hmo) { return CALL_ORIGINAL_FUNC(midiOutClose)(hmo); }
	DLLEXPORT MMRESULT WINAPI midiOutGetDevCapsA(UINT_PTR uDeviceID, LPMIDIOUTCAPSA pmoc, UINT cbmoc) { return CALL_ORIGINAL_FUNC(midiOutGetDevCapsA)(uDeviceID, pmoc, cbmoc); }
	DLLEXPORT MMRESULT WINAPI midiOutGetDevCapsW(UINT_PTR uDeviceID, LPMIDIOUTCAPSW pmoc, UINT cbmoc) { return CALL_ORIGINAL_FUNC(midiOutGetDevCapsW)(uDeviceID, pmoc, cbmoc); }
	DLLEXPORT MMRESULT WINAPI midiOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(midiOutGetErrorTextA)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI midiOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(midiOutGetErrorTextW)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI midiOutGetID(HANDLE hmo, LPUINT puDeviceID) { return CALL_ORIGINAL_FUNC(midiOutGetID)(hmo, puDeviceID); }
	DLLEXPORT UINT WINAPI midiOutGetNumDevs() { return CALL_ORIGINAL_FUNC(midiOutGetNumDevs)(); }
	DLLEXPORT MMRESULT WINAPI midiOutGetVolume(HANDLE hmo, LPDWORD pdwVolume) { return CALL_ORIGINAL_FUNC(midiOutGetVolume)(hmo, pdwVolume); }
	DLLEXPORT MMRESULT WINAPI midiOutLongMsg(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh) { return CALL_ORIGINAL_FUNC(midiOutLongMsg)(hmo, pmh, cbmh); }
	DLLEXPORT MMRESULT WINAPI midiOutMessage(HANDLE hmo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) { return CALL_ORIGINAL_FUNC(midiOutMessage)(hmo, uMsg, dw1, dw2); }
	DLLEXPORT MMRESULT WINAPI midiOutOpen(LPVOID phmo, UINT uDeviceID, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(midiOutOpen)(phmo, uDeviceID, dwCallback, dwInstance, fdwOpen); }
	DLLEXPORT MMRESULT WINAPI midiOutPrepareHeader(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh) { return CALL_ORIGINAL_FUNC(midiOutPrepareHeader)(hmo, pmh, cbmh); }
	DLLEXPORT MMRESULT WINAPI midiOutReset(HANDLE hmo) { return CALL_ORIGINAL_FUNC(midiOutReset)(hmo); }
	DLLEXPORT MMRESULT WINAPI midiOutSetVolume(HANDLE hmo, DWORD dwVolume) { return CALL_ORIGINAL_FUNC(midiOutSetVolume)(hmo, dwVolume); }
	DLLEXPORT MMRESULT WINAPI midiOutShortMsg(HANDLE hmo, DWORD dwMsg) { return CALL_ORIGINAL_FUNC(midiOutShortMsg)(hmo, dwMsg); }
	DLLEXPORT MMRESULT WINAPI midiOutUnprepareHeader(HANDLE hmo, LPMIDIHDR pmh, UINT cbmh) { return CALL_ORIGINAL_FUNC(midiOutUnprepareHeader)(hmo, pmh, cbmh); }
	DLLEXPORT MMRESULT WINAPI midiStreamClose(HANDLE hms) { return CALL_ORIGINAL_FUNC(midiStreamClose)(hms); }
	DLLEXPORT MMRESULT WINAPI midiStreamOpen(LPVOID phms, LPUINT puDeviceID, DWORD cMidi, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(midiStreamOpen)(phms, puDeviceID, cMidi, dwCallback, dwInstance, fdwOpen); }
	DLLEXPORT MMRESULT WINAPI midiStreamOut(HANDLE hms, LPMIDIHDR pmh, UINT cbmh) { return CALL_ORIGINAL_FUNC(midiStreamOut)(hms, pmh, cbmh); }
	DLLEXPORT MMRESULT WINAPI midiStreamPause(HANDLE hms) { return CALL_ORIGINAL_FUNC(midiStreamPause)(hms); }
	DLLEXPORT MMRESULT WINAPI midiStreamPosition(HANDLE hms, LPMMTIME lpmmt, UINT cbmmt) { return CALL_ORIGINAL_FUNC(midiStreamPosition)(hms, lpmmt, cbmmt); }
	DLLEXPORT MMRESULT WINAPI midiStreamProperty(HANDLE hms, LPBYTE lppropdata, DWORD dwProperty) { return CALL_ORIGINAL_FUNC(midiStreamProperty)(hms, lppropdata, dwProperty); }
	DLLEXPORT MMRESULT WINAPI midiStreamRestart(HANDLE hms) { return CALL_ORIGINAL_FUNC(midiStreamRestart)(hms); }
	DLLEXPORT MMRESULT WINAPI midiStreamStop(HANDLE hms) { return CALL_ORIGINAL_FUNC(midiStreamStop)(hms); }
	DLLEXPORT MMRESULT WINAPI mixerClose(HANDLE hmx) { return CALL_ORIGINAL_FUNC(mixerClose)(hmx); }
	DLLEXPORT MMRESULT WINAPI mixerGetControlDetailsA(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails) { return CALL_ORIGINAL_FUNC(mixerGetControlDetailsA)(hmxobj, pmxcd, fdwDetails); }
	DLLEXPORT MMRESULT WINAPI mixerGetControlDetailsW(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails) { return CALL_ORIGINAL_FUNC(mixerGetControlDetailsW)(hmxobj, pmxcd, fdwDetails); }
	DLLEXPORT MMRESULT WINAPI mixerGetDevCapsA(UINT_PTR uMxId, LPMIXERCAPSA pmxcaps, UINT cbmxcaps) { return CALL_ORIGINAL_FUNC(mixerGetDevCapsA)(uMxId, pmxcaps, cbmxcaps); }
	DLLEXPORT MMRESULT WINAPI mixerGetDevCapsW(UINT_PTR uMxId, LPMIXERCAPSW pmxcaps, UINT cbmxcaps) { return CALL_ORIGINAL_FUNC(mixerGetDevCapsW)(uMxId, pmxcaps, cbmxcaps); }
	DLLEXPORT MMRESULT WINAPI mixerGetID(HANDLE hmxobj, UINT* puMxId, DWORD fdwId) { return CALL_ORIGINAL_FUNC(mixerGetID)(hmxobj, puMxId, fdwId); }
	DLLEXPORT MMRESULT WINAPI mixerGetLineControlsA(HANDLE hmxobj, LPMIXERLINECONTROLSA pmxlc, DWORD fdwControls) { return CALL_ORIGINAL_FUNC(mixerGetLineControlsA)(hmxobj, pmxlc, fdwControls); }
	DLLEXPORT MMRESULT WINAPI mixerGetLineControlsW(HANDLE hmxobj, LPMIXERLINECONTROLSW pmxlc, DWORD fdwControls) { return CALL_ORIGINAL_FUNC(mixerGetLineControlsW)(hmxobj, pmxlc, fdwControls); }
	DLLEXPORT MMRESULT WINAPI mixerGetLineInfoA(HANDLE hmxobj, LPMIXERLINEA pmxl, DWORD fdwInfo) { return CALL_ORIGINAL_FUNC(mixerGetLineInfoA)(hmxobj, pmxl, fdwInfo); }
	DLLEXPORT MMRESULT WINAPI mixerGetLineInfoW(HANDLE hmxobj, LPMIXERLINEW pmxl, DWORD fdwInfo) { return CALL_ORIGINAL_FUNC(mixerGetLineInfoW)(hmxobj, pmxl, fdwInfo); }
	DLLEXPORT UINT WINAPI mixerGetNumDevs() { return CALL_ORIGINAL_FUNC(mixerGetNumDevs)(); }
	DLLEXPORT DWORD WINAPI mixerMessage(HANDLE hmx, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2) { return CALL_ORIGINAL_FUNC(mixerMessage)(hmx, uMsg, dwParam1, dwParam2); }
	DLLEXPORT MMRESULT WINAPI mixerOpen(LPVOID phmx, UINT uMxId, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(mixerOpen)(phmx, uMxId, dwCallback, dwInstance, fdwOpen); }
	DLLEXPORT MMRESULT WINAPI mixerSetControlDetails(HANDLE hmxobj, LPMIXERCONTROLDETAILS pmxcd, DWORD fdwDetails) { return CALL_ORIGINAL_FUNC(mixerSetControlDetails)(hmxobj, pmxcd, fdwDetails); }
	DLLEXPORT UINT WINAPI mmDrvInstall(HDRVR hDriver, LPCWSTR wszDrvEntry, DRIVERMSGPROC drvMessage, UINT wFlags) { return CALL_ORIGINAL_FUNC(mmDrvInstall)(hDriver, wszDrvEntry, drvMessage, wFlags); }
	DLLEXPORT DWORD WINAPI mmGetCurrentTask() { return CALL_ORIGINAL_FUNC(mmGetCurrentTask)(); }
	DLLEXPORT void WINAPI mmTaskBlock(DWORD h) { return CALL_ORIGINAL_FUNC(mmTaskBlock)(h); }
	DLLEXPORT UINT WINAPI mmTaskCreate(LPTASKCALLBACK lpfn, HANDLE* lph, DWORD_PTR dwInst) { return CALL_ORIGINAL_FUNC(mmTaskCreate)(lpfn, lph, dwInst); }
	DLLEXPORT BOOL WINAPI mmTaskSignal(DWORD h) { return CALL_ORIGINAL_FUNC(mmTaskSignal)(h); }
	DLLEXPORT void WINAPI mmTaskYield() { return CALL_ORIGINAL_FUNC(mmTaskYield)(); }
	DLLEXPORT MMRESULT WINAPI mmioAdvance(HANDLE hmmio, LPMMIOINFO pmmioinfo, UINT fuAdvance) { return CALL_ORIGINAL_FUNC(mmioAdvance)(hmmio, pmmioinfo, fuAdvance); }
	DLLEXPORT MMRESULT WINAPI mmioAscend(HANDLE hmmio, LPMMCKINFO pmmcki, UINT fuAscend) { return CALL_ORIGINAL_FUNC(mmioAscend)(hmmio, pmmcki, fuAscend); }
	DLLEXPORT MMRESULT WINAPI mmioClose(HANDLE hmmio, UINT fuClose) { return CALL_ORIGINAL_FUNC(mmioClose)(hmmio, fuClose); }
	DLLEXPORT MMRESULT  WINAPI mmioCreateChunk(HANDLE hmmio, LPMMCKINFO pmmcki, UINT fuCreate) { return CALL_ORIGINAL_FUNC(mmioCreateChunk)(hmmio, pmmcki, fuCreate); }
	DLLEXPORT MMRESULT WINAPI mmioDescend(HANDLE hmmio, LPMMCKINFO pmmcki, const MMCKINFO* pmmckiParent, UINT fuDescend) { return CALL_ORIGINAL_FUNC(mmioDescend)(hmmio, pmmcki, pmmcki, fuDescend); }
	DLLEXPORT MMRESULT WINAPI mmioFlush(HANDLE hmmio, UINT fuFlush) { return CALL_ORIGINAL_FUNC(mmioFlush)(hmmio, fuFlush); }
	DLLEXPORT MMRESULT WINAPI mmioGetInfo(HANDLE hmmio, LPMMIOINFO pmmioinfo, UINT fuInfo) { return CALL_ORIGINAL_FUNC(mmioGetInfo)(hmmio, pmmioinfo, fuInfo); }
	DLLEXPORT LPMMIOPROC WINAPI mmioInstallIOProcA(DWORD fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags) { return CALL_ORIGINAL_FUNC(mmioInstallIOProcA)(fccIOProc, pIOProc, dwFlags); }
	DLLEXPORT LPMMIOPROC WINAPI mmioInstallIOProcW(DWORD fccIOProc, LPMMIOPROC pIOProc, DWORD dwFlags) { return CALL_ORIGINAL_FUNC(mmioInstallIOProcW)(fccIOProc, pIOProc, dwFlags); }
	DLLEXPORT HANDLE WINAPI mmioOpenA(LPSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(mmioOpenA)(pszFileName, pmmioinfo, fdwOpen); }
	DLLEXPORT HANDLE WINAPI mmioOpenW(LPWSTR pszFileName, LPMMIOINFO pmmioinfo, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(mmioOpenW)(pszFileName, pmmioinfo, fdwOpen); }
	DLLEXPORT LONG WINAPI mmioRead(HANDLE hmmio, LPSTR pch, LONG cch) { return CALL_ORIGINAL_FUNC(mmioRead)(hmmio, pch, cch); }
	DLLEXPORT MMRESULT WINAPI mmioRenameA(LPCSTR pszFileName, LPCSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename) { return CALL_ORIGINAL_FUNC(mmioRenameA)(pszFileName, pszNewFileName, pmmioinfo, fdwRename); }
	DLLEXPORT MMRESULT WINAPI mmioRenameW(LPCWSTR pszFileName, LPCWSTR pszNewFileName, LPCMMIOINFO pmmioinfo, DWORD fdwRename) { return CALL_ORIGINAL_FUNC(mmioRenameW)(pszFileName, pszNewFileName, pmmioinfo, fdwRename); }
	DLLEXPORT LONG WINAPI mmioSeek(HANDLE hmmio, LONG lOffset, int iOrigin) { return CALL_ORIGINAL_FUNC(mmioSeek)(hmmio, lOffset, iOrigin); }
	DLLEXPORT LRESULT WINAPI mmioSendMessage(HANDLE hmmio, UINT uMsg, LPARAM lParam1, LPARAM lParam2) { return CALL_ORIGINAL_FUNC(mmioSendMessage)(hmmio, uMsg, lParam1, lParam2); }
	DLLEXPORT MMRESULT WINAPI mmioSetBuffer(HANDLE hmmio, LPSTR pchBuffer, LONG cchBuffer, UINT fuBuffer) { return CALL_ORIGINAL_FUNC(mmioSetBuffer)(hmmio, pchBuffer, cchBuffer, fuBuffer); }
	DLLEXPORT MMRESULT WINAPI mmioSetInfo(HANDLE hmmio, LPCMMIOINFO pmmioinfo, UINT fuInfo) { return CALL_ORIGINAL_FUNC(mmioSetInfo)(hmmio, pmmioinfo, fuInfo); }
	DLLEXPORT DWORD WINAPI mmioStringToFOURCCA(LPCSTR sz, UINT uFlags) { return CALL_ORIGINAL_FUNC(mmioStringToFOURCCA)(sz, uFlags); }
	DLLEXPORT DWORD WINAPI mmioStringToFOURCCW(LPCWSTR sz, UINT uFlags) { return CALL_ORIGINAL_FUNC(mmioStringToFOURCCW)(sz, uFlags); }
	DLLEXPORT LONG WINAPI mmioWrite(HANDLE hmmio, const char* pch, LONG cch) { return CALL_ORIGINAL_FUNC(mmioWrite)(hmmio, pch, cch); }
	DLLEXPORT WORD WINAPI mmsystemGetVersion() { return CALL_ORIGINAL_FUNC(mmsystemGetVersion)(); }
	DLLEXPORT DWORD WINAPI mod32Message(UINT uDeviceID, UINT uMessage, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(mod32Message)(uDeviceID, uMessage, dwInstance, dwParam1, dwParam2); }
	DLLEXPORT DWORD WINAPI mxd32Message(UINT uId, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(mxd32Message)(uId, uMsg, dwInstance, dwParam1, dwParam2); }
	DLLEXPORT BOOL WINAPI sndPlaySoundA(LPCSTR pszSound, UINT fuSound) { return CALL_ORIGINAL_FUNC(sndPlaySoundA)(pszSound, fuSound); }
	DLLEXPORT BOOL WINAPI sndPlaySoundW(LPCWSTR pszSound, UINT fuSound) { return CALL_ORIGINAL_FUNC(sndPlaySoundW)(pszSound, fuSound); }
	DLLEXPORT DWORD WINAPI tid32Message(UINT uDevId, UINT uMessage, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(tid32Message)(uDevId, uMessage, dwInstance, dwParam1, dwParam2); }
	DLLEXPORT MMRESULT WINAPI timeBeginPeriod(UINT uPeriod) { return CALL_ORIGINAL_FUNC(timeBeginPeriod)(uPeriod); }
	DLLEXPORT MMRESULT WINAPI timeEndPeriod(UINT uPeriod) { return CALL_ORIGINAL_FUNC(timeEndPeriod)(uPeriod); }
	DLLEXPORT MMRESULT WINAPI timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc) { return CALL_ORIGINAL_FUNC(timeGetDevCaps)(ptc, cbtc); }
	DLLEXPORT MMRESULT WINAPI timeGetSystemTime(LPMMTIME pmmt, UINT cbmmt) { return CALL_ORIGINAL_FUNC(timeGetSystemTime)(pmmt, cbmmt); }
	DLLEXPORT DWORD WINAPI timeGetTime() { return CALL_ORIGINAL_FUNC(timeGetTime)(); }
	DLLEXPORT MMRESULT WINAPI timeKillEvent(UINT uTimerID) { return CALL_ORIGINAL_FUNC(timeKillEvent)(uTimerID); }
	DLLEXPORT MMRESULT WINAPI timeSetEvent(UINT uDelay, UINT uResolution, LPTIMECALLBACK fptc, DWORD_PTR dwUser, UINT fuEvent) { return CALL_ORIGINAL_FUNC(timeSetEvent)(uDelay, uResolution, fptc, dwUser, fuEvent); }
	DLLEXPORT MMRESULT WINAPI waveInAddBuffer(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh) { return CALL_ORIGINAL_FUNC(waveInAddBuffer)(hwi, pwh, cbwh); }
	DLLEXPORT MMRESULT WINAPI waveInClose(HANDLE hwi) { return CALL_ORIGINAL_FUNC(waveInClose)(hwi); }
	DLLEXPORT MMRESULT WINAPI waveInGetDevCapsA(UINT_PTR uDeviceID, LPWAVEINCAPSA pwic, UINT cbwic) { return CALL_ORIGINAL_FUNC(waveInGetDevCapsA)(uDeviceID, pwic, cbwic); }
	DLLEXPORT MMRESULT WINAPI waveInGetDevCapsW(UINT_PTR uDeviceID, LPWAVEINCAPSW pwic, UINT cbwic) { return CALL_ORIGINAL_FUNC(waveInGetDevCapsW)(uDeviceID, pwic, cbwic); }
	DLLEXPORT MMRESULT WINAPI waveInGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(waveInGetErrorTextA)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI waveInGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(waveInGetErrorTextW)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI waveInGetID(HANDLE hwi, LPUINT puDeviceID) { return CALL_ORIGINAL_FUNC(waveInGetID)(hwi, puDeviceID); }
	DLLEXPORT UINT WINAPI waveInGetNumDevs() { return CALL_ORIGINAL_FUNC(waveInGetNumDevs)(); }
	DLLEXPORT MMRESULT WINAPI waveInGetPosition(HANDLE hwi, LPMMTIME pmmt, UINT cbmmt) { return CALL_ORIGINAL_FUNC(waveInGetPosition)(hwi, pmmt, cbmmt); }
	DLLEXPORT MMRESULT WINAPI waveInMessage(HANDLE hwi, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) { return CALL_ORIGINAL_FUNC(waveInMessage)(hwi, uMsg, dw1, dw2); }
	DLLEXPORT MMRESULT WINAPI waveInOpen(LPVOID phwi, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(waveInOpen)(phwi, uDeviceID, pwfx, dwCallback, dwInstance, fdwOpen); }
	DLLEXPORT MMRESULT WINAPI waveInPrepareHeader(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh) { return CALL_ORIGINAL_FUNC(waveInPrepareHeader)(hwi, pwh, cbwh); }
	DLLEXPORT MMRESULT WINAPI waveInReset(HANDLE hwi) { return CALL_ORIGINAL_FUNC(waveInReset)(hwi); }
	DLLEXPORT MMRESULT WINAPI waveInStart(HANDLE hwi) { return CALL_ORIGINAL_FUNC(waveInStart)(hwi); }
	DLLEXPORT MMRESULT WINAPI waveInStop(HANDLE hwi) { return CALL_ORIGINAL_FUNC(waveInStop)(hwi); }
	DLLEXPORT MMRESULT WINAPI waveInUnprepareHeader(HANDLE hwi, LPWAVEHDR pwh, UINT cbwh) { return CALL_ORIGINAL_FUNC(waveInUnprepareHeader)(hwi, pwh, cbwh); }
	DLLEXPORT MMRESULT WINAPI waveOutBreakLoop(HANDLE hwo) { return CALL_ORIGINAL_FUNC(waveOutBreakLoop)(hwo); }
	DLLEXPORT MMRESULT WINAPI waveOutClose(HANDLE hwo) { return CALL_ORIGINAL_FUNC(waveOutClose)(hwo); }
	DLLEXPORT MMRESULT WINAPI waveOutGetDevCapsA(UINT_PTR uDeviceID, LPWAVEOUTCAPSA pwoc, UINT cbwoc) { return CALL_ORIGINAL_FUNC(waveOutGetDevCapsA)(uDeviceID, pwoc, cbwoc); }
	DLLEXPORT MMRESULT WINAPI waveOutGetDevCapsW(UINT_PTR uDeviceID, LPWAVEOUTCAPSW pwoc, UINT cbwoc) { return CALL_ORIGINAL_FUNC(waveOutGetDevCapsW)(uDeviceID, pwoc, cbwoc); }
	DLLEXPORT MMRESULT WINAPI waveOutGetErrorTextA(MMRESULT mmrError, LPSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(waveOutGetErrorTextA)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI waveOutGetErrorTextW(MMRESULT mmrError, LPWSTR pszText, UINT cchText) { return CALL_ORIGINAL_FUNC(waveOutGetErrorTextW)(mmrError, pszText, cchText); }
	DLLEXPORT MMRESULT WINAPI waveOutGetID(HANDLE hwo, LPUINT puDeviceID) { return CALL_ORIGINAL_FUNC(waveOutGetID)(hwo, puDeviceID); }
	DLLEXPORT UINT WINAPI waveOutGetNumDevs() { return CALL_ORIGINAL_FUNC(waveOutGetNumDevs)(); }
	DLLEXPORT MMRESULT WINAPI waveOutGetPitch(HANDLE hwo, LPDWORD pdwPitch) { return CALL_ORIGINAL_FUNC(waveOutGetPitch)(hwo, pdwPitch); }
	DLLEXPORT MMRESULT WINAPI waveOutGetPlaybackRate(HANDLE hwo, LPDWORD pdwRate) { return CALL_ORIGINAL_FUNC(waveOutGetPlaybackRate)(hwo, pdwRate); }
	DLLEXPORT MMRESULT WINAPI waveOutGetPosition(HANDLE hwo, LPMMTIME pmmt, UINT cbmmt) { return CALL_ORIGINAL_FUNC(waveOutGetPosition)(hwo, pmmt, cbmmt); }
	DLLEXPORT MMRESULT WINAPI waveOutGetVolume(HANDLE hwo, LPDWORD pdwVolume) { return CALL_ORIGINAL_FUNC(waveOutGetVolume)(hwo, pdwVolume); }
	DLLEXPORT MMRESULT WINAPI waveOutMessage(HANDLE hwo, UINT uMsg, DWORD_PTR dw1, DWORD_PTR dw2) { return CALL_ORIGINAL_FUNC(waveOutMessage)(hwo, uMsg, dw1, dw2); }
	DLLEXPORT MMRESULT WINAPI waveOutOpen(LPVOID phwo, UINT uDeviceID, LPCWAVEFORMATEX pwfx, DWORD_PTR dwCallback, DWORD_PTR dwInstance, DWORD fdwOpen) { return CALL_ORIGINAL_FUNC(waveOutOpen)(phwo, uDeviceID, pwfx, dwCallback, dwInstance, fdwOpen); }
	DLLEXPORT MMRESULT WINAPI waveOutPause(HANDLE hwo) { return CALL_ORIGINAL_FUNC(waveOutPause)(hwo); }
	DLLEXPORT MMRESULT WINAPI waveOutPrepareHeader(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh) { return CALL_ORIGINAL_FUNC(waveOutPrepareHeader)(hwo, pwh, cbwh); }
	DLLEXPORT MMRESULT WINAPI waveOutReset(HANDLE hwo) { return CALL_ORIGINAL_FUNC(waveOutReset)(hwo); }
	DLLEXPORT MMRESULT WINAPI waveOutRestart(HANDLE hwo) { return CALL_ORIGINAL_FUNC(waveOutRestart)(hwo); }
	DLLEXPORT MMRESULT WINAPI waveOutSetPitch(HANDLE hwo, DWORD dwPitch) { return CALL_ORIGINAL_FUNC(waveOutSetPitch)(hwo, dwPitch); }
	DLLEXPORT MMRESULT WINAPI waveOutSetPlaybackRate(HANDLE hwo, DWORD dwRate) { return CALL_ORIGINAL_FUNC(waveOutSetPlaybackRate)(hwo, dwRate); }
	DLLEXPORT MMRESULT WINAPI waveOutSetVolume(HANDLE hwo, DWORD dwVolume) { return CALL_ORIGINAL_FUNC(waveOutSetVolume)(hwo, dwVolume); }
	DLLEXPORT MMRESULT WINAPI waveOutUnprepareHeader(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh) { return CALL_ORIGINAL_FUNC(waveOutPrepareHeader)(hwo, pwh, cbwh); }
	DLLEXPORT MMRESULT WINAPI waveOutWrite(HANDLE hwo, LPWAVEHDR pwh, UINT cbwh) { return CALL_ORIGINAL_FUNC(waveOutWrite)(hwo, pwh, cbwh); }
	DLLEXPORT DWORD WINAPI wid32Message(UINT uDeviceID, UINT uMessage, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(wid32Message)(uDeviceID, uMessage, dwInstance, dwParam1, dwParam2); }
	DLLEXPORT DWORD WINAPI wod32Message(UINT uDeviceID, UINT uMessage, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2) { return CALL_ORIGINAL_FUNC(wod32Message)(uDeviceID, uMessage, dwInstance, dwParam1, dwParam2); }
}