# BreakpadTest

该仓储包含 qBreakpad 和 breakpad 的测试程序。

## 功能说明
- **qBreakpad**: 这是一个用于捕获和报告应用崩溃的工具。
- **breakpad**: 提供一个客户端和服务器组件，实施崩溃报告系统。

## 主要编程语言
- C++ (68.1%)
- Makefile (13.8%)
- C (5%)
- Shell (4.5%)
- Objective-C (3.2%)
- Objective-C++ (2.7%)
- 其他 (2.7%)

## 安装说明

### 前置要求
- Qt 5.x 或更高版本
- C++ 编译器 (支持 C++11)
- CMake 或 qmake

### 构建步骤
1. 克隆仓库：
   ```bash
   git clone https://github.com/nealwang123/BreakpadTest.git
   cd BreakpadTest
   ```

2. 创建崩溃转储目录：
   ```bash
   mkdir crashes
   ```

3. 使用 qmake 构建：
   ```bash
   qmake BreakpadTest.pro
   make
   ```

## 使用说明

### 测试崩溃转储功能
应用程序包含了用于测试崩溃转储生成的示例代码（已注释）。

要测试崩溃处理：
1. 在 `widget.cpp` 中取消注释以下任一测试代码：
   - 析构函数中的 `*((int*)0) = 10;` - 测试应用关闭时的崩溃
   - 按钮处理器中的空指针访问 - 测试运行时崩溃

2. 重新编译并运行应用程序

3. 触发崩溃后，在 `crashes` 目录中会生成 .dmp 文件

### 注意事项
- 确保在运行前创建 `crashes` 目录
- 崩溃转储文件采用 minidump 格式
- 可以使用 Breakpad 工具分析生成的转储文件

## 贡献
欢迎提交 Pull Request 和 Issue。

## 许可证
请参考项目中的 LICENSE 文件。

