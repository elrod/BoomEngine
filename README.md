# Boom Engine

![Boom Engine Logo](docs/img/logo_400.png)

This is a simple toy game-engine built on top of raylib. 
This is made just for fun... Don't expect anything special, use it at your own risk...

## Supported platforms

The engine currently supports the following target platforms:

* MacOS
* WebAssembly

## How To Build

### MacOS

```bash
chmod +x scripts/build-macos.sh
./scripts/build-macos.sh
```

### WebAssembly

Requires [emscripten](https://emscripten.org/)

```bash
chmod +x scripts/build-wasm.sh
./scripts/build-wasm.sh
```