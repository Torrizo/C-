#include <pthread.h>
#include "tcpsocket.hpp"

void *thr_start(void *arg)
{
	TcpSocket *con_sock = (TcpSocket *)arg;
	while (1){
		std::string buf;
		bool ret = con_sock->Recv(&buf);
		if (ret == false) {
			con_sock->Close();
			delete con_sock;
			return NULL;
		}
		printf("client say:%s\n", buf.c_str());

		std::cout << "server say:";
		std::cin >> buf;
		ret = con_sock->Send(buf);
		if (ret == false) {
			con_sock->Close();
			delete con_sock;
			return NULL;
		}
	}
	delete con_sock;
	return NULL;
}
int main()
{
	TcpSocket lst_sock;//�����׽���
	//1. �����׽���
	CHECK_RET(lst_sock.Socket());
	//2. �󶨵�ַ��Ϣ
	CHECK_RET(lst_sock.Bind("0.0.0.0", 9000));
	//3. ��ʼ����
	CHECK_RET(lst_sock.Listen());
	while (1) {
		//4. ��ȡ�½�����
		TcpSocket *con_sock = new TcpSocket();
		bool ret = lst_sock.Accept(con_sock);
		if (ret == false) {
			continue;
		}
		pthread_t tid;
		pthread_create(&tid, NULL, thr_start, (void*)con_sock);
		pthread_detach(tid);
	}
	//6. �ر��׽���
	lst_sock.Close();
	return 0;
}
