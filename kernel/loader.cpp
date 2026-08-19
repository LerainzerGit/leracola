// Application Executable Loader
#pragma once

namespace leraOS::Loader {
    typedef void (*ExecutableEntry)();

    class AppLoader {
    public:
        static bool LaunchBinary(const unsigned char* codeAddress) {
            if (!codeAddress) return false;
            ExecutableEntry entry = reinterpret_cast<ExecutableEntry>(const_cast<unsigned char*>(codeAddress));
            entry();
            return true;
        }
    };
}
