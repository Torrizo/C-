#include "tcpsocket.hpp"

int main()
{
	TcpSocket cli_sock;
	//1. �����׽���
	CHECK_RET(cli_sock.Socket());
	//2. �󶨵�ַ��Ϣ--���ǲ����Ƽ�
	//3. �����˷�����������
	CHECK_RET(cli_sock.Connect("172.31.43.144", 9000));
	while (1) {
		//��������
		std::string buf;
		std::cout << "client say:";
		std::cin >> buf;
		CHECK_RET(cli_sock.Send(buf));
		//��������
		buf.clear();
		CHECK_RET(cli_sock.Recv(&buf));
		std::cout << "server say: " << buf << std::endl;
	}
	//�ر��׽���
	cli_sock.Close();
	return 0;
}
