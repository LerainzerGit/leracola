// UEFI Bootloader for leraOS Cola
typedef unsigned long long UINTN;
typedef void* EFI_HANDLE;
typedef UINTN EFI_STATUS;

#define EFI_SUCCESS 0

struct EFI_SYSTEM_TABLE {
    char Header[52];
    void* ConOut;
    char Reserved[48];
    void* BootServices;
};

extern "C" EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    (void)ImageHandle;
    (void)SystemTable;

    typedef void (*kernel_main_t)(unsigned long long fb_base, unsigned int width, unsigned int height, unsigned int pitch);
    kernel_main_t kernel_entry = (kernel_main_t)0x100000;

    if (kernel_entry) {
        kernel_entry(0xC0000000, 1024, 768, 1024 * 4);
    }

    return EFI_SUCCESS;
}
