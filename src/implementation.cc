#include <mylib/interface.h>
#include <string>

#include <string>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#define HAVE_DLFCN_H
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dlfcn.h>
#endif

#ifdef __APPLE__
#include <mach-o/dyld.h> /* _NSGetExecutablePath */
#endif

static const int MAXPATHLEN = 1024;

namespace MyLib {

void anchor() {}

Message::Message(std::string const& data)
    : m_data(data) {}

std::string const& Message::get() {
    return m_data;
}

void Message::set(std::string const& data) {
    m_data = data;
}

// /llvm/lib/Support/Unix/Path.inc
std::string get_lib_dir(const char *library_name, void *MainAddr)
{
    char exe_path[MAXPATHLEN];

#if defined(HAVE_DLFCN_H)
    // Use dladdr to get executable path if available.
    Dl_info DLInfo;
    int err = dladdr(MainAddr, &DLInfo);
    if (err == 0)
    {
        return "";
    }
    // If the filename is a symlink, we need to resolve and return the location of
    // the actual executable.
    char link_path[MAXPATHLEN];
    if (realpath(DLInfo.dli_fname, link_path))
    {
        return std::string(link_path);
    }
#elif defined(__APPLE__)
    uint32_t bufsize = sizeof(exe_path);
    if (_NSGetExecutablePath(exe_path, &bufsize) == 0)
    {
        char link_path[MAXPATHLEN];
        if (realpath(exe_path, link_path))
        {
            return std::string(link_path);
        }
    }
#elif defined(__FreeBSD__) || defined (__NetBSD__) || \
      defined(__OpenBSD__) || defined(__minix)
    if (getprogpath(exe_path, library_name) != NULL)
    {
      return std::string(exe_path);
    }
#elif defined(__linux__) || defined(__CYGWIN__)
    ssize_t len = readlink("/proc/self/exe", exe_path,MAXPATHLEN-1);
    if (len >= 0)
    {
      return std::string(exe_path, len));
    }
#elif defined(_WIN32)
    GetModuleFileNameA (0, exe_path, MAXPATHLEN);
    return std::string(exe_path);
#else
    #error GetMainExecutable is not implemented on this host yet.
#endif
  return "";
}

};

