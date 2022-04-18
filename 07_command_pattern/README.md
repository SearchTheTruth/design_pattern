Command Pattern
将请求封装成对象，这可以让你使用不同的请求，队列，或日志请求来参数话其他对象。命令模式也可以支持撤销操作

Command Pattern的经典结构由三个部分组成，分别是Command，Invoker，Receiver
提供两个方法execute(), undo()用来描述需要具体执行的命令并记录执行该命令的对象(receiver)是谁
本例中FanCommand，LightCommand等均为此类对象

Invoker
管理Command对象，并决定何时调用execute()和undo()方法
本例中RemoteControl为此对象，相应按键按下的时候就是execute()或undo()调用的时机

Receiver
Command动作真正的执行者
本例中Fan, Light均为此类对象

TODO:
用队列或日志的方式实现Command Pattern