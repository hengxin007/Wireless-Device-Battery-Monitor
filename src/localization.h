#pragma once
#include <string>

// Translate only display text. Drivers keep their original names and connection values
// for device matching, deduplication and Bluetooth detection.
namespace zh_cn {

inline constexpr wchar_t kAppName[] = L"无线设备电量监控";

inline std::wstring Text(const std::wstring& value) {
    static constexpr const wchar_t* translations[][2] = {
        { L"Empty", L"耗尽" },
        { L"Critical", L"极低" },
        { L"Low", L"低" },
        { L"Medium", L"中等" },
        { L"Good", L"充足" },
        { L"Full", L"满电" },
        { L"Bluetooth", L"蓝牙" },
        { L"USB cable", L"USB 有线连接" },
        { L"USB / Bluetooth", L"USB / 蓝牙" },
        { L"2.4 GHz receiver", L"2.4 GHz 接收器" },
        { L"2.4 GHz receiver / USB", L"2.4 GHz 接收器 / USB" },
        { L"Wireless adapter", L"无线适配器" },
        { L"Logitech receiver", L"Logitech 接收器" },
        { L"Razer receiver", L"Razer 接收器" },
        { L"Corsair receiver", L"Corsair 接收器" },
        { L"ROG Omni Receiver", L"ROG Omni 接收器" },
        { L"Xbox Wireless", L"Xbox 无线连接" },
        { L"Xbox Wireless / Bluetooth", L"Xbox 无线连接 / 蓝牙" },
        { L"UWB base station", L"UWB 基站" },
        { L"Wireless device", L"无线设备" },
        { L"Wireless mouse", L"无线鼠标" },
        { L"Wireless keyboard", L"无线键盘" },
        { L"Bluetooth device", L"蓝牙设备" },
        { L"Headset", L"耳机" },
        { L"Xbox controller", L"Xbox 手柄" },
        { L"Xbox headset", L"Xbox 耳机" },
        { L"Logitech wireless device", L"Logitech 无线设备" },
        { L"Corsair wireless device", L"Corsair 无线设备" },
        { L"Corsair wireless headset", L"Corsair 无线耳机" },
        { L"Razer device", L"Razer 设备" },
        { L"LAMZU wireless mouse", L"LAMZU 无线鼠标" },
        { L"Rapoo wireless mouse", L"Rapoo 无线鼠标" },
        { L"Redragon wireless mouse", L"Redragon 无线鼠标" },
        { L"ATK wireless mouse", L"ATK 无线鼠标" },
        { L"G-Wolves wireless mouse", L"G-Wolves 无线鼠标" },
        { L"Ajazz mouse", L"Ajazz 鼠标" },
        { L"AJAZZ mouse", L"AJAZZ 鼠标" },
        { L"ZOWIE DW mouse", L"ZOWIE DW 鼠标" },
    };
    for (const auto& entry : translations)
        if (value == entry[0]) return entry[1];

    // XInput numbers controllers when more than one is available.
    const std::wstring prefix = L"Xbox controller ";
    if (value.compare(0, prefix.size(), prefix) == 0 && value.size() > prefix.size() &&
        value.find_first_not_of(L"0123456789", prefix.size()) == std::wstring::npos)
        return L"Xbox 手柄 " + value.substr(prefix.size());
    return value;
}

}  // namespace zh_cn
