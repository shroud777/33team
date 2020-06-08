# 33team

[LG-LuoGu](https://www.luogu.com.cn/)、[LOJ-LibreOJ](https://loj.ac/)、[VJudge](https://vjudge.net/)、[CF-CodeForces](https://codeforces.com/)、[NC-NowCoder](https://www.nowcoder.com/)

## 20200608~20200614


校内专题：二分查找二分答案

- HDU_2141_Can you find it：预处理，枚举、二分查找。时间限制空间限制卡的非常好，预处理两层，枚举一层在前面预处理的结果中二分查找即可，如果枚举了两层时间超限，如果直接预处理三层空间超限。
- HDU_2199_Can you solve this equation：二分答案、精度控制、数学。求导后为：$32x^3+21x^2+4x+3$，在$[0,100]$ 区间大于0，所以原函数在这段区间单调递增，只要二分答案即可。

扩展：初级数据结构

- LG_3865_【模板】ST表：求解静态区间最大值，$O(n\log{n})$预处理，$O(1)$查询
- LG_3374_【模板】树状数组 1：$O(\log{n})$ 单点修改、$O(\log{n})$ 区间和查询
- LG_3368_【模板】树状数组 2：配合差分数组实现的$O(\log{n})$ 区间修改，$O(\log{n})$ 单点查询
- LG_3372_【模板】线段树 1：带延迟标记的线段树，最基础单点修改区间查询的线段树可以用上面的树状数组1测试，$O(\log{n})$ 区间修改，$O(\log{n})$ 区间查询
- LOJ_6279_数列分块入门 3：轻松一下，好理解的 $O(\sqrt{n})$ 时间复杂度算法，分块！可参考[这篇](https://www.luogu.com.cn/blog/deco/qian-tan-ji-chu-gen-hao-suan-fa-fen-kuai#)题解
- LG_3373_【模板】线段树 2：线段树进阶，有区间加和区间乘的线段树，可选题。

以上为基础的一系列数据结构，不要一道题一道题自己想，一道题一道题自己学就好，学会了要能看懂模板代码，并至少能手打出来一次，然后就是要保存好自己风格的模板方便后面使用。

特别需要注意不同数据结构能处理的问题、对应的时间复杂度常数和空间复杂度，线段树是初级阶段的究极数据结构，可以自己想想线段树的区间修改、区间最值查询怎么处理，自己找找题做做。


## 20200601~20200607

校内专题：

- POJ_1995_Raising Modulo Numbers：快速幂
- HDU_5616_Jam's balance：01背包，wi与-wi两个物品，注意方向
- POJ_2436_Disease Management：位运算，暴力二进制枚举
- HDU_1157_权利指数：位运算，暴力二进制枚举
- HDU_1060_Leftmost Digit：数学
- HDU_3835_R(N)：数学、暴力枚举，二分查找
- CF_962C_Make a Square：数位分解、位运算、暴力二进制枚举
- CF_1278B_A and B：数学、构造

扩展：洛谷对应题解、[牛客每日一题](https://ac.nowcoder.com/discuss/390407)

- LG_1305_新二叉树
- LG_1087_FBI树
- LG_3915_树的分解：dfs子树大小，大小为k的子树计数后减去
- NC_13886_Shortes  t Path：树上搜索，选边 
- NC_22598_Rinne Loves Edges：树形DP
- NC_14248_Treepath：树上搜索

## 20200527~20200529

前缀和与差分：https://oi-wiki.org/basic/prefix-sum/

- LG_1115_最大子段和：贪心
- LG_5638_【CSGRound2】光骓者的荣耀：前缀和、贪心
- LG_2004_领地选择：二维前缀和
- LG_3406_海底高铁：差分数组、模拟、贪心
- CF_1355C_Count Triangles：差分数组
- LG_4231_三步必杀：二重差分数组

