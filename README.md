# Cake Build System

A custom build system for C++ projects with support for various graphics libraries and templates.

## Prerequisites

- **g++** compiler installed on your system
- Windows OS (uses .bat files)

## Installation Steps

### 1. Download and Setup
1. Download the repository from the provided link
2. Extract the folder to your desired location
3. Navigate to the extracted folder

### 2. Build the System
1. Run `release.bat` to build the Cake build system
2. This will generate `cake.exe`

### 3. Environment Setup
1. Create the following directory structure: `development/cake/`
2. Copy `cake.exe` to the `development/cake/` folder
3. Add the `development/cake/` path to your system's PATH environment variable

## Usage

### Basic Commands

#### Initialize Project
```bash
cake pre-bake
```
Use this command to set up a new project structure.

#### Build Commands
- **For console applications** (with print/cout support):
  ```bash
  cake bake console
  ```

- **For applications without console output**:
  ```bash
  cake bake app
  ```

## Template Support

The Cake Build System supports several graphics library templates:

### SDL2 Template
```bash
cake bake app
```
Use for SDL2-based projects (no console output needed).

### Raylib Template
```bash
cake bake console
```
Use for Raylib-based projects (console output supported).

### OpenGL Template (GLFW + GLAD)
- **With terminal attached**:
  ```bash
  cake bake console
  ```

- **Without terminal attached**:
  ```bash
  cake bake app
  ```

## Quick Start

1. Open command prompt/terminal
2. Navigate to your project directory
3. Run `cake pre-bake` to initialize
4. Choose appropriate `cake bake` command based on your project type
5. Your project will be compiled and ready to run

## Notes

- Ensure g++ is properly installed and accessible from command line
- The system must be added to PATH to use from any directory
- Choose the correct bake command based on whether you need console output or not

---

*Happy coding! 🎂*