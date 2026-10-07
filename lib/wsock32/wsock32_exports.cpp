#include "proxy.hpp"
#include "patch_gethostbyname.hpp"

#define DLLEXPORT __declspec(dllexport)

// predeclarations

#include <inaddr.h>

typedef UINT_PTR SOCKET;
struct sockaddr;
struct fd_set;
struct timeval;
struct hostent;
struct protoent;
struct servent;
struct WSAData;
using LPWSADATA = WSAData*;
struct _TRANSMIT_FILE_BUFFERS;
using LPTRANSMIT_FILE_BUFFERS = _TRANSMIT_FILE_BUFFERS*;

extern "C"
{
	DLLEXPORT SOCKET WINAPI accept(SOCKET s, sockaddr* addr, int* addrlen) { return CALL_ORIGINAL_FUNC(accept)(s, addr, addrlen); }
	DLLEXPORT int WINAPI bind(SOCKET s, const sockaddr* addr, int namelen) { return CALL_ORIGINAL_FUNC(bind)(s, addr, namelen); }
	DLLEXPORT int WINAPI closesocket(SOCKET s) { return CALL_ORIGINAL_FUNC(closesocket)(s); }
	DLLEXPORT int WINAPI connect(SOCKET s, const sockaddr* name, int namelen) { return CALL_ORIGINAL_FUNC(connect)(s, name, namelen); }
	DLLEXPORT int WINAPI getpeername(SOCKET s, sockaddr* name, int* namelen) { return CALL_ORIGINAL_FUNC(getpeername)(s, name, namelen); }
	DLLEXPORT int WINAPI getsockname(SOCKET s, sockaddr* name, int* namelen) { return CALL_ORIGINAL_FUNC(getsockname)(s, name, namelen); }
	DLLEXPORT int WINAPI getsockopt (SOCKET s, int level, int optname, char* optval, int* optlen) { return CALL_ORIGINAL_FUNC(getsockopt)(s, level, optname, optval, optlen); }
	DLLEXPORT unsigned long WINAPI htonl(unsigned long hostlong) { return CALL_ORIGINAL_FUNC(htonl)(hostlong); }
	DLLEXPORT unsigned short WINAPI htons(unsigned short hostshort) { return CALL_ORIGINAL_FUNC(htons)(hostshort); }
	DLLEXPORT unsigned long WINAPI inet_addr(const char* cp) { return CALL_ORIGINAL_FUNC(inet_addr)(cp); }
	DLLEXPORT char* WINAPI inet_ntoa (in_addr in) { return CALL_ORIGINAL_FUNC(inet_ntoa)(in); }
	DLLEXPORT int WINAPI ioctlsocket(SOCKET s, long cmd, unsigned long* argp) { return CALL_ORIGINAL_FUNC(ioctlsocket)(s, cmd, argp); }
	DLLEXPORT int WINAPI listen (SOCKET s, int backlog) { return CALL_ORIGINAL_FUNC(listen)(s, backlog); }
	DLLEXPORT unsigned long WINAPI ntohl(unsigned long netlong) { return CALL_ORIGINAL_FUNC(ntohl)(netlong); }
	DLLEXPORT unsigned short WINAPI ntohs (unsigned short netshort) { return CALL_ORIGINAL_FUNC(ntohs)(netshort); }
	DLLEXPORT int WINAPI recv(SOCKET s, char* buf, int len, int flags) { return CALL_ORIGINAL_FUNC(recv)(s, buf, len, flags); }
	DLLEXPORT int WINAPI recvfrom(SOCKET s, char* buf, int len, int flags, sockaddr* from, int* fromlen) { return CALL_ORIGINAL_FUNC(recvfrom)(s, buf, len, flags, from, fromlen); }
	DLLEXPORT int WINAPI select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const timeval* timeout) { return CALL_ORIGINAL_FUNC(select)(nfds, readfds, writefds, exceptfds, timeout); }
	DLLEXPORT int WINAPI send(SOCKET s, const char* buf, int len, int flags) { return CALL_ORIGINAL_FUNC(send)(s, buf, len, flags); }
	DLLEXPORT int WINAPI sendto(SOCKET s, const char* buf, int len, int flags, const sockaddr* to, int tolen) { return CALL_ORIGINAL_FUNC(sendto)(s, buf, len, flags, to, tolen); }
	DLLEXPORT int WINAPI setsockopt(SOCKET s, int level, int optname, const char* optval, int optlen) { return CALL_ORIGINAL_FUNC(setsockopt)(s, level, optname, optval, optlen); }
	DLLEXPORT int WINAPI shutdown(SOCKET s, int how) { return CALL_ORIGINAL_FUNC(shutdown)(s, how); }
	DLLEXPORT SOCKET WINAPI socket(int af, int type, int protocol) { return CALL_ORIGINAL_FUNC(socket)(af, type, protocol); }
	DLLEXPORT int WINAPI MigrateWinsockConfiguration(int a, int b, int c) { return CALL_ORIGINAL_FUNC(MigrateWinsockConfiguration)(a, b, c); }
	DLLEXPORT hostent* WINAPI gethostbyaddr(const char* addr, int len, int type) { return CALL_ORIGINAL_FUNC(gethostbyaddr)(addr, len, type); }
	DLLEXPORT hostent* WINAPI gethostbyname(const char* addr) { return patch_gethostbyname(addr); }
	DLLEXPORT protoent* WINAPI getprotobyname(const char* name) { return CALL_ORIGINAL_FUNC(getprotobyname)(name); }
	DLLEXPORT protoent* WINAPI getprotobynumber(int proto) { return CALL_ORIGINAL_FUNC(getprotobynumber)(proto); }
	DLLEXPORT servent* WINAPI getservbyname(const char* name, const char* proto) { return CALL_ORIGINAL_FUNC(getservbyname)(name, proto); }
	DLLEXPORT servent* WINAPI getservbyport(int port, const char* proto) { return CALL_ORIGINAL_FUNC(getservbyport)(port, proto); }
	DLLEXPORT int WINAPI gethostname(char* name, int namelen) { return CALL_ORIGINAL_FUNC(gethostname)(name, namelen); }
	DLLEXPORT int WINAPI WSAAsyncSelect(SOCKET s, HWND hWnd, unsigned int wMsg, long lEvent) { return CALL_ORIGINAL_FUNC(WSAAsyncSelect)(s, hWnd, wMsg, lEvent); }
	DLLEXPORT HANDLE WINAPI WSAAsyncGetHostByAddr(HWND hWnd, unsigned int wMsg, const char* addr, int len, int type, char* buf, int buflen) { return CALL_ORIGINAL_FUNC(WSAAsyncGetHostByAddr)(hWnd, wMsg, addr, len, type, buf, buflen); }
	DLLEXPORT HANDLE WINAPI WSAAsyncGetHostByName(HWND hWnd, unsigned int wMsg, const char* name, char* buf, int buflen) { return CALL_ORIGINAL_FUNC(WSAAsyncGetHostByName)(hWnd, wMsg, name, buf, buflen); }
	DLLEXPORT HANDLE WINAPI WSAAsyncGetProtoByNumber(HWND hWnd, unsigned int wMsg, int number, char* buf, int buflen) { return CALL_ORIGINAL_FUNC(WSAAsyncGetProtoByNumber)(hWnd, wMsg, number, buf, buflen); }
	DLLEXPORT HANDLE WINAPI WSAAsyncGetProtoByName(HWND hWnd, unsigned int wMsg, const char* name, char* buf, int buflen) { return CALL_ORIGINAL_FUNC(WSAAsyncGetProtoByName)(hWnd, wMsg, name, buf, buflen); }
	DLLEXPORT HANDLE WINAPI WSAAsyncGetServByPort(HWND hWnd, unsigned int wMsg, int port, const char* proto, char* buf, int buflen) { return CALL_ORIGINAL_FUNC(WSAAsyncGetServByPort)(hWnd, wMsg, port, proto, buf, buflen); }
	DLLEXPORT HANDLE WINAPI WSAAsyncGetServByName(HWND hWnd, unsigned int wMsg, const char* name, const char* proto, char* buf, int buflen) { return CALL_ORIGINAL_FUNC(WSAAsyncGetServByName)(hWnd, wMsg, name, proto, buf, buflen); }
	DLLEXPORT int WINAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle) { return CALL_ORIGINAL_FUNC(WSACancelAsyncRequest)(hAsyncTaskHandle); }
	DLLEXPORT FARPROC WINAPI WSASetBlockingHook(FARPROC lpBlockFunc) { return CALL_ORIGINAL_FUNC(WSASetBlockingHook)(lpBlockFunc); }
	DLLEXPORT int WINAPI WSAUnhookBlockingHook() { return CALL_ORIGINAL_FUNC(WSAUnhookBlockingHook)(); };
	DLLEXPORT int WINAPI WSAGetLastError() { return CALL_ORIGINAL_FUNC(WSAGetLastError)(); }
	DLLEXPORT void WINAPI WSASetLastError(int iError) { return CALL_ORIGINAL_FUNC(WSASetLastError)(iError); }
	DLLEXPORT int WINAPI WSACancelBlockingCall() { return CALL_ORIGINAL_FUNC(WSACancelBlockingCall)(); }
	DLLEXPORT BOOL WINAPI WSAIsBlocking() { return CALL_ORIGINAL_FUNC(WSAIsBlocking)(); }
	DLLEXPORT int WINAPI WSAStartup(WORD wVersionRequired, LPWSADATA lpWSAData) { return CALL_ORIGINAL_FUNC(WSAStartup)(wVersionRequired, lpWSAData); }
	DLLEXPORT int WINAPI WSACleanup() { return CALL_ORIGINAL_FUNC(WSACleanup)(); }
	DLLEXPORT int WINAPI __WSAFDIsSet(SOCKET s, fd_set* fds) { return CALL_ORIGINAL_FUNC(__WSAFDIsSet)(s, fds); }
	DLLEXPORT int WINAPI WEP() { return CALL_ORIGINAL_FUNC(WEP)(); }
	DLLEXPORT LPVOID WINAPI WSApSetPostRoutine(void* Unknown) { return CALL_ORIGINAL_FUNC(WSApSetPostRoutine)(Unknown); }
	DLLEXPORT int WINAPI inet_network(int a) { return CALL_ORIGINAL_FUNC(inet_network)(a); }
	DLLEXPORT int WINAPI getnetbyname(int a) { return CALL_ORIGINAL_FUNC(getnetbyname)(a); }
	DLLEXPORT int WINAPI rcmd(int a, int b, int c, int d, int e, int f) { return CALL_ORIGINAL_FUNC(rcmd)(a, b, c, d, e, f); }
	DLLEXPORT int WINAPI rexec(int a, int b, int c, int d, int e, int f) { return CALL_ORIGINAL_FUNC(rexec)(a, b, c, d, e, f); }
	DLLEXPORT int WINAPI rresvport(int a) { return CALL_ORIGINAL_FUNC(rresvport)(a); }
	DLLEXPORT int WINAPI sethostname(int a, int b) { return CALL_ORIGINAL_FUNC(sethostname)(a, b); }
	DLLEXPORT int WINAPI dn_expand(int a, int b, int c, int d, int e) { return CALL_ORIGINAL_FUNC(dn_expand)(a, b, c, d, e); }
	DLLEXPORT int WINAPI WSARecvEx(SOCKET s, char* buf, int len, int* flags) { return CALL_ORIGINAL_FUNC(WSARecvEx)(s, buf, len, flags); }
	DLLEXPORT int WINAPI s_perror(int a, int b) { return CALL_ORIGINAL_FUNC(s_perror)(a, b); }
	DLLEXPORT int WINAPI GetAddressByNameA(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) { return CALL_ORIGINAL_FUNC(GetAddressByNameA)(a, b, c, d, e, f, g, h, i, j); }
	DLLEXPORT int WINAPI GetAddressByNameW(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) { return CALL_ORIGINAL_FUNC(GetAddressByNameW)(a, b, c, d, e, f, g, h, i, j); }
	DLLEXPORT int WINAPI EnumProtocolsA(int a, int b, int c) { return CALL_ORIGINAL_FUNC(EnumProtocolsA)(a, b, c); }
	DLLEXPORT int WINAPI EnumProtocolsW(int a, int b, int c) { return CALL_ORIGINAL_FUNC(EnumProtocolsW)(a, b, c); }
	DLLEXPORT int WINAPI GetTypeByNameA(int a, int b) { return CALL_ORIGINAL_FUNC(GetTypeByNameA)(a, b); }
	DLLEXPORT int WINAPI GetTypeByNameW(int a, int b) { return CALL_ORIGINAL_FUNC(GetTypeByNameW)(a, b); }
	DLLEXPORT int WINAPI GetNameByTypeA(int a, int b, int c) { return CALL_ORIGINAL_FUNC(GetNameByTypeA)(a, b, c); }
	DLLEXPORT int WINAPI GetNameByTypeW(int a, int b, int c) { return CALL_ORIGINAL_FUNC(GetNameByTypeW)(a, b, c); }
	DLLEXPORT int WINAPI SetServiceA(int a, int b, int c, int d, int e, int f) { return CALL_ORIGINAL_FUNC(SetServiceA)(a, b, c, d, e, f); }
	DLLEXPORT int WINAPI SetServiceW(int a, int b, int c, int d, int e, int f) { return CALL_ORIGINAL_FUNC(SetServiceW)(a, b, c, d, e, f); }
	DLLEXPORT int WINAPI GetServiceA(int a, int b, int c, int d, int e, int f, int g) { return CALL_ORIGINAL_FUNC(GetServiceA)(a, b, c, d, e, f, g); }
	DLLEXPORT int WINAPI GetServiceW(int a, int b, int c, int d, int e, int f, int g) { return CALL_ORIGINAL_FUNC(GetServiceW)(a, b, c, d, e, f, g); }
	DLLEXPORT int WINAPI NPLoadNameSpaces(int a, int b, int c) { return CALL_ORIGINAL_FUNC(NPLoadNameSpaces)(a, b, c); }
	DLLEXPORT BOOL WINAPI TransmitFile(SOCKET hSocket, HANDLE hFile, DWORD nNumberOfBytesToWrite, DWORD nNumberOfBytesPerSend, LPOVERLAPPED lpOverlapped, LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers, DWORD dwReserved) { return CALL_ORIGINAL_FUNC(TransmitFile)(hSocket, hFile, nNumberOfBytesToWrite, nNumberOfBytesPerSend, lpOverlapped, lpTransmitBuffers, dwReserved); }
	DLLEXPORT BOOL WINAPI AcceptEx(SOCKET sListenSocket, SOCKET sAcceptSocket, PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, LPDWORD lpdwBytesReceived, LPOVERLAPPED lpOverlapped) { return CALL_ORIGINAL_FUNC(AcceptEx)(sListenSocket, sAcceptSocket, lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, lpdwBytesReceived, lpOverlapped); }
	DLLEXPORT void WINAPI GetAcceptExSockaddrs(PVOID lpOutputBuffer, DWORD dwReceiveDataLength, DWORD dwLocalAddressLength, DWORD dwRemoteAddressLength, sockaddr** LocalSockaddr, LPINT LocalSockaddrLength, sockaddr** RemoteSockaddr, LPINT RemoteSockaddrLength) { return CALL_ORIGINAL_FUNC(GetAcceptExSockaddrs)(lpOutputBuffer, dwReceiveDataLength, dwLocalAddressLength, dwRemoteAddressLength, LocalSockaddr, LocalSockaddrLength, RemoteSockaddr, RemoteSockaddrLength); }
}