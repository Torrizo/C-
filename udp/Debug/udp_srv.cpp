#include "udpsocket.hpp"

int main (int argc, char *argv[])
{
    if (argc != 3) {
        std::cout << "Usage: ./udp_srv 192.168.1.1 9000\n";
        return -1;
    }
    std::string ip = argv[1];
    int port = std::stol(argv[2]);//stol字符串转数字
    UdpSocket sock;
    //创建套接字
    CHECK_RET(sock.Socket());
    //绑定地址信息
    CHECK_RET(sock.Bind(ip, port));
    while(1) {
        //接收数据
        std::string buf;
        std::string cli_ip;
        int cli_port;
        sock.Recv(&buf, &cli_ip, &cli_port);
        std::cout<<cli_ip <<":"<<cli_port<<" say: "<<buf<<std::endl;
        //响应数据
        std::cout << "我说: ";
        std::cin >>buf;
        sock.Send(buf, cli_ip, cli_port);
    }
    //关闭套接字
    sock.Close();
    return 0;
}
