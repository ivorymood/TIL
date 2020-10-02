import socket

HOST = ''
PORT = 9009


def runServer():
    # TCP 소켓 생성, socket 객체 리턴
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind((HOST, PORT))
        sock.listen(1)
        print('클라이언트 연결을 기다리는 중...')

        # 클라이언트로부터 연결요청이 올 때까지 대기
        # (연결시 클라이언트와 연결된 TCP소켓과 클라이언트 주소 리턴)
        conn, addr = sock.accept()
        with conn:
            print('[%s]와 연결됨' % addr[0])
            while True:

                # 수신한 데이터 - 이진 바이트 스트림
                data = conn.recv(1024)
                if not data:
                    break
                print('메시지 수신[%s]' % data.decode())

                # 모두 전송하면 None리턴. 오류발생하면 오류발생
                conn.sendall(data)


runServer()
