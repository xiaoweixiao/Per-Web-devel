# Personnal Web Develpment
**使用技术：线程池、进程间通信、进程替换、unordered_map**

**开发环境：Centos7.0**

**使用工具：vim、g++、shell、makefile**
## 项目成果
**1. 实现了tcp端口复用**

**2.可以实现CGI请求和非CGI请求**

**3.采用线程池任务队列处理http请求**

**4.可以处理GET方法和POST方法的http请求**
## 项目收获
**对于http协议更加熟悉，对于web服务器的连接访问有了一定掌握，使用C和C++混编的形式，对C++的类和对象有了更深层次的认识，对于线程有了更加清晰的认识。**

## 部分截图
#### 404
![image text](https://github.com/xiaoweixiao/Per-Web-devel/blob/master/picture/404.png)
#### POST方法的CGI计算器
![image text](https://github.com/xiaoweixiao/Per-Web-devel/blob/master/picture/POST.png)
#### 解析其它html文件
![image text](https://github.com/xiaoweixiao/Per-Web-devel/blob/master/picture/html.png)
#### 采用POST方法实现CGI请求
![image text](https://github.com/xiaoweixiao/Per-Web-devel/blob/master/picture/post_cal.png)
#### 采用POST方法实现CGI请求结果
![image text](https://github.com/xiaoweixiao/Per-Web-devel/blob/master/picture/post_cal2.png)

## 服务器启动使用说明
**关闭防火墙**
```
sudo systemctl stop firewalld
```
**执行编译脚本**
```
./build.sh
```
**启动服务器脚本**
```
./start.sh
```
