# 贪吃蛇 (Snake Game)

用 C 语言 + [raylib](https://www.raylib.com/) 写的经典贪吃蛇小游戏。

## 功能

- 网格棋盘、随机食物
- 吃到食物长度 +1，得分 +5
- 撞墙或撞到自己 -> Game Over
- 开始界面，按空格开始
- 结束后按 R 重新开始

## 操作

| 按键 | 功能 |
|------|------|
| `SPACE` | 开始游戏 |
| `W` `A` `S` `D` | 上下左右移动 |
| `R` | 游戏结束后重新开始 |

## 如何编译运行

### 环境
- Visual Studio 2022
- raylib **MSVC 版**（[下载地址](https://github.com/raysan5/raylib/releases)）

### 编译方式 A：手动用命令行

```bash
gcc main.c -o snake.exe -I <raylib路径>/include -L <raylib路径>/lib -lraylib -lopengl32 -lgdi32 -lwinmm
```

### 编译方式 B：Visual Studio

1. 新建一个空控制台项目，把 `main.c` 添加进去
2. 项目属性 → **C/C++ → 常规 → 附加包含目录**：填 raylib 的 `include` 路径
3. 项目属性 → **链接器 → 常规 → 附加库目录**：填 raylib 的 `lib` 路径
4. 项目属性 → **链接器 → 输入 → 附加依赖项**：填 `raylib.lib;winmm.lib;gdi32.lib;opengl32.lib;user32.lib;shell32.lib`
5. 生成并运行

> 注意：raylib 必须是 **MSVC 版本**，MinGW 版的 `libraylib.a` 在 Visual Studio 中无法使用。
