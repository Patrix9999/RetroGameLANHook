#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <algorithm>
#include <format>
#include <string>
#include <utility>

template <std::size_t N>
struct fixed_string
{
    char value[N] {};

    constexpr fixed_string(const char (&str)[N])
    {
        std::copy_n(str, N, value);
    }
};

inline HMODULE GetOriginalLibraryModule()
{
    static const HMODULE module = [] {
        wchar_t path[MAX_PATH];

        if (!GetSystemDirectoryW(path, MAX_PATH))
        {
            MessageBoxA(nullptr, "GetSystemDirectoryW failed!", "Error", MB_OK);
            return HMODULE{};
        }

        wcscat_s(path, L"\\wsock32.dll");

        return LoadLibraryW(path);
    }();

    return module;
}

template <typename T, fixed_string Name, typename... Args>
decltype(auto) CallOriginalFunc(Args&&... args)
{
    static const auto fn = reinterpret_cast<T>(GetProcAddress(GetOriginalLibraryModule(), Name.value));
    if (!fn)
    {
        const std::string msg = std::format("Failed to find function {} in original network dll", Name.value);
        MessageBoxA(nullptr, msg.c_str(), "RetroGameLANHook", MB_OK | MB_ICONERROR);

        std::terminate();
    }

    return fn(std::forward<Args>(args)...);
}

#define CALL_ORIGINAL_FUNC(name) CallOriginalFunc<decltype(&name), #name>
#define CALL_ORIGINAL_FUNC_AS(func_name, name) CallOriginalFunc<decltype(&func_name), #name>