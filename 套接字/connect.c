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

    int connect_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect_fd == -1)
    {
        perror("connect");
        return -1;
    }

    // 2.连接服务器 connect

    struct sockaddr_in con_inf;
    memset(&con_inf, 0, sizeof(struct sockaddr_in));

    con_inf.sin_family = AF_INET;
    con_inf.sin_port = htons(8888);
    con_inf.sin_addr.s_addr = inet_addr("172.31.227.250");

    if (connect(connect_fd, (struct sockaddr *)&con_inf, sizeof(con_inf)) == -1)
    {
        perror("connect");
        return -1;
    }

    // 5.收发信息

    // 6.关闭套接字

    return 0;
}