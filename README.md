# Image-Label-Tool

# 图片标记工具

## 功能<br />

该软件可用来进行图片标记，进而用来制作用于目标检测的数据集。<br/>
该软件界面简单(甚至简陋，后期会完善，欢迎熟悉Qt的朋友完善），操作方便，可以跨平台使用。<br/>

## 用法<br/>

#### 源码编译<br/>
软件代码基于Desktop Qt 5.10.0 MinGW 32bit + Qt Creator开发，下载 [src](https://github.com/EchoWangHF/Image-Label-Tool/tree/master/src) 文件夹当中的代码进行编译运行，即可使用。

#### 直接解压缩<br/>
windows 用户可以直接下载Image_Label_Windows.zip，解压缩后，点击LabelImg.exe,即可使用。<br/>

#### 标记流程<br/>
（1）首先打开软件可以看到以下简陋的界面：<br/>
![fig1](https://github.com/EchoWangHF/Image-Label-Tool/blob/master/images/1.png)<br/>
（2）点击“设置”按钮，填写你需要标记的目标数和目标名称。这个比较重要，因为生成的anontation是按照事先设置的目标顺序和目标名称写成的，如果不够严谨，会影响后续的xml文件的使用。<br/>
![fig2](https://github.com/EchoWangHF/Image-Label-Tool/blob/master/images/2.png)<br/>
（3）点击“添加文件”按钮,选择待标记图片所在的文件夹，必须选择到图片所在目录，因为软件不会检索该目录的子目录。<br/>
![fig3](https://github.com/EchoWangHF/Image-Label-Tool/blob/master/images/3.png)<br/>
（4）点击“开始标记"按钮，开始标记。按住鼠标左键拖动，则会选择一个矩形框，矩形框框住待标记目标。矩形框的标记顺序也要和预先设置的目标内容相同，比如我设置的标记目标内容分别是车，车标，车牌。那么我的矩形框标记顺序也要是先框车，再框车标，最后框车牌。标记错误，可以点击撤销，撤销标记信息。<br>
![fig4](https://github.com/EchoWangHF/Image-Label-Tool/blob/master/images/4.png)<br/>
（5）框完所有目标之后，点击保存或者直接点击下一张都行，软件会自动生成一个xml文件，当中保存了标记目标的位置信息。xml文件保存在annotation文件当中，该文件夹存放在源图片所在的文件夹当中。<br>
（6）备注：如上图所示，软件会表示出该图片是否被标记过，分别显示“已标记”和“未标记”。其中“下一张”，“上一张”,"撤销","保存"设置有键盘快捷键，分为:D,A,W,S。


