#!/bin/bash

if [ -f "githubsite.txt" ]; then
    GITHUB_REPO=$(cat githubsite.txt)
    echo "GitHub 仓库地址: $GITHUB_REPO"
else
    echo "错误：找不到 githubsite.txt 文件。"
    exit 1
fi

cd "$(dirname "$0")/Factory" || exit

BUILD_DIR="build"
mkdir -p "$BUILD_DIR" && cd "$BUILD_DIR"

echo "运行 CMake..."
cmake ..

if [ $? -ne 0 ]; then
    echo "CMake 配置失败。"
    exit 1
fi

echo "编译项目..."
make

if [ $? -ne 0 ]; then
    echo "编译失败。"
    exit 1
fi
echo "运行程序..."
./FactoryPattern

echo "程序运行完成。"