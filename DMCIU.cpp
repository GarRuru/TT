#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <winsock2.h>
///�ݭn�s��libwsock32.a

#pragma comment(lib, "ws2_32.lib")
/******************
    ���A���׺�
******************/

int main(int argc, char *argv[])
{
    WSADATA wsaData;//WSAStartup�ΨӪ�l��winsock��DLL�w�A���榨�\���^0�A���ѫ�h��^socket_error
    WORD sockVersion = MAKEWORD(2,2);//�إߨ�Ӧ줸�ժ�word�榡 �]�wsocket������2
    if(WSAStartup(sockVersion, &wsaData) != 0)
    {
        return 0;
    }

    SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);//�w�]2 2 17
    if(serSocket == INVALID_SOCKET)
    {
        printf("�s�����~!!!");
        return 0;
    }

    sockaddr_in serAddr;//�إ߳s��
    serAddr.sin_family = AF_INET;
    #ifdef DEBUG
    serAddr.sin_port = htons(8888);//�ϥΪ��s����ݤf
    #else
    printf("��J�n�ϥΪ��s���𸹽X:");

    u_short port_number;
    std::cin >> port_number;//��J�һݨϥΪ��s����ݤf��Ƹ��X
    serAddr.sin_port = htons(port_number);//�ϥΪ��s����ݤf
    #endif // DEBUG
    serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
    if(bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
    {
        printf("�i�j���~!!!");
        closesocket(serSocket);
        return 0;
    }

    sockaddr_in remoteAddr;
    int nAddrLen = sizeof(remoteAddr);
    while (true)
    {
        char recvData[255];
        int ret = recvfrom(serSocket, recvData, 255, 0, (sockaddr *)&remoteAddr, &nAddrLen);
        if (ret > 0)
        {
            recvData[ret] = 0x00;
            printf("������@�ӳs���G%s \r\n", inet_ntoa(remoteAddr.sin_addr));
            printf(recvData);
        }

        const char *sendData = "�Ӧۦ��A���׺ݪ�UDP�ʥ]\n";
        sendto(serSocket, sendData, strlen(sendData), 0, (sockaddr *)&remoteAddr, nAddrLen);

    }
    closesocket(serSocket);
    WSACleanup();
    return 0;
}
