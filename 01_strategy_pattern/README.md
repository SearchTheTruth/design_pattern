strategy pattern

1.第一版code如下
    Character player_1 = King(Sword());
这会导致派生类被截断，只剩基类的内容，king在发起进攻时，只会用手攻击。
因此要注意动态绑定只会在引用和指针上发生。

2.Character中has-a(包含) IWeapon接口
  Knife，Axe等武器is-a(继承) IWeapon接口并在useWeapon中实现不同的攻击方式
  是这个例子中strategy pattern的核心体现

3.TODO:
    使用模板类可以简化大量内容，如本例中King，Queen，Knight这三个类都可以合并成一个模板类
