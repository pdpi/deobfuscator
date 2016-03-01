# Bitcoin Deobfuscator

This tool removes the obfuscation introduced in Bitcoin Core 0.12, for
compatibility with earlier versions of Core and all versions of Classic.

## Prerequisites

You need Boost and LevelDB installed in your system.

## Building

    mkdir build
    cd build
    cmake ..
    make

##  Running

You can run this tool by pointing it at an obfuscated db:

    cd build;
    ./deobfuscate /path/to/testnet3/blocks/index
    ./deobfuscate /path/to/testnet3/chainstate