#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

int main(int argc, char * argv[]){
        int sd;
        sd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in *addr;
        addr = (struct sockaddr_in *) malloc (sizeof(struct sockaddr_in));
        addr->sin_family = AF_INET;
        addr->sin_port = htons(5000);
        inet_pton(AF_INET, "94.23.252.188", &(addr->sin_addr));
        connect(sd, (struct sockaddr *)addr, sizeof(*addr));
        int rd;
        char Buff[1025];
        cout << "What is your name?" << endl;
        cin >> Buff;
        write (sd, Buff, 1025);
        return 0;
}
