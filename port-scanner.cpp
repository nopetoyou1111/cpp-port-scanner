#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main()
{
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];
    int port;
    string host;
    cout << "Enter the host to scan: ";
    cin >> host;
    for (port = 1; port < 65535; port++)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
        {
            cout << "Could not create socket" << endl;
        }
        cout << "Socket created" << endl;
        server.sin_addr.s_addr = inet_addr(host.c_str());
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
        {
            cout << "Port " << port << " is closed" << endl;
        }
        else
        {
            cout << "Port " << port << " is open" << endl;
        }
        close(sock);
    }
    return 0;
}

