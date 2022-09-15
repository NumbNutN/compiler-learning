docker pull ubuntu  拉取一个镜像

docker run -it ubuntu 从镜像装载到一个临时的容器

docker exec  -it {NAME or ID} {Command} 从一个容器执行命令

-i 交互式操作
-t 终端

docker start 启动一个容器
docker stop 停止一个容器
docker restart 重启一个容器
docker logs 查看一个容器的标准输入输出

和宿主机共享目录
docker run -it --name compiler -P -v d:\Coding\DockerSpace\compiler-dev:/root maxxing/compiler-dev bash