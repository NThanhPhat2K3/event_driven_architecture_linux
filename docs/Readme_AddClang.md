# README — Clang-Format Integration

This project uses clang-format to enforce a consistent coding style across all C/C++ source files.
Below are the steps to install, configure, and use clang-format in your workflow.

## 1. Install Clang-Format

***Ubuntu / Debian***

```console
sudo apt install clang-format
```

## 2. Project Coding Style (.clang-format)

The project includes a .clang-format file at the repository root:

```console
BasedOnStyle: Google
IndentWidth: 8
TabWidth: 8
UseTab: Always
ColumnLimit: 80
PointerAlignment: Right
SpaceBeforeParens: Never
AllowShortIfStatementsOnASingleLine: false
BreakBeforeBraces: GNU
```

This provides a Linux-like formatting style using TAB width 8 and K&R-inspired structure.

## 3. Format Code Manually

Format a single file:

```console
clang-format -i main.cpp
```

## 4. VSCode Integration (Recommended)

***Step 1: Install extension***

Search and install:

```console
Clang-Format (by xaver)
```

***Step 2: Enable format on save***

Open VSCode Settings (JSON):

```console
Ctrl + Shift + P → Preferences: Open Settings (JSON)
```

Paste:

```console
{
    "editor.formatOnSave": true,
    "[cpp]": {
        "editor.defaultFormatter": "xaver.clang-format"
    },
    "[c]": {
        "editor.defaultFormatter": "xaver.clang-format"
    }
}
```

Now your C/C++ files will automatically format when you press Ctrl + S.
