## sample code to test finding the absolute path to a shared library across platforms


## Build

On Unix/Mac

	make
	test


Should print:

```
hello
/usr/local/lib/libmylib.dylib
hello
/Users/dane/projects/dlpath/build/out/Default/libmylib.dylib
hello
/Users/dane/projects/dlpath/libmylib.dylib
```