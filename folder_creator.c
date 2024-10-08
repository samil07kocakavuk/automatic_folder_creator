#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h> 

int main()
{
    char dizin[200];
    // Prompt user for the directory path
    printf("Lütfen klasörleri oluşturmak istediginiz dosya yolunu girin: ");
    scanf("%199s", dizin);
    
    char basePath[200];
    // Copy the user input to basePath
    strcpy(basePath, dizin);  

    // Check if the directory exists
    if (_access(dizin, 0) != 0)
    {
        printf("Dosya yolu bulunamadı: %s\n", dizin);
        return 1;
    }

    char fullPath[256];
    // Prompt user for the folder name
    printf("Klasörün adını girin: ");
    char folderName[50];
    scanf("%s", folderName);

    int bas, bit, i;
    // Prompt user for the starting number
    printf("Başlangıç numarasını girin: ");
    scanf("%d", &bas);
    // Prompt user for the ending number
    printf("Bitiş numarasını girin: ");
    scanf("%d", &bit);

    // Loop to create folder names
    for (i = bas; i <= bit; i++)
    {
        snprintf(fullPath, sizeof(fullPath), "%s%s%d", basePath, folderName, i);
        printf("Bu dizin oluşturacak %s\n", fullPath);
    }

    char onay;
    // Ask for user confirmation to create directories
    printf("Bu dizinlerin oluşturulmasını onaylıyorumusun: Y/n\n");
    scanf(" %c", &onay);
    printf("onay: %c\n", onay);

    // If user confirms, create the directories
    if (onay == 'Y' || onay == 'y')
    {
        for (i = bas; i <= bit; i++)
        {
            snprintf(fullPath, sizeof(fullPath), "%s%s%d", basePath, folderName, i);
            if (_mkdir(fullPath) == 0)
            {
                printf("Dizin başarıyla oluşturuldu: %s\n", fullPath);
            }
            else
            {
                perror("Dizin oluşturulamadı");
            }
        }
    }
    else
    {
        // If user cancels, print a message
        printf("Dizinler oluşturuma iptal edildi\n");
    }

    // Wait for user input before closing the program
    printf("Programı kapatmak için bir tuşa basın...\n");
    getchar();
    getchar();
    return 0;
}