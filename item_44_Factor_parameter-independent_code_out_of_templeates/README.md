# 条款44: 将与参数无关的代码抽离 templates



- Template 生成多个 classes 和多个函数，所以任何 template 代码都不该与某个造成膨胀的 template 参数产生关系
- 因非类型模板参数(non-type template parameters) 而造成的代码膨胀，往往可消除，做法是以函数参数或 class 成员变量替换 template 参数
- 因类型参数(typename parameters) 而造成的代码膨胀，往往可以降低，做法是让带有完全相同的二进制表述(binary representations)的具现类型(instantiation types)共享代码