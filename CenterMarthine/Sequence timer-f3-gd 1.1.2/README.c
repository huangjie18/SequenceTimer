/*
1,将按键挂载在外部中断线上，设置最高优先级，当时别有级联时，关闭使能按键状态改变
2,
  1，打开CHANNEL时候按照设定的描述打开
  2，关闭CHANNEL时候，若CHANEL已经全部打开则按照设定的值关闭，若没有全部打开（正在打开突然有关闭信号），则按照时序一秒去关闭







*/