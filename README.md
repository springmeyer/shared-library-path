## sample code to test finding the absolute path to a shared library across platforms

## Requires gyp to build

    sudo pip install gyp

## Build

On Unix/Mac:

	make
	make test

Should print something like:

```
hello
/usr/local/lib/libmylib.dylib
hello
/Users/dane/projects/dlpath/build/out/Default/libmylib.dylib
hello
/Users/dane/projects/dlpath/libmylib.dylib
```

Other platforms: Need help testing

For windows and gyp see: https://github.com/springmeyer/hello-gyp