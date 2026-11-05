# Tower

基于 **C 语言与 raylib** 编写的轻量级 2D 塔防原型。项目围绕敌人生成、塔位交互、选塔面板、实体管理与 2D 渲染组织代码，探索从游戏主循环到业务逻辑、控制器和实体数据的分层实现。

> 当前仓库为开发中的原型版本。敌人移动、塔位选择与贴图切换已经接入主流程；子弹、伤害和游戏结束等逻辑仍有待完善。

## 视频演示

**[▶ 在 Bilibili 观看 Tower 项目演示](https://www.bilibili.com/video/BV1Vv4t6TEgc/)**

- 项目仓库：[Lazyihui / Tower](https://github.com/Lazyihui/Tower)
- 开发语言：C
- 图形与交互库：raylib
- 当前构建方式：Windows 批处理 + GCC
- 默认窗口尺寸：800 × 400

## 项目内容

### 已接入主流程的功能

- **开始界面**：通过 `start game` 按钮进入游戏。
- **2D 场景绘制**：使用 `Camera2D` 绘制道路、塔位、敌人与世界空间 UI。
- **固定塔位**：初始化 6 个可交互的塔位。
- **选塔菜单**：点击塔位打开菜单，提供红色、粉色和紫色三种贴图选项。
- **塔位外观切换**：点击菜单选项后，替换对应塔位的贴图并关闭面板。
- **敌人生成与移动**：按计时器生成敌人，使其沿预设方向移动。
- **状态显示**：显示游戏时间、金币数量和生命条。
- **基础金币计时**：游戏中每隔 2 秒增加 1 金币，目前未接入购买或建造消耗。
- **鼠标交互**：分别保存屏幕坐标与世界坐标，用于开始按钮和场景内交互。

### 已有代码、仍待接通或完善的部分

- **子弹系统**：包含生成、追踪最近目标、移动、圆形碰撞检测和命中移除逻辑。
- **敌人模板**：定义两类敌人的颜色、速度、半径与生命值；当前生成流程固定使用类型 2。
- **防御塔模板**：定义三类塔的颜色与伤害字段；当前选塔操作主要切换贴图。
- **游戏状态**：已声明开始、游戏中、结束三种状态，主循环目前处理开始和游戏中两种状态。

当前选塔流程没有把塔位的 `cellToTower` 标记设为真，因此不能把自动开火视为已完成的可玩功能；怪物伤害处理函数也尚未接入游戏更新流程。

## 使用的库与工具

### 直接使用的依赖

| 库 / 工具 | 项目中的用途 | 仓库位置 / 说明 |
| --- | --- | --- |
| [raylib](https://www.raylib.com/) | 窗口创建、游戏循环接口、键鼠输入、图形绘制、文字显示、纹理加载和 2D 摄影机 | `include/raylib.h`、`lib/raylib.dll` |
| [raymath](https://github.com/raysan5/raylib/blob/4.5.0/src/raymath.h) | 二维向量加减、缩放、归一化、距离平方计算，用于移动、目标搜索和碰撞判断 | `include/raymath.h`；作为头文件参与编译 |
| C 标准库 | 使用 `stdio.h` 输出日志，使用 `stdlib.h` 进行动态内存分配与释放 | 源码中的 `printf`、`perror`、`malloc`、`calloc`、`free` |
| GCC / MinGW-w64 | 编译 C 源码并链接 raylib DLL | `run.bat` 使用 `gcc` 命令 |
| clang-format | 源码格式化配置 | `.clang-format`，属于开发辅助工具 |

仓库中的 `raylib.h` 标记版本为 **4.5**。此版本信息来自头文件；仓库所附 DLL 的具体构建配置和编译工具链版本未单独记录。

### 随仓库附带的图形模块

`include/rlgl.h` 是 raylib 的底层图形抽象模块头文件。当前游戏业务源码没有直接包含或调用它，README 将其列为附带模块。

raylib 头文件还说明了 GLFW / rglfw、glad、miniaudio 和 stb 系列等内部依赖。它们属于 raylib 自身的实现或可选模块，不能据此认定本项目直接使用了这些库的全部能力。当前业务源码未调用音频播放接口。

### 自行实现的功能

以下模块由项目代码实现：

- 开始按钮、鼠标悬停和点击检测：`GUI_Button.h`。
- 三选项选塔面板：`E_UIManifest.h`。
- 矩形点击检测、圆形碰撞检测和网格坐标转换：`A_Common.h`。
- 范围内最近敌人搜索：`A_FindUtil.h`。
- 实体工厂、模板查询和共享上下文：`A_Factory.h`、`Util_Template.h`、`A_Ctx.h`。

当前 UI 使用 raylib 绘制接口和自定义交互逻辑实现，未发现 raygui 的直接使用。

## 编译与运行

### 环境准备

当前仓库提供的是 Windows 构建脚本和 `raylib.dll`，建议先在 Windows 上复现。

准备以下工具：

1. Git，或直接下载仓库 ZIP。
2. Windows GCC 工具链，例如 MinGW-w64。
3. 将工具链的 `bin` 目录加入 `PATH`，确保终端中能执行 `gcc --version`。

编译器的目标架构需与 `lib/raylib.dll` 一致，例如 64 位程序应搭配 64 位 DLL。

### 获取项目

```powershell
git clone https://github.com/Lazyihui/Tower.git
cd Tower
```

### 使用现有脚本

在 **项目根目录** 打开 PowerShell，先创建输出目录：

```powershell
New-Item -ItemType Directory -Force build, bin | Out-Null
cmd /c run.bat
```

现有 `run.bat` 会依次执行：

1. 编译 `src/main.c`，生成 `build/main.o`。
2. 链接 `lib/raylib.dll`，生成 `bin/main.exe`。
3. 将 `raylib.dll` 复制到 `bin`。
4. 启动游戏。

> 原脚本没有创建 `build` 和 `bin` 目录，也没有在编译失败后自动停止。首次运行请先创建目录；出现错误时，优先检查最早的编译或链接报错。

### 手动编译

也可以在项目根目录逐步执行与原脚本一致的命令：

```powershell
New-Item -ItemType Directory -Force build, bin | Out-Null
gcc .\src\main.c -I .\include\ -c -o .\build\main.o
gcc .\build\main.o .\lib\raylib.dll -o .\bin\main.exe
Copy-Item .\lib\raylib.dll .\bin\raylib.dll -Force
.\bin\main.exe
```

每条命令执行成功后，再执行下一条。

### 资源路径

纹理通过 `assets/cell.png`、`assets/red.png` 等相对路径加载，运行时工作目录应为项目根目录。

例如，在项目根目录执行：

```powershell
.\bin\main.exe
```

如果要把程序单独分发到其他文件夹，应同时携带 `raylib.dll` 和 `assets` 目录，并保证资源路径与工作目录对应。

以上命令依据仓库现有脚本整理，尚未完成本机编译和运行验证。Linux、macOS 需要另行准备对应平台的 raylib 库并调整构建命令。

## 操作说明

| 操作 | 效果 |
| --- | --- |
| 鼠标左键点击 `start game` | 进入游戏场景 |
| 鼠标左键点击塔位 | 打开或关闭选塔面板 |
| 鼠标左键点击选塔面板中的图标 | 切换该塔位贴图并关闭面板 |
| 空格键 | 调试操作：生命值减少 10 |
| 关闭窗口 / Esc | 在 raylib 默认退出键设置下结束程序 |

空格扣血是当前源码中的调试逻辑。敌人抵达终点扣血、生命值归零后的结算流程尚未实现。

## 代码结构

```text
Tower/
├── assets/                   # 塔位与三种塔的 PNG 贴图
├── include/
│   ├── raylib.h              # raylib 公共接口，头文件版本为 4.5
│   ├── raymath.h             # 向量等数学工具
│   ├── rlgl.h                # 底层图形抽象模块头文件
│   └── raylib.h.gch          # 已提交的预编译头文件
├── lib/
│   └── raylib.dll            # Windows 动态链接库
├── src/
│   ├── main.c                # 初始化、主循环、状态分发与退出
│   ├── A_Common.h            # 通用函数、常量与碰撞辅助
│   ├── A_Ctx.h               # 全局上下文、资源加载与部分清理
│   ├── A_Factory.h           # 实体创建
│   ├── A_FindUtil.h          # 最近敌人搜索
│   ├── B_Login.h             # 开始界面逻辑
│   ├── B_Game.h              # 游戏更新与分层绘制
│   ├── C_InfraStructure.h    # 敌人和塔的模板初始化
│   ├── C_Monster.h           # 敌人生成、移动及待接入的伤害处理
│   ├── C_Cell.h              # 塔位初始化、绘制与条件开火
│   ├── C_Blt.h               # 子弹更新、追踪和命中移除
│   ├── C_UserInterface.h     # 塔位点击与面板交互
│   ├── C_Tower.h             # 防御塔控制器预留代码
│   ├── E_*.h                 # 实体结构与相关基础操作
│   ├── GUI_Button.h          # 自定义按钮
│   ├── TowerManifestPanel.h  # 另一套选塔面板实现
│   └── Util_Template.h       # 敌人、塔的模板查找
├── Architecture.txt          # 分层设计记录
├── run.bat                   # Windows 编译与启动脚本
└── .clang-format             # 代码格式配置
```

`build/` 与 `bin/` 是运行前需要创建的输出目录，当前源码树未包含它们。

## 主要实现方式

### 1. 基于上下文的数据组织

`Ctx` 集中保存窗口尺寸、游戏状态、时间、金币、生命值、摄影机、输入、贴图，以及敌人、塔位和子弹集合。

各业务模块通过传入 `Ctx*` 访问共享数据；工厂函数负责创建实体，控制器负责更新集合中的对象。

### 2. 按职责组织代码

项目使用文件名前缀表达职责：

| 前缀 | 主要职责 | 示例 |
| --- | --- | --- |
| `A_` | 公共基础、上下文、工厂和查询工具 | `A_Ctx.h`、`A_Factory.h` |
| `B_` | 场景或业务流程 | `B_Login.h`、`B_Game.h` |
| `C_` | 控制器与系统更新 | `C_Monster.h`、`C_UserInterface.h` |
| `E_` | 实体数据与基础行为 | `E_Mst.h`、`E_Bullet.h` |

当前多数函数直接定义在头文件中，由 `main.c` 包含后整体编译。若后续拆成多个 `.c` 文件，需要同步整理声明和定义，避免链接时重复定义。

### 3. 帧时间驱动移动与计时

主循环通过 `GetFrameTime()` 获取帧间隔 `dt`，再传给业务更新函数。

敌人和子弹的移动采用“方向归一化 × 速度 × 帧时间”的方式计算位移；金币增加和敌人生成使用倒计时控制。

### 4. 世界绘制与屏幕 UI 分离

道路、塔位、敌人和选塔面板在 `BeginMode2D()` / `EndMode2D()` 之间绘制。开始按钮、时间、金币和生命条在屏幕坐标下绘制。

当前鼠标世界坐标通过“屏幕坐标减摄影机偏移”得到，适用于现有默认摄影机设置。后续加入缩放、旋转或目标跟随后，可改用 raylib 的 `GetScreenToWorld2D()` 完成转换。

### 5. 模板驱动实体创建

敌人模板 `TM_Mst` 保存类型、颜色、速度、半径和生命值。工厂通过类型 ID 查找模板，再创建敌人实例。

塔模板 `TM_Tower` 保存类型、伤害与颜色。当前模板中的战斗属性尚未完整连接到选塔和攻击流程。

## 当前边界与后续方向

当前版本已经搭起塔防原型的基础结构，后续可以围绕以下内容继续完善：

- 将选塔操作与塔位激活、类型和攻击属性绑定。
- 接通子弹命中、伤害结算、敌人死亡与奖励。
- 为每座塔维护独立攻击计时器；当前开火逻辑共用上下文中的计时器。
- 增加敌人终点判定、基地扣血、游戏结束和重新开始。
- 增加建造费用、金币消耗和升级规则。
- 为固定容量的实体数组增加边界检查。
- 完善移除实体后的内存释放、塔模板和贴图资源清理。
- 整理构建脚本，增加目录创建和错误中止。

这些条目描述当前实现边界与可继续开发的方向，不表示已经完成。

## 常见问题

### 提示找不到 gcc

确认已安装 Windows GCC 工具链，并将其 `bin` 目录加入 `PATH`。重新打开终端后执行：

```powershell
gcc --version
```

### 提示无法创建 main.o 或 main.exe

先确认项目根目录下存在 `build` 和 `bin`，再重新编译。

### 启动时提示缺少 raylib.dll

确认 `raylib.dll` 已复制到 `bin/main.exe` 所在目录，并检查 DLL 与程序的目标架构是否一致。

### 程序启动了，但贴图没有加载

从项目根目录运行，确认 `assets` 目录存在，且包含 `cell.png`、`red.png`、`pink.png`、`purple.png`。

### 更换编译器后出现预编译头错误

仓库附带 `include/raylib.h.gch`。预编译头可能与生成它的编译器版本、目标架构和参数有关；若日志指向该文件，可先将其改名备份，让 GCC 使用普通头文件重新编译。

## 第三方致谢与许可

- [raylib](https://github.com/raysan5/raylib)：窗口、输入和图形接口。
- [raymath](https://github.com/raysan5/raylib/blob/4.5.0/src/raymath.h)：向量数学工具。

随仓库提供的 raylib 头文件包含 zlib/libpng 许可证声明，第三方代码应遵守对应许可并保留相关声明。

当前仓库未发现项目级 `LICENSE` 文件；项目源码与美术资源的使用授权应以作者明确说明为准。

