#include <stdio.h>
#include <fstream>


int main() {
    char key[45];
    char ip[16];

    printf("Public key: ");
    fgets(key, 45, stdin);
    while(getchar() != '\n'){};

    printf("IP: ");
    fgets(ip, 16, stdin);

    //maybe confirm input

    FILE *conf = fopen("/etc/wireguard/wg0.conf", "a");
    fprintf(conf, "[Peer]\nPublic key = %s\nAllowedIPs = %s\n\n", key, ip);
    fclose(conf);

    system("sudo wg-quick down wg0");
    system("sudo wg-quick up wg0");
    return 0;
}