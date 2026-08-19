// Minimal POSIX Memory & C Runtime Stub (for OBS Studio target)
#pragma once

using size_t = unsigned long long;
using uint8_t = unsigned char;

namespace leraOS::Compat::POSIX {
    static uint8_t heapMemory[1024 * 1024 * 16];
    static size_t heapIndex = 0;

    class Runtime {
    public:
        static void* malloc(size_t size) {
            if (heapIndex + size > sizeof(heapMemory)) return nullptr;
            void* ptr = &heapMemory[heapIndex];
            heapIndex += size;
            return ptr;
        }

        static void free(void* ptr) { (void)ptr; }

        static void memcpy(void* dest, const void* src, size_t n) {
            char* d = static_cast<char*>(dest);
            const char* s = static_cast<const char*>(src);
            while (n--) *d++ = *s++;
        }
    };
}

extern "C" {
    void* malloc(size_t size) { return leraOS::Compat::POSIX::Runtime::malloc(size); }
    void free(void* ptr) { leraOS::Compat::POSIX::Runtime::free(ptr); }
    void* memcpy(void* dest, const void* src, size_t n) {
        leraOS::Compat::POSIX::Runtime::memcpy(dest, src, n);
        return dest;
    }
}
