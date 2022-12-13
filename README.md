# cpp-test

## dependencies

### general 

1. GCC >= v9.4.0
2. CMake >= v.3.16
3. Ninja Build System >= v1.10.0
4. Git >= v2.25.1
   
### development

1. NodeJS >= v16.17.1 e NPM >= 8.15
2. CTest >= v3.16
3. clang-format >= v15.0.6
4. clang-tidy >= v15.0.6

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

2. Run tests

```script
cd build && ctest -C Debug
```