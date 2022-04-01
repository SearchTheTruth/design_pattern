observer pattern
在对象之间定义一对多的依赖，这样一来，当一个对象改变状态，依赖它的对象都会收到通知并自动更新

1.TempDashBoard，WetDashBoard依赖WeatherStation的问温度，湿度数据来改变看板的输出
2.本例中采用了push,pull的流程, pull的体现在于update中getTemp()，getWet()

TODO：
1.Observerable和Observerable本意只负责observer框架，进行事件通知，而不负责处理业务逻辑，就像bbinder，bpbinder一样
但目前实现的代码中Observerable揉入了业务逻辑getTemp(),getWet()这是因为在具体的dashboard中保存的是Observerable *subject，
想要通过subject调用WeatherStation中的getTemp()就只能利用虚函数实现

是否还有其他好的办法能够将Observerable中的业务逻辑拆分出去呢？

眼下有一个不太好的办法：保存具体的气象站，但这样造成了dashboard对weatherstation的依赖。
若日后dashbord决定不再从气象站获取数据，而是从网络获取数据，这时就只能重新编译代码，而没有办法动态的调整。

class WebInfo : public Observerable {
    //something...
}

class WetDashBoard : public Observer
{
private:
    //Observerable *subject = nullptr;
    WeatherStation *station = nullptr;

    //更换数据源只能修改代码
    //WebInfo *web = nullptr;
};