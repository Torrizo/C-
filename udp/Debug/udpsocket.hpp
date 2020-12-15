#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>//地址转换接口头文件
#include <netinet/in.h>//地址结构类型定义头文件
#include <sys/socket.h>//套接字接口头文件

#define CHECK_RET(q) if((q)==false){return -1;}
class UdpSocket
{
    public:
        UdpSocket():_sockfd(-1){
        }
        bool Socket() {
            //int socket(地址域，套接字类型，协议类型)
            _sockfd = socket(AF_INET, SOCK_DGRAM,IPPROTO_UDP);
            if (_sockfd < 0) {
                perror("socket error");
                return false;
            }
            return true;
        }
        bool Bind(const std::string &ip, int port) {
            //int bind(描述符， 地址信息结构， 地址长度)
            int ret;
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);
            ret = bind(_sockfd, (struct sockaddr*)&addr, len);
            if (ret < 0) {
                perror("bind error");
                return false;
            }
            return true;
        }
        bool Send(std::string &d, std::string &ip, int port){
            //send(描述符，数据，长度，标志位，对端地址，长度)
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);
            int ret = sendto(_sockfd, d.c_str(), d.size(), 0,
                    (struct sockaddr*)&addr, len);
            if (ret < 0) {
                perror("sendto error");
                return false;
            }
            return true;
        }
        bool Recv(std::string *b, std::string *ip = NULL, 
                int *port = NULL){
            //recvfrom(fd,缓冲区,长度，标志位，对端地址，长度)
            char tmp[4096] = {0};
            struct sockaddr_in addr;
            socklen_t len = sizeof(struct sockaddr_in);
            int ret = recvfrom(_sockfd, tmp, 4096, 0,
                    (struct sockaddr*)&addr, &len);
            if (ret < 0) {
                perror("recvfrom error");
                return false;
            }
            b->assign(tmp, ret);
            if (ip != NULL) {
                *ip = inet_ntoa(addr.sin_addr);
            }
            if (port != NULL) {
                *port = ntohs(addr.sin_port);
            }
            return true;
        }
        bool Close() {
            if (_sockfd != -1) {
                close(_sockfd);
                _sockfd = -1;
            }
            return true;
        }
    private:
        int _sockfd;
};
