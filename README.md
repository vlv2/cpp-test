# cpp-test

## dependencies

1. CMake >= v.3.16
2. Ninja Build System >= v1.10.0
3. NodeJS >= v16.17.1 e NPM >= 8.15 (development only)

## build

1. Clone and change to cpp-test folder

```script
git clone --recursive https://github.com/vlv2/cpp-test -j8 && cd cpp-test/
```

2. Generate build files

```script
cmake -S . -B build/ -G "Ninja Multi-Config" -DCMAKE_BUILD_TYPE:STRING=Debug
```

3. Build
```script
cmake --build build/ --config Debug --target all -j8
```

## development environment

1. Install npm dependencies

```script
npm install
```