// Virtual File System (VFS)
#pragma once

using uint32_t = unsigned int;
using uint8_t = unsigned char;

namespace leraOS::FS {
    struct File {
        char name[32];
        uint32_t size;
        const uint8_t* data;
    };

    class VirtualFileSystem {
    private:
        static constexpr uint32_t MAX_FILES = 32;
        File fileRegistry[MAX_FILES];
        uint32_t totalFiles = 0;

    public:
        bool RegisterFile(const char* name, const uint8_t* buffer, uint32_t size) {
            if (totalFiles >= MAX_FILES) return false;
            File& f = fileRegistry[totalFiles++];
            f.size = size;
            f.data = buffer;

            int i = 0;
            while (name[i] != '\0' && i < 31) {
                f.name[i] = name[i];
                i++;
            }
            f.name[i] = '\0';
            return true;
        }

        const File* FindFile(const char* name) const {
            for (uint32_t i = 0; i < totalFiles; ++i) {
                int j = 0;
                while (name[j] != '\0' && fileRegistry[i].name[j] == name[j]) j++;
                if (name[j] == '\0' && fileRegistry[i].name[j] == '\0') return &fileRegistry[i];
            }
            return nullptr;
        }
    };
}
