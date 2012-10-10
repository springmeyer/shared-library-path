all: mylib

mylib:
	gyp mylib.gyp --depth=. -f make --generator-output=./build
	V=1 make -C ./build

clean:
	rm -rf ./build

install:
	@ cp ./build/out/Default/libmylib.dylib /usr/local/lib/libmylib.dylib

test: install
	@ ./build/out/Default/myapp
	@export DYLD_LIBRARY_PATH=`pwd`/build/out/Default/ && ./build/out/Default/myapp
	@cp ./build/out/Default/libmylib.dylib .
	@export DYLD_LIBRARY_PATH=`pwd`/ && ./build/out/Default/myapp

.PHONY: all mylib clean test
