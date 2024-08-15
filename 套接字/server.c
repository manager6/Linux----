#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// 创建一个简单的TCP服务器
int main(int argc, char *argv[])
{

    // 1.创建套接字

    int sever_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sever_fd == -1)
    {
        perror("socket");
        return -1;
    }

    // 2.绑定套接字

    struct sockaddr_in ser_inf;
    memset(&ser_inf, 0, sizeof(struct sockaddr_in));

    ser_inf.sin_family = AF_INET;
    ser_inf.sin_port = htons(8888);
    ser_inf.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sever_fd, (struct sockaddr *)&ser_inf, sizeof(ser_inf)) == -1)
    {
        perror("bind");
        return -1;
    }
    else
    {
        printf("绑定套接字成功\n");
    }

    // 3.监听

    if (listen(sever_fd, 30) == -1)
    {
        perror("listen");
        return -1;
    }

    // 4.等待连接

    if (accept(sever_fd, NULL, NULL) == -1)
    {
        perror("accept");
        return -1;
    }
    else
    {
        printf("连接成功\n");
    }
    // 5.收发信息

    // 6.关闭套接字

    return 0;
}