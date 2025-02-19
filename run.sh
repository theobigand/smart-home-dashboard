#!/bin/bash
# This script is used to build and run the program
echo "🚀 Building the program..."
# rm -rf build _deps
mkdir -p build
cd build
cmake ..
make
echo "✅ Build complete!"

# Check if there is an argument and if it is equal to "test"
if [ "$1" == "test" ]; then
    echo "🧪 Running tests..."
    echo ""
    ./SmartHomeDashboardTests
else
    echo "🚀 Running the program..."
    echo ""
    ./SmartHomeDashboard
fi

# make clean