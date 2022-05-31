### 基于DS18B20温度传感器的温度传感与控制系统  
## 试验箱接线和硬件改动  
所有接线可以参考config.h文件  
  
1. 确认晶振跳线位置  
将JP1和JP2跳线连接到1-2位置,以便选择正确的晶振频率  
  
2. 硬件接线连接
P0 使用分叉线,0端接温度传感器接口J15,7端接LCD控制口J11
P1 连接到LCD屏数据接口J12
P2 使用分叉线,0端接印有字母B的板子上的蜂鸣器-继电器-电机接口J8,7端不接

## 工程代码使用
# 使用VSCode+EIDE开发下载
环境要求:  
1. 装有Keil C51环境  
2. 装有EIDE的VSCode编辑器   
3. Python3 + stcgal

本项目在EIDE + Keil C51环境下编写,项目文件为Code Workspace格式,需要使用装有EIDE组件的VSCode打开.
在VSCode中,经测试,EIDE自带的stcflash模块无法将程序下载到实验箱,因此需安装stcgal模块.项目已被配置为使用stcgal.

* 如何安装stcgal *  
安装Python3后,终端输入指令:pip install stcgal  
运行完成后即安装完成.  

若实在无法使用stcgal,也可找到输出的.hex文件,然后使用stcisp软件手动下载.  

# 使用Keil C51 IDE开发  
新建Keil C51项目,然后将本项目src下的所有文件复制到项目目录下.  

## 功能介绍
LCD屏幕显示当前测得的温度.如果温度高于26度,继电器闭合(开启风扇);如果高于27度,蜂鸣警报响起,屏幕闪烁报警.