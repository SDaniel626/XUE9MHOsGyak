#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE "XUE9MH.txt"

int main(void)
{
    int fileHandle = open(FILE, O_RDWR);
    if(fileHandle == -1)
    {
        printf("Nem sikerult megnyitni a(z) \"%s\" fajlt!\n", FILE);
        return 1;
    } else printf("Megnyitottam a(z) \"%s\" fajlt!\n", FILE);

    char tartalom[64];
    int olvasott = read(fileHandle, tartalom, sizeof(tartalom));

    tartalom[olvasott] = '\0';
    printf("beolvasott tartalom: \"%s\" osszesen \"%i\" byte.\n", tartalom, olvasott);

    lseek(fileHandle, 0, SEEK_SET);
    printf("A fajl elejere allitottuk a mutatot\n");

    char szoveg[] = "Rendszerhivassal iras fajlba";
    int irt = write(fileHandle, szoveg, sizeof(szoveg));
    printf("A fajlba irtuk a(z) \"%s\" szoveget. osszesen \"%i\" byte.\n", szoveg, irt);
    close(fileHandle);
    return 0;
}
