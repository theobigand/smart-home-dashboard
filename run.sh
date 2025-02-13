#!/bin/bash
mkdir -p build
cd build
cmake ..
make
echo "✅ Build complete! Running the program..."
echo ""
./SmartHomeAutomation
make clean