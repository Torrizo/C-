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
    while(1) {
        //发送数据
        std::string buf;
        std::cout << "我说: ";
        std::cin >>buf;
        sock.Send(buf, ip, port);
        //接收数据
        sock.Recv(&buf);
        std::cout<<"服务端说：" << buf<<std::endl;
    }
    //关闭套接字
    sock.Close();
    return 0;
}
