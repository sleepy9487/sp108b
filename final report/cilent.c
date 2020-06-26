#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc , char *argv[])
{

    int sockfd = 0;
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if (sockfd == -1){
        printf("創建失敗");
    }


    struct sockaddr_in info;
    bzero(&info,sizeof(info));
    info.sin_family = PF_INET;

    //localhost test
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = htons(8700);


    int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
    if(err==-1){
        printf("連線失敗");
    }


    char message[] = {"哈囉"};
    char receiveMessage[100] = {};
    send(sockfd,message,sizeof(message),0);
     recv(sockfd,receiveMessage,sizeof(receiveMessage),0);

    printf("%s",receiveMessage);
    printf("關閉\n");
    close(sockfd);
    return 0;