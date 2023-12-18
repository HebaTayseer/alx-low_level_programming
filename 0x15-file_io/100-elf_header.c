#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include "main.h"

/**
 * print_elf_header - Print information from the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_header(Elf64_Ehdr *header) {
    _printf("ELF Header:\n");
    _printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        _printf("%02x ", header->e_ident[i]);
    }
    _printf("\n");
    _printf("  Class:                             %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    _printf("  Data:                              %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    _printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    _printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            _printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            _printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_SOLARIS:
            _printf("UNIX - Solaris\n");
            break;
        default:
            _printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
    }
    _printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    _printf("  Type:                              ");
    switch (header->e_type) {
        case ET_EXEC:
            _printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            _printf("DYN (Shared object file)\n");
            break;
        default:
            _printf("<unknown: %d>\n", header->e_type);
    }
    _printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        _printf("Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        _printf("Error: Cannot open file %s\n", argv[1]);
        return 98;
    }

    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        _printf("Error: Cannot read ELF header from file %s\n", argv[1]);
        close(fd);
        return 98;
    }

    print_elf_header(&elf_header);

    close(fd);
    return 0;
}
