# 无线设备电量监控（Wireless Battery）

[English](README.en.md)

在 Windows 任务栏直接查看无线鼠标、耳机、键盘和手柄的电量。

![任务栏上的无线设备电量监控](docs/screenshot.png)

> 当前工作区已汉化为简体中文，涵盖菜单、电量状态、悬浮提示、通知、命令行及安装程序。上图为上游项目截图。
>
> **使用汉化版：** 按下方[编译说明](#编译)生成 `WirelessBattery.exe`，双击即可运行。上游发布页中的安装包和便携版由原项目提供，不包含此工作区尚未发布的汉化修改。

- **轻量：** 上游版本程序大小约 350 KB，内存占用约 2 MB。使用原生 C++/Win32，无需额外运行库或后台服务，安装时默认不需要管理员权限。
- **无需厂商软件：** 直接读取设备电量。G HUB、Synapse、iCUE、GG 和 NGenuity 可以关闭，也可以继续运行。
- **支持多种品牌：** Logitech、Razer、SteelSeries、Corsair、HyperX、Glorious、PlayStation 和 Xbox 手柄、Windows 能读取电量的蓝牙设备，以及随安装包提供的 [HeadsetControl](https://github.com/Sapd/HeadsetControl) 支持的耳机。

## 显示方式

**任务栏模式（默认）：** 在通知区域左侧显示 `🎧 30%  🖱 93%`，图标使用 Windows 图标字体绘制。

- **电量不足：** 电量不高于 15% 时，数字显示为红色。
- **正在充电：** 电量旁显示蓝色 ⚡。
- **设备休眠：** 文字变暗，并保留上次读取的电量。
- **电量档位：** 仅提供粗略电量的设备显示“耗尽、极低、低、中等、充足、满电”等对应档位。
- **系统主题：** 自动适配浅色、深色模式和 DPI 缩放。

**托盘图标模式：** 每台设备各显示一个带电量数字的图标，电量降至 15% 或更低时弹出“电量不足”通知。任务栏为竖直方向或无法找到任务栏时，程序自动使用此模式。

将鼠标移到图标上可查看详情。点击打开菜单，可执行以下操作：

- 点击设备名称，显示或隐藏该设备；勾选表示显示。
- 隐藏休眠或仅有上次电量的设备。
- 切换任务栏显示和托盘图标显示。
- 立即刷新、设置开机自启动或退出。

电量每 60 秒刷新一次。插拔设备或电脑从睡眠中唤醒后，也会立即刷新。品牌、具体型号和设备自报名称保留原名，通用设备名称和连接方式显示为中文。

## 支持的设备

| 品牌 / 类型 | 设备 | 读取方式 |
|---|---|---|
| **Logitech** | 使用 Unifying、Bolt、Lightspeed、Nano 接收器或通过 USB、蓝牙连接的鼠标和键盘；G533、G535、G633/G635/G733/G933/G935、G PRO/PRO X 耳机 | HID++ 1.0 / 2.0，自动发现电量、电压、ADC 等功能 |
| **Razer** | 无线鼠标、键盘、接收器；BlackShark V3 / V3 Pro 耳机 | Razer 特征报告协议；耳机封装协议（每 5 分钟查询） |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless、Arctis Nova 3P/5/7/7X/7P/Pro Wireless、GameBuds；Aerox 3/5/9 Wireless、Prime Wireless、Rival 3 Wireless（含 Gen 2）、Rival 650、Rival Pro | 厂商 HID 报告 |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 无线耳机；Bragi 设备（Virtuoso、Void V2、HS80 MAX、Slipstream 鼠标和键盘） | 厂商 HID 报告、Bragi `GET`（只读） |
| **Cooler Master** | MM712、MM731（2.4 GHz 接收器或 USB 有线连接） | 厂商 HID 状态报告（只读） |
| **HyperX** | Cloud III Wireless、Cloud III S Wireless、Cloud II Wireless（HP、Kingston、DTS）、Cloud II Core Wireless、Cloud Alpha Wireless、Cloud Alpha 2 Wireless、Cloud Flight、Cloud Flight S | 厂商 HID 报告 |
| **Glorious** | Model O / O- / D / D- Wireless、Model O 2 / D 2 PRO | 厂商特征报告 |
| **Hitscan** | Hyperlight X、Hyperlight N | 厂商特征报告（与 Glorious 相同协议） |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury、Pulsar 和 ATK VXE 无线鼠标（如 VXE X3 Pro、ATK F1 Extreme）、Hitscan Hyperlight | 共用厂商协议，带回复校验 |
| **ATK 耳机** | ATK N9 Pro | 虚拟串口协议，需关闭 ATK 桌面软件 |
| **G-Wolves** | Fenrir、Fenrir Pro / Max / Asym、HTX、HTS、HSK、HTR、HT-S2、Lycan、WARG、VUK 及对应 8K 接收器 | 根据型号使用 Glorious 或 Kysona 协议 |
| **Keychron 鼠标** | 2.4 GHz 接收器上的 M4 等型号；TurboLink 8K 接收器上的 M5 8K、G6 HE 8K 等型号 | Keychron Launcher 厂商报告 |
| **LAMZU** | Maya X、Maya、Maya M、Tachi、Inca、Paro、Thorn、Atlantis Mini / OG Champion、Orcus（有线、1K、4K/8K 接收器） | LAMZU Aurora 厂商特征报告 |
| **Redragon** | 基于 Compx 的无线鼠标：M916 Pro 1K（已测试）、M913 Impact Elite（三模）、G49（接收器或有线） | Kysona 协议 |
| **AULA** | 通过 2.4 GHz 接收器连接的 F75 / F87 Pro / F99 无线键盘 | `0x13` 报告帧、`0x4A` 命令及求和校验；蓝牙和有线模式未经测试 |
| **ASUS ROG** | Strix Scope II 96 (RX)、Azoth、Falchion 键盘；Keris、Harpe、Gladius、Chakram、Spatha、Pugio、Strix Impact 鼠标；Omni 接收器 | ROG HID 电量查询 |
| **ZOWIE** | EC1/EC2/EC3-CW 和 DW 系列（U2-DW、S2-DW 等） | 社区记录的厂商只读命令 |
| **Rapoo VT** | VT3 Max Gen 2（已测试）；具有相同状态接口的其他 Nordic 54L VT 鼠标；旧款 VT3 Pro（实验性） | `FF00:0002` 上的被动 HID 状态报告 `07`；旧版 `BB` 仅用于 VT3 Pro `1215/4415`，支持接收器、有线及充电状态 |
| **Motospeed / Delux / Ajazz** | Motospeed X6、Delux M900 Pro、Ajazz AJ179 系列；3151 接收器上的 AJ159 等 AJ 系列鼠标 | 厂商报告；Delux 被动广播；AJ 系列使用 `0xF7` 查询和 `0x05` 特征报告 |
| **Attack Shark 及其他国产品牌** | 荣源接收器（81 个型号，包括 Attack Shark R3、X82 PRO HE、Ajazz 键盘及部分 MSI 等）；Xenta 接收器（Attack Shark X6 / R1、X11、X3 Max、V3 Pro） | 荣源状态报告、Xenta 被动广播 |
| **Sony** | DualShock 4、DualSense、DualSense Edge（USB、蓝牙、无线适配器）；INZONE H9 II、H5 耳机 | 输入报告、INZONE 厂商协议 |
| **GameSir** | 2.4 GHz 接收器上的 Nova Lite、Nova 2、Nova 2 Lite；USB 连接的 Nova 2 Lite | 厂商设备信息查询（用途页 `FF7A`） |
| **Xbox** | 通过 Xbox 无线适配器、USB 或蓝牙连接的手柄；插入手柄的耳机 | Windows.Gaming.Input 电量报告（实际百分比），XInput 作为后备 |
| **蓝牙** | “设置 → 蓝牙和设备”中能显示电量的设备，如耳塞、耳机、BLE 鼠标和键盘 | Windows 设备属性 |
| **通用 HID** | 报告标准 HID 电量用途（Battery Strength）的设备 | HID 用途页 `0x06` / `0x85` |
| **HeadsetControl** | [该项目支持的耳机](https://github.com/Sapd/HeadsetControl#supported-headsets)，包括 Audeze、Jabra、Sony INZONE 和较新的 Logitech 等 | 安装包内附，通过 JSON 输出读取 |

**上游已用实物测试：** Glorious Model O Wireless、HyperX Cloud III Wireless、Cooler Master MM712（接收器）、Rapoo VT3 Max Gen 2（接收器 `24AE:1417`、有线 `24AE:4617`）和 Redragon M916 Pro 1K（接收器 `3554:F55D`）。其他 Rapoo 型号未经实物测试，详见 [Rapoo 协议说明（英文）](docs/rapoo.md)。

其余型号主要依据协议文档和其他项目实现，尚未逐一实测。可以向[上游提交 Issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues)反馈兼容情况。

## 安装与运行

汉化版编译完成后，直接运行 `WirelessBattery.exe`。如已生成安装包，也可运行 `WirelessBattery-Setup-<版本>.exe`，按中文向导完成安装。

安装程序默认按当前用户安装，无需管理员权限。它会创建开始菜单快捷方式和卸载项（“设置 → 应用”），并提供登录 Windows 时自动启动的选项。也可选择为所有用户安装，此时需要管理员权限。

便携版 `WirelessBattery-<版本>-portable.zip` 解压后即可运行。安装包和便携版均包含 HeadsetControl。单独运行 `WirelessBattery.exe` 时，如程序同目录或 `PATH` 中没有 `headsetcontrol.exe`，仅会缺少由它额外支持的耳机。

**注意：**

- 程序未进行代码签名，Windows SmartScreen 可能显示“Windows 已保护你的电脑”。确认文件来源后，可通过“更多信息 → 仍要运行”启动，也可自行编译。
- Windows 11 的托盘新图标通常位于 `^` 折叠区域。可将图标拖到任务栏，或在“设置 → 个性化 → 任务栏 → 其他系统托盘图标”中启用。
- [上游发布页](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)提供原版安装包和便携版；本工作区的汉化修改需要自行编译后使用。

## 命令行

```text
WirelessBattery.exe --list   # 列出设备及电量，然后退出
WirelessBattery.exe --dump   # 列出所有 HID 集合，便于排查设备兼容问题
WirelessBattery.exe --quit   # 关闭正在运行的程序
```

控制台输出中文时使用 Windows Unicode 接口；输出重定向到文件或管道时使用 UTF-8，无 BOM。

## 编译

需要 [MinGW-w64](https://www.mingw-w64.org/)，例如安装 [MSYS2](https://www.msys2.org/) 后，在 MINGW64 环境中执行：

```sh
pacman -S mingw-w64-x86_64-gcc make
make
make test
```

也可在已将 `g++` 和 `windres` 加入 `PATH` 的 Windows 命令提示符中运行：

```bat
build.bat
```

产物为项目根目录的 `WirelessBattery.exe`。构建脚本已显式指定 UTF-8 源码编码与资源代码页。所有新增或修改的文本文件使用 UTF-8 无 BOM、Windows CRLF 换行。

生成中文安装包和便携版需要 **Inno Setup 6.5.0 或更高版本**，使用其自带的简体中文语言文件：

```powershell
powershell -File installer\build-installer.ps1 -Version 1.0.0
```

脚本下载固定版本的 HeadsetControl，并核对 SHA-256 校验值。产物写入 `dist` 目录。

GitHub Actions 会自动构建。向仓库推送 `v1.0.0` 之类的版本标签，将发布安装包、便携版及 GPL 许可证要求一并提供的 HeadsetControl 对应源码。

## 已知限制

- **仅主显示器：** 任务栏组件只显示在主显示器的任务栏上。
- **任务栏拥挤：** Windows 11 的居中任务栏应用过多时，按钮可能延伸到电量组件位置。Windows 10 会自动缩小任务按钮区域。
- **休眠设备：** 设备休眠后可能不再回复查询，程序会以暗色保留上次电量。Logitech 接收器可能断开休眠设备的连接，因此会保留其电量最多 30 分钟。可通过菜单隐藏此类设备。
- **Keychron 键盘：** 仅通过蓝牙提供电量，2.4 GHz 接收器固件不提供电量接口。Keychron 鼠标已支持。
- **Rapoo：** 支持的 VT 鼠标主动推送状态，因此每个匹配接口刷新时可能等待最多 4 秒。休眠后最多保留上次电量 30 分钟。当前支持 Nordic 54L 的 `07` 和旧款 VT3 Pro 的 `BB` 报告；不涵盖 CH584 的 `08`、办公 MT/M 系列及其他固件协议。
- **尚未支持：** MSI 无线鼠标和键盘、Razer Kraken / Barracuda 耳机、HyperX Pulsefire 鼠标，以及通过 Xbox 适配器连接的 Xbox Wireless Headset。相关电量协议缺少文档；Xbox Wireless Headset 通过蓝牙连接时可用。部分采用荣源协议的 MSI 设备由通用荣源驱动覆盖，实际兼容性仍需测试。
- **其他设备：** 部分 2.4 GHz 设备使用未公开的协议。协助适配的方法见 [CONTRIBUTING.md（英文）](CONTRIBUTING.md)。

## 工作原理

[`src/drivers/`](src/drivers) 中的厂商驱动根据 USB 厂商 ID 和产品 ID 识别设备，仅发送只读电量查询。不会向未知设备写入数据。通用后备驱动（HID 电量、蓝牙、XInput、HeadsetControl）处理未被厂商驱动接管的设备。

任务栏组件是 `Shell_TrayWnd` 的分层子窗口，位于 `TrayNotifyWnd` 左侧。资源管理器重启后，程序会重新创建组件。

中文显示转换集中在 `src/localization.h` 和界面代码中。设备协议、匹配字符串、设备标识和注册表配置键保留原值，以兼容原有识别逻辑和设置。

## 致谢

设备协议参考了下列项目和资料：

- [HeadsetControl](https://github.com/Sapd/HeadsetControl)：SteelSeries、Corsair、HyperX、Logitech 耳机。
- [OpenRazer](https://github.com/openrazer/openrazer)：Razer。
- [Solaar](https://github.com/pwr-Solaar/Solaar) 和 Logitech HID++ 2.0 文档：Logitech。
- [rivalcfg](https://github.com/flozz/rivalcfg)：SteelSeries 鼠标；Rival Pro 参考其 PR #294。
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator)、[glorious-ctl](https://github.com/louis4craft/glorious-ctl)：Glorious。
- [Hitscan 网页配置器](https://control.hitscan.com)：Hitscan。
- Linux `hid-kysona`（Lode Willems）：Kysona、Pulsar、ATK。
- [ATK 网页配置器](https://hub.atk.pro)：ATK 鼠标、N9 Pro 耳机。
- [G-Wolves 网页驱动](https://mouse.xyz)：G-Wolves 型号和协议。
- [Keychron Launcher](https://launcher.keychron.com)：Keychron 鼠标。
- [LAMZU Aurora](https://www.lamzu.net)：LAMZU 鼠标。
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy)、[g49-web-control](https://github.com/pingpingjinping/g49-web-control)：Redragon 设备 ID。
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray)、[G-Helper](https://github.com/seerge/g-helper)：ASUS ROG。
- [zowie-battery](https://github.com/yleshchuk/zowie-battery)、[zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray)：ZOWIE EC-CW、DW。
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6)、[omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900)、[aj179-linux](https://github.com/Rockeyxx/aj179-linux)：Motospeed、Delux、Ajazz。
- OpenRazer PR #2794、[omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3)：BlackShark V3。
- [HyperXWM](https://github.com/Medprj/HyperXWM)：HyperX Cloud III Wireless。
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset)：HyperX Cloud III S、Cloud II Core、Cloud Flight S。
- [BatteryTray](https://github.com/qu1ncky/BatteryTray)：荣源、Xenta 接收器。
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol)、[MM731-Controller](https://github.com/riVFerd/MM731-Controller)：Cooler Master MM712、MM731。
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray)、[Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection)：GameSir Nova。
- Linux `hid-playstation`：DualShock 4 / DualSense 报告格式。

## 许可证

使用 [GNU General Public License v3.0 或更高版本](LICENSE)。允许使用、修改和再分发；分发基于本项目的软件时，必须使用相同许可证并提供对应源码。许可证原文与第三方版权声明保留原文。
