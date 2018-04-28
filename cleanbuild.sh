rm -rf build || echo 1
mkdir build
cd build
cmake ../
cd ..
cmake --build ./build
