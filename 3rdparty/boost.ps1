$boost_version = "boost-1.78.0"

mkdir boost
cd boost
git clone --recursive -b $boost_version  https://github.com/boostorg/boost.git ./
./bootstrap.bat
./b2.exe install -j2 --prefix=.\

Pause
