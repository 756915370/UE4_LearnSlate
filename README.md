# UE4_LearnSlate
Slate是什么？Slate是UE4的底层UI框架。我们经常使用的UMG和UE4编辑器的各个界面底层都是Slate。
关于Slate的教程，大都是把[**Unreal Engine 4: Slate UI Tutorial 1 - HUD initialization and first widget**](http://students.ceid.upatras.gr/~vpapadatos/UE4cpp_slate_1.html)系列文章翻译成中文。对于里面的细节没有进行详细的描述。所以我重新写了这篇文章。**实现功能和代码和这篇文章大致相同**，不过我会讲得更加细致，对于新人更加友好。[github工程点这里](https://github.com/756915370/UE4_LearnSlate)。
**实现的功能就是在画一个居中的Text和2个靠右下的Button。** 这些Widget看起来很小是因为用默认的大小画的，没有在代码里指定大小。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603155753225.png#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603155803285.png#pic_center)

***

#### HUD类

HUD类也是用来画UI的，但是现在有UMG的存在，HUD类很少用到了。根据[官方文档](https://docs.unrealengine.com/4.26/en-US/InteractiveExperiences/Framework/UIAndHUD/)所说，在多人分屏游戏里，每个玩家共享一个屏幕但是有各自的UI，这种时候可以使用HUD类。这个教程中我们在HUD类里来画Slate控件。
**通过在Setting里可以看到我们当前使用的HUD类**。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603162009654.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)
首先我们创建自己的HUD类AMainMenuHud：
里面有：

- 一个初始化函数。初始化要做的事情后面会讲。

- 一个存储我们待会要建的SCompoundWidget的智能指针，**为什么使用TSharedPtr也是后面会讲。**  
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603165705476.png#pic_center)

  接着我们创建自己的GameMode并把成员变量HUDClass设为AMainMenuHud。
  ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603165843557.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)

***

#### SWidget类

SWidget是所有Slate控件的基类。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603164022828.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)

- **SCompoundWidget可以放一个子控件。**
- **SLeafWidget不能放子控件。**
- **SPanel可以放多个子控件。**

UE4编辑器下提供了创建SCompoundWidget子类的入口。这里我们使用SCompoundWidget来绘制我们的按钮和文字。**注意创建了以后在UE4编辑器下是看不到你建的类的，只能在C++工程里看到。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021060316453987.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)
接着我们创建自己的SCompoundWidget类叫**MainMenuWidget。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603172223952.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)
里面有：

- 三个宏**SLATE_BEGIN_ARGS**、**SLATE_END_ARGS()**这两个是自带的。**SLATE_ARGUMENT**我们自己添加，作用是指明构造时需要的参数。这里写的**MainMenuHud**变量实际上没有用到。只是为了展示如何构造时传入参数。写法上要注意不能写在{}里面不然会编译不过。

- **Construct**函数。构造SWidget时会调用的函数。里面只有一个参数FArguments。我们可以这么写来拿到我们刚才用宏定义的值。**加下划线_的原因看一眼SLATE_ARGUMENT的定义就能明白**。

  ```cpp
  auto CacheHud = InArgs._MainMenuHud
  ```

  ![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603174339698.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)

- 两个方法**PlayGameClicked和QuitGameClicked**，**返回FReply**。用于后面Button的事件绑定。FReply类作用是Widget拿到玩家输入后如何处理。**FReply:Handle()表示把这个输入截断，不会再传给当前Widget后面的Widget。FReply:UnHandle()表示把这个输入穿透，让它继续传给当前Widget后面的Widget。** FReplay:Handle().xxx根据后面加的xxx不同还有很多其他用法，比如**检测拖拽DetectDrag**、**设置鼠标位置SetMousePos**等其他用法。这里不做进一步深入。

***

#### Slate语法

Slate的语法比较特殊，不过可读性很强，注意它的特殊缩进格式，如果使用vs的格式化快捷键会破坏掉缩进格式要小心。**SNew(WidgetType)** 作用是创建一个SWidget。**STextBlock、SButton、SVerticalBox**的功能和我们经常使用的UMG里的控件差不多。**Slot**直译为插槽，通过增加插槽我们可以嵌套其他SWidget。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603200512333.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)
如果出现下面这种乱码，**说明字体设置错误。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603200950568.png#pic_center)
开头提到的英文的那个教程多了**设置Font** 这一步，由于找不到字体就会出现Text控件乱码的问题。这个乱码问题在使用UMG时也会出现。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603201047281.png#pic_center)

***

#### TSharePtr、TShareRef

在创建**MainMenuHud**类时，我们使用了**TSharePtr**来存储**SMainMenuWidget**。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603165705476.png#pic_center)
智能指针的作用官方文档写得很清楚。[**关于智能指针。**](https://docs.unrealengine.com/4.26/zh-CN/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/SmartPointerLibrary/SharedPointer/) 
我在看原版英文教程时到这里有一个困惑：**为什么这里使用TSharePtr而不是TShareRef?** 明明官网是建议我们使用共享引用的。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603202636536.png#pic_center)
一番实验，发现在**类定义时不能使用共享引用，共享引用必须在定义的时候就赋值。** 
下面这么写会编译失败：

```cpp
 TSharedRef<class SMainMenuWidget> MainMenuWidget;
```

这么写编译成功：

```cpp
{
	...
	TSharedRef<SMainMenuWidget> MainMenuWidget = SNew(SMainMenuWidget).MainMenuHud(this);
	...
}
```

回到我们创建的HUD类**MainMenuHud**类，在初始化函数里构建**SMainMenuWidget**，**父类调用一定要写**，不然又会崩溃：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210603203119539.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)
**SAssignNew和SNew都能创建SWidget，区别是前者返回TSharedPtr，后者返回TSharedRef**。但是因为**TSharedRef**可以被隐式转换为**TSharedPtr**，所以对于**TSharedPtr**来说用哪个都一样，对于**TSharedRef**来说只能使用SNew。**后面加点表示构造时要传入的参数。**
SAssignNew和SNew在写法上还有一点点不同，下面两种写法都是ok的：

```cpp
//MainMenuWidget = SNew(SMainMenuWidget).MainMenuHud(this);
SAssignNew(MainMenuWidget, SMainMenuWidget).MainMenuHud(this);
```

***

#### 总结

- **HUD类。以前的UI解决方案，现在很少用了。**
- **SWidget类图。三大类，SCompoundWidget能放一个子Widget，SLeafWidget不能放子Widget，SPanelWidget能放很多个。**
- **Slate特殊写法。SNew新建，加点设置参数，加Slot设置子Widget。**
- **TSharePtr和TShareRef智能指针。TSharefPtr可以为空，可以在头文件定义。**



***

关于作者

- **水曜日鸡**，喜欢ACG的游戏程序员。曾参与索尼中国之星项目《硬核机甲》的开发。 目前在某大厂做UE4项目。

CSDN博客：[https://blog.csdn.net/j756915370](https://blog.csdn.net/j756915370)  
知乎专栏：[https://zhuanlan.zhihu.com/c_1241442143220363264](https://zhuanlan.zhihu.com/c_1241442143220363264)  
游戏同行聊天群：891809847